def readData():
    with open('data.txt','r',encoding='utf-8') as f:
        lines=f.readlines()
        dict = {}
        for l in lines:
            info = l.split(l[1])
            word = info[1].split('\n')[0]
            dict.setdefault(word,int(info[0]))
        print(dict)
        #print(lines)
if __name__=="__main__":
    readData()
