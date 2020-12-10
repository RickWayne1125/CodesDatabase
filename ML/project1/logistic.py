import numpy as np
import math
import pandas as pd
import matplotlib.pyplot as plt


class Logistic:
    def __init__(self):
        self.xr, self.yr = self.readData()
        self.xp, self.yp = self.xr, self.yr
        self.num = len(self.yr)  # 数据条数
        self.col = len(self.xr[0])  # 属性数量
        self.w = np.zeros((self.col, 1))
        self.b = np.zeros((1, 1))
        self.beta = np.row_stack((self.w, self.b))
        self.xt = np.column_stack((self.xr, np.ones((self.num, 1))))
        self.eta = 0.001

    def readData(self):
        data = pd.read_csv('../data/watermelon_3a.csv')
        raw_data = np.array(data)
        rawx = raw_data[:, :len(raw_data[0]) - 1]
        rawy = raw_data[:, len(raw_data[0]) - 1]
        return rawx, rawy

    def Shuffle(self):
        seed = np.random.randint(0, 100)
        np.random.seed(seed)
        x = np.random.permutation(self.xt)
        np.random.seed(seed)
        y = np.random.permutation(self.yt)
        self.xt = x
        self.yt = y

    def getLoss(self):
        loss = 0
        for i in range(self.num):
            temp = np.dot(self.beta.T, self.xt[i])
            loss += -self.yr[i] * temp + np.log(1 + pow(np.e, temp))
        return loss

    def gradDescent(self):
        dbeta = 0
        for i in range(self.num):
            temp = 1 + pow(np.e, np.dot(self.beta.T, self.xt[i]))
            dbeta -= self.xt[i] * (self.yr[i] - 1 + 1 / temp)
        dbeta = np.array(dbeta).reshape((self.col + 1, 1))
        self.beta = self.beta - self.eta * dbeta

    def trainModel(self, epoch=50000, eta=0.001, eps=0.1):
        loss = []
        x = []
        self.eta = eta
        for i in range(epoch):
            l = self.getLoss()
            loss.append(l)
            x.append(i)
            print("epoch = ", i, ", loss = ", l)
            if (l <= eps):
                break;
            self.gradDescent()
        plt.plot(x, loss)
        plt.show()

    def preData(self):
        for i in range(self.num):
            z = pow(np.e, np.dot(self.beta.T, self.xt[i]))
            p1 = z / (1 + z)
            if (p1 >= 0.5):
                pre = 1
            else:
                pre = 0
            print('pre = ', pre, ', real = ', self.yr[i],", posilibity of 1 = ",p1)


if __name__ == '__main__':
    model = Logistic()
    model.__init__()
    model.trainModel()
    model.preData()
