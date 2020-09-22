import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 2628
문제 제목 : 종이자르기 
풀이 날짜 : 2020-09-22
Solved By Reamer
*/
public class acm_2628 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());

		int[] horizon = new int[M + 1];
		int[] vertical = new int[N + 1];

		int K = Integer.parseInt(br.readLine());

		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int mode = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());

			if (mode == 0) {
				vertical[num] = 1;
			} else {
				horizon[num] = 1;
			}
		}
		
		int start = 0;
		int maxWidth = 0;
		for (int i = 0; i <= M; i++) {
			if (horizon[i] == 1) {
				if (maxWidth < i - start) {
					maxWidth = i - start;
				}
				start = i;
			}
		}
		if (maxWidth < M - start)
			maxWidth = M - start;

		start = 0;
		int maxHeight = 0;

		for (int i = 0; i <= N; i++) {
			if (vertical[i] == 1) {
				if (maxHeight < i - start) {
					maxHeight = i - start;
				}
				start = i;
			}
		}
		if (maxHeight < N - start) {
			maxHeight = N - start;
		}
		System.out.println(maxWidth * maxHeight);
	}

}
