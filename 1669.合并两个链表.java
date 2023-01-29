/*
 * @lc app=leetcode.cn id=1669 lang=java
 *
 * [1669] 合并两个链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode head = new ListNode(0, list1);
        ListNode prev = head, p = list1;
        int i = 0;
        while (i < a) {
            prev = p;
            p = p.next;
            i++;
        }
        prev.next = list2;
        while (i < b) {
            p = p.next;
            i++;
        }
        while (list2.next != null) {
            list2 = list2.next;
        }
        list2.next = p.next;
        return head.next;
    }
}
// @lc code=end

