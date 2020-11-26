# 
# ACMICPC 
# 문제 번호 : 12813
# 문제 제목 : 이진수 연산
# 풀이 날짜 : 2020-11-26
# Solved By Reamer 
# 

A = input()
B = input() 

aAndB = ""
aOrB = ""
aXorB = ""
notA = ""
notB = ""

for i in range(0, len(A)):
    tmpA = int(A[i])
    tmpB = int(B[i])
    aAndB = aAndB + str(tmpA & tmpB)
    aOrB = aOrB + str(tmpA | tmpB)
    aXorB = aXorB + str(tmpA ^ tmpB)
    tmpA = not tmpA
    tmpB = not tmpB
    notA = notA + str(int(tmpA))
    notB = notB + str(int(tmpB))

print(aAndB)
print(aOrB)
print(aXorB)
print(notA)
print(notB)