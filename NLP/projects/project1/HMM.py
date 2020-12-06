import DataReader as DR


class HMM:
    def __init__(self):
        dr = DR.DataReader()
        self.data = dr.getData()
        self.pinyin = dr.getPinyin()
        self.pi = self.getPi()
        self.b = self.getB()
        self.a = self.getA()
        self.writeParameter()
        # print(self.a)
        # print(self.pi)
        # print(self.b['色'])
        # print(data)
        # for key in pinyin:
        #     print(key,pinyin[key])

    def getPi(self):
        pi = {}
        data_size = len(self.data)
        for line in self.data:
            if len(line) > 0:
                temp_word = line[0]
                if (pi.__contains__(temp_word)):
                    pi[temp_word] += 1
                else:
                    pi.setdefault(temp_word, 1)
        for word in pi:
            pi[word] = pi[word] / data_size
        return pi

    def getA(self):
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
                a[word][next_word] = a[word][next_word] / total
        return a

    def getB(self):
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


if __name__ == '__main__':
    model = HMM()
