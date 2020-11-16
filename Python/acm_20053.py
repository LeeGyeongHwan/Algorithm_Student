# 
# ACMICPC 
# 문제 번호 : 20053
# 문제 제목 : 최소, 최대 2
# 풀이 날짜 : 2020-11-16
# Solved By Reamer 
# 

T = input()

for i in range(0, int(T)):
    N = input()
    minNum = 1000000
    maxNum = -1000000
    nums = input().split()
    for num in nums:
        minNum = min(minNum, int(num))
        maxNum = max(maxNum, int(num))
    print(str(minNum)+" "+str(maxNum))
