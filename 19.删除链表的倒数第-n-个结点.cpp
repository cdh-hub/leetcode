/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head, *prev = nullptr;
        for (int i = 0; i < n; i++) {
            q = q->next;
        }
        while (q) {
            prev = p;
            p = p->next;
            q = q->next;
        }
        if (!prev) {
            return p->next;
        }
        else {
            prev->next = p->next;
            return head;
        }
    }
};
// @lc code=end

