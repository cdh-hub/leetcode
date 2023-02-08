/*
 * @lc app=leetcode.cn id=2526 lang=cpp
 *
 * [2526] 找到数据流中的连续整数
 */

// @lc code=start
class DataStream {
private:
    int value, k, count;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        count = 0;
    }
    
    bool consec(int num) {
        if (num == value) count++;
        else count = 0;
        return count >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
// @lc code=end

