/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
#include <stack>
#include <iostream>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a_ten = 0;
        
        int l1_size = 0, l2_size = 0;                  //* List Size
        ListNode* ll1 = l1; ListNode* ll2 = l2;
        for (; ll1!=nullptr;) {
            ll1 = ll1->next;
            l1_size++;
        }
        for (; ll2!=nullptr;) {
            ll2 = ll2->next;
            l2_size++;
        }
        int result_size = l1_size < l2_size ? l2_size : l1_size;
        
        int a = 0, b = 0;
        ListNode* result = nullptr;                    //* [Init] 
        stack<int> tmp;

        for (int i = 0; i < result_size; i++) {
            if (l1 == nullptr) {
                a = 0;
            } else {
                a = l1->val;
            }
            if (l2 == nullptr) {
                b = 0;
            } else {
                b = l2->val;
            } 
            int tmpVal = a + b;
            if (a_ten == 1) {
                a_ten = 0;
                tmpVal += 1;
            }
            if (tmpVal >= 10) {
                tmpVal = tmpVal - 10;
                a_ten = 1;    
            }
            tmp.push(tmpVal); 
            
            //for (int cnt = 0; cnt < i; cnt++) {      //* Traversal Condition
                if (l1 != nullptr) {
                    l1 = l1->next;
                }
                if (l2 != nullptr) {
                    l2 = l2->next;
                }
            //}
        }
        if (a_ten == 1) { 
            tmp.push(1); 
        }

        result = new ListNode(tmp.top());              //* Insert List
        tmp.pop();
        while (!tmp.empty()) {
            ListNode* tmpNode = result;
            result = new ListNode(tmp.top(), tmpNode);
            tmp.pop();
        }
        
    return result;
    }
};
// @lc code=end

/*
Solutions:
https://leetcode.cn/problems/add-two-numbers/comments/

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
    
};
*/