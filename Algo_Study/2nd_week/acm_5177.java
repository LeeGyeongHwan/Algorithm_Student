package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/* 
ACMICPC
Study Group
2nd Week
문제 번호 : 5177
문제 제목 : 출력 형식이 잘못되었습니다
풀이 날짜 : 2020-08-10
Solved By Reamer 
*/

public class acm_5177 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		for (int testCase = 1; testCase <= T; testCase++) {
			String str1 = br.readLine();
			String str2 = br.readLine();

			str1 = str1.trim();
			str2 = str2.trim();

			int idx1 = 0, idx2 = 0;
			boolean isSame = true;
			boolean isSpace1 = false;
			boolean isSpace2 = false;
			boolean isAlphabet = false;
			while (idx1 < str1.length() && idx2 < str2.length()) {
				char char1 = str1.charAt(idx1);
				char char2 = str2.charAt(idx2);
				if (char1 == char2) {
					if ((char1 >= 'A' && char1 <= 'Z') || (char1 >= 'a' && char1 <= 'z')) {
						if (isAlphabet && (isSpace1 ^ isSpace2)) {
							isSame = false;
							break;
						}
						isAlphabet = true;
					} else if (char1 == ' ') {
						while (char1 == ' ') {
							idx1++;
							char1 = str1.charAt(idx1);
							isSpace1 = true;
						}
						while (char2 == ' ') {
							idx2++;
							char2 = str2.charAt(idx2);
							isSpace2 = true;
						}
						continue;
					} else if (char1 >= '0' && char1 <= '9') {
						isAlphabet = false;
					} else { // 특수문자
						isAlphabet = false;
					}
					idx1++;
					idx2++;

				} else if (((char1 >= 'A' && char1 <= 'Z') || (char1 >= 'a' && char1 <= 'z'))
						&& ((char2 >= 'A' && char2 <= 'Z') || (char2 >= 'a' && char2 <= 'z'))) {

					if (isAlphabet && (isSpace1 ^ isSpace2)) {
						isSame = false;
						break;
					}
					int num = Math.abs(char1 - char2);
					if (num == 0 || num == 32) {// same
						idx1++;
						idx2++;
					} else {
						isSame = false;
						break;
					}
					isAlphabet = true;

				} else if (char1 == ' ' || char2 == ' ') {
					while (char1 == ' ') {
						idx1++;
						char1 = str1.charAt(idx1);
						isSpace1 = true;
					}
					while (char2 == ' ') {
						idx2++;
						char2 = str2.charAt(idx2);
						isSpace2 = true;
					}
					continue;
				} else {
					if ((char1 == '(' || char1 == '[' || char1 == '{')
							&& (char2 == '(' || char2 == '[' || char2 == '{')) {
						idx1++;
						idx2++;
					} else if ((char1 == ')' || char1 == '}' || char1 == ']')
							&& (char2 == ')' || char2 == '}' || char2 == ']')) {
						idx1++;
						idx2++;
					} else if ((char1 == ',' || char1 == ';') && (char2 == ',' || char2 == ';')) {
						idx1++;
						idx2++;
					} else {
						isSame = false;
						break;

					}
					isAlphabet = false;
				}
				isSpace1 = false;
				isSpace2 = false;
			}
			if (!(idx1 == str1.length() && idx2 == str2.length()))
				isSame = false;
			sb.append("Data Set ").append(testCase).append(": ");
			if (!isSame)
				sb.append("not ");
			sb.append("equal\n\n");

		} // end of for(testCase)
		System.out.println(sb);
	}
}
