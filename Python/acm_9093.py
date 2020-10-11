#  
# ACMICPC 
# 문제 번호 : 9093
# 문제 제목 : 단어 뒤집기
# 풀이 날짜 : 2020-10-11
# Solved By Reamer 
# 

N = input()
for i in range(0, int(N)):
    str = input().split(" ")
    for j in range(0, len(str)):
        tmp = ''.join(reversed(str[j]))
        print(tmp, end = " ")
    print()