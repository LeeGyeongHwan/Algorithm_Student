#  
# ACMICPC 
# 문제 번호 : 3460
# 문제 제목 : 이진수
# 풀이 날짜 : 2020-10-18
# Solved By Reamer 
# 

T = input()

for i in range(0, int(T)):
    N = input()
    N = int(N)
    idx = 0
    while (True):
        if (1<<idx) > N:
            break
        if (N & (1 << idx)) > 0 :
            print(idx, end=" ")
        idx = idx + 1

    print()

