# /* 
# ACMICPC 
# 문제 번호 : 10822
# 문제 제목 : 더하기
# 풀이 날짜 : 2020-11-18
# Solved By Reamer 
# */

str = input().split(",")

num = 0 
for i in range(0,len(str)):
    num = num + int(str[i])
print(num)
