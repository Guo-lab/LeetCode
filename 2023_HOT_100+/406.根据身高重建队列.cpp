/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    // first  ascending
    // second descending 
    // [4,4],[5,2],[5,0],[6,1],[7,1],[7,0]
    static bool cmp(vector<int> &a, vector<int> &b) {
        //X if (a[0] < b[0]) {} else {}
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
        
        // if(a[0] < b[0]) 
        //     return true;
        // else if(a[0] == b[0])
        //     if(a[1] > b[1]) 
        //         return true;
        // return false;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size());
        vector<int> idx(people.size() + 1);
        for (int i = 0; i < people.size(); i++) {
            idx[i] = i;
        }

        sort(people.begin(), people.end(), cmp);

        for (int i = 0; i < people.size(); i++) {
            ans[ idx[people[i][1]] ] = people[i];
            cout << idx[people[i][1]] << endl;
            // erase the value correponding to the idx
            // idx[x] has the idxValue in the global ans 
            auto it = find(idx.begin(), idx.end(), idx[people[i][1]]);
            idx.erase(it);
        }

        return ans;
    }
};
// @lc code=end

