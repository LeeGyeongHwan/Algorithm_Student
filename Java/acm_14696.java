import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 14696
문제 제목 : 딱지놀이
풀이 날짜 : 2020-09-22
Solved By Reamer
*/
public class acm_14696 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		StringTokenizer st;
		es: for (int i = 0; i < N; i++) {
			int[] cardA = new int[4];
			int[] cardB = new int[4];
			st = new StringTokenizer(br.readLine());
			int K = Integer.parseInt(st.nextToken());
			for (int j = 0; j < K; j++) {
				int tmp = Integer.parseInt(st.nextToken());
				cardA[tmp - 1]++;
			}

			st = new StringTokenizer(br.readLine());
			K = Integer.parseInt(st.nextToken());
			for (int j = 0; j < K; j++) {
				int tmp = Integer.parseInt(st.nextToken());
				cardB[tmp - 1]++;
			}

			for (int j = 3; j >= 0; j--) {
				if (cardA[j] > cardB[j]) {
					System.out.println("A");
					continue es;
				} else if (cardA[j] < cardB[j]) {
					System.out.println("B");
					continue es;
				}
			}
			System.out.println("D");
		}
	}
}
