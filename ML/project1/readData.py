import pandas as pd
import numpy as np


def readData():
    data = pd.read_csv('../data/watermelon_3a.csv')
    raw_data = np.array(data)
    rawx = raw_data[:, :len(raw_data[0]) - 1]
    rawy = raw_data[:, len(raw_data[0]) - 1]
    print(rawx)
    print(rawy)
    return rawx, rawy

# def normalizeData(rawx, rawy):
#


if __name__ == "__main__":
    readData()
