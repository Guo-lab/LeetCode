/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (54.79%)
 * Likes:    1220
 * Dislikes: 0
 * Total Accepted:    536.5K
 * Total Submissions: 979.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [], val = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1 
 * 0 
 * 
 * 
 */

// ---------------------- link ------------------------

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

// -------------------------------------------------------------
// 单链表
// struct ListNode {
//     int val;  // 节点上存储的元素
//     ListNode *next;  // 指向下一个节点的指针
//     ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
// };
// -------------------------------------------------------------
// ListNode* head = new ListNode(5);
// ----------------------------------
// ListNode* head = new ListNode();
// head->val = 5;
// ------------------

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0, head);
        // if (!head) return nullptr;
        ListNode* tmp = dummyHead;

        while (tmp->next != nullptr) {
            if (tmp->next->val == val) {
                ListNode* wait = tmp->next;
                tmp->next = tmp->next->next;
                delete wait;
                // 不要提前 x = x->next
            } else {
                tmp = tmp->next;
            }
        }

        return dummyHead->next;
    }
};
// @lc code=end

