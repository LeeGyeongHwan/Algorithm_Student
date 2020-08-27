package com.ssafy.day27;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 3109
문제 제목 : 빵집
풀이 날짜 : 2020-08-27
Solved By Reamer 
*/

public class acm_3109 {
	static int answer;
	private static char[][] shop;
	static int[] dx = { -1, 0, 1 };
	private static int R;
	private static int C;
	private static boolean isAnswer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		String str;

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		shop = new char[R][C];

		for (int i = 0; i < R; i++) {
			str = br.readLine();
			for (int j = 0; j < C; j++) {
				shop[i][j] = str.charAt(j);
			}
		}

		for (int i = 0; i < R; i++) {
			pipeLine(i, 0);
			isAnswer = false;

		}

		System.out.println(answer);
	}

	private static void pipeLine(int x, int y) {
		if (y == C - 1) {
			answer++;
			isAnswer = true;
			return;
		}

		for (int i = 0; i < 3; i++) {
			int newX = x + dx[i];
			if (newX >= 0 && newX < R && shop[newX][y + 1] == '.') {
				shop[newX][y + 1] = 'x';
				pipeLine(newX, y + 1);
				if (isAnswer)
					break;
			}
		}
	}
}
