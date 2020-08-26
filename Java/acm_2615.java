package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 2615
문제 제목 : 오목
풀이 날짜 : 2020-08-26
Solved By Reamer 
*/

public class Jungol_1733 {

	static int[] dx = { 0, 1, 1, 1 };
	static int[] dy = { 1, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int[][] board = new int[20][20];
		boolean[][][] isVisited = new boolean[20][20][4];

		for (int i = 1; i <= 19; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 1; j <= 19; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int gameMode = 0;
		int winX = 0;
		int winY = 0;

		gs: for (int i = 1; i <= 19; i++) {
			for (int j = 1; j <= 19; j++) {
				if (board[i][j] != 0) {

					for (int k = 0; k < 4; k++) {
						int newX = i + dx[k];
						int newY = j + dy[k];
						int cnt = 1;
						while (true) {
							if (!(newX >= 1 && newX <= 19 && newY >= 1 && newY <= 19 && board[i][j] == board[newX][newY]
									&& !isVisited[newX][newY][k]))
								break;
							isVisited[newX][newY][k] = true;
							cnt++;
							newX += dx[k];
							newY += dy[k];
						}
						if (cnt == 5) {
							winX = i;
							winY = j;
							gameMode = board[i][j];
							if (k == 3) {
								winX = i + 4 * dx[k];
								winY = j + 4 * dy[k];
							}
							break gs;
						}
					}
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(gameMode).append("\n");
		if (gameMode != 0) {
			sb.append(winX).append(" ").append(winY);
		}
		System.out.println(sb);

	}
}
