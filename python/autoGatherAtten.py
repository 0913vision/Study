original_student_name = ["강지연","김민재","김재휘","김진아","김태윤","남기찬","박정주","박지윤","안연아","이수빈","이유빈","이정민","이지언","이지우","장나경"]
student_name = []

f = open('D:/programming/2020-2021/python/todayStudent.txt', 'r', encoding="UTF-8")
raw = f.readlines()

for r in raw:
    r = r.replace('_', ' ')
    r = r.replace('\n', ' ')
    sp = r.split(' ')
    for rr in sp:
        #print("[",rr,"]")
        if(rr in original_student_name):
            student_name.append(rr)

print("▶ IN:")
for o in original_student_name:
    if(o in student_name):
        print(o, end=" ")
print("\n▶ OUT:")
for o in original_student_name:
    if(o not in student_name):
        print(o, end=" ")
        
        
print(" ")

while(1):
    print(">> ", end="")
    prompt = input()
    name = prompt[1:]
    op = prompt[0]
    if(prompt == ""):
        continue
    else:
        name = prompt[1:]
        op = prompt[0] 


    if(op == '+' and name not in student_name):
        student_name.append(name)
    elif(op == '-' and name in student_name):
        student_name.remove(name)
    elif(op == 'l' or op == 'ㅣ'):
        print("▶ IN:")
        for o in original_student_name:
            if(o in student_name):
                print(o, end=" ")
        print("\n▶ OUT:")
        for o in original_student_name:
            if(o not in student_name):
                print(o, end=" ")
        print("")
    elif(op == 'q'):
        break
    else:
        print("Error")
