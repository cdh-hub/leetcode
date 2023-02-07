/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *fast = head, *slow = head;
        do {
            if (fast->next) fast = fast->next;
            else return nullptr;
            if (fast->next) fast = fast->next;
            else return nullptr;
            if (slow->next) slow = slow->next;
            else return nullptr;
        } while (fast != slow);
        slow = head;
        while (fast != slow) {
            if (fast->next) fast = fast->next;
            if (slow->next) slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

