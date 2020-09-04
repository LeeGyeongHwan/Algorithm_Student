import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

/* 
ACMICPC 
문제 번호 : 18513
문제 제목 : 샘터
풀이 날짜 : 2020-09-04
Solved By Reamer 
*/

public class acm_18513 {
	static int[] dx = { -1, 1 };// x의 좌우를 확인할 배열

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);// 입력을 위한 스캐너 선언 및 초기화
		Queue<House> queue = new LinkedList<House>();// 집정보를 담을 큐
		Set<Integer> isVisited = new HashSet<Integer>();
		int N = sc.nextInt(); // 치킨집의 개수 변수
		int K = sc.nextInt(); // 집의 개수 변수
		long chickenDistance = 0;// 치킨지수 변수 초기화
		for (int i = 0; i < N; i++) {
			int x = sc.nextInt(); // 치킨집의 좌표를 입력받는다.
			isVisited.add(x); // 방문처리를 위한 set에 좌표추가
			queue.offer(new House(x, 0));// 치킨집의 좌표와 거리를 0으로 설정해 큐에 저장
		} // end of for i
		fb: while (!queue.isEmpty()) { // 집의 위치 제한이 없기 때문에 계속 반복됨
			House house = queue.poll();// 큐의 앞부분 빼기
			int dist = house.distance; // 현재 위치와과 치킨집까지의 거리
			for (int i = 0; i < 2; i++) { // 현재 위치의 좌,우를 살핌
				int x = house.x + dx[i]; // 현재위치의 좌우 좌표정보
				/*
				 * 문제에는 모든 집의 위치정보는 정수라는 조건만 존재하고 좌표 제한이 없습니다.
				 * 만약 집도 치킨집과 같이 -1억 ~1억의 범위를 가진다면
				 * 아래 조건문을 if (isVisited.contains(x) || x < -100000000 || x > 100000000 )로 변경합니다.
				 */
				if (isVisited.contains(x)) // 변경된 위치에 이미 집이나 치킨집이 있다면
					continue; // 큐에 추가하지 않고 넘어감
				isVisited.add(x); // Set에 변경된위치를 저장해줌
				queue.offer(new House(x, dist + 1)); // 큐에 변경된 위치와 거리를 하나 더해줘서 저장해줌
				K--; // 집을 배치했으므로 전체 집개수에 -1을 해준다.
				chickenDistance += dist + 1; // 총 치킨 지수에 변경된 위치의 치킨값을 더해준다.
				
				if (K == 0) // 집을 다 배치했으면
					break fb; // while문을 탈출한다.
			} // end of for i
		} // end of while
		System.out.println(chickenDistance); // 치킨지수를 출력
	} // end of main

	static class House {
		int x; // x 좌표를 나타낼 변수
		int distance; // 거리를 나타낼 변수

		public House(int x, int distance) { // 생성자
			this.x = x;
			this.distance = distance;
		} // end of Constructor House
	}// end of class house
}// end of class
