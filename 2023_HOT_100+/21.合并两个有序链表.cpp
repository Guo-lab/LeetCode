/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head(0);             //! ////////
        ListNode* resultList = &head; //! ////////
        if(list1 == nullptr && list2 == nullptr) {
            return list1;
        } else if (list1 == nullptr && list2 != nullptr) {
            return list2;
        } else if (list1 != nullptr && list2 == nullptr) {
            return list1;
        } else {
            while (list1!=nullptr || list2!=nullptr) {
                if(list2 == nullptr) {
                    resultList->next = list1;
                    break;            //! ////////
                } else if (list1 == nullptr) {
                    resultList->next = list2;
                    break;            //! ////////
                } else {
                    if(list1->val <= list2->val) {
                        ////cout << list1->val << endl;
                        ListNode *tmp = new ListNode(list1->val);
                        resultList->next = tmp;
                        resultList = resultList->next;
                        list1 = list1->next;
                        ////cout << list1 << endl;
                    } else {
                        ////cout << list2->val << endl;
                        ListNode *tmp = new ListNode(list2->val);
                        resultList->next = tmp;
                        resultList = resultList->next;
                        list2 = list2->next;
                        ////cout << list2 << endl;
                    }
                }
            }
        return head.next;
        }
    }
};
// @lc code=end

