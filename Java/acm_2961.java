package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 2961
문제 제목 : 도영이가 만든 맛있는 음식
풀이 날짜 : 2020-08-06
Solved By Reamer 
*/

public class acm_2961 {

	static class Taste {
		int s, b;

		public Taste(int s, int b) {
			super();
			this.s = s;
			this.b = b;
		}
	}

	private static Taste[] taste;
	private static boolean[] comb;
	private static int N;
	private static int minCook = 1000000001;

	private static void cook(int cnt) {
		if (cnt == N) {
			int mulS = 1;
			int sumB = 0;
			int numCook=0;
			for (int i = 0; i < N; i++) {
				if (comb[i]) {
					numCook++;
					mulS *= taste[i].s;
					sumB += taste[i].b;
				}
			}
			if(numCook == 0) 
				return;
			int num = Math.abs(mulS - sumB);
			if (num < minCook)
				minCook = num;
			return;
		}

		comb[cnt] = true;
		cook(cnt + 1);
		comb[cnt] = false;
		cook(cnt + 1);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		taste = new Taste[N];
		comb = new boolean[N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int sour = Integer.parseInt(st.nextToken());
			int bitter = Integer.parseInt(st.nextToken());
			taste[i] = new Taste(sour, bitter);
		}

		cook(0);
		System.out.println(minCook);
	}
}
