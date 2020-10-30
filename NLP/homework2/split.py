def readData():
    with open('data.txt', 'r', encoding='utf-8') as f:
        lines = f.readlines()
        dict = {}
        for l in lines:
            info = l.split(l[1])
            word = info[1].split('\n')[0]
            dict.setdefault(word, int(info[0]))
        print(dict)
        return dict
        # print(lines)


def patchForward(sentence,dict):
    max_len = 10
    length = len(sentence)
    result =[]
    while length > 0:
        word = sentence[0:max_len]
        while word not in dict:
            if(len(word)==1):
                break
            word = word[0:len(word)-1]
        if (word != ''):
            result.append(word)
        sentence = sentence[len(word):]
        length = len(sentence)
    return result

def patchBack(sentence,dict):
    max_len = 10
    length = len(sentence)
    result =[]
    while length > 0:
        word = sentence[length-max_len:length]
        while word not in dict:
            if(len(word)==1):
                break
            word = word[1:length]
        if(word!=''):
            result.append(word)
        length = len(sentence)
        sentence = sentence[0:length-len(word)]
    result.reverse()
    return result

if __name__ == "__main__":
    dict = readData()
    sentence = input("Please enter the test sentence: ")
    result1=patchForward(sentence,dict)
    print(result1)
    result2=patchBack(sentence,dict)
    print(result2)