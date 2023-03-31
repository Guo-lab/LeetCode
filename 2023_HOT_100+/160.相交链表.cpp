/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { // 还是使用双指针，跳过思想
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        int lengthA = 0, lengthB = 0;
        while (tmpA != nullptr) {
            lengthA++;
            tmpA = tmpA->next;
        }
        while (tmpB != nullptr) {
            lengthB++;
            tmpB = tmpB->next;
        }
        int skip = lengthA >= lengthB ? lengthA - lengthB : lengthB - lengthA;
        if (lengthA >= lengthB) {
            for (int i = 0; i < skip; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < skip; i++) {
                headB = headB->next;
            }
        }
        while (headA != nullptr) { // && headB != nullptr
            if (headA == headB) return headA;
            else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end




/**
 *X @brief Wrong again Reason: 节点相同为交叉点，不是数值相等... 
 */
class Wrong_2_Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<int> lista;
        vector<int> listb;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;
        while (headA != nullptr)
        {
            lista.push_back(headA->val);
            headA = headA->next;
        }
        while (headB != nullptr)
        {
            listb.push_back(headB->val);
            headB = headB->next;
        }
        int pointa = lista.size() - 1;
        int pointb = listb.size() - 1;
        int ansPos = -1;
        while (pointa >= 0 && pointb >= 0) {
            if (lista[pointa] != listb[pointb]) {
                break;
            }
            ansPos = pointa;
            pointa--;
            pointb--;
        }
        // -1 -> nullptr
        // 
        if (ansPos == -1) return nullptr;
        else {
            ListNode* ans = tmpA;
            for (int i = 0; i < ansPos; i++) {
                tmpA = tmpA->next;
            }
            return tmpA;
        }
    }
};

/**
 *X @brief Wrong Reason: find() only return th first one
 */
class Wrong_Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<int> lista;
        while (headA != nullptr)
        {
            lista.push_back(headA->val);
            headA = headA->next;
        }
        ListNode* result;
        int index = -1;
        while (headB != nullptr)
        {
            if (find(lista.begin(), lista.end(), headB->val) != lista.end()) {
                int pos = distance(lista.begin(), find(lista.begin(), lista.end(), headB->val));
                if (index == -1) {
                    cout << "first" << endl;
                    cout << pos << endl;
                    index = pos;
                    result = headB;
                } else {
                    if (index + 1 == pos) { //? Wrong
                        cout << "second" << endl;
                        cout << pos << endl;
                        index++;
                    } else {
                        index = pos;
                        result = nullptr;
                    }
                }
            } else {
                index = -1;
                result = nullptr;
            }
            headB = headB->next;
        }
    return result;
    }
};