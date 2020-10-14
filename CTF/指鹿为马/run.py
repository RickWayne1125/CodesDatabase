import numpy as np
from PIL import Image
import math
import operator
import os
import time
import base64
import random

def load_horse():
    data = []
    p = Image.open('./horse.jpg').convert('L')
    p = np.array(p).reshape(-1)
    p = np.append(p,0)
    data.append(p)
    return np.array(data)

def load_deer():
    data = []
    p = Image.open('./deer.jpg').convert('L')
    p = np.array(p).reshape(-1)
    p = np.append(p,1)
    data.append(p)
    return np.array(data)

def load_test(pic):
    data = []
    p = Image.open(pic).convert('L')
    p = np.array(p).reshape(-1)
    p = np.append(p,1)
    data.append(p)
    return np.array(data)


def euclideanDistance(instance1, instance2, length):
    distance = 0
    for x in range(length):
        distance += pow((instance1[x] - instance2[x]), 2)
    return math.sqrt(distance)


def getNeighbors(trainingSet, testInstance, k):
    distances = []
    length = len(testInstance) - 1
    for x in range(len(trainingSet)):
        dist = euclideanDistance(testInstance, trainingSet[x], length)
        distances.append((trainingSet[x], dist))
    distances.sort(key=operator.itemgetter(1))
    neighbors = []
    for x in range(k):
        neighbors.append(distances[x][0])
        return neighbors


def getResponse(neighbors):
    classVotes = {}
    for x in range(len(neighbors)):
        response = neighbors[x][-1]
        if response in classVotes:
            classVotes[response] += 1
        else:
            classVotes[response] = 1
    sortedVotes = sorted(classVotes.items(), key=operator.itemgetter(1), reverse=True)
    return sortedVotes[0][0]


def getAccuracy(testSet, predictions):
    correct = 0
    for x in range(len(testSet)):
        if testSet[x][-1] == predictions[x]:
            correct += 1
    return (correct / float(len(testSet))) * 100.0

def check(pic):
    source_p = Image.open('deer.jpg')
    try:
        c_p = Image.open(pic)
    except:
        print("Please upload right picture.")
        exit()
    diff_pixel = 0
    a, b = source_p.size
    if c_p.size[0] != a and c_p.size[1] != b:
    	print("Please upload right picture size("+str(a)+','+str(b)+')')
    	exit()
    for y in range(b):
        for x in range(a):
            print(source_p.getpixel((x, y)))
            print(c_p.getpixel((x,y)))
            diff_pixel += abs(source_p.getpixel((x, y)) - c_p.getpixel((x, y)))
    return diff_pixel

def main():
    while 1:
    #     print('-' * 134)
    #     print('''      ____       __            _          _   _                _                              _   _            _
    #  |  __ \     / _|          | |        | | | |              | |                            | | | |          | |
    #  | |__) |___| |_ ___ _ __  | |_ ___   | |_| |__   ___    __| | ___  ___ _ __    __ _ ___  | |_| |__   ___  | |__   ___  _ __ ___  ___
    #  |  _  // _ \  _/ _ \ '__| | __/ _ \  | __| '_ \ / _ \  / _` |/ _ \/ _ \ '__|  / _` / __| | __| '_ \ / _ \ | '_ \ / _ \| '__/ __|/ _ \\
    #  | | \ \  __/ ||  __/ |    | || (_) | | |_| | | |  __/ | (_| |  __/  __/ |    | (_| \__ \ | |_| | | |  __/ | | | | (_) | |  \__ \  __/
    #  |_|  \_\___|_| \___|_|     \__\___/   \__|_| |_|\___|  \__,_|\___|\___|_|     \__,_|___/  \__|_| |_|\___| |_| |_|\___/|_|  |___/\___|
    # ''')
    #     print('-'*134)
    #     print('\t1.show source code')
    #     print('\t2.give me the source pictures')
    #     print('\t3.upload picture')
    #     print('\t4.exit')
    #     choose = input('>')
    #     if choose == '1':
    #         w = open('run.py','r')
    #         print(w.read())
    #         continue
    #     elif choose == '2':
    #         print('this is horse`s picture:')
    #         h = base64.b64encode(open('horse.jpg','rb').read())
    #         print(h.decode())
    #         print('-'*134)
    #         print('this is deer`s picture:')
    #         d = base64.b64encode(open('deer.jpg', 'rb').read())
    #         print(d.decode())
    #         continue
    #     elif choose == '4':
    #         break
    #     elif choose == '3':
    #         print('Please input your deer picture`s base64(Preferably in png format)')
    #         pic = input('>')
    #         try:
    #             pic = base64.b64decode(pic)
    #         except:
    #         	exit()
    #         if b"<?php" in pic or b'eval' in pic:
    #             print("Hacker!!This is not WEB,It`s Just a misc!!!")
    #             exit()
            pic = input('>')
            pic = base64.b64decode(pic)
            salt = str(random.getrandbits(15))
            pic_name = 'tmp_'+salt+'.png'
            tmp_pic = open(pic_name,'wb')
            tmp_pic.write(pic)
            tmp_pic.close()
            if check(pic_name)>=100000:
                print('Don`t give me the horse source picture!!!')
                os.remove(pic_name)
                break
            ma = load_horse()
            lu = load_deer()
            k = 1
            trainingSet = np.append(ma, lu).reshape(2, 5185)
            testSet = load_test(pic_name)
            neighbors = getNeighbors(trainingSet, testSet[0], k)
            print(neighbors)
            result = getResponse(neighbors)
    #         if repr(result) == '0':
    #             os.system('clear')
    #             print('Yes,I want this horse like deer,here is your flag encoded by base64')
    #             flag = base64.b64encode(open('flag','rb').read())
    #             print(flag.decode())
    #             os.remove(pic_name)
    #             break
    #         else:
    #             print('I want horse but not deer!!!')
    #             os.remove(pic_name)
    #             break
    #     else:
    #         print('wrong choose!!!')
    #         break
    # exit()

if __name__=='__main__':
    main()
