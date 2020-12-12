import numpy as np
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


class BPNet:
    def __init__(self, layer_list, active_list):
        self.layer_num = len(layer_list)
        self.layer_size = layer_list


if __name__ == '__main__':
    n = Neuron(n=10)
