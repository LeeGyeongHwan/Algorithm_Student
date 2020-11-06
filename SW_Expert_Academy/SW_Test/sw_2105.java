package com.swexpert;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
난이도 : SW Test
문제 번호 : 2105
문제 제목 : 디저트 카페
풀이 날짜 : 2020-11-06
Solved By Reamer
*/

public class sw_2105 {
	private static int[][] map;

	static int[] dx = { 1, 1, -1, -1 };
	static int[] dy = { 1, -1, -1, 1 };
	static int[] dirRight = { 1, 0, -1, 0 };
	static int[] dirLeft = { 0, 1, 0, -1 };

	static int maxSum, startX, startY, answer;

	private static boolean[] dessert;

	private static int N;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int testCase = 1; testCase <= T; testCase++) {
			N = Integer.parseInt(br.readLine());
			map = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			maxSum = 0;
			answer = -1;

			for (int i = 0; i < N - 2; i++) {
				for (int j = 1; j < N - 1; j++) {
					dessert = new boolean[101];
					startX = i;
					startY = j;
					dessert[map[i + dx[0]][j + dy[0]]] = true;
					DFS(i + dx[0], j + dy[0], 0, map[i + dx[0]][j + dy[0]], 1, 1, 0);
				}

			}

			sb.append("#").append(testCase).append(" ").append(answer).append("\n");
		}
		System.out.println(sb);
	}

	private static void DFS(int x, int y, int dir, int sum, int cnt, int rightCnt, int leftCnt) {

		if (rightCnt == 0 && leftCnt == 0) {
			answer = Math.max(cnt, answer);
			return;
		}

		int nextX = x + dx[dir];
		int nextY = y + dy[dir];

		if (nextX >= startX && nextX < N && nextY >= 0 && nextY < N) {
			int tmpDessert = map[nextX][nextY];
			if (!dessert[tmpDessert] && rightCnt + dirRight[dir] >= 0 && leftCnt + dirLeft[dir] >= 0) {
				dessert[tmpDessert] = true;
				DFS(nextX, nextY, dir, sum + tmpDessert, cnt + 1, rightCnt + dirRight[dir], leftCnt + dirLeft[dir]);
				dessert[tmpDessert] = false;
			}

		}

		if (dir != 3) {
			int oX = x + dx[dir + 1];
			int oY = y + dy[dir + 1];

			if (oX >= startX && oX < N && oY >= 0 && oY < N) {
				int tmpDessert = map[oX][oY];
				if (!dessert[tmpDessert] && rightCnt + dirRight[dir + 1] >= 0 && leftCnt + dirLeft[dir + 1] >= 0) {
					dessert[tmpDessert] = true;
					DFS(oX, oY, dir + 1, sum + tmpDessert, cnt + 1, rightCnt + dirRight[dir + 1],
							leftCnt + dirLeft[dir + 1]);
					dessert[tmpDessert] = false;
				}

			}
		}

	}
}
