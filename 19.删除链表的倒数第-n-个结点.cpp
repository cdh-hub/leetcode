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
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy, *fast = dummy;
        for (int i = 0; i <= n; i++) fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

