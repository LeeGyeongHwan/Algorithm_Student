#  
# ACMICPC 
# 문제 번호 : 8849
# 문제 제목 : 대충 더해
# 풀이 날짜 : 2020-10-10
# Solved By Reamer 
# 

A, B = input().split(" ")
absLen = abs(len(A)-len(B))
if len(A) < len(B):
    for i in range(0, absLen):
        A = '0' + A
elif len(A) > len(B):
    for i in range(0, absLen):
        B = '0' + B
answer = ''
for i in range(0, len(A)):
    num = int(A[i]) + int(B[i])
    answer += str(num)

print(answer)
