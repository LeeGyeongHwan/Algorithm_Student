#  
# ACMICPC 
# 문제 번호 : 4564
# 문제 제목 : 숫자 카드놀이
# 풀이 날짜 : 2020-09-29
# Solved By Reamer 
# 

while(True):
    num = input()
    if int(num) == 0:
        break
    
    while(True):
        tmp = 1
        for i in range(0, len(str(num))):
            tmp *= int(str(num)[i])

        print(num,end=" ")
        if int(num) < 10:
            break
        num = tmp
    print()