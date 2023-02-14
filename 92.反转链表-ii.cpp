/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* p1 = dummy;
        for (int i = 0; i < left - 1; i++) p1 = p1->next;
        ListNode* p2 = p1->next;
        ListNode *pre = p2, *cur = p2->next;
        for (int i = 0; i < right-left; i++) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        p1->next = pre;
        p2->next = cur;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

