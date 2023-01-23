/*
 * @lc app=leetcode.cn id=251 lang=cpp
 *
 * [251] 展开二维向量
 */

// @lc code=start
class Vector2D {
private:
    vector<vector<int>> vec;
    int n, m;
public:
    Vector2D(vector<vector<int>>& vec) {
        this->vec = vec;
        m = 0;
        n = 0;
        while (n < vec.size() && vec[n].size() == 0) {
            n++;
        }
    }
    
    int next() {
        int tmp = vec[n][m];
        if (m + 1 < vec[n].size()) m++;
        else {
            n++;
            m = 0;
            while (n < vec.size() && vec[n].size() == 0) {
                n++;
            }
        }
        return tmp;
    }
    
    bool hasNext() {
        return n < vec.size() && m < vec[n].size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

