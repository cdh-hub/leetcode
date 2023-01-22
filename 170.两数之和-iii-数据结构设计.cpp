/*
 * @lc app=leetcode.cn id=170 lang=cpp
 *
 * [170] 两数之和 III - 数据结构设计
 */

// @lc code=start
typedef long long ll;
class TwoSum {
private:
    unordered_map<ll, int> map;
public:
    TwoSum() {

    }
    
    void add(int number) {
        map[number]++;
    }
    
    bool find(int value) {
        for (auto& [k,v]: map) {
            if (value - k != k && map.count(value - k) || value - k == k && v >= 2) return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
// @lc code=end

