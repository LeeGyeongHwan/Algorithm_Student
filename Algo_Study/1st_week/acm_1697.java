package com.acmicpc;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/* 
ACMICPC
Study Group
1st Week
문제 번호 : 1698
문제 제목 : 숨바꼭질
풀이 날짜 : 2020-07-31
Solved By Reamer 
*/

public class acm_1697 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean[] isVisit = new boolean[100001];
		Queue<move> q = new LinkedList<move>();
		int N = sc.nextInt();
		int K = sc.nextInt();

		q.offer(new move(N, 0));
		isVisit[N] = true;
		int timer = 0;

		while (!q.isEmpty()) {
			move m = q.poll();
			int newL = m.getLocation();
			int newT = m.getTime();

			if (newL == K) {
				timer = newT;
				break;
			}
			
			if(newL-1>=0 && !isVisit[newL-1]) {
				isVisit[newL-1] = true;
				q.offer(new move(newL-1,newT+1));
			}
			if(newL+1<=100000 && !isVisit[newL+1]) {
				isVisit[newL+1] = true;
				q.offer(new move(newL+1,newT+1));
			}
			if(newL+newL<=100000 && !isVisit[newL+newL]) {
				isVisit[newL+newL] = true;
				q.offer(new move(newL+newL,newT+1));
			}
		}
		
		System.out.println(timer);
		sc.close();
	}
}

class move {
	private int location, time;

	move(int location, int time) {
		this.location = location;
		this.time = time;
	}

	public int getLocation() {
		return location;
	}

	public void setLocation(int location) {
		this.location = location;
	}

	public int getTime() {
		return time;
	}

	public void setTime(int time) {
		this.time = time;
	}
}