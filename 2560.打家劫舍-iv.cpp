class Solution {
private:
    bool check(vector<int>& nums, int price, int k) {
        int num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = num2;
            if (nums[i] <= price) num = max(num, num1 + 1);
            if (num >= k) return true;
            num1 = num2;
            num2 = num;
        }
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int maxNum = nums[0];
        for (auto num: nums) maxNum = max(maxNum, num);
        int price1 = 0, price2 = maxNum;
        while (price1 <= price2) {
            int mid = price1 + (price2 - price1) / 2;
            if (check(nums, mid, k)) {
                price2 = mid - 1;
            }
            else {
                price1 = mid + 1;
            }
        }
        return price1;
    }
};