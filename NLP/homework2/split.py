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


def matchForward(sentence, dict):
    max_len = 10
    length = len(sentence)
    result = []
    while length > 0:
        word = sentence[0:max_len]
        while word not in dict:
            if (len(word) == 1):
                break
            word = word[0:len(word) - 1]
        if (word != ''):
            result.append(word)
        sentence = sentence[len(word):]
        length = len(sentence)
    return result


def matchBack(sentence, dict):
    max_len = 10
    length = len(sentence)
    result = []
    while length > 0:
        word = sentence[length - max_len:length]
        while word not in dict:
            if (len(word) == 1):
                break
            word = word[1:length]
        if (word != ''):
            result.append(word)
        length = len(sentence)
        sentence = sentence[0:length - len(word)]
    result.reverse()
    return result


def matchBi(result1, result2):
    len1 = len(result1)
    len2 = len(result2)
    if (result1 == result2):
        return result1
    if (len1 > len2):
        return result2
    elif (len1 < len2):
        return result1
    n=1
    while(n<=max(len1,len2)):
        cnt1=countWord(n,result1)
        cnt2=countWord(n,result2)
        if(cnt1<cnt2):
            return result1
        elif(cnt1>cnt2):
            return result2
        else:
            if(cnt1==0):
                return result1
            else:
                n+=1

def countWord(n,result):
    cnt=0
    for word in result:
        if n==len(word):
            cnt+=1
    return cnt

if __name__ == "__main__":
    dict = readData()
    sentence = input("Please enter the test sentence: ")
    result1 = matchForward(sentence, dict)
    print("The result of FMM: ",result1)
    result2 = matchBack(sentence, dict)
    print("The result of BMM: ",result2)
    result3=matchBi(result1,result2)
    print("The result of Bi-Direction: ",result3)
