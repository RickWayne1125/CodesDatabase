import re


class DataReader:
    def __init__(self, path='../data/toutiao_cat_data.txt'):
        self.raw_data = []
        self.data = []
        with open(path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
            for line in lines:
                line = re.sub(r'\n', '', line)
                self.raw_data.append(line)
                text = line[28:]
                text = re.sub(r'[\w]*_!_', '', text)
                text = re.sub(r'_!_', '', text)
                text = re.sub(r'\s', '', text)
                self.data.append(text)

    def getData(self):
        return self.data

    def getRawData(self):
        return self.raw_data


if __name__ == '__main__':
    dr = DataReader()
