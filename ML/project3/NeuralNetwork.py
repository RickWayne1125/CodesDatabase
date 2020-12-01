import numpy as np
import math


class Neuron:
    def __init__(self, w=None, b=0, active='Sigmoid', n=1):
        self.weight = w
        self.bias = b
        self.act_method = active
        self.input_size = n
        self.result = None
        self.output = None

    def activeFunction(self):
        if self.act_method == 'Sigmoid':
            self.output = 1 / (1 + pow(math.e, self.result))
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

    def getLoss(self):
