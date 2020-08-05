package com.acmicpc;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 4963
문제 제목 : 섬의 개수
풀이 날짜 : 2020-08-05
Solved By Reamer 
*/

public class acm_4963 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		int[] dx = { -1, -1, -1, 0, 1, 1, 1, 0 };
		int[] dy = { -1, 0, 1, 1, 1, 0, -1, -1 };
		Queue<pair> queue = new LinkedList<pair>();
		int[][] land;
		boolean[][] isVisited;
		while (true) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int h = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			if (w == 0 && h == 0)
				break;
			land = new int[w][h];
			isVisited = new boolean[w][h];

			for (int i = 0; i < w; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < h; j++) {
					land[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			int cnt = 0;
			for (int i = 0; i < w; i++) {
				for (int j = 0; j < h; j++) {
					if (!isVisited[i][j] && land[i][j] == 1) {
						cnt++;
						queue.offer(new pair(i, j));
						isVisited[i][j] = true;

						while (!queue.isEmpty()) {
							pair p = queue.poll();
							int x = p.getX();
							int y = p.getY();

							for (int k = 0; k < 8; k++) {
								int newX = x + dx[k];
								int newY = y + dy[k];
								if (newX >= 0 && newX < w && newY >= 0 && newY < h && !isVisited[newX][newY]
										&& land[newX][newY] == 1) {
									isVisited[newX][newY] = true;
									queue.offer(new pair(newX, newY));
								}
							}
						}
					}
				}
			}

			sb.append(cnt).append("\n");
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