import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

/*
난이도 : D4
문제 번호 : 1868
문제 제목 : 파핑파핑 지뢰찾기
풀이 날짜 : 2020-11-05
Solved By Reamer
*/

public class sw_1868 {
	private static char[][] map;

	private static int[] dx = { -1, -1, 0, 1, 1, 1, 0, -1 };
	private static int[] dy = { 0, -1, -1, -1, 0, 1, 1, 1 };

	private static int[][] infoMap;

	private static boolean[][] isVisited;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int testCase = 1; testCase <= T; testCase++) {
			int N = Integer.parseInt(br.readLine());
			map = new char[N][N];
			infoMap = new int[N][N];
			isVisited = new boolean[N][N];
			Queue<Info> queue = new LinkedList<Info>();

			int dotCount = 0;
			for (int i = 0; i < N; i++) {
				String str = br.readLine();
				for (int j = 0; j < N; j++) {
					map[i][j] = str.charAt(j);
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] == '.') {
						dotCount++;
						int cnt = 0;
						for (int k = 0; k < 8; k++) {
							int newX = i + dx[k];
							int newY = j + dy[k];
							if (newX < 0 || newX >= N || newY < 0 || newY >= N || map[newX][newY] == '.')
								continue;
							cnt++;
						}
						infoMap[i][j] = cnt;
					} else {
						infoMap[i][j] = -1;
					}

				}
			}

			int total = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (!isVisited[i][j] && infoMap[i][j] == 0) {
						total++;
						queue.offer(new Info(i, j));
						isVisited[i][j] = true;
						while (!queue.isEmpty()) {
							Info info = queue.poll();
							dotCount--;
							if (infoMap[info.x][info.y] != 0)
								continue;

							for (int k = 0; k < 8; k++) {
								int newX = info.x + dx[k];
								int newY = info.y + dy[k];
								if (newX < 0 || newX >= N || newY < 0 || newY >= N || isVisited[newX][newY]
										|| map[newX][newY] == '*')
									continue;

								isVisited[newX][newY] = true;
								queue.offer(new Info(newX, newY));
							}

						}

					}
				}
			}
			sb.append("#").append(testCase).append(" ").append(total + dotCount).append("\n");
		}
		System.out.println(sb);
	}

	static class Info {
		int x, y;

		public Info(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}
}
