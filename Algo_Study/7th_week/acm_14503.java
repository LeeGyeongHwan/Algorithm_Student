package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/* 
ACMICPC
Study Group
7th Week
문제 번호 : 14503
문제 제목 : 로봇 청소기
풀이 날짜 : 2020-09-26
Solved By Reamer 
*/
public class acm_14503 {

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[][] room = new int[N][M];

		st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int dir = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				room[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int cleanCnt = 0;

		Queue<Cleaner> queue = new LinkedList<Cleaner>();

		boolean[][] isVisited = new boolean[N][M];

		queue.offer(new Cleaner(r, c, dir));

		while (!queue.isEmpty()) {
			Cleaner cleaner = queue.poll();
			dir = cleaner.dir;
			if(!isVisited[cleaner.x][cleaner.y]) {
				isVisited[cleaner.x][cleaner.y]=true;
				cleanCnt++;
			}
			
			boolean cleaned = false;

			for (int i = 0; i < 4; i++) {
				dir--;
				if (dir < 0)
					dir = 3;
				int newX = cleaner.x + dx[dir];
				int newY = cleaner.y + dy[dir];
				if (newX < 0 || newX >= N || newY < 0 || newY >= M || isVisited[newX][newY] || room[newX][newY] == 1)
					continue;
				queue.offer(new Cleaner(newX, newY, dir));
				cleaned = true;
				break;
			}

			if (!cleaned) {
				int newD = (dir + 2) % 4;
				int backX = cleaner.x + dx[newD];
				int backY = cleaner.y + dy[newD];
				if (room[backX][backY] == 1)
					break;
				queue.offer(new Cleaner(backX, backY, dir));
			}
		}
		System.out.println(cleanCnt);

	}

	static class Cleaner {
		int x, y, dir;

		public Cleaner(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}

	}
}
