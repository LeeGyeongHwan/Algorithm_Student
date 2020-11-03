#  
# ACMICPC 
# 문제 번호 : 1676
# 문제 제목 : 팩토리얼 0의 개수
# 풀이 날짜 : 2020-11-03
# Solved By Reamer 
# 

N = input()
answer = 0
for i in range(1,int(N)+1):
    tmp = i
    while tmp > 0:
        if tmp % 5 == 0:
            answer = answer + 1
            tmp = tmp / 5
        else:
            break
print(answer)