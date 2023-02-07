/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    void sortHelper(ListNode* p, ListNode* ptail, ListNode* q, ListNode* qtail) {
        ListNode *i = p->next, *j = q->next, *pre = p;
        while (i != ptail && j != qtail) {
            if (i->val < j->val) {
                pre->next = i;
                i = i->next;
            }
            else {
                pre->next = j;
                j = j->next;
            }
            pre = pre->next;
        }
        if (i != ptail) {
            pre->next = i;
            while (pre->next != ptail) pre = pre->next;
            pre->next = qtail;
        }
        else pre->next = j;
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode* newHead = new ListNode();
        newHead->next = head;
        int i = 0;
        while (1) {
            ListNode *p = newHead, *q = newHead;
            for (int j = 0; j < (1 << i); j++) {
                if (q->next) q = q->next;
            }
            if (!q->next) break;
            ListNode* t = q;
            for (int j = 0; j < (1 << i); j++) {
                if (t->next) t = t->next;
            }
            sortHelper(p, q->next, q, t->next);
            while (t->next) {
                for (int j = 0; j < (1 << (i+1)); j++) {
                    if (p->next) p = p->next;
                }
                q = p;
                for (int j = 0; j < (1 << i); j++) {
                    if (q->next) q = q->next;
                }
                if (!q->next) break;
                t = q;
                for (int j = 0; j < (1 << i); j++) {
                    if (t->next) t = t->next;
                }
                sortHelper(p, q->next, q, t->next);
            }
            i++;
        }
        return newHead->next;
    }
};
// @lc code=end

