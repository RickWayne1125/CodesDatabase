# 导入 jieba
import jieba
import jieba.posseg as pseg  # 词性标注
import jieba.analyse as anls  # 关键词提取

words = pseg.cut("我爱北京天安门") #jieba默认模式
jieba.enable_paddle() #启动paddle模式。 0.40版之后开始支持，早期版本不支持
words = pseg.cut("我爱北京天安门",use_paddle=True) #paddle模式
for word, flag in words:
    print('%s %s' % (word, flag))

