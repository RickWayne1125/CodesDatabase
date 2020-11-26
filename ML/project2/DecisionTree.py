import numpy as np
import pandas as pd


class node:
    def __init__(self):
        self.value  # 分类参考值
        self.left  # 左子节点
        self.right  # 右子节点
        self.dimension


class Model:
    def __init__(self):
        self.xr = []
        self.yr = []
        self.xtrain = []
        self.ytrain = []
        self.xtest = []
        self.ytest = []

    def getEntropy(self, y):
        ent = 0
        if y.size <= 1:
            cate = [y.item()]
            y = [y.item()]
        else:
            cate = list(set(y))
        for i in cate:
            temp = len([j for j in y if j == i]) / len(y)
            ent -= temp * np.log(temp, 2)
        return ent

    def getGainEnt(self, x, y, d):
        gain = 0
        value = 0
        ent = self.getEntropy(y)
        attr = sorted(list(set(x[:, d])))
        anum = len(attr)
        dnum = len(x[:, d])
        for i in range(anum - 1):
            tmpv = (attr[i] + attr[i + 1]) / 2
            l = [j for j in range(dnum) if x[j, d] <= value]
            r = [j for j in range(dnum) if x[j, d] > value]
            yl = y[l]
            yr = y[r]
            tmpg = ent - (len(yl) / len(y)) * self.getEntropy(yl) - (len(yr) / len(y)) * self.getEntropy(yr)
            if tmpg > gain:
                value = tmpv
                gain = tmpg
        return gain, value
