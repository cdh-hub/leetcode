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
        if (fast->next != nullptr) fast = fast->next;
        else return nullptr;
        if (fast->next != nullptr) fast = fast->next;
        else return nullptr;
        if (slow->next != nullptr) slow = slow->next;
        else return nullptr;
        int len1 = 1, len2 = 2;
        while (fast != slow) {
            if (fast->next != nullptr) {
                fast = fast->next;
                len2++;
            }
            else return nullptr;
            if (fast->next != nullptr) {
                fast = fast->next;
                len2++;
            }
            else return nullptr;
            if (slow->next != nullptr) {
                slow = slow->next;
                len1++;
            }
            else return nullptr;
        }
        for (int i = 0; i < 2 * len1 - len2; i++) {
            head = head->next;
        }
        return head;
    }
};
// @lc code=end

