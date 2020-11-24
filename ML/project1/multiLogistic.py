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
        self.col = 4
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
        self.X, self.yt = self.readData('Iris-setosa')
        self.num = len(self.yt)  # 数据条数
        self.xt = np.column_stack((self.X, np.ones((self.num, 1))))
        print('\nTraining Iris-setosa OvR Learner: ')
        self.trainModel(0,8000)

        # Second learner
        self.X, self.yt = self.readData('Iris-versicolor')
        self.num = len(self.yt)  # 数据条数
        self.xt = np.column_stack((self.X, np.ones((self.num, 1))))
        print('\nTraining Iris-versicolor OvR Learner: ')
        self.trainModel(1,20000)

        # Third learner
        self.X, self.yt = self.readData('Iris-virginica')
        self.num = len(self.yt)  # 数据条数
        self.xt = np.column_stack((self.X, np.ones((self.num, 1))))
        print('\nTraining Iris-virginica OvR Learner: ')
        self.trainModel(2,20000)

        # Show Beta
        print(self.beta)

        # Test Data
        self.preData()

    def cutData(self):
        data = pd.read_csv('../data/Iris.csv')
        raw_data = np.array(data)
        flag = 0
        raw_data = raw_data[:, 1:]
        self.raw_data1 = []
        self.raw_data2 = []
        self.raw_data3 = []
        # Cut data by label
        for i in raw_data:
            if i[4] == 'Iris-setosa':
                self.raw_data1.append(i)
            elif i[4] == 'Iris-versicolor':
                self.raw_data2.append(i)
            elif i[4] == 'Iris-virginica':
                self.raw_data3.append(i)
        self.raw_data1 = np.array(self.raw_data1)
        self.raw_data2 = np.array(self.raw_data2)
        self.raw_data3 = np.array(self.raw_data3)
        n=int(2*self.raw_data1.shape[0]/3)
        self.train_data1=self.raw_data1[:n,:]
        self.test_data1=self.raw_data1[n:,:]
        n = int(2*self.raw_data2.shape[0]/3)
        self.train_data2 = self.raw_data2[:n, :]
        self.test_data2 = self.raw_data2[n:, :]
        n = int(2*self.raw_data3.shape[0]/3)
        self.train_data3 = self.raw_data3[:n, :]
        self.test_data3 = self.raw_data3[n:, :]

    def readData(self, name):
        if name == 'Iris-setosa':
            raw1 = self.train_data1
            raw2 = np.row_stack((self.train_data2, self.train_data3))
        elif name == 'Iris-versicolor':
            raw1 = self.train_data2
            raw2 = np.row_stack((self.train_data1, self.train_data3))
        elif name == 'Iris-virginica':
            raw1 = self.train_data3
            raw2 = np.row_stack((self.train_data1, self.train_data2))
        print(raw1)
        print(raw2)
        raw1[:, self.col] = 1
        raw2[:, self.col] = 0
        print(raw1)
        print(raw2)
        raw_data = np.row_stack((raw1, raw2))
        X = raw_data[:, :len(raw_data[0]) - 1]
        rawy = raw_data[:, len(raw_data[0]) - 1]
        return X, rawy

    def getLoss(self, no):
        loss = 0
        for i in range(self.num):
            temp = np.dot(self.beta[no].T, self.xt[i])
            loss += -self.yt[i] * temp + np.log(np.asarray(1 + pow(np.e, temp), dtype=float))
        return loss

    def gradDescent(self, no):
        dbeta = 0
        for i in range(self.num):
            temp = 1 + pow(np.e, np.dot(self.beta[no].T, self.xt[i]))
            dbeta -= self.xt[i] * (self.yt[i] - 1 + 1 / temp)
        dbeta = np.array(dbeta).reshape((self.col + 1, 1))
        self.beta[no] = self.beta[no] - self.eta * dbeta

    def trainModel(self, no, epoch=10000, eta=0.001, eps=0.1):
        loss = []
        x = []
        self.eta = eta
        for i in range(epoch):
            l = self.getLoss(no)
            loss.append(l)
            x.append(i)
            if(epoch%100==0):
                print("epoch = ", i, ", loss = ", l)
            if (l <= eps):
                break;
            self.gradDescent(no)
        plt.plot(x, loss)
        plt.show()

    def preData(self):
        self.cnt=0
        self.total=0
        print('\nPredicting Test Data:')
        print('Predicting 1st Dataset:')
        for i in range(self.test_data1.shape[0]):
            testdata=self.test_data1[i]
            self.testData(i,testdata)
        print('Predicting 2nd Dataset:')
        for i in range(self.test_data2.shape[0]):
            testdata=self.test_data2[i]
            self.testData(i,testdata)
        print('Predicting 3rd Dataset:')
        for i in range(self.test_data3.shape[0]):
            testdata=self.test_data3[i]
            self.testData(i,testdata)
        print('Total Accuracy: ',self.cnt/self.total)

    def testData(self,i,testdata):
        p = [0, 0, 0]
        for no in range(3):
            z = pow(np.e, np.dot(self.beta[no].T, np.append(testdata[:4],1)))
            p[no] = z / (1 + z)
        if (p[0] >= p[1] and p[0] >= p[2]):
            pre = 'Iris-setosa'
            n = 0
        elif (p[1] >= p[0] and p[1] >= p[2]):
            pre = 'Iris-versicolor'
            n = 1
        elif (p[2] >= p[0] and p[2] >= p[1]):
            pre = 'Iris-virginica'
            n = 2
        print('pre = ', pre, ', real = ', testdata[4], ", posilibity = ", p)
        self.total += 1
        if pre==testdata[4]:
            self.cnt+=1

if __name__ == '__main__':
    model = MultiLogistic()
    # model.trainModel()
    # model.preData()
