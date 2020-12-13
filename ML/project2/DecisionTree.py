import math

import numpy as np
import pandas as pd
import collections
import sklearn.datasets


class node:
    def __init__(self, v=None, l=None, r=None, d=0, label=None, max=None, leaf=0, nh=0):
        self.value = v  # 分类参考值
        self.left = l  # 左子节点
        self.right = r  # 右子节点
        self.dimension = d  # 节点代表属性值在数据集中下标
        self.leaf = leaf  # 是否为叶子节点
        self.label = label  # 节点标签值
        self.max = max  # 多数表决时使用的标签值
        self.nh = nh  # 经验熵，用于剪枝


class Model:
    def __init__(self, x, y):
        self.root = self.buildTree(x, y)

    def getMost(self, y):
        labels = collections.Counter(y).most_common(1)
        return labels[0][0]

    def getEntropy(self, y):
        ent = 0
        if y.size > 1:
            cate = list(set(y))
        else:
            cate = [y.item()]
            y = [y.item()]
        for i in cate:
            temp = len([j for j in y if j == i]) / len(y)
            ent -= temp * math.log(temp, 2)
        return ent

    def getGainEnt(self, x, y, d):
        gain = 0
        value = 0
        ent = self.getEntropy(y)
        attr = x[:, d]
        attr = list(set(attr))
        attr = sorted(attr)
        anum = len(attr)
        dnum = len(x[:, d])
        for i in range(anum - 1):
            tmpv = (attr[i] + attr[i + 1]) / 2
            l = [j for j in range(dnum) if x[j, d] <= tmpv]
            r = [j for j in range(dnum) if x[j, d] > tmpv]
            yl = y[l]
            yr = y[r]
            tmpg = ent - (len(yl) / len(y)) * self.getEntropy(yl) - (len(yr) / len(y)) * self.getEntropy(yr)
            if tmpg > gain:
                value = tmpv
                gain = tmpg
        return gain, value

    def getAttr(self, x, y):
        gain = 0
        value = 0
        d = 0
        for i in range(len(x[0])):
            tmpg, tmpv = self.getGainEnt(x, y, i)
            if tmpg > gain:
                gain = tmpg
                value = tmpv
                d = i
        return gain, value, d

    def divideTree(self, x, y, v, d):
        attr = x[:, d]
        num = len(x[:, d])
        l = [i for i in range(num) if x[i, d] <= v]
        r = [i for i in range(num) if x[i, d] > v]
        xl = x[l]
        xr = x[r]
        yl = y[l]
        yr = y[r]
        return xl, yl, xr, yr

    def buildTree(self, x, y):
        maxlabel = self.getMost(y)
        ent = self.getEntropy(y)
        nh = ent * len(y)
        if y.size > 1:
            gain, value, d = self.getAttr(x, y)
            if gain > 0:
                xl, yl, xr, yr = self.divideTree(x, y, value, d)
                ltree = self.buildTree(xl, yl)
                rtree = self.buildTree(xr, yr)
                return node(v=value, l=ltree, r=rtree, d=d, max=maxlabel, nh=nh)
            else:
                return node(label=y[0], max=maxlabel, leaf=1, nh=nh)
        else:
            return node(label=y.item(), max=maxlabel, leaf=1, nh=nh)

    def postPruning(self, root, alpha):
        if root.leaf == 0:
            if root.left.leaf == 0:
                self.postPruning(root.left, alpha)
            if root.right.leaf == 0:
                self.postPruning(root.right, alpha)
        if root.left.leaf == 1 and root.right.leaf == 1:
            bef = (root.left.nh + alpha) + (root.right.nh + alpha)
            aft = root.nh + alpha
            print('NH bef:', bef)
            print('NH aft:', aft)
            if bef >= aft:
                root.left = None
                root.right = None
                root.leaf = 1
                root.label = root.max

    def classify(self, input, root):
        if root.label != None:
            return root.label
        else:
            tmp = input[root.dimension]
            if tmp <= root.value:
                next = root.left
            else:
                next = root.right
            return self.classify(input, next)


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


if __name__ == '__main__':
    dr = DataReader()
    dr.load_wine()
    # dr.load_haberman()
    dr.load_iris()
    train_data, train_label = dr.getTrainData()
    test_data, test_label = dr.getTestData()
    model = Model(train_data, train_label)
    true_count = 0
    for i in range(len(test_label)):
        predict = model.classify(test_data[i], model.root)
        print('Prediction: ', predict, 'Real: ', test_label[i])
        if predict == test_label[i]:
            true_count += 1
    print("Before Pruning Accuracy: ", (true_count / len(test_data)))
    true_count = 0
    root = model.root
    model.postPruning(root, alpha=2)
    for i in range(len(test_label)):
        predict = model.classify(test_data[i], root)
        print('Prediction: ', predict, 'Real: ', test_label[i])
        if predict == test_label[i]:
            true_count += 1
    print("After Pruning Accuracy: ", (true_count / len(test_data)))
