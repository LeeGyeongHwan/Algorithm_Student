package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

/* 
ACMICPC 
문제 번호 : 15961
문제 제목 : 회전 초밥
풀이 날짜 : 2020-08-28
Solved By Reamer 
*/

public class acm_15961 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		List<Integer> list = new ArrayList<Integer>();
		int N = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(br.readLine());
			list.add(num);
			if (i < k) {
				if (map.containsKey(num))
					map.put(num, map.get(num) + 1);
				else
					map.put(num, 1);
			}
		}

		int total = map.size();
		int maxDish = total;
		if (!map.containsKey(c))
			maxDish++;
		for (int i = 1; i < N; i++) {
			// 제거
			int deleteDish = list.get(i - 1);
			int addDish = list.get((i + k - 1) % N);
			if (deleteDish == addDish)
				continue;
			if (map.get(deleteDish) == 1) {
				map.remove(deleteDish);
				total--;
			} else {
				map.put(deleteDish, map.get(deleteDish) - 1);
			}
			if (map.containsKey(addDish)) {
				map.put(addDish, map.get(addDish) + 1);
			} else {
				map.put(addDish, 1);
				total++;
			}

			if (!map.containsKey(c) && total + 1 > maxDish)
				maxDish = total + 1;
			else if (map.containsKey(c) && total > maxDish)
				maxDish = total;
		}
		System.out.println(maxDish);
	}
}
