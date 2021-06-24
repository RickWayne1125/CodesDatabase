from Feature import *
from Rule import *


def compare(dict1, dict2):
    if(len(dict1) != len(dict2)):
        return False
    for a in dict1:
        if(dict2.__contains__(a)):
            if(dict1[a] != dict2[a]):
                return False
        else:
            return False
    return True


class Engine():
    def __init__(self, path) -> None:
        self.rules = []
        # 从本地文件读取产生式规则
        with open(path, 'r', encoding='utf-8')as f:
            for line in f.readlines():
                self.rules.append(Rule(line.split('\n')[0]))
        # 通过产生式规则集合生成属性字典
        self.attributes = {}    # 实体的属性集合
        for rule in self.rules:
            if(not self.attributes.__contains__(rule.fact.left)):
                self.attributes.setdefault(rule.fact.left, None)
            for feature in rule.features:
                if(not self.attributes.__contains__(feature.left)):
                    self.attributes.setdefault(feature.left, None)

    def initAttributes(self):
        for a in self.attributes:
            self.attributes[a] = None

    def run(self):
        old_attr = {}
        new_attr = self.attributes
        # 初始化可用的产生式集合
        self.available_rules = self.rules
        while(not compare(old_attr, new_attr)):
            old_attr.update(self.attributes)
            self.inferForward()
            new_attr = self.attributes
            print('old_attr: ', old_attr)
            print('new_attr: ', new_attr)

    def judge(self, feature):
        if(self.attributes.get(feature.left) == None):
            return False
        x = self.attributes.get(feature.left)
        y = feature.right
        op = feature.op
        if(op == '='):
            return x == y
        elif(op == '<'):
            return float(x) < float(y)
        elif(op == '>'):
            return float(x) > float(y)
        elif(op == '<='):
            return float(x) <= float(y)
        elif(op == '>='):
            return float(x) >= float(y)
        elif(op == '!='):
            return x != y

    def choose(self, match_rules, method='longest'):
        choice = None
        # 使用最长匹配
        if(method == 'longest'):
            num = 0
            for rule in match_rules:
                if(num < len(rule.features)):
                    num = len(rule.features)
                    choice = rule
        elif(method == 'first'):
            choice = match_rules[0]
        elif(method == 'last'):
            choice = match_rules[-1]
        return choice

    def inferForward(self):
        # 正向推理
        match_rules = []    # 已匹配的规则
        for rule in self.available_rules:
            # print('\nCURRENT RULE:')
            # rule.show()
            res = True
            for feature in rule.features:
                # 若有一条特征不符合则直接退出当前规则匹配
                if(not self.judge(feature)):
                    res = False
                    break
            if(res):
                match_rules.append(rule)
                # print('ADD: ', rule.text)
        if len(match_rules) > 0:
            # 消除当前所有可以匹配的规则之间的冲突，根据匹配规则选出合适的规则进行规约
            rule = self.choose(match_rules)
            # match_rules[0].show()
            print('\nEXECUTE: ', rule.text)
            # 执行规约结果
            self.execute(rule.fact)
            # 在可用产生式列表中移除使用的产生式
            self.available_rules.remove(rule)
        self.show()

    def execute(self, fact):
        self.attributes[fact.left] = fact.right

    def show(self):
        # 输出属性字典值
        print("\nATTRIBUTES:")
        # for a in self.attributes:
        #     print(a)
        print(self.attributes)

    def set(self, attr, value):
        self.attributes[attr] = value


# TEST PART
if __name__ == '__main__':
    e = Engine("intel_sys/InferenceEngine/rules.txt")
    e.set('Alarm', 'on')
    e.set('Temp', '60')
    e.set('Dust', '100')
    e.run()
