package com.ssafy.algo;
/* 
ACMICPC
Study Group
4th Week
문제 번호 : 2636
문제 제목 : 치즈
풀이 날짜 : 2020-08-21
Solved By Reamer 
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class acm_2636 {
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int cheezeCnt = 0;
		int prevCheeze = 0;

		int board[][] = new int[N][M];
		boolean isVisited[][];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				int tmp = Integer.parseInt(st.nextToken());
				board[i][j] = tmp;
				if (tmp == 1)
					cheezeCnt++;
			}
		}
		Queue<Pair> pairQ = new LinkedList<Pair>();
		int time = 0;
		while (cheezeCnt != 0) {

			time++;
			prevCheeze = cheezeCnt;
			isVisited = new boolean[N][M];
			pairQ.offer(new Pair(0, 0));
			isVisited[0][0] = true;
			while (!pairQ.isEmpty()) {
				Pair p = pairQ.poll();

				for (int i = 0; i < 4; i++) {
					int newX = p.x + dx[i];
					int newY = p.y + dy[i];
					if (newX >= 0 && newX < N && newY >= 0 && newY < M && !isVisited[newX][newY]) {
						isVisited[newX][newY] = true;
						if (board[newX][newY] == 0) {
							pairQ.offer(new Pair(newX, newY));
						} else {
							board[newX][newY] = 0;
							cheezeCnt--;
						}
					}

				}
			}

		}
		StringBuilder sb = new StringBuilder();
		sb.append(time).append("\n").append(prevCheeze);
		System.out.println(sb);
	}
}

class Pair {
	int x, y;

	Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}