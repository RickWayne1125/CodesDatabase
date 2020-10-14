# -*- coding: UTF-8 -*-
import sys

sys.path.append("../")
import jieba

jieba.load_userdict("dict.txt")


def initTrain():
    dict = {}
    odict = {}
    olist = []
    with open("data.txt", "r", encoding="utf-8") as f:
        size = 0
        for line in f.readlines():
            line = line.strip('\n')
            size += 1
            # 每一行以双空格作为定界符进行拆分
            list = line.split(sep="  ")
            for item in list:
                tmp = item.split('/')
                olist.append(tmp[0])
                if (dict.__contains__(item)):
                    dict[item] += 1;
                else:
                    dict.setdefault(item, 1)

    # create user_dict for jieba 生成用户个性化词典供jieba分词使用
    with open("dict.txt", "w", encoding="utf-8") as f:
        for word in dict.keys():
            list = word.split(sep="/")
            odict.setdefault(list[0], dict[word])
            # if (len(list) > 1 and list[1]!='w' and list[1]!='t' and list[1]!='m'):
            if (len(list) > 1):
                s = list[0] + ' ' + str(dict[word]) + ' ' + list[1] + '\n'
                f.write(s)
    return olist, odict, size


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
def calculate(tlist, dict, cnt, V):
    pro = 1
    i = 0
    for word in tlist:
        # 拉普拉斯平滑
        if (dict.__contains__(word)):
            pro *= (float(cnt[i] + 1) / float(dict[word] + V))
            i += 1
        else:
            pro *= (float(cnt[i] + 1) / float(V))
            i += 1
    return pro


if __name__ == "__main__":
    # PS 之前使用原文第一句进行测试，结果发现因为jieba分词结果与语料不一致导致了误差，之后使用了用户个性化词典，但是jieba分词结果仍然没有影响。。
    # 在jieba的github的repo里面也有人提出过类似的issue，不过目前我还没有找到较好的解决方法。。

    # test add words
    jieba.add_word('充满', freq=99999, tag='v')
    jieba.add_word('希望')

    olist = []
    dict = {}
    olist, dict, V = initTrain()
    test = input("Plz input a test sentence: ")
    tlist = jieba.lcut(test)
    print(tlist)
    cnt = cmp(olist, tlist)
    p = calculate(tlist, dict, cnt, V)
    print(p)
