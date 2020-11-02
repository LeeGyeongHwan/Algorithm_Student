import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
난이도 : SW Test
문제 번호 : 5656
문제 제목 : 벽돌 깨기
풀이 날짜 : 2020-11-02
Solved By Reamer
*/

public class sw_5656 {
	private static int[][] map, tmpMap;
	private static int N, W, H;
	private static int[] order;
	static Queue<Pair> queue;

	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	private static int answer;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());

		for (int testCase = 1; testCase <= T; testCase++) {
			answer = Integer.MAX_VALUE;
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());

			order = new int[N];
			map = new int[H][W];

			for (int i = 0; i < H; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < W; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			permutation(0);
			System.out.println("#" + testCase + " " + answer);
		}
	}

	private static void permutation(int cnt) {
		if (cnt == N) {
			breakWall();
			return;
		}

		for (int i = 0; i < W; i++) {
			order[cnt] = i;
			permutation(cnt + 1);
		}
	}

	private static void breakWall() {
		queue = new LinkedList<Pair>();
		tmpMap = new int[H][W];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				tmpMap[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			int dir = order[i];

			for (int j = 0; j < H; j++) {
				int power = tmpMap[j][dir];
				if (power > 0) {
					queue.offer(new Pair(j, dir, power));
					tmpMap[j][dir] = 0;
					while (!queue.isEmpty()) {
						Pair pair = queue.poll();
						for (int k = 0; k < 4; k++) {
							for (int p = 1; p < pair.power; p++) {
								int newX = pair.x + dx[k] * p;
								int newY = pair.y + dy[k] * p;
								if (newX < 0 || newX >= H || newY < 0 || newY >= W || tmpMap[newX][newY] <= 0)
									continue;
								int tmp = tmpMap[newX][newY];
								tmpMap[newX][newY] = 0;
								queue.offer(new Pair(newX, newY, tmp));
							}
						}
					}
					break;
				}
			}
			// 내리기
			for (int j = 0; j < W; j++) {
				int idx = H;
				for (int k = H - 1; k >= 0; k--) {
					if (tmpMap[k][j] <= 0 && idx == H) {
						idx = k;
					} else if (idx != H && tmpMap[k][j] > 0) {
						tmpMap[idx--][j] = tmpMap[k][j];
						tmpMap[k][j] = 0;
					}
				}
			}
		}
		// 벽 구하기
		int sum = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (tmpMap[i][j] > 0)
					sum++;

		if (answer > sum)
			answer = sum;

	}

	static class Pair {
		int x, y, power;

		public Pair(int x, int y, int power) {
			super();
			this.x = x;
			this.y = y;
			this.power = power;
		}

	}
}
