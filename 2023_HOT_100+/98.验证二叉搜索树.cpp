/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return false;
        else {
            ////cout << LONG_MIN << " " << LONG_MAX << endl;
            if (root->left != nullptr && root->left->val >= root->val) return false;
            else if (root->right != nullptr && root->right->val <= root->val) return false;
            else return isValDfs(root->left, LONG_MIN, root->val) & isValDfs(root->right, root->val, LONG_MAX);
        }
    }
    bool isValDfs(TreeNode* root, long long low, long long up) {
        if (root == nullptr) return true;
        else {
            if (root->left != nullptr && root->left->val >= root->val) return false;
            else if (root->right != nullptr && root->right->val <= root->val) return false;
            else if (root->right != nullptr && root->right->val >= up) return false;
            else if (root->left != nullptr && root->left->val <= low) return false;
            else return isValDfs(root->left, low, root->val) & isValDfs(root->right, root->val, up);
        }
    }
};
// @lc code=end

/**
 * @brief case
 * [5,4,6,null,null,3,7]\n 
 * false
 * 
 * [120,70,140,50,100,130,160,20,55,75,110,119,135,150,200]\n
 * false
 * 
 * [32,26,47,19,null,null,56,null,27]\n 
 * false
 * 
 * [3,1,5,0,2,4,6]\n 
 * true
 */

/**
 * @brief  我的愚蠢的思路 少穿一参边界无法收敛
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return false;
        else if(root->left != nullptr && root->left->val >= root->val) return false;
        else if(root->right != nullptr && root->right->val <= root->val) return false;
        else {
            bool isV = false;
            isV = isLeftValidDfs(root->left, root->val) & isRightValidDfs(root->right, root->val);
            return isV;
        }
    }
    bool isLeftValidDfs(TreeNode* root, int val){
        if (root == nullptr) return true;
        else if(root->left != nullptr && root->left->val >= root->val) return false;
        else if(root->right != nullptr && root->right->val <= root->val) return false;
        else if(root->right != nullptr && root->right->val >= val) return false;
        else {
            bool isV = false;
            isV = isLeftValidDfs(root->left, root->val) & isRightValidDfs(root->right, root->val);
            return isV;            
        }
    }
    bool isRightValidDfs(TreeNode* root, int val){
        if (root == nullptr) return true;
        else if(root->left != nullptr && root->left->val >= root->val) return false;
        else if(root->right != nullptr && root->right->val <= root->val) return false;
        else if(root->left != nullptr && root->left->val <= val) return false;
        else {
            bool isV = false;
            isV = isLeftValidDfs(root->left, root->val) & isRightValidDfs(root->right, root->val);
            return isV;            
        }
    }
 */


/**
 * @brief 记录上一个，相当于遍历了每一个
class Solution {
public:
    int* last = NULL;
    bool isValidBST(TreeNode* root) {
        if (root){
            if(!isValidBST(root->left)) return false;
            if (last && *last>=root->val) return false;
            last = &root->val;
            if(!isValidBST(root->right)) return false;
            return true;
        }else return true;
    };
};
 * 
 */