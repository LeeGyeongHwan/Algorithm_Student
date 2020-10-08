#  
# ACMICPC 
# 문제 번호 : 11944
# 문제 제목 : NN
# 풀이 날짜 : 2020-10-08
# Solved By Reamer 
# 

N, M = input().split(" ")

num = int(M) // len(N)

answer = ''

for i in range(0, int(N)):
    answer += N

if len(answer) > int(M):
    print(answer[:int(M)])
else:
    print(answer)