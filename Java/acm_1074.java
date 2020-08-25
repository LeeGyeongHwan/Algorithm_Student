package com.ssafy.algo;

import java.util.Scanner;

/*
ACMICPC
문제 번호 : 1074
문제 제목 : Z
풀이 날짜 : 2020-08-25
Solved By Reamer
*/


public class acm_1074 {
	private static int c;
	private static int r;
	private static int N;
	static int dx[] = { 0, 0, 1, 0 };
	static int dy[] = { 0, 1, -1, 1 };

	static int cnt = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		r = sc.nextInt();
		c = sc.nextInt();

		int num = 1;
		for (int i = 0; i < N; i++)
			num *= 2;

		System.out.println(makeZ(num, 0, 0));
	}

	private static int makeZ(int num, int x, int y) {
		int answer = 0;
		if (num == 2) {
			int newX = x;
			int newY = y;
			for (int i = 0; i < 4; i++) {
				newX += dx[i];
				newY += dy[i];
				if (newX == r && newY == c) {
					return cnt;
				}
				cnt++;
			}
			return 0;
		}

		num /= 2;
		for (int i = 0; i < 4; i++) {

			x += num * dx[i];
			y += num * dy[i];
			answer += makeZ(num, x, y);
		}
		return answer;
	}
}
