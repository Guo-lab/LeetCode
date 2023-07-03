//445. 两数相加 II

//You are given two non-empty linked lists representing two non-negative integers. 
//The most significant digit comes first and each of their nodes contains a single digit. 
//Add the two numbers and return the sum as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.


//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
//它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

//你可以假设除了数字 0 之外，这两个数字都不会以零开头。


// 噢噢噢噢 题解用了栈，因为逆序处理优先考虑了栈......


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1->val == 0) return l2;
        if (l2->val == 0) return l1;

        ListNode* head  = l1;
        ListNode* prev  = nullptr;
        ListNode* cur_1 = head;
        ListNode* temp  = cur_1->next;
        while (temp != nullptr) {
            ListNode* tmp = temp->next;
            temp->next = cur_1;
            cur_1->next = prev;
            prev = cur_1;
            cur_1 = temp;
            temp = tmp;
        }
        ListNode* l1_new = cur_1;
        // while (l1_new != nullptr) {
        //     cout << l1_new->val;
        //     l1_new = l1_new->next;
        // }

        ListNode* head_2 = l2;
        ListNode* prev_2 = nullptr;
        ListNode* cur_2  = head_2;
        ListNode* temp_2 = cur_2->next;
        while (temp_2 != nullptr) {
            ListNode* tmp = temp_2->next;
            temp_2->next = cur_2;
            cur_2->next = prev_2;
            prev_2 = cur_2;
            cur_2  = temp_2;
            temp_2 = tmp;
        }
        ListNode* l2_new = cur_2;
        // while (l2_new != nullptr) {
        //     cout << l2_new->val;
        //     l2_new = l2_new->next;
        // }

        // 4 6 5
        // 3 4 2 7

        ListNode* cur = new ListNode(0);
        ListNode* listnode = new ListNode(0);
        ListNode* previous;
        listnode = cur;
        int tenFlag = 0;
        while (l1_new != nullptr || l2_new != nullptr) {  
            if (l1_new == nullptr) {
                previous->next = l2_new;
                l2_new->val += tenFlag;
                while (l2_new->val == 10) {
                    l2_new->val = 0;
                    if (l2_new->next != nullptr) {
                        l2_new->next->val += 1;
                    } else {
                        l2_new->next = new ListNode(1);
                    }
                    l2_new = l2_new->next;
                }
                break;
            }    
            if (l2_new == nullptr) {
                previous->next = l1_new;
                l1_new->val += tenFlag;
                while (l1_new->val == 10) {
                    l1_new->val = 0;
                    if (l1_new->next != nullptr) {
                        l1_new->next->val += 1;
                    } else {
                        l1_new->next = new ListNode(1);
                    }
                    l1_new = l1_new->next;
                }
                break;
            }
            int bitSum = (l1_new->val + l2_new->val + tenFlag) % 10;
            tenFlag    = (l1_new->val + l2_new->val + tenFlag) / 10;   
            cur->val = bitSum; 
            cur->next = new ListNode(0);
            previous = cur;
            cur = cur->next;
            l1_new = l1_new->next;
            l2_new = l2_new->next;
            if (l1_new == nullptr && l2_new == nullptr) {
                if (tenFlag)
                    cur->val = 1;
                break;
            }
        }
        // while (listnode->next != nullptr) {
        //     cout << listnode->val;
        //     listnode = listnode->next;
        // }

        cur  = listnode;
        prev = nullptr;
        ListNode* behind = listnode->next;
        while (behind != nullptr) {
            ListNode* tmp = behind->next;
            behind->next = cur;
            cur->next  = prev;
            prev = cur;
            cur = behind;
            behind = tmp;
        }
        if (cur->val == 0)
            return cur->next;
        return cur;
    }
};

// [6,4,5,0,4,4,9,4,1]
// [3,8,8,0,3,0,1,4,8]
// --------------------
// [1,0,3,3,0,7,5,0,8,9]


// [2,4,3]
// [5,6,4]
// ----------
// [8,0,7]

//[3,9,9,9,9,9,9,9,9,9]
//[7]

// [2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9]
// [5,6,4,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9,9,9,9]

class overflow_Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1->val)
            return l2;
        if (!l2->val)
            return l1;
        __int64_t a = 0, b = 0;
        while (l1) {
            a *= 10;
            a += l1->val;
            l1 = l1->next;
        }
        while (l2) {
            b *= 10;
            b += l2->val;
            l2 = l2->next;
        }
        __int64_t sum = a + b;
        ListNode* listnode = new ListNode(0);
        ListNode* cur      = listnode;
        while (sum) {
            int bit = sum % 10;
            ListNode* nxt = new ListNode(bit);
            cur->next = nxt;
            cur = nxt;
            sum /= 10;
        }
        // cur = 7, <- 8 <- 0 <- 7
        //               temp <- cur <- listnode(prev)

        ListNode* head = listnode->next;
        ListNode* prev = nullptr;
        cur = head;
        ListNode* temp = cur->next;

        // prev -> cur -> temp
        while (temp != nullptr) {
            ListNode* tmp = temp->next;
            temp->next = cur;
            cur->next = prev;
            prev = cur;
            cur = temp;
            temp = tmp;
        }
        return cur;
    }
};