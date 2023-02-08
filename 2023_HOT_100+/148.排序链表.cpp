/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head); 
    }
    ListNode* mergeSort(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = head;
        while (fast != nullptr && fast->next != nullptr) {
            mid  = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // merge并未分配其他空间，因此不可以直接 slow 赋空 
        mid->next = nullptr;            // ListNode* l2 = mergeSort(slow->next); 两个的时候不可以了
        ListNode* l2 = mergeSort(slow); // slow->next = nullptr;
        ListNode* l1 = mergeSort(head); // ListNode* l1 = mergeSort(head);
        return merge(l1, l2); 
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l2->next, l1);
            return l2;
        }
    }
};
// @lc code=end








/**
 * @brief Time Limit Exceeded
 */

class Time_Exceeded_Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        else if (head->next == nullptr) return head;
        else {
            int change = 1;
            while (change == 1) {
                change = 0;
                ListNode* pointer = head;
                while (pointer->next)
                {
                    if (pointer->val > pointer->next->val) {
                        swap_list_val(pointer, pointer->next);
                        change = 1;
                    }
                    pointer = pointer->next;
                } 
            }  
            return head;
        }
    }
    void swap_list_val(ListNode* a, ListNode* b) {
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
};