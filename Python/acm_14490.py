#  
# ACMICPC 
# 문제 번호 : 14490
# 문제 제목 : 백대열
# 풀이 날짜 : 2020-11-02
# Solved By Reamer 
# 

def gcd(a, b):
    if b==0:
        return a
    return gcd(b, a%b)

A,B = input().split(":")

gcdNum = gcd(int(A), int(B))
A = int(int(A)/gcdNum)
B = int(int(B)/gcdNum)
print(str(A)+":"+str(B))