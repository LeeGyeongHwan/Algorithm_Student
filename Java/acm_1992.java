package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 1992
문제 제목 : 쿼드트리
풀이 날짜 : 2020-08-25
Solved By Reamer
*/

public class acm_1992 {
	private static int[][] board;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str;
		int N = Integer.parseInt(br.readLine());
		board = new int[N][N];

		for (int i = 0; i < N; i++) {
			str = br.readLine();
			for (int j = 0; j < N; j++) {
				board[i][j] = str.charAt(j) - '0';
			}
		}

		if (!Scan(0, 0, N))
			Compression(0, 0, N);
		System.out.println(sb);

	}

	public static void Compression(int x, int y, int num) {

		if (num == 0) {
			return;
		}

		sb.append("(");

		if (!Scan(x, y, num / 2))
			Compression(x, y, num / 2);
		if (!Scan(x, y + num / 2, num / 2))
			Compression(x, y + num / 2, num / 2);
		if (!Scan(x + num / 2, y, num / 2))
			Compression(x + num / 2, y, num / 2);
		if (!Scan(x + num / 2, y + num / 2, num / 2))
			Compression(x + num / 2, y + num / 2, num / 2);

		sb.append(")");
	}

	public static boolean Scan(int x, int y, int num) {
		int count = 0;
		for (int i = x; i < x + num; i++) {
			for (int j = y; j < y + num; j++) {
				count += board[i][j];
			}
		}
		if (count == 0) {
			sb.append("0");
		} else if (count == num * num) {
			sb.append("1");
		} else {
			return false;
		}
		return true;
	}
}
