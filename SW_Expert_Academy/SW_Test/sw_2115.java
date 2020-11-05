import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
난이도 : SW Test
문제 번호 : 2115
문제 제목 : 벌꿀채취
풀이 날짜 : 2020-11-05
Solved By Reamer
*/

public class sw_2115 {
	private static int[][] map;
	private static int[] order;
	private static int N, M, C;
	private static int maxSum;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int testCase = 1; testCase <= T; testCase++) {
			st = new StringTokenizer(br.readLine());

			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());

			map = new int[N][N];
			order = new int[2];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			maxSum = 0;
			findMax(0, 0);

			sb.append("#").append(testCase).append(" ").append(maxSum).append("\n");
		}
		System.out.println(sb);

	}

	private static void findMax(int cnt, int start) {
		if (cnt == 2) {
			int total = 0;
			for (int i = 0; i < cnt; i++) {
				int x = order[i] / N;
				int y = order[i] % N;
				int tmpSum = 0;
				int tmpProfit = 0;
				for (int j = 0; j < M; j++) {
					tmpSum += map[x][y + j];
					tmpProfit += map[x][y + j] * map[x][y + j];
				}
				if (tmpSum <= C)
					total += tmpProfit;
				else {
					int tmpMax = 0;
					for (int j = 0; j < (1 << M); j++) {
						tmpSum = 0;
						tmpProfit = 0;
						for (int k = 0; k < M; k++) {
							if ((j & (1 << k)) != 0) {
								tmpSum += map[x][y + k];
								tmpProfit += map[x][y + k] * map[x][y + k];
							}
						}
						if (tmpSum <= C && tmpMax < tmpProfit)
							tmpMax = tmpProfit;
					}
					total += tmpMax;
				}
			}
			
			if (maxSum < total)
				maxSum = total;
			return;
		}

		for (int i = start; i < N * N; i++) {

			int x = i / N;
			int y = i % N;
			if (y + M <= N) {
				order[cnt] = i;
				if (y + M + M <= N)
					findMax(cnt + 1, i + M);
				else
					findMax(cnt + 1, (x + 1) * N);
			}

		}
	}

}
