/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start = 0;
        int end = k - 1;
        priority_queue<pair<int, int>> window;
        vector<int> max_in_window(nums.size() - k + 1);
        for (int i = 0; i < k; i++) {
            // priority queue sort first
            window.push(make_pair(nums[i], i));
        }
        max_in_window[0] = window.top().first;
        ////cout << max_in_window[0] << endl;

        for (; end < nums.size();) {
            if (end + 1 == nums.size()) 
                break;
            ////cout << start << " " << end << endl;
            window.emplace(nums[end + 1], end + 1);
            start++;
            end++;
            while (window.top().second < start) { 
                window.pop();
            }

            max_in_window[start] = window.top().first;
        }

        return max_in_window;
    }
};
// @lc code=end

//[1, -1]\n1\n
//[1, -1]

//[1,3,1,2,0,5]\n3\n
//[3,3,2,5]

//[9,10,9,-7,-4,-8,2,-6]\n5\n
//[10,10,9,2]

//[-7,-8,7,5,7,1,6,0]\n4\n
//[7,7,7,7,7]

class Time_Limit_Exceeded_Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start, end = k - 1;
        vector<int> max_in_window(nums.size() - k + 1);
        int currentmax   = max_in_k(nums, 0, k - 1); 
        max_in_window[0] = currentmax;

        for (; end < nums.size();) {
            if (nums[start] == currentmax) {
                currentmax = max_in_k(nums, start + 1, end);
            }
            if (end + 1 == nums.size()) 
                break;
            if (nums[end + 1] > currentmax) {
                currentmax = nums[end + 1];
            }
            start++;
            end++;
            max_in_window[start] = currentmax;
        }

        return max_in_window;
    }

    int max_in_k(vector<int>& nums, int l, int r) {
        int max_num = -100000;
        for (int i = l; i <= r; i++) {
            if (nums[i] > max_num)
                max_num = nums[i];
        }
        return max_num; 
    }
};





class Worse_Time_Limit_Exceeded_Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start, end = k - 1;
        priority_queue<int> window;
        window.push(-100000);
        stack<int> tmp;
        vector<int> max_in_window(nums.size() - k + 1);
        for (int i = 0; i < k; i++) {
            window.push(nums[i]);
        }
        max_in_window[0] = window.top();

        for (; end < nums.size();) {
            if (nums[start] == window.top()) {
                window.pop();
            } else {
                while (window.top() != nums[start]) {
                    tmp.push(window.top());
                    window.pop();
                }
                window.pop();
                while (!tmp.empty()) {
                    window.push(tmp.top());
                    tmp.pop();
                }
            }

            if (end + 1 == nums.size()) 
                break;
            
            window.push(nums[end + 1]);
            start++;
            end++;
            max_in_window[start] = window.top();
        }

        return max_in_window;
    }
};