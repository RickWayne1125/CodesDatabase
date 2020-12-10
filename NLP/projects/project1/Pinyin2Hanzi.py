from HMM import HMM
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
        possible_hanzi = []
        for i in self.b:
            for j in self.b[i]:
                if (j == head_pinyin):
                    possible_hanzi.append(i)
                    break
        for i in possible_hanzi:
            if self.pi.__contains__(i):
                p = self.pi[i] * self.b[i][head_pinyin]
            else:
                p = self.pi['*'] * self.b[i][head_pinyin]
            self.delta.append(p)
            self.psi.append([i])
        print(self.delta)
        print(self.psi)

    # def getNext(self):


if __name__ == '__main__':
    model = Viterbi()
    test_input = ['ni', 'hao', 'ma']
    model.getInput(test_input)
    model.getHead()
