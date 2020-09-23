import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
/*
ACMICPC
문제 번호 : 1244
문제 제목 : 스위치 켜고 끄기 
풀이 날짜 : 2020-09-23
Solved By Reamer
*/
public class acm_1244 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] switchArr = new int[N + 1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) 
			switchArr[i] = Integer.parseInt(st.nextToken());
		int student = Integer.parseInt(br.readLine());
		for (int i = 0; i < student; i++) {
			st = new StringTokenizer(br.readLine());
			int sex = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			if (sex == 1) {// 남자
				int tmp = num;
				while (tmp <= N) {
					switchArr[tmp] = switchArr[tmp] == 0 ? 1 : 0;
					tmp += num;
				}
			} else {// 여자
				int start = num, end = num;
				while (true) {
					if (start - 1 > 0 && end + 1 <= N && switchArr[start - 1] == switchArr[end + 1]) {
						start--;
						end++;
					} else
						break;
				}
				for (int j = start; j <= end; j++) 
					switchArr[j] = switchArr[j] == 0 ? 1 : 0;
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= N; i++) {
			sb.append(switchArr[i]);
			if (i % 20 != 0)
				sb.append(" ");
			else
				sb.append("\n");
		}
		System.out.println(sb);
	}
}
