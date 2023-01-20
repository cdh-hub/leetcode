/*
 * @lc app=leetcode.cn id=774 lang=cpp
 *
 * [774] 最小化去加油站的最大距离
 */

// @lc code=start
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double dmin = 0, dmax = 0;
        double* dist = new double[stations.size()-1];
        for (int i = 1; i < stations.size(); i++) {
            dist[i-1] = stations[i] - stations[i-1];
            dmax = max(dmax, dist[i-1]);
        }
        while (dmax - dmin >= 1e-6) {
            double dmid = (dmax + dmin) / 2;
            int need = 0;
            for (int i = 0; i < stations.size()-1; i++) {
                need += (int)(dist[i] / dmid);
            }
            if (need <= k) {
                dmax = dmid;
            }
            else {
                dmin = dmid;
            }
        }
        return (dmax + dmin) / 2;
    }
};
// @lc code=end

