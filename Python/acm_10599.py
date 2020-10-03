# 
# ACMICPC 
# 문제 번호 : 10599
# 문제 제목 : 페르시아의 왕들
# 풀이 날짜 : 2020-10-03
# Solved By Reamer 
# 

while(True):
    arr = input().split(" ")
    num1 = int(arr[0])
    num2 = int(arr[1])
    num3 = int(arr[2])
    num4 = int(arr[3])
    if num1 == 0 and num2 == 0 and num3 == 0 and num4 == 0:
        break
    print(str(num3-num2)+" "+str(num4-num1))