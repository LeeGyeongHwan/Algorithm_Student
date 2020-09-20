import java.util.Scanner;
/*
ACMICPC
문제 번호 : 10157
문제 제목 : 자리배정
풀이 날짜 : 2020-09-20
Solved By Reamer
*/
public class acm_10157 {
	static int[] dx = { 1, 0, -1, 0 };
	static int[] dy = { 0, 1, 0, -1 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int C = sc.nextInt();
		int R = sc.nextInt();
		int K = sc.nextInt();

		int[][] concert = new int[R][C];
		boolean[][] isVisited = new boolean[R][C];

		if (K > R * C) {
			System.out.println(0);
			System.exit(0);
		}
		int dir = 0;
		int x = 0, y = 0;
		int cnt = 1;
		while (true) {
			if (cnt == K)
				break;
			isVisited[x][y] = true;
			int newX = x + dx[dir];
			int newY = y + dy[dir];
			if (newX < 0 || newX >= R || newY < 0 || newY >= C || isVisited[newX][newY]) {
				dir = (dir + 1) % 4;
				newX = x + dx[dir];
				newY = y + dy[dir];
			}
			x = newX;
			y = newY;
			cnt++;
		}
		System.out.println((y + 1) + " " + (x + 1));

	}
}
