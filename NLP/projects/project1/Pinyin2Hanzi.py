import json


class Viterbi:
    def __init__(self):
        self.readJSON()
        self.path = []
        self.result = ''
        self.delta = []  # 最大概率
        self.psi = []  # 对应路径

    def readJSON(self):
        with open('Pi.json', 'r', encoding='utf-8') as f:
            self.pi = json.loads(f.read())
        with open('A.json', 'r', encoding='utf-8') as f:
            self.a = json.loads(f.read())
        with open('B.json', 'r', encoding='utf-8') as f:
            self.b = json.loads(f.read())

    def getInput(self, text_in):
        """
        Input Type: ['pinyin1','pinyin2','pinyin3']
        :param text_in:
        :return:
        """
        self.input = text_in
        return self.input

    def getHead(self):
        """
        计算句首汉字概率并保留路径
        :return:
        """
        head_pinyin = self.input[0]
        possible_hanzi = self.findHanziByPinyin(head_pinyin)
        for i in possible_hanzi:
            if self.pi.__contains__(i):
                p = self.pi[i] * self.b[i][head_pinyin]
            else:
                p = self.pi['*'] * self.b[i][head_pinyin]
            self.delta.append(p)
            self.psi.append([i])

    def getNext(self, i):
        pinyin = self.input[i]
        possible_hanzi = self.findHanziByPinyin(pinyin)
        path = []
        result = []
        for i in possible_hanzi:
            flag = -1
            pmax = 0
            for j in range(len(self.psi)):
                last_hanzi = self.psi[j][len(self.psi[j]) - 1]
                p = self.getA(last_hanzi, i) * self.delta[j] * self.b[i][pinyin]
                # print('now path',self.psi[j],i,p)
                if p > pmax:
                    pmax = p
                    flag = j
            if (flag == -1 and pmax == 0):
                flag = self.delta.index(max(self.delta))
                pmax = self.delta[flag] * self.b[i][pinyin] * self.getA(self.psi[flag][len(self.psi[flag]) - 1], '*')
            temp = list(self.psi[flag])
            temp.append(i)
            path.append(temp)
            result.append(pmax)
        self.delta = result
        self.psi = path

    def flush(self):
        self.psi = []
        self.delta = []

    def findHanziByPinyin(self, pinyin):
        possible_hanzi = []
        for i in self.b:
            for j in self.b[i]:
                if (j == pinyin):
                    possible_hanzi.append(i)
                    break
        return possible_hanzi

    def getA(self, hanzi1, hanzi2):
        if (self.a.__contains__(hanzi1)):
            if (self.a[hanzi1].__contains__(hanzi2)):
                return self.a[hanzi1][hanzi2]
            else:
                return 0
                # return self.a[hanzi1]['*']
        else:
            return 0

    def getHanzi(self):
        index = self.delta.index(max(self.delta))
        return self.psi[index]

    def pinyin2Hanzi(self, pinyin):
        self.getInput(pinyin)
        self.flush()
        self.getHead()
        length = len(pinyin)
        for i in range(1, length):
            self.getNext(i)
        return self.getHanzi()


def loadTestData(data_path):
    with open(data_path, 'r', encoding='GBK') as f:
        lines = f.readlines()
    i = 0
    pinyin = []
    hanzi = []
    for line in lines:
        if i % 2 == 0:
            pinyin.append(line.split())
        else:
            hanzi.append(line)
        i += 1
    return pinyin, hanzi


def getAccuracy(str1, str2):
    if (len(str1) != len(str2)):
        print('Something Wrong')
        return 0
    cnt = 0
    for i in range(len(str1)):
        if (str1[i] == str2[i]):
            cnt += 1
    return cnt / len(str1)


if __name__ == '__main__':
    model = Viterbi()
    pinyin, hanzi = loadTestData('../data/测试集.txt')
    for i in range(len(pinyin)):
        test_sentence = hanzi[i].strip()
        print('测试句:', test_sentence)
        pre = ''.join(model.pinyin2Hanzi(pinyin[i]))
        print('预测值:', pre)
        print('准确率:', getAccuracy(test_sentence, pre))
        print('====================')
