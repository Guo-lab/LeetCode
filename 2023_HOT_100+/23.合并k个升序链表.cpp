/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct item {
        /* data */
        int val;
        ListNode* address;
        bool operator<(const item &B) const {
            return val > B.val;
        } 
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode resultHead;
        ListNode *pointer = &resultHead;

        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1 && lists[0] == nullptr) return nullptr;

        ////priority_queue<int, vector<int>, greater<int>> container;//! //
        priority_queue<item> container;
        
        bool isAllNull = true;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                container.push({
                    lists[i]->val, 
                    lists[i]
                });
                isAllNull = false;
            }
        }
        if (isAllNull == true) return nullptr;
        
        while (!container.empty()) {
            item tmp = container.top();
            container.pop();
            cout << tmp.val << endl;
            pointer->next = tmp.address;  //! /////////////////////////////
            pointer->next->val = tmp.val;
            pointer = pointer->next;
            if (tmp.address->next != nullptr) {
                container.push({
                    tmp.address->next->val,
                    tmp.address->next
                });
            }
        } 
        return resultHead.next;
    }
};
// @lc code=end

