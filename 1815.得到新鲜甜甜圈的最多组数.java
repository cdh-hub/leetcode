/*
 * @lc app=leetcode.cn id=1815 lang=java
 *
 * [1815] 得到新鲜甜甜圈的最多组数
 */

// @lc code=start
class Solution {
    ArrayList<HashMap<Long, Integer>> record;
    private int helper(int num, int[] count) {
        Long index = 0L;
        for (int i = 0; i < count.length; i++) {
            index = (index << 5) + count[i];
        }
        if (index == 0) return 0;
        if (record.get(num).containsKey(index)) return record.get(num).get(index);
        int maxHappy = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] != 0) {
                count[i]--;
                maxHappy = Math.max(maxHappy, helper((num + i) % count.length, count) + (num % count.length == 0 ? 1 : 0));
                count[i]++;
            }
        }
        record.get(num).put(index, maxHappy);
        return maxHappy;
    }
    public int maxHappyGroups(int batchSize, int[] groups) {
        int[] count = new int[batchSize];
        for (int i = 0; i < count.length; i++) {
            count[i] = 0;
        }
        for (int g : groups) {
            count[g%batchSize]++;
        }
        int cnt = count[0];
        count[0] = 0;
        record = new ArrayList<>();
        for (int i = 0; i < batchSize; i++) {
            record.add(new HashMap<>());
        }
        return cnt + helper(0, count);
    }
}
// @lc code=end

