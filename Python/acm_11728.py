#  
# ACMICPC 
# 문제 번호 : 11728
# 문제 제목 : 배열 합치기
# 풀이 날짜 : 2020-10-23
# Solved By Reamer 
# 

N, M = input().split()

A = input().split()
B = input().split()

idxA = 0
idxB = 0

while (idxA < len(A) and idxB < len(B)):
    if int(A[idxA]) > int(B[idxB]):
        print(B[idxB], end=" ")
        idxB = idxB + 1
    else:
        print(A[idxA], end=" ")
        idxA = idxA + 1

while(idxA < len(A)):        
    print(A[idxA], end=" ")
    idxA = idxA + 1

while(idxB < len(B)):
    print(B[idxB], end=" ")
    idxB = idxB + 1