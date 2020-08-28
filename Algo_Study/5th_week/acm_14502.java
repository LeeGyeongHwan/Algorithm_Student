package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* 
ACMICPC
Study Group
5th Week
문제 번호 : 14502
문제 제목 : 연구소
풀이 날짜 : 2020-08-28
Solved By Reamer 
*/

public class acm_14502 {
	private static int[][] map;
	private static int N;
	private static int M;
	private static int[][] tmpMap;
	private static boolean[][] isVisited;
	private static int[] dx = { -1, 0, 1, 0 };
	private static int[] dy = { 0, 1, 0, -1 };
	static int maxArea;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		tmpMap = new int[N][M];
		isVisited = new boolean[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		buildWall(0, 0);
		System.out.println(maxArea);

	}

	private static void buildWall(int cnt, int start) {
		if (cnt == 3) {
			spread();
			return;
		}
		for (int i = start; i < N * M; i++) {
			int r = i / M;
			int c = i % M;
			if (map[r][c] == 0) {
				map[r][c] = 1;
				buildWall(cnt + 1, i + 1);
				map[r][c] = 0;
			}
		}

	}

	private static void spread() {
		// 맵 복사
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmpMap[i][j] = map[i][j];
				isVisited[i][j] = false;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!isVisited[i][j] && tmpMap[i][j] == 2) {
					dfs(i, j);
				}
			}
		}

		int safeArea = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (tmpMap[i][j] == 0)
					safeArea++;
			}
		}
		if (safeArea > maxArea)
			maxArea = safeArea;
	}

	private static void dfs(int x, int y) {

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 0 && newX < N && newY >= 0 && newY < M && !isVisited[newX][newY] && tmpMap[newX][newY] == 0) {
				isVisited[newX][newY] = true;
				tmpMap[newX][newY] = 2;
				dfs(newX, newY);
			}
		}
	}
}
