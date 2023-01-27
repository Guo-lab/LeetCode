/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        if(g.size()==0 || s.size()==0) return 0;

        int size = g.size();
        int sIndex = s.size() - 1;
        int satisfied = 0;
        for(int i=size-1; i>=0; i--) {
            if(s[sIndex]>=g[i]) {
                sIndex--;
                satisfied++;
                if(sIndex<0) break;
            }
        }
        return satisfied; 
    }
};
// @lc code=end

