/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *p = head, *q = head;
        while (1) {
            if (p->next) p = p->next;
            else return false;
            if (q->next) q = q->next;
            else return false;
            if (q->next) q = q->next;
            else return false;
            if (p == q) return true;
        }
        return false;
    }
};
// @lc code=end

