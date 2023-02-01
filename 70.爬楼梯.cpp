// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem70.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
typedef struct Node{
    int m;
    int n;
    long long data[2][2];
} matrix;

class Solution {
private:
    matrix multiply(matrix m1, matrix m2) {
        matrix m3;
        m3.m = m1.m;
        m3.n = m2.n;
        for (int i = 0; i < m3.m; i++) {
            for (int j = 0; j < m3.n; j++) {
                m3.data[i][j] = 0;
                for (int k = 0; k < m1.n; k++) {
                    m3.data[i][j] += m1.data[i][k] * m2.data[k][j];
                }
            }
        }
        return m3;
    }
    matrix ksm(matrix a, int n) {
        matrix ans;
        ans.m = 2;
        ans.n = 2;
        ans.data[0][0] = 1;
        ans.data[1][0] = 0;
        ans.data[0][1] = 0;
        ans.data[1][1] = 1;
        while (n) {
            if (n & 1) {
                ans = multiply(ans, a);
            }
            a = multiply(a, a);
            n >>= 1;
        }
        return ans;
    }
public:
    int climbStairs(int n) {
        matrix a;
        a.m = 2;
        a.n = 2;
        a.data[0][0] = 1;
        a.data[1][0] = 1;
        a.data[0][1] = 1;
        a.data[1][1] = 0;
        matrix ans = ksm(a,n);
        return ans.data[1][0] + ans.data[1][1];
    }
};
// @lc code=end

