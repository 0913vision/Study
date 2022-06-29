from functools import cmp_to_key

def sortl(t1, t2):
    if int(t1[1])<int(t2[1]):
        return 1
    else:
        return -1
    
f = open('D:\\programming\\2020-2021\\python\\result.txt', 'r', encoding='UTF-8')

fl = []

for lpLine in f:
    tmp_str = str(lpLine)
    index = tmp_str.rfind(':')
    fl.append((tmp_str[:index], int(tmp_str[index+1:])))

fl = sorted(fl, key=cmp_to_key(sortl))
f.close()
f = open('D:\\programming\\2020-2021\\python\\result_sorted.txt', 'w', encoding='UTF-8')

for ff in fl:
    f.write(str(ff[0])+' : '+str(ff[1])+ '\n')
    
f.close()