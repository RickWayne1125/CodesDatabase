from os import name

from numpy import select


class Feature:
    def __init__(self, text="") -> None:
        # 每一个特征以三元式存储
        self.text = text
        self.left = text.split(" ")[0]   # 左侧属性
        self.op = text.split(" ")[1]  # 操作符，如: =,<,>,......
        self.right = text.split(" ")[2]  # 右侧值

    def show(self):
        print(self.text)


# TEST PART
if __name__ == '__main__':
    f = Feature("Temp > 18")
    f.show()
