/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.17%)
 * Likes:    1368
 * Dislikes: 0
 * Total Accepted:    528.3K
 * Total Submissions: 684.9K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 
 * 你可以按 任何顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */


// -------------------------- backtracking ----------------------
// * https://www.zhihu.com/question/361977014/answer/2317295275
//
// backTrack   ----、___ Recursion
// DFS         ____/

// void backtracking(参数) {
//     if (终止条件) {
//         存放结果;
//         return;
//     }

//     for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
//         处理节点;
//         backtracking(路径，选择列表); // 递归
//         回溯，撤销处理结果
//     }
// }

// -------------------------- backtracking ----------------------

// @lc code=start
class Solution {
public:

    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        vector<int> each;
        bt(each, 0, k, n, 0);
        return ans;
    }
    void bt(vector<int> &each, int x, int k, int n, int idx) {
        if (x == k) { // 变量 x 可以用 each.size()
            ans.push_back(each);
            return;
        }
        for (int i = idx; i < n; i++) {
            each.push_back(i + 1);
            bt(each, x + 1, k, n, i + 1);
            each.pop_back();
        }
    }
};
// @lc code=end

// 注意 idx 这个参数

//! 其次
可以 i <= n - (k - path.size()) + 1 剪枝
