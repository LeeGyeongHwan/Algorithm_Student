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
2nd Week
문제 번호 : 2573
문제 제목 : 빙산
풀이 날짜 : 2020-08-08
Solved By Reamer 
*/

public class acm_2573 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		Queue<Pair> queue = new LinkedList<Pair>();

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[] dx = { -1, 0, 1, 0 };
		int[] dy = { 0, 1, 0, -1 };

		int[][] iceLand = new int[N][M];
		int[][] tmpLand = new int[N][M];
		boolean[][] isVisited;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				iceLand[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int year = 0;
		boolean isMelt = false;

		while (true) {
			isVisited = new boolean[N][M];// 방문여부 배열 초기화
			// iceLand -> tmpLand 복사
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					tmpLand[i][j] = iceLand[i][j];
				}
			}
			int cntLand = 0; // 빙산 덩어리 갯수

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (!isVisited[i][j] && iceLand[i][j] != 0) { // 빙산이 있고 방문한적이 없을 때 진입
						cntLand++; // 빙산 덩어리 개수 추가
						queue.offer(new Pair(i, j));
						isVisited[i][j] = true;

						while (!queue.isEmpty()) {
							Pair p = queue.poll();
							int cntSea = 0; // 인접 바다 칸 수
							for (int k = 0; k < 4; k++) {
								int newX = p.x + dx[k];
								int newY = p.y + dy[k];

								if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
									if (iceLand[newX][newY] == 0) // 바다라면 바다 칸 수 증가
										cntSea++;
									else if (!isVisited[newX][newY]) { // 방문한적없다면 큐에 추가
										isVisited[newX][newY] = true;
										queue.offer(new Pair(newX, newY));
									}
								}
							}
							tmpLand[p.x][p.y] -= cntSea; // 임시 배열에
							if (tmpLand[p.x][p.y] < 0)
								tmpLand[p.x][p.y] = 0;
						}
					}
				}
			}
			if (cntLand == 0) { // 빙산이 없다면 플래그 표시 후 break
				isMelt = true;
				break;
			} else if (cntLand > 1) { // 빙산이 여러개라면 break
				break;
			}

			// 이외의 경우는 빙산이 한덩어리가 됨
			year++;
			for (int i = 0; i < N; i++) { // 녹은 빙산 일괄 적용
				for (int j = 0; j < M; j++) {
					iceLand[i][j] = tmpLand[i][j];
				}
			}

		} // end of while

		if (isMelt)	// 다 녹았다면 0 
			System.out.println(0);
		else		//	아니라면 최초 시간 출력
			System.out.println(year);
	} // end of main
} // end of class

class Pair {
	int x, y;

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}

}