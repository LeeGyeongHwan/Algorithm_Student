#  
# ACMICPC 
# 문제 번호 : 9325
# 문제 제목 : 얼마?
# 풀이 날짜 : 2020-11-21
# Solved By Reamer 
# 

N = input()

for i in range(0, int(N)):
    money = int(input())
    option = input()
    for j in range(0, int(option)):
        num, price = input().split()
        money = money + int(num) * int(price)
    print(money)