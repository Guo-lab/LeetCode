/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        stack<int> traversal;
        int length = 0;
        ListNode* cur = head;

        while (head != nullptr) {
            length++;
            head = head->next;
        }
        if (length == 1) 
            return true;
        int odd = length % 2;
        length /= 2;

        while (cur != nullptr) {
            if (length > 0) {
                traversal.push(cur->val);
                cur = cur->next;
                length--;
            }
            else if (odd == 1) {
                cur = cur->next;
                odd = 0;
            }
            else if (cur->val == traversal.top()) {
                cur = cur->next;
                traversal.pop();
            } else {
                return false;
            }
        }

        if (!traversal.empty()) 
            return false;
        return true;
    }
};
// @lc code=end

