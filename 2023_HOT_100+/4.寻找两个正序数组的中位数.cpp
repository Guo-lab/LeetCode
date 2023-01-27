/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include<iostream>
#include<math.h>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        double midnum = 0;
        for (int i = 0, j = 0; (i < nums1.size() || j < nums2.size()); ) {
            if (i == nums1.size()) {
                if (j < nums2.size()) {
                    merge.push_back(nums2[j]);
                    j++;
                    continue;
                } else {
                    break;
                }
            }
            if (j == nums2.size()) {
                if (i < nums1.size()) {
                    merge.push_back(nums1[i]);
                    i++;
                    continue;
                } else {
                    break;
                }
            }
            if (nums1[i] <= nums2[j]) {
                merge.push_back(nums1[i]);
                i++;
            } else {
                merge.push_back(nums2[j]);
                j++;
            }
        } 
        double all = nums1.size() + nums2.size();
        int all_ = all;
        if (all_ % 2) {
            midnum = merge[round(all/2) - 1];
        } else {
            midnum = double(merge[round(all/2) - 1] + merge[round(all/2)]) / 2;
        }
    return midnum;
    }
};
// @lc code=end

