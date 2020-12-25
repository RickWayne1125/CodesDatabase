import numpy as np
import pandas as pd
import sklearn.datasets
import math
from sklearn.preprocessing import MinMaxScaler
from matplotlib import pyplot as plt


class DataReader:
    def __init__(self):
        self.rawx = None
        self.rawy = None
        self.trainx = None
        self.testx = None
        self.trainy = None
        self.testy = None

    def load_iris(self):
        data = sklearn.datasets.load_iris()
        self.rawx = data.data
        self.rawy = data.target
        self.splitData()

    def load_haberman(self):
        data = pd.read_csv('../data/haberman.txt')
        print(data)
        data = np.array(data)
        self.rawx = data[:, :3]
        self.rawy = data[:, 3]
        self.splitData()

    def load_watermelon(self):
        data = pd.read_csv('../data/watermelon_3a.csv')
        data = np.array(data)
        self.rawx = data[:, 1:3]
        self.rawy = data[:, 3]
        self.splitData()

    def load_wine(self):
        data = pd.read_csv('../data/wine.txt', index_col=False)
        data = np.array(data)
        self.rawx = data[:, 1:]
        self.rawy = data[:, 0]
        self.splitData()

    def splitData(self):
        permutation = np.random.permutation(self.rawx.shape[0])
        shuffled_dataset = self.rawx[permutation, :]
        shuffled_labels = self.rawy[permutation]
        tlen = int(len(shuffled_labels) * 2 / 3)
        # print('Size of Test Datasets:', tlen)
        dlen = len(shuffled_labels)
        self.trainx = shuffled_dataset[:tlen, :]
        self.trainy = shuffled_labels[:tlen]
        self.testx = shuffled_dataset[tlen:dlen, :]
        self.testy = shuffled_labels[tlen:dlen]

    def getTrainData(self):
        return self.trainx, self.trainy

    def getTestData(self):
        return self.testx, self.testy


class Layer:
    """
    神经网络层类,用于表示当前层每个神经元的输入以及输入尺寸、偏置值还有输入权重
    包含方法：
        - initParameters
        - forwardCalculate
        - activeFunction
        - updateParameters
        - getDerivative
    """

    def __init__(self, input_size=10, method='sigmoid', n=10, level=0):
        self.method = method  # 激活函数
        self.input_size = input_size  # 输入大小
        self.nerual_num = n  # 神经元个数
        self.level = level  # 层数索引
        self.w, self.b = self.initParameters()
        self.result = None  # 原输出
        self.output = None  # 激活后输出
        self.delta = None  # 梯度项
        self.input = None  # 最近一次输入值
        self.delta = None  # 大小为(n,1)

    def initParameters(self):
        """
        随机初始化参数
        :return: 初始化权重矩阵与偏置矩阵
        """
        w = np.random.rand(self.nerual_num, self.input_size)
        b = np.random.rand(self.nerual_num, 1)
        return w, b

    def forwardCalculate(self, input):
        """
        前向计算
        :param input: 输入值, shape为(n,1)
        :return: 初始输出值
        """
        self.input = input
        result = np.dot(self.w, input) - self.b
        self.result = result
        return result

    def activeFunction(self):
        """
        激活函数,通过对前向计算产生结果result按对应函数进行激活得到实际输出值
        :return: 实际输出值output
        """
        if self.method == 'sigmoid':
            self.output = 1 / (1 + np.exp(-self.result))
        elif self.method == 'relu':
            self.output = max(0, self.result)
        elif self.method == 'tanh':
            tmp = pow(math.e, self.result)
            self.output = (tmp - 1 / tmp) / (tmp + 1 / tmp)
        else:
            print('Method Not Found!')
        return self.output

    def updateParameters(self, dw, db):
        """
        通过输入变化值对权重以及偏置进行更新
        :param dw: deltaW,权重矩阵变化值
        :param db: deltaB,偏置矩阵变化值
        :return:
        """
        self.w += dw
        self.b += db

    def getDerivative(self):
        """
        按该层神经元激活方式对激活函数求导
        :return:
        """
        if self.method == 'sigmoid':
            return self.output * (1 - self.output)


class BPNet:
    def __init__(self, layer_list, active_list):
        """
        根据输入的层数列表以及激活列表初始化神经网络,同时完成数据的载入,初始化完成后顺序执行模型的训练与评估
        :param layer_list: 层数列表,size为神经网络隐含层层数,layer_list[i],表示第i+1层中神经元个数
        :param active_list: 激活列表,size为神经网络隐含层层数,active_list[i],表示第i+1层的激活方式
        """
        self.layer_num = len(layer_list)
        self.layer_size = layer_list
        self.layers = []
        # 导入数据
        self.loadData()
        input_size = len(self.trainx[0])
        # 添加隐层
        for i in range(self.layer_num):
            if i != 0:
                temp_layer = Layer(input_size=layer_list[i - 1], method=active_list[i], n=layer_list[i])
            else:
                temp_layer = Layer(input_size=input_size, method=active_list[i], n=layer_list[i])
            self.layers.append(temp_layer)
        # 添加输出层
        output_size = len(self.labels)
        output_layer = Layer(input_size=layer_list[-1], method='sigmoid', n=output_size)
        self.layers.append(output_layer)
        # 设置默认学习率
        self.eta = 0.01
        # 训练模型
        self.trainModel()
        # 评估模型
        self.judgeModel()

    def loadData(self):
        """
        数据载入
        :return:
        """
        dr = DataReader()
        dr.load_wine()
        self.labels = list(set(dr.rawy))
        self.trainx, self.trainy = dr.getTrainData()
        self.testx, self.testy = dr.getTestData()

    def showLayers(self):
        """
        打印神经网络
        :return:
        """
        for layer in self.layers:
            print(layer.w)
            print(layer.b)

    def forwardCalculateAll(self, input):
        """
        逐层前向计算最终得到神经网络输出矩阵
        :param input: 输入值X
        :return: 最终输出值Y
        """
        for layer in self.layers:
            layer.forwardCalculate(input)
            layer.activeFunction()
            input = layer.output
        return input

    def getMSE(self, pre_y, real_y):
        """
        均方误差计算
        :param pre_y: 预测值
        :param real_y: 实际值
        :return: 损失值
        """
        loss = float(sum((pre_y - real_y) ** 2) / 2)
        return loss

    def gradientDescent(self, pre_y, real_y):
        """
        计算梯度
        :param pre_y: 预测值,大小为(n,1)
        :param real_y: 实际值,大小为(n,1)
        :return:
        """
        dw = [0 for x in range(0, len(self.layers))]
        db = [0 for x in range(0, len(self.layers))]

        # 计算输出层梯度
        delta = pre_y * (1 - pre_y) * (real_y - pre_y)
        self.layers[-1].delta = delta
        temp_db = -delta
        output = np.zeros(np.shape(self.layers[-1].w))
        output = output + self.layers[-1].input.T
        temp_dw = output * delta
        dw[-1] = temp_dw
        db[-1] = temp_db
        # 计算隐含层梯度
        for i in range(len(self.layers) - 2, -1, -1):
            temp_db = np.zeros(self.layers[i].b.shape)
            temp_dw = np.zeros(self.layers[i].w.shape)
            # 计算该层δ
            delta = []
            for h in range(self.layers[i].w.shape[0]):
                temp_delta = np.sum(self.layers[i + 1].delta.flatten() * self.layers[i + 1].w[:, h].flatten())
                delta.append(temp_delta)
            delta = np.array(delta)
            delta = delta.reshape((self.layers[i].w.shape[0], 1))
            delta = delta * self.layers[i].getDerivative()
            output = np.zeros((self.layers[i].w.shape[0], self.layers[i].input_size))
            output = output + self.layers[i].input.T
            temp_dw = output * delta
            temp_db = -delta
            self.layers[i].delta = delta
            dw[i] = temp_dw
            db[i] = temp_db

        # 更新参数
        for i in range(len(self.layers)):
            self.layers[i].updateParameters(self.eta * dw[i], self.eta * db[i])

    def trainModel(self, eta=0.01, epoch=10000, batch_size=10, eps=0.00001):
        """
        训练模型,并记录loss
        :param eta: 学习率
        :param epoch: 最大迭代次数
        :param batch_size: mini-batch的每组大小,为1时表示随机梯度下降
        :param eps: 阈值
        :return:
        """
        a = MinMaxScaler()
        self.trainx = a.fit_transform(self.trainx)
        self.eta = eta
        total = 0
        correct = 0
        losses = []
        cnt = 0
        for e in range(epoch):
            trainx, trainy = self.fetchTrainData(batch_size)
            for b in range(batch_size):
                input = trainx[b].reshape(len(trainx[0]), 1)
                pre_y = self.forwardCalculateAll(input)
                real_y = trainy[b]
                self.gradientDescent(pre_y, real_y)
                loss = self.getMSE(pre_y, real_y)
                if e % 1000 == 0:
                    print('epoch =', e, ' b =', b, ' loss =', loss)
                if loss < eps:
                    break
            losses.append(loss)
            if loss < eps:
                break
        axis_x = np.arange(epoch)
        axis_y = losses
        plt.plot(axis_x, axis_y, '-')
        plt.show()

    def judgeModel(self):
        """
        使用测试数据对模型评估
        :return:
        """
        a = MinMaxScaler()
        self.testx = a.fit_transform(self.testx)
        total = len(self.testy)
        correct = 0
        newy = []
        for y in self.testy:
            index = self.labels.index(y)
            temp_y = np.zeros((len(self.labels), 1))
            temp_y[index] = 1
            newy.append(temp_y)
        for i in range(len(self.testx)):
            input = self.testx[i].reshape(len(self.testx[0]), 1)
            pre = self.forwardCalculateAll(input)
            real = newy[i]
            mse = self.getMSE(pre, real)
            if (np.argmax(pre) == np.argmax(real)):
                correct += 1
        print('Test Accuracy:', correct / total)

    def fetchTrainData(self, batch_size):
        """
        从测试数据中无放回地随机选取batch_size个数据用于训练
        :param batch_size: 批次大小
        :return: 该批次的训练数据
        """
        permutation = np.random.permutation(self.trainx.shape[0])
        shuffled_dataset = self.trainx[permutation, :]
        shuffled_labels = self.trainy[permutation]
        new_train_y = []
        for y in shuffled_labels:
            index = self.labels.index(y)
            temp_y = np.zeros((len(self.labels), 1))
            temp_y[index] = 1
            new_train_y.append(temp_y)
        return shuffled_dataset[:batch_size, :], new_train_y[:batch_size]


if __name__ == '__main__':
    llist = [10]
    alist = ['sigmoid']
    net = BPNet(layer_list=llist, active_list=alist)
