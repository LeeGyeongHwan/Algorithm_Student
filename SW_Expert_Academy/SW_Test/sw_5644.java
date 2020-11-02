import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/*
난이도 : SW Test
문제 번호 : 5644
문제 제목 : 무선 충전
풀이 날짜 : 2020-11-02
Solved By Reamer
*/

public class SW5644 {

	static int[] dx = { 0, -1, 0, 1, 0 };
	static int[] dy = { 0, 0, 1, 0, -1 };

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		List<Integer> listA, listB;
		int[][] map;
		int[] infoA, infoB, charge;

		for (int testCase = 1; testCase <= T; testCase++) {
			map = new int[11][11];
			st = new StringTokenizer(br.readLine());
			int M = Integer.parseInt(st.nextToken());
			int A = Integer.parseInt(st.nextToken());
			infoA = new int[M + 1];
			infoB = new int[M + 1];
			charge = new int[A + 1];
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= M; i++) {
				infoA[i] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= M; i++) {
				infoB[i] = Integer.parseInt(st.nextToken());
			}

			for (int i = 1; i <= A; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				int p = Integer.parseInt(st.nextToken());

				for (int j = c * -1; j <= c; j++) {
					for (int k = (c - Math.abs(j)) * -1; k <= c - Math.abs(j); k++) {
						if (x + j > 10 || x + j <= 0 || y + k > 10 || y + k <= 0)
							continue;
						map[x + j][y + k] |= (1 << i);
					}
				}
				charge[i] = p;
			}
			
			int answer = 0;
			int aX = 1, aY = 1;
			int bX = 10, bY = 10;

			for (int i = 0; i <= M; i++) {
				aX += dx[infoA[i]];
				aY += dy[infoA[i]];
				bX += dx[infoB[i]];
				bY += dy[infoB[i]];
				int chargeA = map[aY][aX];
				int chargeB = map[bY][bX];
				// 최대한 다른것 또는 반으로했을때 최댓값
				if (chargeA != 0 && chargeB != 0) {
					listA = new ArrayList<Integer>();
					listB = new ArrayList<Integer>();
					for (int j = 1; j <= A; j++) {
						if ((chargeA & (1 << j)) > 0) {
							listA.add(j);
						}
						if ((chargeB & (1 << j)) > 0) {
							listB.add(j);
						}
					}
					int maxSum = 0;
					for (int j = 0; j < listA.size(); j++) {
						for (int k = 0; k < listB.size(); k++) {
							int tmpSum = 0;
							if (listA.get(j) == listB.get(k)) {
								tmpSum = charge[listA.get(j)];
							} else {
								tmpSum = charge[listA.get(j)] + charge[listB.get(k)];
							}
							if (tmpSum > maxSum)
								maxSum = tmpSum;
						}
					}
					answer += maxSum;

				} else if (chargeA != 0) {
					int maxP = 0;
					for (int j = 1; j <= A; j++) {
						if ((chargeA & (1 << j)) > 0) {
							if (charge[j] > maxP)
								maxP = charge[j];
						}
					}
					answer += maxP;
				} else if (chargeB != 0) {
					int maxP = 0;
					for (int j = 1; j <= A; j++) {
						if ((chargeB & (1 << j)) > 0) {
							if (charge[j] > maxP)
								maxP = charge[j];
						}
					}
					answer += maxP;
				}
			}
			System.out.println("#" + testCase + " " + answer);
		}
	}
}
