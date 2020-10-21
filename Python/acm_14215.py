#  
# ACMICPC 
# 문제 번호 : 14215
# 문제 제목 : 세 막대
# 풀이 날짜 : 2020-10-21
# Solved By Reamer 
# 

abc = input().split()
abc = list(map(int, abc))

abc.sort()
a = int(abc[0])
b = int(abc[1])
c = int(abc[2])

if a + b <= c:
    print((a+b)*2-1)
else:    
    print(a+b+c)