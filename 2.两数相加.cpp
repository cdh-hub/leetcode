/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* helper(int r, ListNode* l1, ListNode* l2) {
        int sum = r;
        if (l1) sum += l1->val;
        if (l2) sum += l2->val;
        if (sum >= 10) sum = sum % 10, r = 1;
        else r = 0;
        if (!l1 && !l2 && sum == 0) return nullptr;
        return new ListNode(sum, helper(r, l1 ? l1->next : nullptr, l2 ? l2->next : nullptr));
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if (l1->val == 0 && l2->val == 0) return new ListNode(0, nullptr);
        return helper(0, l1, l2);
    }
};
// @lc code=end

