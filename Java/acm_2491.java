import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 2491
문제 제목 : 수열
풀이 날짜 : 2020-09-19
Solved By Reamer
*/
public class acm_2491 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] numArr = new int[N];
		for (int i = 0; i < N; i++) {
			numArr[i] = Integer.parseInt(st.nextToken());
		}

		int start = 0, end = 1;
		int maxASClength = 1;

		while (true) {
			if (end == N) {
				int length = end - start;
				if (maxASClength < length)
					maxASClength = length;
				break;
			}
			if (numArr[end] >= numArr[end - 1]) {
				end++;
			} else {
				int length = end - start;
				if (maxASClength < length)
					maxASClength = length;
				start = end;
				end++;
			}
		}
		start = 0;
		end = 1;
		int maxDESClength = 1;

		while (true) {
			if (end == N) {
				int length = end - start;
				if (maxDESClength < length)
					maxDESClength = length;
				break;
			}
			if (numArr[end] <= numArr[end - 1]) {
				end++;
			} else {
				int length = end - start;
				if (maxDESClength < length)
					maxDESClength = length;
				start = end;
				end++;
			}
		}
		int answer = maxASClength > maxDESClength ? maxASClength : maxDESClength;

		System.out.println(answer);
	}
}
