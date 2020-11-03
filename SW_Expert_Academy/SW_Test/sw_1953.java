import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
난이도 : SW Test
문제 번호 : 1953
문제 제목 : 탈주범 검거
풀이 날짜 : 2020-11-03
Solved By Reamer
*/

public class sw_1953 {
	private static int[][] map;
	private static boolean[][] isVisited;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());

		for (int testCase = 1; testCase <= T; testCase++) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int R = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());

			map = new int[N][M];
			isVisited = new boolean[N][M];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < M; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			Queue<Pair1953> queue = new LinkedList<Pair1953>();

			queue.offer(new Pair1953(R, C));
			isVisited[R][C] = true;

			int answer = 0;

			for (int i = 0; i < L; i++) {
				int size = queue.size();
				for (int j = 0; j < size; j++) {
					answer++;
					Pair1953 pair = queue.poll();

					switch (map[pair.x][pair.y]) {
					case 1:
						if (pair.x - 1 >= 0 && !isVisited[pair.x - 1][pair.y]
								&& (map[pair.x - 1][pair.y] == 1 || map[pair.x - 1][pair.y] == 2
										|| map[pair.x - 1][pair.y] == 5 || map[pair.x - 1][pair.y] == 6)) {
							isVisited[pair.x - 1][pair.y] = true;
							queue.offer(new Pair1953(pair.x - 1, pair.y));
						}
						if (pair.y - 1 >= 0 && !isVisited[pair.x][pair.y - 1]
								&& (map[pair.x][pair.y - 1] == 1 || map[pair.x][pair.y - 1] == 3
										|| map[pair.x][pair.y - 1] == 4 || map[pair.x][pair.y - 1] == 5)) {
							isVisited[pair.x][pair.y - 1] = true;
							queue.offer(new Pair1953(pair.x, pair.y - 1));
						}
						if (pair.x + 1 < N && !isVisited[pair.x + 1][pair.y]
								&& (map[pair.x + 1][pair.y] == 1 || map[pair.x + 1][pair.y] == 2
										|| map[pair.x + 1][pair.y] == 4 || map[pair.x + 1][pair.y] == 7)) {
							isVisited[pair.x + 1][pair.y] = true;
							queue.offer(new Pair1953(pair.x + 1, pair.y));
						}
						if (pair.y + 1 < M && !isVisited[pair.x][pair.y + 1]
								&& (map[pair.x][pair.y + 1] == 1 || map[pair.x][pair.y + 1] == 3
										|| map[pair.x][pair.y + 1] == 6 || map[pair.x][pair.y + 1] == 7)) {
							isVisited[pair.x][pair.y + 1] = true;
							queue.offer(new Pair1953(pair.x, pair.y + 1));
						}
						break;
					case 2:
						if (pair.x - 1 >= 0 && !isVisited[pair.x - 1][pair.y]
								&& (map[pair.x - 1][pair.y] == 1 || map[pair.x - 1][pair.y] == 2
										|| map[pair.x - 1][pair.y] == 5 || map[pair.x - 1][pair.y] == 6)) {
							isVisited[pair.x - 1][pair.y] = true;
							queue.offer(new Pair1953(pair.x - 1, pair.y));
						}
						if (pair.x + 1 < N && !isVisited[pair.x + 1][pair.y]
								&& (map[pair.x + 1][pair.y] == 1 || map[pair.x + 1][pair.y] == 2
										|| map[pair.x + 1][pair.y] == 4 || map[pair.x + 1][pair.y] == 7)) {
							isVisited[pair.x + 1][pair.y] = true;
							queue.offer(new Pair1953(pair.x + 1, pair.y));
						}
						break;
					case 3:
						if (pair.y - 1 >= 0 && !isVisited[pair.x][pair.y - 1]
								&& (map[pair.x][pair.y - 1] == 1 || map[pair.x][pair.y - 1] == 3
										|| map[pair.x][pair.y - 1] == 4 || map[pair.x][pair.y - 1] == 5)) {
							isVisited[pair.x][pair.y - 1] = true;
							queue.offer(new Pair1953(pair.x, pair.y - 1));
						}
						if (pair.y + 1 < M && !isVisited[pair.x][pair.y + 1]
								&& (map[pair.x][pair.y + 1] == 1 || map[pair.x][pair.y + 1] == 3
										|| map[pair.x][pair.y + 1] == 6 || map[pair.x][pair.y + 1] == 7)) {
							isVisited[pair.x][pair.y + 1] = true;
							queue.offer(new Pair1953(pair.x, pair.y + 1));
						}
						break;
					case 4:
						if (pair.x - 1 >= 0 && !isVisited[pair.x - 1][pair.y]
								&& (map[pair.x - 1][pair.y] == 1 || map[pair.x - 1][pair.y] == 2
										|| map[pair.x - 1][pair.y] == 5 || map[pair.x - 1][pair.y] == 6)) {
							isVisited[pair.x - 1][pair.y] = true;
							queue.offer(new Pair1953(pair.x - 1, pair.y));
						}
						if (pair.y + 1 < M && !isVisited[pair.x][pair.y + 1]
								&& (map[pair.x][pair.y + 1] == 1 || map[pair.x][pair.y + 1] == 3
										|| map[pair.x][pair.y + 1] == 6 || map[pair.x][pair.y + 1] == 7)) {
							isVisited[pair.x][pair.y + 1] = true;
							queue.offer(new Pair1953(pair.x, pair.y + 1));
						}
						break;
					case 5:
						if (pair.y + 1 < M && !isVisited[pair.x][pair.y + 1]
								&& (map[pair.x][pair.y + 1] == 1 || map[pair.x][pair.y + 1] == 3
										|| map[pair.x][pair.y + 1] == 6 || map[pair.x][pair.y + 1] == 7)) {
							isVisited[pair.x][pair.y + 1] = true;
							queue.offer(new Pair1953(pair.x, pair.y + 1));
						}
						if (pair.x + 1 < N && !isVisited[pair.x + 1][pair.y]
								&& (map[pair.x + 1][pair.y] == 1 || map[pair.x + 1][pair.y] == 2
										|| map[pair.x + 1][pair.y] == 4 || map[pair.x + 1][pair.y] == 7)) {
							isVisited[pair.x + 1][pair.y] = true;
							queue.offer(new Pair1953(pair.x + 1, pair.y));
						}
						break;
					case 6:
						if (pair.x + 1 < N && !isVisited[pair.x + 1][pair.y]
								&& (map[pair.x + 1][pair.y] == 1 || map[pair.x + 1][pair.y] == 2
										|| map[pair.x + 1][pair.y] == 4 || map[pair.x + 1][pair.y] == 7)) {
							isVisited[pair.x + 1][pair.y] = true;
							queue.offer(new Pair1953(pair.x + 1, pair.y));
						}
						if (pair.y - 1 >= 0 && !isVisited[pair.x][pair.y - 1]
								&& (map[pair.x][pair.y - 1] == 1 || map[pair.x][pair.y - 1] == 3
										|| map[pair.x][pair.y - 1] == 4 || map[pair.x][pair.y - 1] == 5)) {
							isVisited[pair.x][pair.y - 1] = true;
							queue.offer(new Pair1953(pair.x, pair.y - 1));
						}
						break;
					case 7:
						if (pair.y - 1 >= 0 && !isVisited[pair.x][pair.y - 1]
								&& (map[pair.x][pair.y - 1] == 1 || map[pair.x][pair.y - 1] == 3
										|| map[pair.x][pair.y - 1] == 4 || map[pair.x][pair.y - 1] == 5)) {
							isVisited[pair.x][pair.y - 1] = true;
							queue.offer(new Pair1953(pair.x, pair.y - 1));
						}
						if (pair.x - 1 >= 0 && !isVisited[pair.x - 1][pair.y]
								&& (map[pair.x - 1][pair.y] == 1 || map[pair.x - 1][pair.y] == 2
										|| map[pair.x - 1][pair.y] == 5 || map[pair.x - 1][pair.y] == 6)) {
							isVisited[pair.x - 1][pair.y] = true;
							queue.offer(new Pair1953(pair.x - 1, pair.y));
						}
						break;
					}

				}
			}
			System.out.println("#" + testCase + " " + answer);
		}
	}

	static class Pair1953 {
		int x, y;

		public Pair1953(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}
}
