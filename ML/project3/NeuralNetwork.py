import numpy as np


class Neuron:
    def __init__(self, w=None, b=0, active='Sigmoid', n=1):
        self.weight = w
        self.bias = b
        self.act_method = active
        self.input_size = n

    def activeFunction(self):
        if self.act_method == 'Sigmoid':
            
    def forwardCal(self, input):
