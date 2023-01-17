/*
 * @lc app=leetcode.cn id=975 lang=cpp
 *
 * [975] 奇偶跳
 */

// @lc code=start
class Solution {
private:
    static bool increasing(pair<int, int> a, pair<int, int> b) {
        if (a.first < b.first) return true;
        if (a.first == b.first && a.second < b.second) return true;
        return false; 
    }
    static bool descending(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) return true;
        if (a.first == b.first && a.second < b.second) return true;
        return false; 
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        int* odd = new int[n];
        int* even = new int[n];
        stack<int> stk;
        memset(odd, -1, sizeof(int)*n); 
        memset(even, -1, sizeof(int)*n);
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back(make_pair(arr[i], i));
        }
        sort(pairs.begin(), pairs.end(), increasing);
        for (auto p : pairs) {
            while (!stk.empty() && stk.top() < p.second) {
                odd[stk.top()] = p.second;
                stk.pop();
            }
            stk.push(p.second);
        }
        sort(pairs.begin(), pairs.end(), descending);
        for (auto p : pairs) {
            while (!stk.empty() && stk.top() < p.second) {
                even[stk.top()] = p.second;
                stk.pop();
            }
            stk.push(p.second);
        }
        bool* oddbegin = new bool[n];
        bool* evenbegin = new bool[n];
        memset(oddbegin, 0, sizeof(bool)*n);
        memset(evenbegin, 0, sizeof(bool)*n);
        oddbegin[n-1] = true;
        evenbegin[n-1] = true;
        int cnt = 1;
        for (int i = n-2; i >= 0; i--) {
            if (odd[i] != -1) {
                oddbegin[i] = evenbegin[odd[i]];
                if (oddbegin[i]) cnt++;
            }
            if (even[i] != -1) evenbegin[i] = oddbegin[even[i]];
        }
        return cnt;
    }
};
// @lc code=end

