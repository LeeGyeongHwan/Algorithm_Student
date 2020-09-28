#  
# ACMICPC 
# 문제 번호 : 10174
# 문제 제목 : 팰린드롬
# 풀이 날짜 : 2020-09-28
# Solved By Reamer 
# 

N = input()

for i in range(0, int(N)):
    str = input().lower()
    tmp = ''.join(reversed(str))
    if str == tmp:
        print("Yes")
    else:
        print("No")