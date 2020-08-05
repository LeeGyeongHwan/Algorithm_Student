package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/* 
ACMICPC 
문제 번호 : 2667
문제 제목 : 단지번호붙이기
풀이 날짜 : 2020-08-05
Solved By Reamer 
*/

public class acm_2667 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		int[] dx = { -1, 0, 1, 0 };
		int[] dy = { 0, 1, 0, -1 };
		Queue<pair> queue = new LinkedList<pair>();

		int[][] map = new int[N][N];
		boolean[][] isVisited = new boolean[N][N];
		int[] cityNum = new int[N * N];

		for (int i = 0; i < N; i++) {
			String str = br.readLine();
			for (int j = 0; j < N; j++) {
				map[i][j] = str.charAt(j) - '0';
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!isVisited[i][j] && map[i][j] == 1) {
					queue.offer(new pair(i, j));
					isVisited[i][j] = true;
					int house = 0;
					while (!queue.isEmpty()) {
						pair p = queue.poll();
						int x = p.getX();
						int y = p.getY();
						house++;
						for (int k = 0; k < 4; k++) {
							int newX = x + dx[k];
							int newY = y + dy[k];
							if (newX >= 0 && newX < N && newY >= 0 && newY < N && !isVisited[newX][newY]
									&& map[newX][newY] == 1) {
								isVisited[newX][newY] = true;
								queue.offer(new pair(newX, newY));
							}

						}
					}
					cityNum[cnt++] = house;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(cnt);
		Arrays.sort(cityNum, 0, cnt);
		for (int i = 0; i < cnt; i++) {
			sb.append("\n").append(cityNum[i]);
		}
		System.out.println(sb);
	}
}

class pair {
	int x, y;

	public pair(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

}