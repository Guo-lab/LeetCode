/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 *
 * https://leetcode.cn/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (67.48%)
 * Likes:    571
 * Dislikes: 0
 * Total Accepted:    98K
 * Total Submissions: 145.2K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 树可以看成是一个连通且 无环 的 无向 图。
 * 
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n
 * 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai
 * 和 bi 之间存在一条边。
 * 
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * 输出: [1,4]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * edges 中无重复元素
 * 给定的图是连通的 
 * 
 * 
 */

// ------------------------ Disjoint Set -----------------------

// @lc code=start
class Solution {
public:                       
    vector<int> father = vector<int> (1005, 0);
    void init() {
        for (int i = 0; i < 1005; ++i)
            father[i] = i;
    }
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    bool isSame(int u, int v) {
        return find(u) == find(v);
    }
    void join(int u, int v) {
        u = find(u); 
        v = find(v);
        if (u == v) return ;
        father[v] = u;
        //cout << father[v] << " -> " << v << endl;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        // father[0]    = 0
        // father[1]    = 1
        // ...
        // father[1004] = 1004
        for (int i = 0; i < edges.size(); i++) {
            if (isSame(edges[i][0], edges[i][1]))
                return edges[i];
            else
                join(edges[i][0], edges[i][1]);
                // father[2] = 1
                // father[3] = 2 -> 1
                // father[4] = 3 -> 1
                // isSame(1,4)
        }
        
        return {};
    }
};
// @lc code=end



// =============================================================
// ====================== Template: ============================ 

int n = 1005; // n 根据题目中节点数量而定，比节点数量大一点就好                            
vector<int> father = vector<int> (n, 0);

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        father[i] = i;
    }
}
// 并查集里寻根的过程
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]); // 路径压缩
}
1->2 father[1] = 2 
2->3 father[2] = 3
3->4 father[3] = 4
1->4 father[1] = 4
1->5 father[1] = 5


// 判断 u 和 v 是否找到同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}

// 将 v -> u 这条边加入并查集
void join(int u, int v) {
    u = find(u); // 寻找u的根
    v = find(v); // 寻找v的根
    if (u == v) return ; // 如果发现根相同，则说明在一个集合，不用两个节点相连直接返回
    father[v] = u;
}

// =============================================================
// =============================================================