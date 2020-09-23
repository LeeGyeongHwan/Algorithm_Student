package com.ssafy.day23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 17069
문제 제목 : 파이프 옮기기 2
풀이 날짜 : 2020-09-23
Solved By Reamer
*/
public class acm_17069 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());

		int[][] map = new int[N][N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		long [][][] dp = new long[N][N][3];

		dp[0][1][0] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if(map[i][j]==1)
					continue;
				for (int k = 0; k < 3; k++) {
					switch (k) {
					case 0:
						dp[i][j][k] += dp[i][j - 1][0] + dp[i][j - 1][1];
						break;
					case 1:
						if (i - 1 >= 0) {
							if (map[i - 1][j] == 0 && map[i][j - 1] == 0) {
								dp[i][j][k] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
							}
						}
						break;
					case 2:
						if (i - 1 >= 0)
							dp[i][j][k] += dp[i - 1][j][1] + dp[i - 1][j][2];

						break;
					}
				}
			}
		}
		
		long sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += dp[N - 1][N - 1][i];
		}
		System.out.println(sum);

	}
}
