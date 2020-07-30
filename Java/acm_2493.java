package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 2493
문제 제목 : 탑
풀이 날짜 : 2020-07-30
Solved By Reamer 
*/

public class acm_2493 {
	static boolean isStop;
	private static int tmp;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		Stack<Integer> stack = new Stack<Integer>();
		Stack<Integer> indexS = new Stack<Integer>();
		int top = Integer.parseInt(br.readLine());
		
		int[] answer = new int[top];
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < top; i++) {
			int num = Integer.parseInt(st.nextToken());
			
			while(!stack.empty()) {
				if(stack.peek()>num) {
					answer[i] = indexS.peek()+1;
					break;
				} else {
					stack.pop();
					indexS.pop();
				}
			}
			
			stack.push(num);
			indexS.push(i);
		}
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < answer.length; i++) {
			sb.append(answer[i]).append(" ");
		}

		System.out.println(sb.toString());

	}
}