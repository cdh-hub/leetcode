/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class MinStack {
private:
    stack<long long> stk;
    int minValue;
public:
    MinStack() {

    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push(0);
            minValue = val;
        }
        else {
            stk.push((long long)val - minValue);
            if (val < minValue) minValue = val;
        }
    }
    
    void pop() {
        if (stk.top() < 0) {
            minValue = (int)(minValue - stk.top());
        }
        stk.pop();
    }
    
    int top() {
        return stk.top() > 0 ? (int)(stk.top() + minValue) : (int) minValue;
    }
    
    int getMin() {
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

