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
#include <bits/stdc++.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* chain = head;
        
        while (chain != nullptr) {
            chain = chain->next;
            length++;
        }
        
        if (length == 1 && n == 1) {
            return nullptr;
        }
        if (length == n) {
            return head->next;
        }
    
        chain = head;
        for (int i = 0; i < length - n - 1; i++) {
            chain = chain->next;
        }
        ListNode* chain_tmp = chain->next;
        chain->next = chain_tmp->next;
    
    return head;
    }
};
// @lc code=end

