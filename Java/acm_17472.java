package com.ssafy.day04;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 17472
문제 제목 : 다리 만들기 2
풀이 날짜 : 2020-09-04
Solved By Reamer 
*/

public class acm_17472 {
	private static int[][] map;
	static int minBridge = Integer.MAX_VALUE;
	static List<List<Pair>> island;
	static int islandCnt = 0;
	static int bridgeCnt = 0;
	static boolean[][] selected;
	static boolean[] dfsVisited;
	private static int N, M;
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static int[] combi = new int[2];
	private static List<List<Pair>> bridgeList;
	static int[][] allLink = new int[6][6];
	static List<Pair> linkedStatus = new ArrayList<Pair>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		island = new ArrayList<>();
		bridgeList = new ArrayList<>();
		for (int i = 0; i < 6; i++)
			island.add(new ArrayList<Pair>());
		for (int i = 0; i < 15; i++)
			bridgeList.add(new ArrayList<Pair>());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		makeIsland();
		combination(0, 0);

		connectBridge(0, 0);
		if (minBridge == Integer.MAX_VALUE)
			System.out.println("-1");
		else
			System.out.println(minBridge);
	}

	private static void connectBridge(int cnt, int distance) {
		if (cnt == bridgeCnt) {
			dfsVisited = new boolean[islandCnt];

			allConnected(0);
			int tmpCnt = 0;
			for (int i = 0; i < islandCnt; i++) {

				if (dfsVisited[i])
					tmpCnt++;
			}

			if (tmpCnt == islandCnt) {
				if (minBridge > distance)
					minBridge = distance;
			}

			return;
		}

		List<Pair> tmpList = bridgeList.get(cnt);
		if (tmpList.size() == 0)
			// 다음으로 넘김
			connectBridge(cnt + 1, distance);
		else {
			// 연결
			for (int i = 0; i < tmpList.size() / 2; i++) {
				int length = setBridge(tmpList.get(i + i), tmpList.get(i + i + 1), 2);
				allLink[linkedStatus.get(cnt).x][linkedStatus.get(cnt).y]++;
				allLink[linkedStatus.get(cnt).y][linkedStatus.get(cnt).x]++;
				connectBridge(cnt + 1, distance + length);
				setBridge(tmpList.get(i + i), tmpList.get(i + i + 1), 0);
				allLink[linkedStatus.get(cnt).x][linkedStatus.get(cnt).y]--;
				allLink[linkedStatus.get(cnt).y][linkedStatus.get(cnt).x]--;

			}
		}
		// 연결해제
		connectBridge(cnt + 1, distance);
	}

	private static void allConnected(int idx) {

		dfsVisited[idx] = true;

		for (int i = 0; i < islandCnt; i++) {
			if (idx == i)
				continue;
			if (allLink[idx][i] != 0 && !dfsVisited[i]) {
				allConnected(i);
			}
		}
	}

	private static int setBridge(Pair pair1, Pair pair2, int mode) {
		//
		if (pair1.x == pair2.x) {
			for (int i = Math.min(pair1.y, pair2.y) + 1; i < Math.max(pair1.y, pair2.y); i++) {
				if (mode == 0)
					map[pair1.x][i] -= 2;
				else
					map[pair1.x][i] += 2;
			}
			return Math.abs(pair1.y - pair2.y) - 1;
		} else {
			for (int i = Math.min(pair1.x, pair2.x) + 1; i < Math.max(pair1.x, pair2.x); i++) {
				if (mode == 0)
					map[i][pair1.y] -= 2;
				else
					map[i][pair1.y] += 2;
			}
			return Math.abs(pair1.x - pair2.x) - 1;
		}
	}

	private static void combination(int cnt, int start) {
		if (cnt == 2) {
			checkConnect();
			return;
		}

		for (int i = start; i < islandCnt; i++) {
			combi[cnt] = i;
			combination(cnt + 1, i + 1);
		}
	}

	private static void checkConnect() {
		List<Pair> firstIsland = island.get(combi[0]);
		List<Pair> secondIsland = island.get(combi[1]);
		List<Pair> list = bridgeList.get(bridgeCnt);
		int minDistance = 10;

		for (int i = 0; i < firstIsland.size(); i++) {
			Pair firstLand = firstIsland.get(i);
			for (int j = 0; j < secondIsland.size(); j++) {
				Pair secondLand = secondIsland.get(j);
				boolean canBuild = true;
				if (firstLand.x == secondLand.x && Math.abs(firstLand.y - secondLand.y) > 2) {
					for (int k = Math.min(firstLand.y, secondLand.y) + 1; k < Math.max(firstLand.y,
							secondLand.y); k++) {
						if (map[firstLand.x][k] == 1) {
							canBuild = false;
							break;
						}
					}
					if (canBuild) {
						if (minDistance > Math.abs(firstLand.y - secondLand.y)) {
							minDistance = Math.abs(firstLand.y - secondLand.y);
							list = new ArrayList<Pair>();
							list.add(firstLand);
							list.add(secondLand);
						} else if (minDistance == Math.abs(firstLand.y - secondLand.y)) {
							list.add(firstLand);
							list.add(secondLand);
						}
					}
				} else if (firstLand.y == secondLand.y && Math.abs(firstLand.x - secondLand.x) > 2) {
					for (int k = Math.min(firstLand.x, secondLand.x) + 1; k < Math.max(firstLand.x,
							secondLand.x); k++) {
						if (map[k][firstLand.y] == 1) {
							canBuild = false;
							break;
						}
					}
					if (canBuild) {
						if (minDistance > Math.abs(firstLand.x - secondLand.x)) {
							minDistance = Math.abs(firstLand.x - secondLand.x);
							list = new ArrayList<Pair>();
							list.add(firstLand);
							list.add(secondLand);
						} else if (minDistance == Math.abs(firstLand.x - secondLand.x)) {
							list.add(firstLand);
							list.add(secondLand);
						}
					}
				}
			}
		}
		linkedStatus.add(new Pair(combi[0], combi[1]));
		bridgeList.set(bridgeCnt++, list);
	}

	private static void makeIsland() {
		selected = new boolean[N][M];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!selected[i][j] && map[i][j] == 1) {
					Queue<Pair> queue = new LinkedList<Pair>();
					queue.offer(new Pair(i, j));
					selected[i][j] = true;
					while (!queue.isEmpty()) {
						Pair pair = queue.poll();
						island.get(islandCnt).add(pair);
						for (int k = 0; k < 4; k++) {
							int newX = pair.x + dx[k];
							int newY = pair.y + dy[k];
							if (newX >= 0 && newX < N && newY >= 0 && newY < M && !selected[newX][newY]
									&& map[newX][newY] == 1) {
								selected[newX][newY] = true;
								queue.offer(new Pair(newX, newY));
							}
						}
					}
					islandCnt++;
				}
			}
		}
	}

	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}
