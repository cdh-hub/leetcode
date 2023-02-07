class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= 0) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        int pos = nums.size() - l;
        l = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < 0) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return max(l, pos);
    }
};