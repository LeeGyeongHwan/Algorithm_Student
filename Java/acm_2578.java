import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 2578
문제 제목 : 빙고
풀이 날짜 : 2020-09-18
Solved By Reamer
*/
public class acm_2578 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int[][] userBingo = new int[5][5];
		int[] order = new int[25];

		StringTokenizer st;
		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++) {
				userBingo[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < 5; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 5; j++) {
				order[5 * i + j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < order.length; i++) {
			es: for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (userBingo[j][k] == order[i]) {
						userBingo[j][k] = 0;
						break es;
					}
				}
			}
			int bingoCnt = 0;
			int[] colSum = new int[5];
			int leftCross = 0, rightCross = 0;
			for (int j = 0; j < 5; j++) {
				int rowSum = 0;
				for (int k = 0; k < 5; k++) {
					if (j == k)
						leftCross += userBingo[j][k];
					if (j == 4 - k)
						rightCross += userBingo[j][k];
					rowSum += userBingo[j][k];
					colSum[k] += userBingo[j][k];
				}
				if (rowSum == 0)
					bingoCnt++;
			}
			if (leftCross == 0)
				bingoCnt++;
			if (rightCross == 0)
				bingoCnt++;
			for (int j = 0; j < colSum.length; j++) {
				if (colSum[j] == 0)
					bingoCnt++;
			}
			if (bingoCnt >= 3) {
				System.out.println(i + 1);
				System.exit(0);
			}

		}
	}
}
