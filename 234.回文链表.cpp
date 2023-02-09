/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head, *pre = nullptr;
        while (fast && fast->next) {
            fast = fast->next; fast = fast->next;
            ListNode* tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        ListNode *l = pre, *r = slow;
        if (fast) r = r->next;
        bool ans = true;
        while (l) {
            if (l->val != r->val) {
                ans = false;
                break;
            }
            l = l->next;
            r = r->next;
        }
        swap(slow, pre);
        while (slow) {
            ListNode* tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        return ans;
    }
};
// @lc code=end

