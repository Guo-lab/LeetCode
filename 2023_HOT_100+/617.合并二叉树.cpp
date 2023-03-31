/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        if (!root1 || !root2) return !root1 ? root2 : root1;
        root1->val += root2->val;
        if (root1->left != nullptr && root2->left != nullptr)
            dfs(root1->left, root2->left);
        else if (!root1->left)
            root1->left = root2->left;
        
        if (root1->right && root2->right)
            dfs(root1->right, root2->right);
        else if (!root1->right)
            root1->right = root2->right;

        return root1;
    }
    void dfs(TreeNode* root1, TreeNode* root2) {
        root1->val += root2->val;
        // cout << root1->val << endl;
        if (root1->left && root2->left)
            dfs(root1->left, root2->left);
        else if (!root1->left)
            root1->left = root2->left;

        if (root1->right && root2->right)
            dfs(root1->right, root2->right);
        else if (!root1->right) {
            root1->right = root2->right;
            // cout << root1->right->val << endl;
        }
    }
};
// @lc code=end

//[1,3,2,5]\n[2,1,3,null,4,null,7]\n
//[3,4,5,5,4,null,7]

class WA_null_pointer_Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        if (!root1 || !root2) return !root1 ? root2 : root1;
        root1->val += root2->val;
        dfs(root1->left, root2->left);
        dfs(root1->right, root2->right);
        return root1;
    }
    void dfs(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return;
        if (!root1) {
            cout << root2->val << endl;
            root1 = root2;
        }
        if (!root2)
            return;
        root1->val += root2->val;
        dfs(root1->left, root2->left);
        dfs(root1->right, root2->right);
    }
};




//@ 好吧我还是复杂了

class Official_Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null) {
            return t2;
        }
        if (t2 == null) {
            return t1;
        }
        TreeNode merged = new TreeNode(t1.val + t2.val);
        merged.left = mergeTrees(t1.left, t2.left);
        merged.right = mergeTrees(t1.right, t2.right);
        return merged;
    }
}