import re


class DataReader:
    def __init__(self, data_path='../data/toutiao_cat_data.txt', pinyin_path='../data/lexicon.txt'):
        self.raw_data = []
        self.data = []
        self.pinyin = {}
        with open(data_path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
            for line in lines:
                line = re.sub(r'\n', '', line)
                self.raw_data.append(line)
                text = line[28:]
                # text = re.sub(r'[\w]*_!_', '', text)
                # text = re.sub(r'_!_', '', text)
                # text = re.sub(r'\s', '', text)
                # 通过正则表达式保留中文内容
                text = re.findall('.*?([\u4E00-\u9FA5]+).*?', text)
                self.data.extend(text)
        with open(pinyin_path, 'r', encoding='GBK') as f:
            lines = f.readlines()
            for line in lines:
                tmp = line.split()
                length = len(tmp[0])
                for i in range(length):
                    tempword = tmp[i + 1][0:len(tmp[i + 1]) - 1]
                    if (self.pinyin.__contains__(tmp[0][i])):
                        if (self.pinyin[tmp[0][i]].__contains__(tempword)):
                            self.pinyin[tmp[0][i]][tempword] += 1
                        else:
                            self.pinyin[tmp[0][i]].setdefault(tempword, 1)
                    else:
                        tempdict = {}
                        tempdict.setdefault(tempword, 1)
                        self.pinyin.setdefault(tmp[0][i], tempdict)

    def getData(self):
        return self.data

    def getRawData(self):
        return self.raw_data

    def getPinyin(self):
        return self.pinyin

# if __name__ == '__main__':
#     dr = DataReader()
