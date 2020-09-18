import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/*
ACMICPC
문제 번호 : 2309
문제 제목 : 일곱 난쟁이
풀이 날짜 : 2020-09-18
Solved By Reamer
*/
public class acm_2309 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		List<Integer> list = new ArrayList<Integer>();
		int[] dwarf = new int[9];
		int heightSum = 0;
		for (int i = 0; i < 9; i++) {
			dwarf[i] = sc.nextInt();
			heightSum += dwarf[i];
		}

		es: for (int i = 0; i < 8; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (heightSum - dwarf[i] - dwarf[j] == 100) {
					dwarf[i] = 0;
					dwarf[j] = 0;
					break es;
				}
			}
		}

		Arrays.sort(dwarf);
		for (int i = 2; i < dwarf.length; i++) {
			System.out.println(dwarf[i]);
		}

	}
}
