/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* helper(vector<ListNode*>& lists, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return lists[l];
        ListNode* a = helper(lists, l, (l+r)/2);
        ListNode* b = helper(lists, (l+r)/2+1, r);
        ListNode* head = new ListNode(0);
        ListNode *p = head, *i = a, *j = b;
        while (i && j) {
            if (i->val < j->val) {
                p->next = i;
                i = i->next;
            }
            else {
                p->next = j;
                j = j->next;
            }
            p = p->next;
        }
        if (!i) p->next = j;
        else p->next = i;
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists, 0, lists.size()-1);
    }
};
// @lc code=end

