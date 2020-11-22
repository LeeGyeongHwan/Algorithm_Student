# 
# ACMICPC 
# 문제 번호 : 14909
# 문제 제목 : 양수 개수 세기
# 풀이 날짜 : 2020-11-23
# Solved By Reamer 
# 

num = input().split()

cnt = 0

for i in range(0, len(num)):
    if int(num[i]) > 0:
        cnt = cnt + 1

print(cnt)