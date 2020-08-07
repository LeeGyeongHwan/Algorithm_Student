package com.day0807;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_백준_17135_캐슬디펜스_이경환 {

	static int numArcher = 3;
	private static boolean[] archer;
	private static int N, M;
	private static int upBound;
	private static int MaxEnemy = 0;
	private static int distance;
	private static int[][] board;
	private static int[][] tmpBoard;
	static Queue<Pair> queue = new LinkedList<Pair>();

	static void setArcher(int cnt, int idx) {
		if (cnt == 3) {
			int enemy = 0;
			// board -> tmpboard
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					tmpBoard[i][j] = board[i][j];
				}
			}

			for (int stage = 0; stage <N; stage++) {

				na: for (int i = 0; i < archer.length; i++) {

					if (archer[i]) {
						for (int j = 1; j <= distance; j++) {
							for (int k = 0; k < 2 * j - 1; k++) {
								int newX = N - (j - Math.abs(j - 1 - k));
								int newY = i + k - (j - 1);

								if (newX >= 0 && newX < N && newY >= 0 && newY < M && tmpBoard[newX][newY] == 1) {
									queue.offer(new Pair(newX, newY));
									continue na;
								}
							}
						}
					}
				}
				while (!queue.isEmpty()) {
					Pair p = queue.poll();
					if (tmpBoard[p.x][p.y] == 1) {
						tmpBoard[p.x][p.y] = 0;
						enemy++;
					}
				}

				for (int i = 0; i < M; i++) {
					for (int j = N - 1; j > 0; j--) {
						tmpBoard[j][i] = tmpBoard[j - 1][i];
					}
					tmpBoard[0][i] = 0;
				}
			}

			if (MaxEnemy < enemy) {
				MaxEnemy = enemy;
			}

			return;
		}
		if (idx > M)
			return;
		if (idx < M) {
			archer[idx] = true;
			setArcher(cnt + 1, idx + 1);
			archer[idx] = false;
			setArcher(cnt, idx + 1);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		distance = Integer.parseInt(st.nextToken());

		board = new int[N][M];
		tmpBoard = new int[N][M];
		archer = new boolean[M];
		upBound = -1;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				int tmp = Integer.parseInt(st.nextToken());
				board[i][j] = tmp;
				if (upBound == -1 && tmp == 1)
					upBound = i;
			}
		}
		setArcher(0, 0);
		System.out.println(MaxEnemy);
	}
}

class Pair {
	int x, y;

	public Pair(int x, int y) {
		super();
		this.x = x;
		this.y = y;
	}

}