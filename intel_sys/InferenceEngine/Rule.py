# 定义推理机规则类
from Feature import *
from Fact import *


class Rule():
    def __init__(self, text):
        self.text = text
        # 从文本中提取产生式规则
        features = text.split(" -> ")[0]
        features = features.split(", ")  # 提取产生式左侧的每一条特征
        temp = []
        for f in features:
            temp.append(Feature(f))
        fact = text.split(" -> ")[1]
        # List<Feature> features
        self.features = temp
        # string fact
        self.fact = Fact(fact)

    def show(self):
        print('\nFEATURES:')
        for feature in self.features:
            feature.show()
        print('\nFACT:')
        self.fact.show()


# TEST PART
if __name__ == '__main__':
    r = Rule("Temp >= 14, Alarm = on -> FireAlarm = on")
    r.show()
