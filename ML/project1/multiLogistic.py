import numpy as np
import math
import pandas as pd
import matplotlib.pyplot as plt


class MultiLogistic:
    def __init__(self):
        # init parameter
        self.eta = 0.001
        self.raw_data1 = []
        self.raw_data2 = []
        self.raw_data3 = []
        self.cutData()
        self.col = 5
        self.w = []
        self.b = []
        self.beta = []
        w1 = np.zeros((self.col, 1))
        b1 = np.zeros((1, 1))
        beta1 = np.row_stack((w1, b1))
        for i in range(3):
            self.w.append(w1)
            self.b.append(b1)
            self.beta.append(beta1)

        # First learner
        self.xr, self.yr = self.readData('Iris-setosa')
        # self.xp, self.yp = self.xr, self.yr
        self.num = len(self.yr)  # 数据条数
        self.xt = np.column_stack((self.xr, np.ones((self.num, 1))))
        self.trainModel(1)

        # Second learner
        self.xr, self.yr = self.readData('Iris-versicolor')
        # self.xp, self.yp = self.xr, self.yr
        self.num = len(self.yr)  # 数据条数
        self.xt = np.column_stack((self.xr, np.ones((self.num, 1))))
        self.trainModel(2)

        # Third learner
        self.xr, self.yr = self.readData('Iris-virginica')
        # self.xp, self.yp = self.xr, self.yr
        self.num = len(self.yr)  # 数据条数
        self.xt = np.column_stack((self.xr, np.ones((self.num, 1))))
        self.trainModel(3)

    def cutData(self):
        data = pd.read_csv('../data/Iris.csv')
        raw_data = np.array(data)
        flag = 0
        self.raw_data1 = []
        self.raw_data2 = []
        self.raw_data3 = []
        # Cut data by label
        for i in raw_data:
            if i[5] == 'Iris-setosa':
                self.raw_data1.append(i)
            elif i[5] == 'Iris-versicolor':
                self.raw_data2.append(i)
            elif i[5] == 'Iris-virginica':
                self.raw_data3.append(i)
        self.raw_data1 = np.array(self.raw_data1)
        self.raw_data2 = np.array(self.raw_data2)
        self.raw_data3 = np.array(self.raw_data3)
        print(self.raw_data1)

    def readData(self, name):
        if name == 'Iris-setosa':
            raw1 = self.raw_data1
            # label = 1
            raw2 = np.row_stack((self.raw_data2, self.raw_data3))
            # label = 0
            raw1[:,self.col]=1
            raw2[:,self.col]=0
        elif name == 'Iris-versicolor':
            raw1 = self.raw_data2
            # label = 1
            raw2 = np.row_stack((self.raw_data1, self.raw_data3))
            # label = 0
            raw1[:,self.col]=1
            raw2[:,self.col]=0
        elif name == 'Iris-virginica':
            raw1 = self.raw_data3
            # label = 1
            raw2 = np.row_stack((self.raw_data1, self.raw_data2))
            # label = 0
            raw1[:,self.col]=1
            raw2[:,self.col]=0
        raw_data = np.row_stack((raw1, raw2))
        rawx = raw_data[:, 1:len(raw_data[0]) - 1]
        rawy = raw_data[:, len(raw_data[0]) - 1]
        return rawx, rawy

    def getLoss(self, no):
        loss = 0
        for i in range(self.num):
            temp = np.dot(self.beta[no].T, self.xt[i])
            loss += -self.yr[i] * temp + np.log(1 + pow(np.e, temp))
        return loss

    def gradDescent(self, no):
        dbeta = 0
        for i in range(self.num):
            temp = 1 + pow(np.e, np.dot(self.beta[no].T, self.xt[i]))
            dbeta -= self.xt[i] * (self.yr[i] - 1 + 1 / temp)
        dbeta = np.array(dbeta).reshape((self.col + 1, 1))
        self.beta[no] = self.beta - self.eta * dbeta

    def trainModel(self, no, epoch=60000, eta=0.001, eps=0.1):
        loss = []
        x = []
        self.eta = eta
        for i in range(epoch):
            l = self.getLoss(no)
            loss.append(l)
            x.append(i)
            print("epoch = ", i, ", loss = ", l)
            if (l <= eps):
                break;
            self.gradDescent(no)
        plt.plot(x, loss)
        plt.show()

    def preData(self, no):
        for i in range(self.num):
            z = pow(np.e, np.dot(self.beta[no].T, self.xt[i]))
            p1 = z / (1 + z)
            # if (p1 >= 0.5):
            #     pre = 1
            # else:
            #     pre = 0
            # print('pre = ', pre, ', real = ', self.yr[i], ", posilibity of 1 = ", p1)


if __name__ == '__main__':
    model = MultiLogistic()
    model.__init__()
    # model.trainModel()
    # model.preData()
