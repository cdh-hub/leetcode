/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *i = list1, *j = list2;
        if (!i) return j;
        if (!j) return i;
        if (i->val > j->val) swap(i, j);
        ListNode *head = i, *iPre = nullptr, *jPre = nullptr;
        while (i && j) {
            while (i && i->val <= j->val) {
                iPre = i;
                i = i->next;
            }
            iPre->next = j;
            if (!i) break;
            while (j && j->val <= i->val) {
                jPre = j;
                j = j->next;
            }
            jPre->next = i;
        }
        return head;
    }
};
// @lc code=end

