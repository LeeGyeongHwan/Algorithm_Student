# 
# ACMICPC 
# 문제 번호 : 10409
# 문제 제목 : 서버
# 풀이 날짜 : 2020-10-02
# Solved By Reamer 
# 

nT = input().split(" ")
n = nT[0]
T = int(nT[1])
cnt = 0
numArr = input().split(" ")
for i in range(0, int(n)):
    T -= int(numArr[i])
    if T < 0:
        continue
    cnt += 1
print(cnt)
