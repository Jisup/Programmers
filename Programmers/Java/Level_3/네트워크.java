package Level_3;

import java.util.*;
class Solution {
    static int answer = 0;
    static boolean visit[] = new boolean[201];
    static void solve(int index, int n, int[][] computers) {
        answer++;
        Queue<Integer>q=new LinkedList<>();
        q.add(index);
        visit[index]=true;
        while(!q.isEmpty()) {
            int item = q.poll();
            System.out.println(item);
            for(int i=0;i<n; i++)
                if(computers[item][i] == 1) {
                    if (!visit[i]) {
                        visit[i]=true;
                        q.add(i);
                    }
                }
        }
    }
    public int solution(int n, int[][] computers) {
        for(int i=0;i<n;i++) {
            if (!visit[i])
                solve(i, n, computers);
        }
        return answer;
    }
}