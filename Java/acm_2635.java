import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
ACMICPC
문제 번호 : 2635
문제 제목 : 수 이어가기 
풀이 날짜 : 2020-09-23
Solved By Reamer
*/
public class acm_2635 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		List<Integer> list, longestList = null;

		int maxLength = 0;

		for (int i = N / 2; i <= N; i++) {
			list = new ArrayList<Integer>();
			list.add(N);
			list.add(i);

			int length = 2;
			while (true) {
				int tmp = list.get(length - 2) - list.get(length - 1);
				if (tmp < 0) {
					if (length > maxLength) {
						maxLength = length;
						longestList = list;
					}
					break;
				}
				list.add(tmp);
				length++;
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append(maxLength).append("\n");
		for (int a : longestList) {
			sb.append(a).append(" ");
		}
		System.out.println(sb);

	}
}
