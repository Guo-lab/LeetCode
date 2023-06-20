/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 *
 * https://leetcode.cn/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (42.19%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    29.3K
 * Total Submissions: 69.4K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 在本问题中，有根树指满足以下条件的 有向
 * 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
 * 
 * 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n
 * 中的两个不同顶点间，这条附加的边不属于树中已存在的边。
 * 
 * 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是
 * vi 的一个父节点。
 * 
 * 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：edges = [[1,2],[1,3],[2,3]]
 * 输出：[2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * 输出：[4,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == edges.length
 * 3 
 * edges[i].length == 2
 * 1 i, vi 
 * 
 * 
 */

// @lc code=start

// ------------------------ Disjoint Set -----------------------

class Solution {
public:
    // ===========================================
    vector<int> father = vector<int> (1005, 0); 
    void init() {
        for (int i = 0; i < 1005; i++) father[i] = i;
    }
    int find(int u) {
        return father[u] == u ? u : father[u] = find(father[u]);
    }
    bool isSame(int u, int v) {
        return find(u) == find(v);
    }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
    // ===========================================

    bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int deletedEdge) {
        init();
        for (int i = 0; i < edges.size(); i++) {
            if (i == deletedEdge) 
                continue;
            if (isSame(edges[i][0], edges[i][1])) // 构成有向环了，一定不是树
                return false;
            else
                join(edges[i][0], edges[i][1]);
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) { // 图保证了连通
        vector<int> e;
        vector<int> indegree(1005);
        for (int i = edges.size() - 1; i >= 0; i--) {
            indegree[edges[i][1]]++;
        }
        for (int i = edges.size() - 1; i >= 0; i--) { // 成对出现的入度为2
            if (indegree[edges[i][1]] > 1)
                e.push_back(i);
        }
        if (e.size() > 0) {
            if (isTreeAfterRemoveEdge(edges, e[0]))
                return edges[e[0]];
            else
                return edges[e[1]];
        }

        // ----------- 没有入度为 2 的节点，一定有向环 -----------
        init();
        for (int i = 0; i < edges.size(); i++) {
            if (isSame(edges[i][0], edges[i][1])) // ---- 根同
                return edges[i];
            else
                join(edges[i][0], edges[i][1]);
        }
        return {};
    }
};
// @lc code=end


============================ 成环的情况 有入度为 2 的节点
[[2,1],[3,1],[4,2],[1,4]]
-------------------------
[2,1]
============================

* 2 -> 1
3 -> 1
* 4 -> 2
* 1 -> 4