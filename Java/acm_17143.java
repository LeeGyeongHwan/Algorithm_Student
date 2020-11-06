package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 17143
문제 제목 : 낚시왕
풀이 날짜 : 2020-11-06
Solved By Reamer 
*/

public class acm_17143 {
	static int[] dx = { 0, -1, 1, 0, 0 };
	static int[] dy = { 0, 0, 0, 1, -1 };
	private static Shark[][] sharkMap;
	private static int R, C, M;
	private static int answer;
	private static Shark[][] tmpSharkMap;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		sharkMap = new Shark[R][C];

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());

			sharkMap[r - 1][c - 1] = new Shark(s, d, z);
		}

		if (M != 0)
			fishing(-1, 0);
		System.out.println(answer);

	}

	private static void fishing(int fisher, int sumShark) {

		// 1. 오른쪽이동
		fisher++;
		if (fisher == C) {
			answer = sumShark;
			return;
		}
		// 2. 제일 낮은 행 잡기
		for (int i = 0; i < R; i++) {
			if (sharkMap[i][fisher] != null) {
				sumShark += sharkMap[i][fisher].size;
				sharkMap[i][fisher] = null;
				break;
			}
		}
		// 3. 상어 이동
		tmpSharkMap = new Shark[R][C];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				Shark s = sharkMap[i][j];
				if (s != null) {
					int xSpeed = s.speed % ((R - 1) * 2);
					int ySpeed = s.speed % ((C - 1) * 2);
					int newX = i + dx[s.dir] * xSpeed;
					int newY = j + dy[s.dir] * ySpeed;

					if (newX < 0) {
						newX = Math.abs(newX);
						int even = newX / (R - 1);
						int idx = newX % (R - 1);
						if (even > 0) {
							if (idx == 0)
								s.dir = 2;
							newX = R - 1 - idx;
						} else {
							s.dir = 2;
							newX = idx;
						}
					} else if (newX >= R) {
						int even = newX / (R - 1);
						int idx = newX % (R - 1);
						if (even == 2) {
							if (idx == 0)
								s.dir = 1;
							newX = idx;
						} else {
							s.dir = 1;
							newX = R - 1 - idx;
						}
					} else if (newY < 0) {
						newY = Math.abs(newY);
						int even = newY / (C - 1);
						int idx = newY % (C - 1);
						if (even > 0) {
							if (idx == 0)
								s.dir = 3;
							newY = C - 1 - idx;
						} else {
							s.dir = 3;
							newY = idx;
						}
					} else if (newY >= C) {
						int even = newY / (C - 1);
						int idx = newY % (C - 1);
						if (even == 2) {
							if (idx == 0)
								s.dir = 4;
							newY = idx;
						} else {
							s.dir = 4;
							newY = C - 1 - idx;
						}
					}

					if (tmpSharkMap[newX][newY] != null && tmpSharkMap[newX][newY].size > s.size) {
						continue;
					}
					tmpSharkMap[newX][newY] = s;
				}
			}
		}
		// 복사
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				sharkMap[i][j] = tmpSharkMap[i][j];
			}
		}
		// 다음 호출
		fishing(fisher, sumShark);
	}

	static class Shark {
		int speed, dir, size;

		public Shark(int speed, int dir, int size) {
			super();
			this.speed = speed;
			this.dir = dir;
			this.size = size;
		}

	}
}
