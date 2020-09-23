import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 2304
문제 제목 : 창고 다각형
풀이 날짜 : 2020-09-24
Solved By Reamer
*/
public class acm_2304 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		List<Pair> list = new ArrayList<Pair>();
		Stack<Pair> stack = new Stack<Pair>();
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken());
			int H = Integer.parseInt(st.nextToken());
			list.add(new Pair(X, H));
		}
		Collections.sort(list, new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				return o1.X - o2.X;
			}
		});
		int sum = 0;
		for (Pair p : list) {
			if (stack.empty()) {
				stack.push(p);
			} else {
				if (stack.peek().H < p.H) {

					Pair removedP = null;
					while (!stack.empty() && stack.peek().H < p.H) {
						removedP = stack.pop();
					}
					if (stack.empty()) {
						sum += (p.X - removedP.X) * removedP.H;
					}
				}
				stack.push(p);
			}
		}
		Pair prevP = null;
		while (!stack.empty()) {
			if (prevP == null) {
				prevP = stack.pop();
			} else {
				Pair curP = stack.pop();
				sum += (prevP.X - curP.X) * prevP.H;
				prevP = curP;
			}
		}
		sum += prevP.H;

		System.out.println(sum);

	}

	static class Pair {
		int X, H;

		public Pair(int x, int h) {
			super();
			X = x;
			H = h;
		}
	}
}
