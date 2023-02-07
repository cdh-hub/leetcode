import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.TreeSet;

/*
 * @lc app=leetcode.cn id=1604 lang=java
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
class NameTime {
    String keyName;
    String keyTime;
}
class Solution {
    private int diff(String t1, String t2) {
        int h1 = (t1.charAt(0) - '0') * 10 + (t1.charAt(1) - '0');
        int h2 = (t2.charAt(0) - '0') * 10 + (t2.charAt(1) - '0');
        int m1 = (t1.charAt(3) - '0') * 10 + (t1.charAt(4) - '0'); 
        int m2 = (t2.charAt(3) - '0') * 10 + (t2.charAt(4) - '0');
        return (h2 - h1) * 60 + (m2 - m1);
    }
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        NameTime[] a = new NameTime[keyName.length];
        for (int i = 0; i < a.length; i++) {
            a[i] = new NameTime();
            a[i].keyName = keyName[i];
            a[i].keyTime = keyTime[i];
        }
        Arrays.sort(a, (NameTime x, NameTime y)-> x.keyName.equals(y.keyName) ? x.keyTime.compareTo(y.keyTime) : x.keyName.compareTo(y.keyName));
        TreeSet<String> names = new TreeSet<>();
        int i = 0, j = i + 2;
        while (j < a.length) {
            if (a[i].keyName.equals(a[j].keyName) && diff(a[i].keyTime, a[j].keyTime) <= 60) names.add(a[i].keyName);
            i++;
            j++;
        }
        List<String> ans = new ArrayList<String>();
        for (String name: names) {
            ans.add(name);
        }
        return ans;
    }
}
// @lc code=end

