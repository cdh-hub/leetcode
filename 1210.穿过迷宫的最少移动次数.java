import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode.cn id=1210 lang=java
 *
 * [1210] 穿过迷宫的最少移动次数
 */

// @lc code=start
class Solution {
    public int minimumMoves(int[][] grid) {
        int n = grid.length;
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        boolean record[] = new boolean[n*n*2];
        for (int i = 0; i < n*n*2; i++) {
            record[i] = false;
        }
        int cnt = 1, cnt2, pathLen = 0;
        while (!q.isEmpty()) {
            cnt2 = cnt;
            cnt = 0;
            while (cnt2 > 0) {
                int cur = q.poll();
                int status = cur % 2;
                int x = cur / 2 / n, y = (cur / 2) % n;
                if (x == n-1 && y == n-2 && status == 0) return pathLen;
                if (status == 0) {
                    if (y + 2 < n && grid[x][y+2] == 0 && !record[(x*n+y+1)*2]) {
                        q.offer((x*n+y+1)*2);
                        cnt++;
                        record[(x*n+y+1)*2] = true;
                    }
                    if (x + 1 < n && grid[x+1][y] == 0 && grid[x+1][y+1] == 0 && !record[((x+1)*n+y)*2]) {
                        q.offer(((x+1)*n+y)*2);
                        cnt++;
                        record[((x+1)*n+y)*2] = true;
                    }
                    if (x + 1 < n && grid[x+1][y] == 0 && grid[x+1][y+1] == 0 && !record[(x*n+y)*2+1]) {
                        q.offer((x*n+y)*2+1);
                        cnt++;
                        record[(x*n+y)*2+1] = true;
                    }
                }
                else {
                    if (x + 2 < n && grid[x+2][y] == 0 && !record[((x+1)*n+y)*2+1]) {
                        q.offer(((x+1)*n+y)*2+1);
                        cnt++;
                        record[((x+1)*n+y)*2+1] = true;
                    }
                    if (y + 1 < n && grid[x][y+1] == 0 && grid[x+1][y+1] == 0 && !record[(x*n+y+1)*2+1]) {
                        q.offer((x*n+y+1)*2+1);
                        cnt++;
                        record[(x*n+y+1)*2+1] = true;
                    }
                    if (y + 1 < n && grid[x][y+1] == 0 && grid[x+1][y+1] == 0 && !record[(x*n+y)*2]) {
                        q.offer((x*n+y)*2);
                        cnt++;
                        record[(x*n+y)*2] = true;
                    }
                }
                cnt2--;
            }
            pathLen++;
        }
        return -1;
    }
}
// @lc code=end

