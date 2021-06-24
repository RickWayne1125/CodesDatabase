from numpy import select


class Fact:
    def __init__(self, text="") -> None:
        # 每一个事实以二元式存储{X, newX}
        # X = newX
        self.text = text
        self.left = text.split(" = ")[0]   # 左侧属性
        self.right = text.split(" = ")[1]  # 右侧值

    def show(self):
        print(self.text)


# TEST PART
if __name__ == '__main__':
    f = Fact("FireAlarm = on")
    f.show()