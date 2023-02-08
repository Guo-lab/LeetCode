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
        else {
            while (head->next) {
                if (head->next->val == -1000000) return head->next;
                head->val = -1000000;
                head = head->next;
            }
            return nullptr;
        }
    }
};
// @lc code=end

