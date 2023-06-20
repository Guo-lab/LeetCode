/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (53.24%)
 * Likes:    1711
 * Dislikes: 0
 * Total Accepted:    599.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,2,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 * 
 * 
 * 
 * 
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
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

 // ---------------------- link ---------------------
 // --------- try again later
 
class Solution {
public:
    ListNode* pre = nullptr;
    bool isPalindrome(ListNode* head) {
        if (head->next==nullptr) return true;
    // 切割 + 反转 <!>
        ListNode* fast = head; 
        ListNode* slow = head;
        int lengthOfSub = 0;
        while (fast != nullptr && fast->next != nullptr) { // fast->next != nullptr && fast != nullptr runtime error: member access within null pointer of type 'ListNode' (solution.cpp)
            lengthOfSub++;
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr; // <!> 切割，不切割的话，成环 e.g. 1,2,2,2,2,2... 

        ListNode* head_1 = head;
        ListNode* head_2 = reverseList(slow);

        while (lengthOfSub--) {
            if (head_1->val != head_2->val)
                return false;
            head_1 = head_1->next;
            head_2 = head_2->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* dummyHead) {
        ListNode* headPre = pre;  // previous
        ListNode* cur = dummyHead;// current
        ListNode* tmp;  // next

        while (cur != nullptr) {
            tmp = cur->next;
            // 反转
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
// @lc code=end

============
[1]
----
true
============