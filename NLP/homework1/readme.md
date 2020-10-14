## 作业题目

基于人民日报标注语料（见附件），训练一个Bigram语言模型，并预测任意给定语句的语言概率。（中文分词可以采用Jieba, SnowNLP, PkuSeg, IK Analyzer, HanLP等）

要求：

（1）提交电子文档一份（word），内含两部分内容：程序源码文本，程序运行结果截图（至少包含三个测试语句运行结果）；

（2）同时提交源程序文件（可采用任意语言开发）。

## 文件说明

| 文件名称 | 功能说明                                              |
| -------- | ----------------------------------------------------- |
| run.py   | 源代码文件，直接运行输入测试语句获取结果              |
| data.txt | 原始语料数据                                          |
| dict.txt | 基于原始语料生成的jieba-user_dict格式的用户个性化词典 |

## 程序源代码

```python
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

    # 生成用户个性化词典供jieba分词使用
    with open("dict.txt", "w", encoding="utf-8") as f:
        for word in dict.keys():
            list = word.split(sep="/")
            odict.setdefault(list[0], dict[word])
            # if (len(list) > 1 and list[1]!='w' and list[1]!='t' and list[1]!='m'):
            if (len(list) > 1):
                s = list[0] + ' ' + str(dict[word]) + ' ' + list[1] + '\n'
                f.write(s)
    return olist, odict, size


# 对比原始语料列表与测试语句列表
def cmp(olist, tlist):
    cnt = [0] * (len(tlist))
    for i in range(0, len(tlist) - 1):
        for j in range(0, len(olist) - 2):
            if tlist[i] == olist[j]:
                if tlist[i + 1] == olist[j + 1]:
                    cnt[i] += 1
    return cnt


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
```

PS *之前使用原文第一句进行测试，结果发现因为 jieba 分词结果与语料不一致导致了误差，之后使用了addword和用户个性化词典，但是 jieba 分词结果仍然没有影响。。
在 jieba 的 github 的 repo 里面也有人提出过类似的 issue，不过目前我还没有找到较好的解决方法。。*

## 测试截图

![image-20201012210902829](C:\Users\Ricky\AppData\Roaming\Typora\typora-user-images\image-20201012210902829.png)

![image-20201012211659118](C:\Users\Ricky\AppData\Roaming\Typora\typora-user-images\image-20201012211659118.png)

![image-20201012211828055](C:\Users\Ricky\AppData\Roaming\Typora\typora-user-images\image-20201012211828055.png)

![image-20201012211959390](C:\Users\Ricky\AppData\Roaming\Typora\typora-user-images\image-20201012211959390.png)

