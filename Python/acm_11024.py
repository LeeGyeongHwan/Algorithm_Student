# 
# ACMICPC 
# 문제 번호 : 11024
# 문제 제목 : 더하기 4
# 풀이 날짜 : 2020-09-28
# Solved By Reamer 
# 

N = input()

for i in range(0, int(N)):
    str = input().split(" ")
    sum = 0
    for s in str:
        sum += int(s)
    print(sum)