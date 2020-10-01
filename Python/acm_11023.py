# 
# ACMICPC 
# 문제 번호 : 11023
# 문제 제목 : 더하기 3
# 풀이 날짜 : 2020-10-01
# Solved By Reamer 
# 

str = input().split(" ")
sum = 0
for s in str:
    sum += int(s)
print(sum)