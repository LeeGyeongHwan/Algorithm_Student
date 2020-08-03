package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 1406
문제 제목 : 에디터 
풀이 날짜 : 2020-08-03
Solved By Reamer 
*/

public class acm_1406 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String str = br.readLine();
		int M = Integer.parseInt(br.readLine());
		
		Stack<Character> leftStack = new Stack<Character>();
		Stack<Character> rightStack = new Stack<Character>();
		for (int i = 0; i < str.length(); i++) {
			leftStack.push(str.charAt(i));
		}
		
		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			String command = st.nextToken();
			switch (command) {
			case "L":
				if(!leftStack.empty())
					rightStack.push(leftStack.pop());
				break;
			case "D":
				if(!rightStack.empty())
					leftStack.push(rightStack.pop());
				break;
			case "B":
				if(!leftStack.empty())
					leftStack.pop();
				break;
			case "P":
				char ch = st.nextToken().charAt(0);
				leftStack.push(ch);
				break;
			default:
				break;
			}
		}
		
	
		while(!leftStack.empty())
		{
			
			rightStack.push(leftStack.pop());
		}
		while(!rightStack.empty())
		{
			bw.write(rightStack.pop());
		}
		bw.write("\n");
		bw.flush();
		bw.close();
	}
}
