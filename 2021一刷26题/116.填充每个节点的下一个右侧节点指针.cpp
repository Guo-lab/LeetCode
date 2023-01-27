/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<char> result;
        queue<Node*> parse;

        if(root!=nullptr) parse.push(root);
        
        while(!parse.empty()) {
            int size = parse.size();
            Node* head;
            for(int i=0; i<size; i++) {
                auto tmp = parse.front();
                if(i!=0)
                    head->next = tmp;
                head = parse.front();
                parse.pop();
                if(tmp->left) parse.push(tmp->left);
                if(tmp->right) parse.push(tmp->right);
            }
        }
        return root;      
    }
};
// @lc code=end

