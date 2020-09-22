import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 10163
문제 제목 : 색종이
풀이 날짜 : 2020-09-22
Solved By Reamer
*/
public class acm_10163 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		int[][] board = new int[101][101];
		int[] area = new int[N + 1];
		StringTokenizer st;

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int width = Integer.parseInt(st.nextToken());
			int height = Integer.parseInt(st.nextToken());
			for (int j = x1; j < x1 + width; j++) {
				for (int k = y1; k < y1 + height; k++) {
					board[j][k] = i;
				}
			}
		}
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				area[board[i][j]]++;
			}
		}
		for (int i = 1; i <= N; i++) {
			System.out.println(area[i]);
		}
	}
}
