/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
class Solution { //递归 空间占用是 o(n) 吗
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        else if (head->next == nullptr) return head;
        else {
            ListNode* ans = recursion(head->next);
            head->next->next = head;
            head->next = nullptr;
            return ans;
        }
    }

    ListNode* recursion(ListNode* curr) {
        if (curr->next == nullptr) return curr;
        else {
            ListNode* newHead = recursion(curr->next);
            // Until we reach end of List
            // newHead->next is cur
            curr->next->next = curr;
            curr->next = nullptr; // Otherwise bidirectional edges
            // newHead is always Head
            // 也就是说在之后只会讲递归前的链表逐一修正，但是对头节点不会改变了
            return newHead;
        }
    }

};
// @lc code=end

class iterative_Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        else {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while(curr != nullptr) {
                // 存好正向的下一个地址
                ListNode* currNext = curr->next;
                // 逆向的下一个已经可以更新, 指向正向的上一个
                curr->next = prev;
                // 此时正向的上一个不就更新成当前的了
                prev = curr;
                // 那当前的就是第一步存下的正向的下一个
                curr = currNext;
            }
            return prev;
        }
    }
};