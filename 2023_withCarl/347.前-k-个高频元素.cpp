/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.51%)
 * Likes:    1533
 * Dislikes: 0
 * Total Accepted:    416.8K
 * Total Submissions: 656.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 * 
 * 
 * 
 * 
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 * 
 */

// ------------------ S & Q -----------------

// 频率高的想要保留就得用小顶堆
// 这里锻炼了
// 1 cmp 自定义 仿函数：https://blog.csdn.net/Strengthennn/article/details/119078911#:~:text=%E4%B8%89%E3%80%81priority_queue%E8%87%AA%E5%AE%9A%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B%E5%92%8C%E8%87%AA%E5%AE%9A%E4%B9%89%E6%8E%92%E5%BA%8F%E6%96%B9%E5%BC%8F%201%201.%20%E4%BD%BF%E7%94%A8%E8%87%AA%E5%AE%9A%E4%B9%89%E7%B1%BB%E5%9E%8B%E6%AF%94%E8%BE%83%E5%85%B3%E7%B3%BB%202%202.,%E4%BD%BF%E7%94%A8%E4%BB%BF%E5%87%BD%E6%95%B0%EF%BC%88%E5%87%BD%E6%95%B0%E5%AF%B9%E8%B1%A1%EF%BC%89%203%203.%20%E4%BD%BF%E7%94%A8lambda%E8%A1%A8%E8%BE%BE%E5%BC%8F%204%204.%20%E4%BD%BF%E7%94%A8%E5%87%BD%E6%95%B0%E6%8C%87%E9%92%88
// 2 priority_queue 排序

// 大顶堆 小顶堆 底层
// https://blog.csdn.net/weixin_43744293/article/details/118544078 

// @lc code=start
class Solution {
public:
    class _cmp {
        public:
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        } // important
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, _cmp> heap; // important
        for (auto x : count) {
            if (heap.size() < k) {
                heap.push(x);
            } else {
                if (x.second < heap.top().second)
                    continue;
                heap.pop();
                heap.push(x);
            }
        }
        stack<int> tmp;
        while (!heap.empty()) { // priority_queue no begin
            tmp.push(heap.top().first);
            heap.pop();
        }
        vector<int> res;
        while (!tmp.empty()) {
            res.push_back(tmp.top());
            tmp.pop();
        }
        return res;
    }
};
// @lc code=end

-------------------------------
[3,0,1,0]
1
------
[0]
