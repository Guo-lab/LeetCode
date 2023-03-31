/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
// 摩尔投票法
/* 假设有一个擂台，多个门派，每个人实力相等，1vs1能同归于尽。
每次派一个人 num 登台
  如果擂台没人（count=0），就站在台上（result=num, count=1）
  如果擂台上站着的是同门，那就一起留在台上（count++） 
  如果擂台上是其他门派，则同归于尽带走一个（count--）
题目保证了，多数元素出现的次数超过了 n/2，所以最后还站在擂台上的，抗住了其他所有门派的消耗，就是胜出的了
 */
        int ans, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                ans = nums[i];
                cnt++;
                continue;
            }
            if (ans == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ans;
    }
};
// @lc code=end

class time_o_n_space_o_n_Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            tmp[nums[i]]++;
        }
        for (map<int, int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
            if (it->second > nums.size() / 2) {
                return it->first;
            }
        }
        return 0;
    }
};