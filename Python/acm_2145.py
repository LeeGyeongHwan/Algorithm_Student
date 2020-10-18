#  
# ACMICPC 
# 문제 번호 : 2145
# 문제 제목 : 숫자 놀이
# 풀이 날짜 : 2020-10-19
# Solved By Reamer 
# 

while(True):
    N = input()
    if N == "0":
        break
    
    while(len(N)!=1):
        sum = 0
        for i in range(0,len(N)):
            sum += int(N[i])
        N = str(sum)
    print(N)
