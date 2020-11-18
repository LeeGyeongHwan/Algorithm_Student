#  
# ACMICPC 
# 문제 번호 : 10102
# 문제 제목 : 개표
# 풀이 날짜 : 2020-11-19
# Solved By Reamer 
# 

num = input()

vote = input()

aCnt = 0
for i in range(0, int(num)):
    if (vote[i] == 'A'):
        aCnt = aCnt + 1
bCnt = int(num) - aCnt

if aCnt > bCnt:
    print("A")
elif aCnt < bCnt:
    print("B")
else:
    print("Tie")

