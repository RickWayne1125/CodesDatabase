import numpy as np
import math
from .readData import *


def initModel():
    xr, yr = readData()
    num = len(yr)  # 数据条数
    col = len(xr[0])  # 属性数量
    w = np.array()
    b = np.array()
    beta = np.vstack(w, b)


def cntLoss(xr, yr, num, beta):
    loss = 0
    for i in range(num):
        loss += -yr[i] * beta.T * xr[i] + pow(math.log(1 + math.e), beta.T * xr[i])
    return loss