#  
# ACMICPC 
# 문제 번호 : 10988
# 문제 제목 : 팰린드롬인지 확인하기
# 풀이 날짜 : 2020-10-06
# Solved By Reamer 
# 

str = input()

palin = ''.join(reversed(str))
if str == palin:
    print(1)
else:
    print(0)