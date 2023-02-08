import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

/*
 * @lc app=leetcode.cn id=1233 lang=java
 *
 * [1233] 删除子文件夹
 */

// @lc code=start
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        HashSet set = new HashSet<>();
        for (String f : folder) {
            set.add(f);
        }
        List<String> ans = new ArrayList<>();
        for (String f : folder) {
            String[] files = f.split("/");
            boolean isChild = false;
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i < files.length - 1; i++) {
                sb.append('/');
                sb.append(files[i]);
                if (set.contains(sb.toString())) {
                    isChild = true;
                }
            }
            if (!isChild) {
                ans.add(f);
            }
        }
        return ans;
    }
}
// @lc code=end

