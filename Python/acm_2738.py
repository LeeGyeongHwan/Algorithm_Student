#  
# ACMICPC 
# 문제 번호 : 2738
# 문제 제목 : 행렬 덧셈
# 풀이 날짜 : 2020-10-07
# Solved By Reamer 
# 

N, M = input().split(" ")

numArr = [[0 for col in range(int(M))] for row in range(int(N))]

for i in range(0, int(N)):
    row = input().split(" ")
    for j in range(0, int(M)):
        numArr[i][j] += int(row[j])

for i in range(0, int(N)):
    row = input().split(" ")
    for j in range(0, int(M)):
        numArr[i][j] += int(row[j])
    
print("===========")
for i in numArr:
    for j in i:
        print(j,end=" ")
    print()