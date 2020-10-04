# -*- coding: UTF-8 -*-
import sys
sys.path.append("../")
import jieba
jieba.load_userdict("dict.txt")

def initTrain():
    dict = {}
    odict={}
    olist = []
    with open("data.txt", "r", encoding="utf-8") as f:
        for line in f.readlines():
            line = line.strip('\n')
            # 每一行以双空格作为定界符进行拆分
            list = line.split(sep="  ")
            for item in list:
                if (dict.__contains__(item)):
                    dict[item] += 1;
                else:
                    dict.setdefault(item, 1)
            # print(line)
    with open("dict.txt", "w", encoding="utf-8") as f:
        for word in dict.keys():
            list = word.split(sep="/")
            odict.setdefault(list[0],dict[word])
            # print(list)
            # if (len(list) > 1 and list[1]!='w' and list[1]!='t' and list[1]!='m'):
            if (len(list) > 1):
                olist.append(list[0])
                s = list[0] + ' ' + str(dict[word]) + ' ' + list[1] + '\n'
                f.write(s)
    return olist, odict


# compare origin list and test list
def cmp(olist, tlist):
    cnt = [0] * (len(tlist))
    for i in range(0, len(tlist) - 1):
        for j in range(0, len(olist) - 2):
            if tlist[i] == olist[j]:
                if tlist[i + 1] == olist[j + 1]:
                    cnt[i] += 1
    return cnt


# calculate
def calculate(tlist, dict, cnt):
    pro = 1
    i = 0
    for word in tlist:
        if(dict.__contains__(word)):
            pro *= (float(cnt[i] + 1) / float(dict[word] + 1))
            # print(i)
            i += 1
    return pro


if __name__ == "__main__":
    # test add words
    jieba.add_word('充满')
    jieba.add_word('希望')
    olist = []
    dict = {}
    olist, dict = initTrain()
    test = input("Plz input a test sentence: ")
    tlist = jieba.lcut(test)
    print(tlist)
    cnt = cmp(olist, tlist)
    p = calculate(tlist, dict, cnt)
    print(p)
