/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 *
 * https://leetcode.cn/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (56.92%)
 * Likes:    2067
 * Dislikes: 0
 * Total Accepted:    645.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos
 * 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos
 * 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 * 
 * 不允许修改 链表。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：返回索引为 1 的链表节点
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：返回索引为 0 的链表节点
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 输入：head = [1], pos = -1
 * 输出：返回 null
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围在范围 [0, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 * pos 的值为 -1 或者链表中的一个有效索引
 * 
 * 
 * 
 * 
 * 进阶：你是否可以使用 O(1) 空间解决此题？
 * 
 */

// -------------------- link --------------------

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
        // fast-slow
        // whether there is a cycle, fast will be trapped.
        // where is the entry,
        ListNode* slow;
        ListNode* fast;
        // 2 * (x + y) = x + y + n * (y + z)
        // x = (n - 1) * (y + z) + z (先走 z 再走整圈) 
        if (!head || !head->next || !head->next->next) return nullptr;
        if (head->next->next == head) return head; // ----what.---- //
        slow = head;
        fast = head; // head->next;
        // 初始化都是 head 往后遍历，后续 index fast slow 再走也必须是同步向后 // 数学证明中为什么 entry 不用单独考虑呢 https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        // cout << slow->val << endl;
    
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        ListNode* index_slow = head;
        ListNode* index_fast = fast;
        while (index_fast != index_slow) {
            index_fast = index_fast->next;
            // cout << index_slow->val << endl; 
            index_slow = index_slow->next;
        }
        // cout << index_fast->val << endl;
        return index_fast;
    }
};
// @lc code=end

------------------------------------- [1,2]\n0\n
[1,2]
0
------
tail connects to node index 0
-------------------------------------

------------------------------------- [-1,-7,7,-4,19,6,-9,-5,-2,-5]\n6\n
[-1,-7,7,-4,19,6,-9,-5,-2,-5]
6
------------
tail connects to node index 6
fast,slow = -5
-------------------------------------