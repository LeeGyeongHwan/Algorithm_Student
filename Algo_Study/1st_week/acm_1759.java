package com.ssafy.algo;

import java.util.Arrays;
import java.util.Scanner;

/* 
ACMICPC
Study Group
1st Week
문제 번호 : 1759
문제 제목 : 암호 만들기
풀이 날짜 : 2020-08-01
Solved By Reamer 
*/

public class acm_1759 {

	public static int L;
	private static char[] charArr;
	private static boolean[] isVisit;
	static StringBuilder sb = new StringBuilder();
	private static int C;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		L = sc.nextInt();
		C = sc.nextInt();

		charArr = new char[C];
		isVisit = new boolean[C];

		for (int i = 0; i < C; i++) {
			charArr[i] = sc.next().charAt(0);
		}

		Arrays.sort(charArr);

		recur(0,0);

		System.out.println(sb.toString());

		sc.close();
	}// end of main

	public static void recur(int cnt,int index) {

		if (cnt == L) {
			int countVowel = 0;
			int countCon = 0;
			String str = "";
			for (int i = 0; i < isVisit.length; i++) {
				if (isVisit[i]) {
					str += charArr[i];
					if (charArr[i] == 'a' || charArr[i] == 'e' || charArr[i] == 'i' || charArr[i] == 'o'
							|| charArr[i] == 'u')
						countVowel++;
					else
						countCon++;
				}
			}
			if (countVowel >= 1 && countCon >= 2)
				sb.append(str).append("\n");
			return;
		}
		for (int i = index; i < C; i++) {
			if (isVisit[i])
				continue;
			isVisit[i] = true;
			recur(cnt + 1,i+1);
			isVisit[i] = false;
		}
	}	
}// end of class
