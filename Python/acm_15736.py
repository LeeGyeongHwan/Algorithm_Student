# 
# ACMICPC 
# 문제 번호 : 15736
# 문제 제목 : 청기 백기
# 풀이 날짜 : 2020-11-25
# Solved By Reamer 
# 

N = input()

count = 0

num = 1

while True:
    if num > int(N) / num:
        break
    count = count + 1
    num = num + 1

print(count)