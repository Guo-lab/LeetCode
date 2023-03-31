/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
// 三种状态 未搜索，搜索中，搜索完毕
// 拓扑无环
    vector<vector<int>> edge;
    vector<int>      visited;
    bool             isValid;
// 加上栈，可见拓扑顺序

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        visited.resize(numCourses);
        isValid = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // *** 以 dfs(n) 中的 n 做源点的边
        for (int i = 0; i < numCourses; i++) {
            if (isValid == false) 
                break;
            dfs(i);
        }

        return isValid;
    }

    void dfs(int edge_idx) {
        // 正在搜索
        visited[edge_idx] = 1;
        if (edge[edge_idx].size() == 0) {
            // 没有能够达到的点了，结束这条路的搜索
            visited[edge_idx] = 2;
            cout << edge_idx << endl;
            return;
        }

        for (int end = 0; end < edge[edge_idx].size(); end++) {
            if (visited[edge[edge_idx][end]] == 1) {
                isValid = false;
                return;
            }
            else if (visited[edge[edge_idx][end]] == 0) {
                dfs(edge[edge_idx][end]);
            }

            if (isValid == false)
                return;
        }
        // for end
        // stop check        
        visited[edge_idx] = 2;

    }

};
// @lc code=end


// 2\n[[0,1]]\n
// true

// 5\n[[1,4],[2,4],[3,1],[3,2]]\n
// true

// 3\n[[1,0],[2,0],[0,2]]\n
// false