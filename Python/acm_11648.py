# 
# ACMICPC 
# 문제 번호 : 11648
# 문제 제목 : 지속
# 풀이 날짜 : 2020-11-11
# Solved By Reamer 
# 

N = input()

count = 0
while len(N)!=1:
    count = count + 1
    tmp = 1
    for i in range(0,len(N)):
        tmp *= (int)(N[i])
    N = str(tmp)
print(count)