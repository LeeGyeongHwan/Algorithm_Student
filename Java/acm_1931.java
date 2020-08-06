package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 1931
문제 제목 : 회의실배정
풀이 날짜 : 2020-08-06
Solved By Reamer 
*/

public class acm_1931 {

	static class Pair implements Comparable<Pair> {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int compareTo(Pair o) {
			if (this.y == o.y)
				return this.x - o.x;
			return this.y - o.y;
		}

		public String toString() {
			return "Pair [x=" + x + ", y=" + y + "]";
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N = Integer.parseInt(br.readLine());
		Pair[] pair = new Pair[N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			pair[i] = new Pair(from, to);
		}

		Arrays.sort(pair);

		int cnt = 1;
		int prevStart = pair[0].x;
		int prevEnd = pair[0].y;
		for (int i = 1; i < N; i++) {
			if (pair[i].x >= prevEnd) {
				prevStart = pair[i].x;
				prevEnd = pair[i].y;
				cnt++;
			}
		}
		System.out.println(cnt);
	}

}
