import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 2559
문제 제목 : 수열 
풀이 날짜 : 2020-09-22
Solved By Reamer
*/
public class acm_2559 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int[] arr = new int[N];
		st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int sumDegree = 0;
		for (int i = 0; i < K; i++) {
			sumDegree += arr[i];
		}
		int maxDegree = sumDegree;

		for (int i = 0; i < N - K; i++) {
			sumDegree = sumDegree + arr[i + K] - arr[i];
			if (maxDegree < sumDegree)
				maxDegree = sumDegree;
		}
		System.out.println(maxDegree);

	}
}
