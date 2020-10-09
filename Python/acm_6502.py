#  
# ACMICPC 
# 문제 번호 : 6502
# 문제 제목 : 동혁 피자
# 풀이 날짜 : 2020-10-09
# Solved By Reamer 
# 


cnt = 1
while(True):
    info = input().split(" ")
    if len(info) == 1:
        break
    pizzaw = int(info[1]) / 2 
    pizzah = int(info[2]) / 2 
    if int(info[0]) * int(info[0]) >=  pizzaw * pizzaw + pizzah * pizzah:
        print("Pizza "+str(cnt)+" fits on the table.")
    else:
        print("Pizza "+str(cnt)+" does not fit on the table.")
    cnt = cnt + 1