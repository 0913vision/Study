f = open('D:/programming/2020-2021/python/kakaotalk.txt','r',encoding='UTF-8')

talk = []
num = 0;
dash = 0;
my = 0;

wordCount = {}

for lpLine in f:
    num = num+1
    if lpLine.find("---------------") != -1:
        print(lpLine)
        continue
    elif lpLine.find("[김유찬] [") != -1:
        continue
    else:
        spar = lpLine[lpLine.find('M]')+3:]
        wordList = spar.split()
        for word in wordList:
            wordCount[word] = wordCount.get(word, 0) + 1
            keys = sorted(wordCount.keys())
f.close()
f = open('D:/programming/2020-2021/python/result.txt','w',encoding='UTF-8')
for k in keys:
    f.write(k+':'+str(wordCount[k])+'\n')