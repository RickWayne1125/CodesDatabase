import DataReader as DR

class HMM:
    def __init__(self):
        dr = DR.DataReader()
        self.data = dr.getData()
        self.pinyin = dr.getPinyin()
        # print(data)
        # for key in pinyin:
        #     print(key,pinyin[key])

    def getPi(self):
        pi = {}
        data_size = len(self.data)
        for line in self.data:
            temp_word = line[0]
            if(pi.__contains__(temp_word)):
                pi[temp_word]+=1
            else:
                pi.setdefault(temp_word,1)
        for word in pi:
            pi[word] = pi[word]/data_size
        return pi

    # def getA(self):
    #
    # def getB(self):

if __name__ == '__main__':
    model = HMM()