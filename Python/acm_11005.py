#  
# ACMICPC 
# 문제 번호 : 11005
# 문제 제목 : 진법 변환 2
# 풀이 날짜 : 2020-10-12
# Solved By Reamer 
# 

N, B = input().split(" ")

mul = 1

while mul <= int(N):
    mul *= int(B)
mul = mul // int(B)

answer = ''
num = int(N)
while mul > 0:
    div = num // mul
    num = num % mul
    mul = mul // int(B)
    if div >= 10:
        answer += chr(65 + div - 10)
    else:
        answer += str(div)
print(answer)

