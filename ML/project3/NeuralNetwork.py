import numpy as np
import pandas as pd
import sklearn.datasets
import math


class Neuron:
    def __init__(self, w=None, b=0, active='Sigmoid', n=1):
        self.weight = w
        self.bias = b
        self.act_method = active
        self.input_size = n
        self.result = None  # 未激活前的输出值
        self.output = None  # 激活后实际输出值
        self.initParameters()

    def initParameters(self):
        self.weight = np.random.randn(self.input_size, 1)
        self.b = np.zeros((1, 1))
        print(self.weight)
        print(self.b)

    def activeFunction(self):
        if self.act_method == 'Sigmoid':
            self.output = 1 / (1 + np.exp(-self.result))
        elif self.act_method == 'ReLU':
            self.output = max(0, self.result)
        elif self.act_method == 'Tanh':
            tmp = pow(math.e, self.result)
            self.output = (tmp - 1 / tmp) / (tmp + 1 / tmp)
        else:
            print('Method Not Found!')

    def forwardCal(self, input):
        self.input_size = len(input)
        self.result = np.dot(input, self.weight) + self.bias

    # def getLoss(self):


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
        print(data)
        data = np.array(data)
        self.rawx = data[:, 1:]
        self.rawy = data[:, 0]
        print(self.rawx)
        print(self.rawy)
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
    def __init__(self, input_size=10, method='sigmoid', n=10, level=0):
        self.method = method  # 激活函数
        self.input_size = input_size  # 输入大小
        self.nerual_num = n  # 神经元个数
        self.level = level  # 层数索引
        self.w, self.b = self.initParameters()
        self.result = None  # 原输出
        self.output = None  # 激活后输出
        self.delta = None

    def initParameters(self):
        w = np.random.rand(self.nerual_num, self.input_size)
        b = np.zeros((self.nerual_num, 1))
        return w, b

    def forwardCalculate(self, input):
        """
        前向计算
        :param input: 输入值, shape为(n,1)
        :return: 初始输出值
        """
        print('input:', input)
        print('w:', self.w)
        result = np.dot(self.w, input) - self.b
        self.result = result
        return result

    def activeFunction(self):
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
        self.w += dw
        self.b += db

    def getDerivative(self):
        """
        对激活函数求导
        :return:
        """
        if self.method == 'sigmoid':
            return (self.output * (1 - self.output))


class BPNet:
    def __init__(self, layer_list, active_list):
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
        output_size = len(set(self.trainy))
        output_layer = Layer(input_size=layer_list[-1], method='sigmoid', n=output_size)
        self.layers.append(output_layer)

        # test part
        # # self.showLayers()
        # self.getMSE()
        self.eta = 100000000
        print(self.trainx[0].reshape(input_size, 1))
        result = self.forwardCalculateAll(self.trainx[0].reshape(input_size, 1))
        print(result)
        print('w before:', self.layers[-1].w)
        self.outputLayerGradientDescent(result, np.array([[1], [0], [0]]))
        print('w after', self.layers[-1].w)

    def loadData(self):
        dr = DataReader()
        dr.load_iris()
        self.trainx, self.trainy = dr.getTrainData()
        self.testx, self.testy = dr.getTestData()

    def showLayers(self):
        for layer in self.layers:
            print(layer.w)
            print(layer.b)

    def forwardCalculateAll(self, input):
        for layer in self.layers:
            layer.forwardCalculate(input)
            input = layer.activeFunction()
        return input

    def getMSE(self, pre_y, real_y):
        loss = float(sum((pre_y - real_y) ** 2) / 2)
        return loss

    def outputLayerGradientDescent(self, pre_y, real_y):
        # 计算输出层梯度
        delta = self.layers[-1].getDerivative() * (pre_y - real_y)
        db = self.eta * delta
        delta2 = np.zeros((len(delta), len(self.layers[-2].output)))
        delta2 = delta2 + delta
        ouput = np.zeros((len(delta), len(self.layers[-2].output)))
        output = ouput + self.layers[-2].output.T
        dw = output * delta2
        self.layers[-1].updateParameters(dw, db)

    # def hiddenLayerGradientDescent(self,):


if __name__ == '__main__':
    # n = Neuron(n=10)
    # L = Layer()
    # L.initParameters()
    # x = np.random.rand(10, 1)
    # print(x)
    # print(L.forwardCalculate(x))
    # print(L.activeFunction())
    llist = [20, 10]
    alist = ['sigmoid', 'sigmoid']
    net = BPNet(layer_list=llist, active_list=alist)
