import random

import pandas as pd
import numpy as np
from libsvm.commonutil import svm_read_problem
from libsvm.svmutil import *
from libsvm.svm import *


def initData():
    with open('data.txt', 'r', encoding='utf-8') as f:
        lines = f.readlines()
    lines1 = lines[:8]
    lines2 = lines[8:]
    random.shuffle(lines1)
    random.shuffle(lines2)
    mid1 = int(len(lines1) / 2)
    mid2 = int(len(lines2) / 2)
    with open('train.txt', 'w') as f:
        f.writelines(lines1[:mid1])
        f.writelines(lines2[:mid2])
    with open('test.txt', 'w') as f:
        f.writelines(lines1[mid1:])
        f.writelines(lines2[mid2:])


if __name__ == '__main__':
    initData()
    yt, xt = svm_read_problem('test.txt')
    y, x = svm_read_problem('train.txt')
    linear = svm_train(y, x, '-t 0')
    rbf = svm_train(y, x, '-t 2')
    svm_save_model('linear_model', linear)
    svm_save_model('rbf_model',rbf)
    p1_label, p1_acc, p1_val = svm_predict(yt, xt, linear)
    p1_label, p1_acc, p1_val = svm_predict(yt, xt, rbf)
