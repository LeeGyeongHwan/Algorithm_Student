package com.swexpert;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
난이도 : SW Test
문제 번호 : 4013
문제 제목 : 특이한 자석
풀이 날짜 : 2020-11-04
Solved By Reamer
*/

public class SW4013 {
	private static int[][] magnet;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();

		int T = Integer.parseInt(br.readLine());

		for (int testCase = 1; testCase <= T; testCase++) {
			int K = Integer.parseInt(br.readLine());

			magnet = new int[4][8];

			for (int i = 0; i < 4; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < 8; j++) {
					magnet[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				int num = Integer.parseInt(st.nextToken());
				int dir = Integer.parseInt(st.nextToken());
				rotate(num - 1, dir, 0);
			}
			int sum = 0;
			for (int i = 0; i < 4; i++) {
				if (magnet[i][0] == 1)
					sum += (1 << i);
			}
			sb.append("#").append(testCase).append(" ").append(sum).append("\n");
		}
		System.out.println(sb);
	}

	private static void rotate(int num, int dir, int way) {
		if (num - 1 >= 0 && way != 1 && magnet[num - 1][2] != magnet[num][6]) {
			rotate(num - 1, dir * (-1), -1);
		}
		if (num + 1 < 4 && way != -1 && magnet[num + 1][6] != magnet[num][2]) {
			rotate(num + 1, dir * (-1), 1);
		}
		if (dir == 1)
			rotateRight(num);
		else
			rotateLeft(num);
	}

	private static void rotateRight(int num) {
		int tmp = magnet[num][7];
		for (int i = 7; i > 0; i--) {
			magnet[num][i] = magnet[num][i - 1];
		}
		magnet[num][0] = tmp;
	}

	private static void rotateLeft(int num) {
		int tmp = magnet[num][0];
		for (int i = 0; i < 7; i++) {
			magnet[num][i] = magnet[num][i + 1];
		}
		magnet[num][7] = tmp;
	}

}
