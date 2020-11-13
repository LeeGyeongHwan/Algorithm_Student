#  
# ACMICPC 
# 문제 번호 : 4597
# 문제 제목 : 패리티
# 풀이 날짜 : 2020-11-14
# Solved By Reamer 
# 

while True:
    str = input()
    if str == "#":
        break
    cntOne = 0
    for i in range(0, len(str)-1):
        if str[i] == '1':
            cntOne = cntOne + 1
        print(str[i],end="")
    if str[len(str) - 1] == 'e':
        if cntOne % 2 == 0:
            print(0)
        else:
            print(1)
    else:
        if cntOne % 2 == 0:
            print(1)
        else:
            print(0)