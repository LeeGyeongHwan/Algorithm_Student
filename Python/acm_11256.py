# 
# ACMICPC 
# 문제 번호 : 11256
# 문제 제목 : 사탕
# 풀이 날짜 : 2020-10-29
# Solved By Reamer 
# 

testCase = input()

for i in range(0, int(testCase)):
    candy, box = input().split()
    arr = []
    for j in range(0, int(box)):
        R, C = input().split()
        arr.append(int(R)*int(C))
    
    arr.sort()
    arr.reverse()
    answer = 0
    candy = int(candy)
    for box in arr:
        candy = candy - box
        answer = answer + 1
        if candy <= 0:
            break
    print(answer)
        