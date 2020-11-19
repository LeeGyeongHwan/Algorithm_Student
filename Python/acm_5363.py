#  
# ACMICPC 
# 문제 번호 : 5363
# 문제 제목 : 요다
# 풀이 날짜 : 2020-11-20
# Solved By Reamer 
# 

N = input()

for i in range(0, int(N)):
    sentence = input().split()
    for j in range(2, len(sentence)):
        print(sentence[j], end=" ")
    for j in range(0, 2):
        print(sentence[j], end=" ")
    print()