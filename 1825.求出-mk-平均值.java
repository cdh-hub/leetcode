import java.util.LinkedList;
import java.util.Queue;
import java.util.TreeMap;

/*
 * @lc app=leetcode.cn id=1825 lang=java
 *
 * [1825] 求出 MK 平均值
 */

// @lc code=start
class MKAverage {
    private int m;
    private int k;
    private Queue<Integer> q;
    private TreeMap<Integer, Integer> s1, s2, s3;
    private long sum;
    public MKAverage(int m, int k) {
        this.m = m;
        this.k = k;
        q = new LinkedList<>();
        s1 = new TreeMap<>();
        s2 = new TreeMap<>();
        s3 = new TreeMap<>();
        sum = 0;
    }

    public void addElement(int num) {
        q.add(num);
        if (q.size() < m) {
            if (s2.containsKey(num)) {
                s2.put(num, s2.get(num) + 1);
            }
            else s2.put(num, 1);
        }
        else if (q.size() == m) {
            if (s2.containsKey(num)) {
                s2.put(num, s2.get(num) + 1);
            }
            else s2.put(num, 1);
            int cnt1 = 0, cnt2 = 0;
            while (cnt1 < k) {
                if (cnt1 + s2.firstEntry().getValue() <= k) {
                    if (s1.containsKey(s2.firstKey())) {
                        s1.put(s2.firstKey(), s1.get(s2.firstKey()) + s2.firstEntry().getValue());
                    }
                    else {
                        s1.put(s2.firstKey(), s2.firstEntry().getValue());
                    }
                    cnt1 += s2.firstEntry().getValue();
                    s2.pollFirstEntry();
                }
                else {
                    if (s1.containsKey(s2.firstKey())) {
                        s1.put(s2.firstKey(), s1.get(s2.firstKey()) + k-cnt1);
                    }
                    else {
                        s1.put(s2.firstKey(), k-cnt1);
                    }
                    s2.put(s2.firstKey(), s2.firstEntry().getValue() - k + cnt1);
                    cnt1 = k;
                }
            }
            while (cnt2 < k) {
                if (cnt2 + s2.lastEntry().getValue() <= k) {
                    if (s3.containsKey(s2.lastKey())) {
                        s3.put(s2.lastKey(), s3.get(s2.lastKey()) + s2.lastEntry().getValue());
                    }
                    else {
                        s3.put(s2.lastKey(), s2.lastEntry().getValue());
                    }
                    cnt2 += s2.lastEntry().getValue();
                    s2.pollLastEntry();
                }
                else {
                    if (s3.containsKey(s2.lastKey())) {
                        s3.put(s2.lastKey(), s3.get(s2.lastKey()) + k-cnt2);
                    }
                    else {
                        s3.put(s2.lastKey(), k-cnt2);
                    }
                    s2.put(s2.lastKey(), s2.lastEntry().getValue() - k + cnt2);
                    cnt2 = k;
                }
            }
            for (int k : s2.keySet()) {
                sum += s2.get(k) * k;
            }
        }
        else {
            if (num < s1.lastKey()) {
                s1.put(num, s1.containsKey(num) ? (s1.get(num) + 1) : 1);
                s2.put(s1.lastKey(), s2.containsKey(s1.lastKey()) ? (s2.get(s1.lastKey()) + 1) : 1);
                sum += s1.lastKey();
                if (s1.lastEntry().getValue() == 1) s1.pollLastEntry();
                else s1.put(s1.lastKey(), s1.lastEntry().getValue()-1);
            }
            else if (num > s3.firstKey()) {
                s3.put(num, s3.containsKey(num) ? (s3.get(num) + 1) : 1);
                s2.put(s3.firstKey(), s2.containsKey(s3.firstKey()) ? (s2.get(s3.firstKey()) + 1) : 1);
                sum += s3.firstKey();
                if (s3.firstEntry().getValue() == 1) s3.pollFirstEntry();
                else s3.put(s3.firstKey(), s3.firstEntry().getValue()-1);
            }
            else {
                s2.put(num, s2.containsKey(num) ? (s2.get(num) + 1) : 1);
                sum += num;
            }
            if (q.peek() <= s1.lastKey()) {
                if (s1.get(q.peek()) == 1) s1.remove(q.peek());
                else s1.put(q.peek(), s1.get(q.peek()) - 1);
                s1.put(s2.firstKey(), s1.containsKey(s2.firstKey()) ? (s1.get(s2.firstKey()) + 1) : 1);
                sum -= s2.firstKey();
                if (s2.firstEntry().getValue() == 1) s2.pollFirstEntry();
                else s2.put(s2.firstKey(), s2.firstEntry().getValue() - 1);
            }
            else if (q.peek() >= s3.firstKey()) {
                if (s3.get(q.peek()) == 1) s3.remove(q.peek());
                else s3.put(q.peek(), s3.get(q.peek()) - 1);
                s3.put(s2.lastKey(), s3.containsKey(s2.lastKey()) ? (s3.get(s2.lastKey()) + 1) : 1);
                sum -= s2.lastKey();
                if (s2.lastEntry().getValue() == 1) s2.pollLastEntry();
                else s2.put(s2.lastKey(), s2.lastEntry().getValue() - 1);
            }
            else {
                sum -= q.peek();
                if (s2.get(q.peek()) == 1) s2.remove(q.peek());
                else s2.put(q.peek(), s2.get(q.peek()) - 1);
            }
            q.poll();
        }
    }
    
    public int calculateMKAverage() {
        if (q.size() < m) return -1;
        return (int) (sum / (m - k * 2));
    }
}

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage obj = new MKAverage(m, k);
 * obj.addElement(num);
 * int param_2 = obj.calculateMKAverage();
 */
// @lc code=end

