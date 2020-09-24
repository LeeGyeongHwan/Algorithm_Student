import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
ACMICPC
문제 번호 : 10158
문제 제목 : 개미
풀이 날짜 : 2020-09-24
Solved By Reamer
*/
public class acm_10158 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int w = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int p = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());

		int t = Integer.parseInt(br.readLine());

		int remainedX = t % (2 * w);
		int remainedY = t % (2 * h);

		p += remainedX;
		if (p / w == 1)
			
			p = w - p % w;
		else
			p = p % w;
		q += remainedY;
		if (q / h == 1)
			q = h - q % h;
		else
			q = q % h;

		System.out.println(p + " " + q);
	}
}
