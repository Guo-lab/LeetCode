/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> parse;

        if(root!=nullptr) parse.push(root);
        
        while(!parse.empty()) {
            vector<int> element;
            int size = parse.size();

            for(int i=0; i<size; i++) {
                Node* tmp = parse.front();
                element.push_back(tmp->val);
                parse.pop();
                int numChildren = tmp->children.size();
                for(int j=0; j<numChildren; j++) {
                    if(tmp->children[j])
                        parse.push(tmp->children[j]);
                }
            }

            result.push_back(element);
        }
        return result;        
    }
};
// @lc code=end

