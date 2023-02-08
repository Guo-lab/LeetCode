/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1)  {
            return root;
        } else {
            int position;
            for (position = 0; position < inorder.size(); position++) {
                if (inorder[position] == root->val) break;
            }
            cout << position << endl;
            if (position == inorder.size() - 1) {
                root->right = nullptr;
                root->left = new TreeNode(preorder[1]);
                cout << "ok 1" << endl;
                dfsBuild(root->left, preorder, inorder, 1, preorder.size() - 1, 0, position - 1);
            } else if (position == 0) {
                root->left = nullptr;
                root->right = new TreeNode(preorder[1]);
                cout << "ok 2" << endl;
                dfsBuild(root->right, preorder, inorder, 1, preorder.size() - 1, position + 1, inorder.size() - 1);
            } else {
                int pos;
                /*for (pos = 0; pos < preorder.size(); pos++)
                    if (inorder[position - 1] == preorder[pos]) break; */ // Cannot do this
                pos = 0 + 1 + position - 0;
                cout << "ok 3" << endl;
                root->left = new TreeNode(preorder[1]);
                root->right = new TreeNode(preorder[pos]);
                cout << root->left->val << " " << root->right->val << endl;
                dfsBuild(root->left, preorder, inorder, 1, pos - 1, 0, position - 1);
                dfsBuild(root->right, preorder, inorder, pos, preorder.size() - 1, position + 1, inorder.size() - 1);
            }
            return root;
        }
    }
    void dfsBuild(TreeNode* root, vector<int>& preorder, vector<int>& inorder, int lPre, int rPre, int lIn, int rIn) {
        if (lPre == rPre || lIn == rIn) {
            root->left = nullptr;
            root->right = nullptr;
            cout << "ok 4" << endl;
            return;
        } else {
            root->val = preorder[lPre]; // same as root->right = new TreeNode(preorder[pos + 1]);
            int position;
            for (position = lIn; position <= rIn; position++) {
                if (inorder[position] == root->val) break;
            }
            if (position == rIn) {
                root->right = nullptr;
                root->left = new TreeNode(preorder[lPre + 1]);
                cout << "ok 5" << endl;
                dfsBuild(root->left, preorder, inorder, lPre + 1, rPre, lIn, position - 1);
            } else if (position == lIn) {
                root->left = nullptr;
                root->right = new TreeNode(preorder[lPre + 1]);
                cout << "ok 6" << endl;
                dfsBuild(root->right, preorder, inorder, lPre + 1, rPre, position + 1, rIn);
            } else {
                int pos;
                /*for (pos = lPre; pos <= rPre; pos++)
                    if (inorder[position - 1] == preorder[pos]) break; */
                pos = lPre + 1 + (position - lIn);
                cout << "ok 7" << endl;
                root->left = new TreeNode(preorder[lPre + 1]);
                root->right = new TreeNode(preorder[pos]);  
                dfsBuild(root->left, preorder, inorder, lPre + 1, pos - 1, lIn, position - 1);
                dfsBuild(root->right, preorder, inorder, pos, rPre, position + 1, rIn);     
            }                          
        }
    }
};
// @lc code=end

/**
 * @brief Init
 * TreeNode a(0); TreeNode* tmp = &a; Not Work
 */

/**
 * @brief case
 * [1,2,3,4]\n[1,2,3,4]\n
 * Answer
 * [1,null,2,null,3,null,4]
 * 
 * [3,2,1,4]\n[1,2,3,4]\n 
 * [3,2,4,1]
 */