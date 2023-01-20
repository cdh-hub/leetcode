import java.util.Comparator;
import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=1817 lang=java
 *
 * [1817] 查找用户活跃分钟数
 */

// @lc code=start
class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        Arrays.sort(logs, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) return a[0] - b[0];
                else return a[1] - b[1];
            }
        });
        HashMap<Integer, Integer> uam = new HashMap<>();
        for (int i = 0; i < logs.length; i++) {
            if (i != 0 && logs[i][0] == logs[i-1][0] && logs[i][1] == logs[i-1][1]) continue;
            else uam.put(logs[i][0], uam.containsKey(logs[i][0]) ? (uam.get(logs[i][0]) + 1) : 1);
        }
        int[] answer = new int[k];
        for (int i = 0; i < answer.length; i++) answer[i] = 0;
        for (Integer key: uam.keySet()) {
            answer[uam.get(key)-1]++;
        }
        return answer;
    }
}
// @lc code=end

