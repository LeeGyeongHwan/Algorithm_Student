import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 13300
문제 제목 : 방 배정
풀이 날짜 : 2020-09-22
Solved By Reamer
*/
public class acm_13300 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int[][] people = new int[6][2];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int S = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			people[Y - 1][S]++;
		}

		int room = 0;
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 2; k++) {
				if (people[j][k] == 0)
					continue;
				else {
					room += people[j][k] / K;
					if (people[j][k] % K != 0)
						room++;
				}
			}
		}
		System.out.println(room);

	}
}
