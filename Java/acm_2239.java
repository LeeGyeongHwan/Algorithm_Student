package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/* 
ACMICPC 
문제 번호 : 2239
문제 제목 : 스도쿠
풀이 날짜 : 2020-11-04
Solved By Reamer 
*/

public class acm_2239 {
	private static int[][] sudoku;
	static List<Pair2239> list;
	static int zero = 0;
	private static int[] row;
	private static int[] col;
	private static int[][] box;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		list = new ArrayList<Pair2239>();

		sudoku = new int[9][9];
		row = new int[9];
		col = new int[9];
		box = new int[3][3];

		for (int i = 0; i < 9; i++) {
			String str = br.readLine();
			for (int j = 0; j < 9; j++) {
				int tmp = (int) (str.charAt(j) - '0');
				sudoku[i][j] = tmp;
				if (tmp == 0) {
					list.add(new Pair2239(i, j));
					zero++;
				} else {
					row[i] |= (1 << tmp);
					col[j] |= (1 << tmp);
					box[i / 3][j / 3] |= (1 << tmp);
				}
			}
		}

		playSudoku(0);

	}

	private static void playSudoku(int cnt) {

		if (cnt == zero) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					System.out.print(sudoku[i][j]);
				}
				System.out.println();
			}
			System.exit(0);
		}

		Pair2239 pair = list.get(cnt);

		for (int i = 1; i <= 9; i++) {
			if ((row[pair.x] & (1 << i)) == 0 && (col[pair.y] & (1 << i)) == 0
					&& (box[pair.x / 3][pair.y / 3] & (1 << i)) == 0) {
				row[pair.x] |= (1 << i);
				col[pair.y] |= (1 << i);
				box[pair.x / 3][pair.y / 3] |= (1 << i);
				sudoku[pair.x][pair.y] = i;
				playSudoku(cnt + 1);
				row[pair.x] ^= (1 << i);
				col[pair.y] ^= (1 << i);
				box[pair.x / 3][pair.y / 3] ^= (1 << i);
			}
		}
	}

	static class Pair2239 {
		int x, y;

		public Pair2239(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}
}
