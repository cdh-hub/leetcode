#include<bits/stdc++.h>
using namespace std;
class Cmp {
public:
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        map<int, int, Cmp> map;
        for (auto num: nums) {
            map[num]++;
        }
        while (k--) {
            int key = (*map.begin()).first;
            score += key;
            map[(key + 2) / 3]++;
            map[key]--;
            if (map[key] == 0) map.erase(key);
        }
        return score;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> a({1,10,3,3,3});
    cout << s->maxKelements(a, 3);
    return 0;
}