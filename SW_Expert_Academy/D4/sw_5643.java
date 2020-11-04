package com.swexpert;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
난이도 : D4
문제 번호 : 5643
문제 제목 : 키 순서
풀이 날짜 : 2020-11-04
Solved By Reamer
*/

public class sw_5643 {
	private static int[][] small;
	private static int[][] tall;

	final static int MAX_VALUE = 1000000;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int testCase = 1; testCase <= T; testCase++) {
			int N = Integer.parseInt(br.readLine());
			int M = Integer.parseInt(br.readLine());

			small = new int[N + 1][N + 1];
			tall = new int[N + 1][N + 1];

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					small[i][j] = MAX_VALUE;
					tall[i][j] = MAX_VALUE;
				}
			}

			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int A = Integer.parseInt(st.nextToken());
				int B = Integer.parseInt(st.nextToken());
				tall[A][B] = 1;
				small[B][A] = 1;
			}

			for (int k = 1; k <= N; k++) {
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						if (i == j || i == k)
							continue;
						tall[i][j] = Math.min(tall[i][j], tall[i][k] + tall[k][j]);
						small[i][j] = Math.min(small[i][j], small[i][k] + small[k][j]);
					}
				}
			}
			int answer = 0;
			for (int i = 1; i <= N; i++) {

				int cnt = 0;
				for (int j = 1; j <= N; j++) {
					if (tall[i][j] != MAX_VALUE)
						cnt++;
					if (small[i][j] != MAX_VALUE)
						cnt++;
				}
				if (cnt == N - 1)
					answer++;
			}
			System.out.println("#" + testCase + " " + answer);
		}
	}
}
