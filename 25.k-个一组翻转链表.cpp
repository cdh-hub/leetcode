/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        int n = 0;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            n++;
        }
        ListNode *p1 = dummy, *p2 = head;
        for (int i = 0; i < n/k; i++) {
            ListNode* pre = p2, *cur = p2->next;
            for (int j = 0; j < k-1; j++) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            p1->next = pre;
            p2->next = cur;
            p1 = p2;
            p2 = cur;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

