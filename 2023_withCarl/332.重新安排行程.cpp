/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 *
 * https://leetcode.cn/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Hard (47.64%)
 * Likes:    777
 * Dislikes: 0
 * Total Accepted:    84.5K
 * Total Submissions: 177.1K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi]
 * 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
 * 
 * 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK
 * 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
 * 
 * 
 * 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
 * 
 * 
 * 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
 * 输出：["JFK","MUC","LHR","SFO","SJC"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * 输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
 * 解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * tickets[i].length == 2
 * fromi.length == 3
 * toi.length == 3
 * fromi 和 toi 由大写英文字母组成
 * fromi != toi
 * 
 * 
 */

// -------------------------- backtracking ----------------------
// So, 重做吧.

放入终点的方法还有：利用一维数组标记每一条路径是否取过，但是这样需要提前对 tickets 终点字典序排序
, [](vector<string>& A, vector<string>&B) { return A[1] < B[1]; }

// @lc code=start
class Solution {
public:
// multiset 删除后不可迭代
// set, map 可排序
    vector<string> ans;
    unordered_map<string, map<string, int>> flight;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++) {
            flight[tickets[i][0]][tickets[i][1]]++;
        }
        // for (int i = 0; i < tickets.size(); i++) {
        //     if (tickets[i][0] == "JFK") {
        //         bool tmp = bt(tickets, tickets[i][0]);
        //         if (tmp) return ans;
        //     }
        // }
        ans.push_back("JFK");
        if (bt(tickets, "JFK")) return ans;
        return {};
    }
    // 去重，只需要记录终点，去过的标记出来即可
    bool bt(vector<vector<string>>& tickets, string place) {
        if (ans.size() == tickets.size() + 1) {
            return true;
        }
                for (auto & destination : flight[place]) { // 传实参
                    if (destination.second > 0) {
                        ans.push_back(destination.first);
                        destination.second--;
                        if (bt(tickets, destination.first))
                            return true;
                        destination.second++;
                        ans.pop_back();
                    }
                }
        return false;
    }
};
// @lc code=end


===========================================================
[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
-----------------------------------------------------------
["JFK","ATL","JFK","SFO","ATL","SFO"]
===========================================================


===========================================================
[["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]
-------------------------
["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
===========================================================









===============================
[["BIM","VIE"],["ANU","EZE"],["PER","CNS"],["TCB","BIM"],["MEL","PER"],["VIE","ANU"],["ANU","SYD"],["SYD","PER"],["DRW","TIA"],["PER","BAK"],["EZE","BNE"],["ANU","ADL"],["BIM","MEL"],["EZE","ASD"],["SYD","JFK"],["ADL","BIM"],["AUA","EZE"],["CNS","TBI"],["DRW","ANU"],["OOL","VIE"],["DRW","TCB"],["OOL","AXA"],["TIA","BIM"],["TIA","ANU"],["ANU","MEL"],["TIA","MHH"],["SYD","AXA"],["AXA","ADL"],["SYD","ANU"],["CBR","ADL"],["CBR","TIA"],["ADL","BIM"],["TBI","DRW"],["MHH","ADL"],["MEL","HBA"],["CNS","JFK"],["VIE","CBR"],["ANU","VIE"],["BNE","HBA"],["BIM","TCB"],["JFK","BAK"],["EZE","SYD"],["AUA","BIM"],["TBI","TIA"],["MEL","JFK"],["TIA","BAK"],["BNE","VIE"],["HBA","PER"],["ANU","AUA"],["EZE","BNE"],["INN","AUA"],["TIA","ANU"],["BAK","EZE"],["INN","JFK"],["BAK","MEL"],["AUA","TCB"],["PER","BAK"],["SYD","DRW"],["LST","MEL"],["INN","BNE"],["LST","JFK"],["AXA","MEL"],["BAK","CNS"],["BNE","HBA"],["VIE","TCB"],["MHH","ASD"],["OOL","PER"],["PER","EZE"],["MEL","AXA"],["BNE","SYD"],["MEL","ANU"],["LST","DRW"],["EZE","TBI"],["ASD","AXA"],["MHH","LST"],["TIA","EZE"],["DRW","HBA"],["SYD","BGI"],["AUA","MHH"],["BIM","INN"],["AXA","VIE"],["EZE","CNS"],["JFK","BNE"],["TCB","CNS"],["ADL","CBR"],["BIM","INN"],["TBI","TCB"],["BIM","MEL"],["VIE","BNE"],["JFK","TIA"],["ADL","AUA"],["ANU","OOL"],["SYD","AUA"],["JFK","AUA"],["HBA","BIM"],["SYD","ADL"],["TCB","DRW"],["JFK","BNE"],["MHH","SYD"],["CNS","EZE"],["AXA","TIA"],["INN","SYD"],["CBR","INN"],["ADL","TIA"],["SYD","LST"],["BAK","TIA"],["DRW","INN"],["CBR","BAK"],["ASD","SYD"],["EZE","ADL"],["JFK","LST"],["BNE","OOL"],["SYD","BIM"],["ADL","EZE"],["BNE","VIE"],["BAK","PER"],["BNE","VIE"],["EZE","ASD"],["BAK","EZE"],["EZE","JFK"],["LST","BNE"],["VIE","SYD"],["BNE","VIE"],["BAK","AUA"],["ASD","LST"],["VIE","SYD"],["OOL","ADL"],["EZE","SYD"],["AUA","EZE"],["ASD","AXA"],["AXA","OOL"],["TCB","EZE"],["TBI","JFK"],["HBA","SYD"],["AXA","CBR"],["INN","BNE"],["BIM","TBI"],["ANU","OOL"],["DRW","MHH"],["BNE","ANU"],["TCB","OOL"],["TIA","CBR"],["OOL","MHH"],["VIE","ASD"],["VIE","ADL"],["HBA","DRW"],["MEL","EZE"],["PER","AXA"],["ADL","SYD"],["CNS","BNE"],["JFK","TBI"],["SYD","DRW"],["MEL","ANU"],["JFK","BAK"],["EZE","BAK"],["AUA","EZE"],["PER","INN"],["EZE","MEL"],["ADL","PER"]]
-------------------------------
["JFK","AUA","BIM","INN","AUA","EZE","ADL","AUA","EZE","ASD","AXA","ADL","BIM","INN","BNE","ANU","ADL","BIM","MEL","ANU","AUA","EZE","ASD","AXA","CBR","ADL","CBR","BAK","AUA","MHH","ADL","EZE","BAK","CNS","BNE","HBA","BIM","MEL","ANU","EZE","BNE","HBA","DRW","ANU","MEL","AXA","MEL","EZE","BNE","OOL","ADL","PER","AXA","OOL","AXA","TIA","ANU","OOL","MHH","ASD","LST","BNE","SYD","ADL","SYD","ANU","OOL","PER","BAK","EZE","CNS","EZE","JFK","BAK","EZE","MEL","HBA","PER","BAK","MEL","JFK","BAK","PER","CNS","JFK","BNE","VIE","ADL","TIA","ANU","SYD","AUA","TCB","BIM","TBI","DRW","HBA","SYD","AXA","VIE","ANU","VIE","ASD","SYD","BIM","TCB","CNS","TBI","JFK","BNE","VIE","BNE","VIE","CBR","INN","BNE","VIE","SYD","DRW","INN","JFK","LST","DRW","MHH","LST","JFK","TBI","TCB","DRW","TCB","EZE","SYD","DRW","TIA","BAK","TIA","BIM","VIE","TCB","OOL","VIE","SYD","JFK","TIA","CBR","TIA","EZE","SYD","LST","MEL","PER","EZE","TBI","TIA","MHH","SYD","PER","INN","SYD","BGI"]
===============================


找入口，存在才放入，寻找多消耗太多次循环
因此超时
但是出口必定存在，因为每一次放入出口（是下一次的入口），还能剩下判断后面还有没有入口的情况

class TLE_Solution {
public:
// multiset 删除后不可迭代
// set, map 可排序
    vector<string> ans;
    unordered_map<string, map<string, int>> flight;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++) {
            flight[tickets[i][0]][tickets[i][1]]++;
        }
        for (int i = 0; i < tickets.size(); i++) {
            if (tickets[i][0] == "JFK") {
                bool tmp = bt(tickets, tickets[i][0]);
                if (tmp) return ans;
            }
        }
        return {};
    }
    // 去重，只需要记录终点，去过的标记出来即可
    bool bt(vector<vector<string>>& tickets, string place) {
        if (ans.size() == tickets.size() + 1) {
            return true;
        }
        int cnt = 0;
        for (int i = 0; i < tickets.size(); i++) {
            //// cout << tickets[i][0] << " 2 " << tickets[i][1] << endl;
            if (tickets[i][0] == place) {
                //// cout << tickets[i][0] << " 2 " << tickets[i][1] << endl;
                for (auto & destination : flight[place]) { // 传实参
                    if (destination.second > 0) {
                        ans.push_back(place);
                        //// cout << destination.first << " " << destination.second << endl;
                        destination.second--;
                        //// cout << destination.first << " " << destination.second << endl;
                        bool tmp = bt(tickets, destination.first);
                        if (tmp == true) 
                            return true;
                        destination.second++;
                        ans.pop_back();
                    }
                }
            }
            cnt++;
        }
        if (cnt == tickets.size()) {
            ans.push_back(place);
            if (ans.size() == tickets.size() + 1) {
                return true;
            }
            ans.pop_back();
        }
        return false;
    }
};