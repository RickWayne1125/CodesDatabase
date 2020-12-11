import DataReader as DR
import json


class HMM:
    def __init__(self):
        dr = DR.DataReader()
        self.data = dr.getData()
        self.pinyin = dr.getPinyin()
        self.pi = self.getPi()
        self.b = self.getB()
        self.a = self.getA()

        self.writeJSON()
        self.writeParameter()

    def getPi(self):
        """
        统计初始改率，即各汉字作为句首的概率
        :return: 初始概率矩阵
        """
        pi = {}
        data_size = len(self.data)
        V = 1
        for line in self.data:
            if len(line) > 0:
                temp_word = line[0]
                if (pi.__contains__(temp_word)):
                    pi[temp_word] += 1
                else:
                    pi.setdefault(temp_word, 1)
                    V += 1
        for word in pi:
            # 加1平滑
            res = (pi[word] + 1) / (data_size + V)
            pi[word] = res
        # 对于所有未在语料中作为句首出现的汉字，应用平滑后的默认概率
        pi.setdefault('*', 1 / (data_size + V))
        return pi

    def getA(self):
        """
        统计转换概率，即当前汉字到下一汉字的概率
        :return: 转换概率词典
        """
        a = {}
        for line in self.data:
            for i in range(len(line) - 1):
                if (a.__contains__(line[i])):
                    if a[line[i]].__contains__(line[i + 1]):
                        a[line[i]][line[i + 1]] += 1
                    else:
                        a[line[i]].setdefault(line[i + 1], 1)
                else:
                    temp_dict = {}
                    temp_dict.setdefault(line[i + 1], 1)
                    a.setdefault(line[i], temp_dict)
        for word in a:
            total = 0
            for next_word in a[word]:
                total += a[word][next_word]
            for next_word in a[word]:
                # 加1平滑
                a[word][next_word] = (a[word][next_word] + 1) / (total + len(a))
            # 对于所有未在语料中出现的位于二元组第二位的汉字，应用平滑所得默认概率
            a[word].setdefault('*', 1 / (total + len(a)))
            # a[word].setdefault('*', 0.00001)
        return a

    def getB(self):
        """
        统计各汉字对应各种拼音的概率
        :return: 汉字-拼音概率词典
        """
        b = {}
        for word in self.pinyin:
            dict = {}
            total = 0
            for p in self.pinyin[word]:
                total += self.pinyin[word][p]
            for p in self.pinyin[word]:
                dict.setdefault(p, self.pinyin[word][p] / total)
            b.setdefault(word, dict)
        return b

    def writeParameter(self):
        """
        将计算所得参数写入本地文件存储
        """
        # Write Pi in Pi.txt
        with open('Pi.txt', 'w', encoding='utf-8') as f:
            for i in self.pi:
                res = i + ' ' + str(self.pi[i]) + '\n'
                f.write(res)
        # Write A in A.txt
        with open('A.txt', 'w', encoding='utf-8') as f:
            for i in self.a:
                for j in self.a[i]:
                    res = i + ' ' + j + ' ' + str(self.a[i][j]) + '\n'
                    f.write(res)
        # Write B in B.txt
        with open('B.txt', 'w', encoding='utf-8') as f:
            for i in self.b:
                res = i
                for j in self.b[i]:
                    res += ' ' + j + ' ' + str(self.b[i][j])
                res += '\n'
                f.write(res)
        print('Write Parameter Done.')

    def writeJSON(self):
        json_pi = json.dumps(self.pi)
        json_a = json.dumps(self.a)
        json_b = json.dumps(self.b)
        with open('Pi.json', 'w', encoding='utf-8') as f:
            f.write(json_pi)
        with open('A.json', 'w', encoding='utf-8') as f:
            f.write(json_a)
        with open('B.json', 'w', encoding='utf-8') as f:
            f.write(json_b)


if __name__ == '__main__':
    model = HMM()
