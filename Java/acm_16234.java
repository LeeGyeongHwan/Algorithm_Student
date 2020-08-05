package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 16234
문제 제목 : 인구 이동
풀이 날짜 : 2020-08-05
Solved By Reamer 
*/

public class acm_16234 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		Queue<pair> queue = new LinkedList<pair>();
		int N = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());

		int[] dx = { -1, 0, 1, 0 };
		int[] dy = { 0, 1, 0, -1 };

		int[][] population = new int[N][N];
		int[][] disjointSet = new int[N][N];
		int[] sumNum;
		int[] sumCountry;
		boolean[][] isVisited;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < N; j++) {
				population[i][j] = Integer.parseInt(st.nextToken());
				disjointSet[i][j] = i * N + j;
			}
		}
		int cnt = 0;
		while (true) {
			isVisited = new boolean[N][N];
			sumNum = new int[N * N];
			sumCountry = new int[N * N];
			int setNum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (!isVisited[i][j]) {
						setNum++;
						queue.offer(new pair(i, j));
						isVisited[i][j] = true;
						int disNum = disjointSet[i][j];
						sumNum[disNum] = population[i][j];
						int country = 0;

						while (!queue.isEmpty()) {
							pair p = queue.poll();
							int x = p.getX();
							int y = p.getY();
							country++;

							for (int k = 0; k < 4; k++) {
								int newX = x + dx[k];
								int newY = y + dy[k];

								if (newX >= 0 && newX < N && newY >= 0 && newY < N && !isVisited[newX][newY]) {
									int popul = Math.abs(population[x][y] - population[newX][newY]);
									if (popul >= L && popul <= R) {
										disjointSet[newX][newY] = disNum;
										isVisited[newX][newY] = true;
										sumNum[disNum] += population[newX][newY];
										queue.offer(new pair(newX, newY));
									}
								}
							}
						}
						sumCountry[disNum] = country;
						// country 저장
					}
				}
			} // end of for
			if (setNum == N * N) {
				break;
			}
			cnt++;
			// 이동
			isVisited = new boolean[N][N];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {

					if (!isVisited[i][j]) {
						queue.offer(new pair(i, j));
						isVisited[i][j] = true;
						int set = disjointSet[i][j];
						int changeNum = sumNum[set] / sumCountry[set];
						population[i][j] = changeNum;
						while (!queue.isEmpty()) {
							pair p = queue.poll();
							int x = p.getX();
							int y = p.getY();

							for (int k = 0; k < 4; k++) {
								int newX = x + dx[k];
								int newY = y + dy[k];

								if (newX >= 0 && newX < N && newY >= 0 && newY < N && !isVisited[newX][newY]) {
									if (disjointSet[newX][newY] == set) {
										isVisited[newX][newY] = true;
										population[newX][newY] = changeNum;
										queue.offer(new pair(newX, newY));
									}
								}
							}
						}
					}

				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					disjointSet[i][j] = i * N + j;
				}
			}

		} // end of while
		System.out.println(cnt);

	}
}

class pair {
	private int x, y;

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

	public pair(int x, int y) {
		this.x = x;
		this.y = y;
	}

}
