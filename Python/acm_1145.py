#  
# ACMICPC 
# 문제 번호 : 1145
# 문제 제목 : 적어도 대부분의 배수
# 풀이 날짜 : 2020-10-22
# Solved By Reamer 
# 

arr = input().split()
arr = list(map(int, arr))

arr.sort()

start = arr[2]

while(True):
    cnt = 0
    for num in arr:
        if start % int(num) == 0:
            cnt = cnt + 1
    if cnt >= 3:
        print(start)
        break
    start = start+1