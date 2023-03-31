/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
public:
    /// @brief 先尝试 Floyd https://www.cnblogs.com/wangyuliang/p/9216365.html (Copy line by line)
    /// @param equations 
    /// @param values 
    /// @param queries 
    /// @return 
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int howManyNodes = 0;
        unordered_map<string, int> nodeIdx;
        for (int i = 0; i < equations.size(); i++) {
            if (nodeIdx.find(equations[i][0]) == nodeIdx.end()) {
                // 没找到，该节点为新节点，为其注册 idx
                nodeIdx[equations[i][0]] = howManyNodes;
                howManyNodes++;
            }
            if (nodeIdx.find(equations[i][1]) == nodeIdx.end()) {
                nodeIdx[equations[i][1]] = howManyNodes;
                howManyNodes++;
            }
        }

        vector<vector<double>> Graph(howManyNodes, vector<double>(howManyNodes, -1.0));
        // In Graph, a -> b means a / b (a ratio)
        for (int i = 0; i < equations.size(); i++) {
            Graph[nodeIdx[equations[i][0]]][nodeIdx[equations[i][1]]] = values[i];
            Graph[nodeIdx[equations[i][1]]][nodeIdx[equations[i][0]]] = 1.0 / values[i];
        }
        // Floyd, a->b->c === a->c (if a->c = ∞)
        for (int transfer = 0; transfer < howManyNodes; transfer++) {
            for (int i = 0; i < howManyNodes; i++) {
                for (int j = 0; j < howManyNodes; j++) {
                    if (Graph[i][transfer] > 0 && Graph[transfer][j] > 0) {
                        Graph[i][j] = Graph[i][transfer] * Graph[transfer][j];
                    }
                }
            }
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            double result = -1.0;
            if (nodeIdx.find(queries[i][0]) != nodeIdx.end() && nodeIdx.find(queries[i][1]) != nodeIdx.end()) {
                if (Graph[nodeIdx[queries[i][0]]][nodeIdx[queries[i][1]]] > 0)
                    result = Graph[nodeIdx[queries[i][0]]][nodeIdx[queries[i][1]]];
            }
            ans.push_back(result);
        }
        return ans;
    }
};
// @lc code=end

