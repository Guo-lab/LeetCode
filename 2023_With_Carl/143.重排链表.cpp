/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode.cn/problems/reorder-list/description/
 *
 * algorithms
 * Medium (64.89%)
 * Likes:    1220
 * Dislikes: 0
 * Total Accepted:    253.6K
 * Total Submissions: 390.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 * 
 * 
 * L0 → L1 → … → Ln - 1 → Ln
 * 
 * 
 * 请将其重新排列后变为：
 * 
 * 
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * 
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
 * 
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

  // -------------------------- link -------------------------
        // <1> Queue Or Array transfer
        // <2> Cut And Reverse And Merge
        
class Solution {
public:
    ListNode* pre;
    
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        // <1> Queue Or Array transfer
        // <2> Cut And Reverse And Merge
        ListNode* slow = head;
        ListNode* fast = head;
        int leng = 0;
        while (fast != nullptr && fast->next != nullptr) {
            pre  = slow;
            slow = slow->next;
            fast = fast->next->next;
            leng++;
        }
        pre->next = nullptr;

        ListNode* head_1 = head;
        ListNode* head_2 = reverseList(slow);

        // ListNode* a = head_1;
        // ListNode* b = head_2;
        // while (a != nullptr) {
        //     cout << a->val << " ";
        //     a = a->next;
        // }
        // cout << endl;
        // while (b != nullptr) {
        //     cout << b->val << " ";
        //     b = b->next;
        // }
        // cout << endl;

        ListNode* cur = new ListNode(0, head);
        while (head_1 != nullptr || head_2 != nullptr) {
            if (head_1 == nullptr) {
                cur->next = head_2;
                break;
            } 
            else if (head_2 == nullptr) {
                cur->next = head_1;
                break;
            }
            else {
                ListNode* tmp_for_head_1 = head_1->next; // ---link cross
                ListNode* tmp_for_head_2 = head_2->next;
                cur->next = head_1;
                cur = cur->next;
                cur->next = head_2;
                cur = cur->next;
                head_1 = tmp_for_head_1;
                head_2 = tmp_for_head_2;
                // cout << head_1->val << " " << head_2->val << endl;
            }
        }
    }
    ListNode* reverseList(ListNode* dummyHead) {
        pre = nullptr;
        ListNode* cur = dummyHead;
        ListNode* tmp = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
// @lc code=end

=====================
[1,2,3,4,5]
------------
[1,5,2,4,3]
=====================