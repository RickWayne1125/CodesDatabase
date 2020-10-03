# -*- coding: UTF-8 -*-
dict = {}
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
        print(list)
        if (len(list) > 1):
            s = list[0] + ' ' + str(dict[word]) + ' ' + list[1] + '\n'
            f.write(s)
