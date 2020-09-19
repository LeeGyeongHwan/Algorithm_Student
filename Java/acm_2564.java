import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 2564
문제 제목 : 경비원
풀이 날짜 : 2020-09-19
Solved By Reamer
*/
public class acm_2564 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(br.readLine());

		int[] dx = { N, 0, 0, 0 };
		int[] dy = { 0, 0, 0, M };
		List<Location> list = new ArrayList<Location>();

		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int dir = Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			int x = dx[dir - 1];
			int y = dy[dir - 1];
			if (dir <= 2)
				y = dist;
			else
				x = N - dist;
			list.add(new Location(x, y, dir));
		}
		st = new StringTokenizer(br.readLine());
		int dir = Integer.parseInt(st.nextToken());
		int dist = Integer.parseInt(st.nextToken());
		int x = dx[dir - 1];
		int y = dy[dir - 1];
		if (dir <= 2)
			y = dist;
		else
			x = N - dist;
		int distSum = 0;
		for (int i = 0; i < list.size(); i++) {
			if ((dir != list.get(i).dir) && (dir <= 2 && list.get(i).dir <= 2)) {
				int leftD = N + y + list.get(i).y;
				int rightD = N + M - y + M - list.get(i).y;
				if (leftD < rightD)
					distSum += leftD;
				else
					distSum += rightD;
			} else if ((dir != list.get(i).dir) && (dir > 2 && list.get(i).dir > 2)) {
				int leftD = M + x + list.get(i).x;
				int rightD = M + N - x + N - list.get(i).x;
				if (leftD < rightD)
					distSum += leftD;
				else
					distSum += rightD;
			} else {
				distSum += Math.abs(list.get(i).x - x) + Math.abs(list.get(i).y - y);
			}
		}
		System.out.println(distSum);

	}

	static class Location {
		int x, y, dir;

		public Location(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}

	}
}
