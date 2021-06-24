# 定义推理机规则类
from intel_sys.InferenceEngine.Feature import Feature


class Rule():
    def __init__(self, features, fact):
        # List<Feature> features
        self.features = features
        # string fact
        self.fact = fact
    def show(self):
        for feature in self.features:
            feature.show()
        print(self.fact)