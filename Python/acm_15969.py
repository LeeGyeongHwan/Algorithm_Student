# 
# ACMICPC 
# 문제 번호 : 15969
# 문제 제목 : 행복
# 풀이 날짜 : 2020-10-04
# Solved By Reamer 
# 

N = input()
arr = input().split(" ")
arr = list(map(int,arr))
arr.sort()
maxAbs = int(arr[int(N)-1]) - int(arr[0])
print(maxAbs)