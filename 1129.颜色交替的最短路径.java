import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/*
 * @lc app=leetcode.cn id=1129 lang=java
 *
 * [1129] 颜色交替的最短路径
 */

// @lc code=start
class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        int[] shortestPaths1 = new int[n];
        int[] shortestPaths2 = new int[n];
        ArrayList<Integer>[] redGraph = new ArrayList[n];
        ArrayList<Integer>[] blueGraph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            shortestPaths1[i] = Integer.MAX_VALUE;
            shortestPaths2[i] = Integer.MAX_VALUE;
            redGraph[i] = new ArrayList<>();
            blueGraph[i] = new ArrayList<>();
        }
        shortestPaths1[0] = 0;
        shortestPaths2[0] = 0;
        for (int i = 0; i < redEdges.length; i++) {
            redGraph[redEdges[i][0]].add(redEdges[i][1]);
        }
        for (int i = 0; i < blueEdges.length; i++) {
            blueGraph[blueEdges[i][0]].add(blueEdges[i][1]);
        }
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        boolean isRed = true;
        int cnt1 = 1, cnt2, curLen = 0;
        while (!q.isEmpty()) {
            curLen++;
            cnt2 = cnt1;
            cnt1 = 0;
            while (cnt2 > 0) {
                int node = q.poll();
                if (isRed) {
                    for (int i: redGraph[node]) {
                        if (curLen < shortestPaths1[i]) {
                            shortestPaths1[i] = curLen;
                            q.offer(i);
                            cnt1++;
                        }
                    }
                }
                else {
                    for (int i: blueGraph[node]) {
                        if (curLen < shortestPaths2[i]) {
                            shortestPaths2[i] = curLen;
                            q.offer(i);
                            cnt1++;
                        }
                    }
                }
                cnt2--;
            }
            isRed = !isRed;
        }
        q.offer(0);
        isRed = false;
        cnt1 = 1;
        curLen = 0;
        while (!q.isEmpty()) {
            curLen++;
            cnt2 = cnt1;
            cnt1 = 0;
            while (cnt2 > 0) {
                int node = q.poll();
                if (isRed) {
                    for (int i: redGraph[node]) {
                        if (curLen < shortestPaths1[i]) {
                            shortestPaths1[i] = curLen;
                            q.offer(i);
                            cnt1++;
                        }
                    }
                }
                else {
                    for (int i: blueGraph[node]) {
                        if (curLen < shortestPaths2[i]) {
                            shortestPaths2[i] = curLen;
                            q.offer(i);
                            cnt1++;
                        }
                    }
                }
                cnt2--;
            }
            isRed = !isRed;
        }
        for (int i = 0; i < n; i++) {
            shortestPaths1[i] = Math.min(shortestPaths1[i], shortestPaths2[i]);
            if (shortestPaths1[i] == Integer.MAX_VALUE) shortestPaths1[i] = -1;
        }
        return shortestPaths1;
    }
}
// @lc code=end