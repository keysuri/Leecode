#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // 主要是该数据结构的设计，unordered_map保证了起始点不重复，map同时又保证了大小顺序
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result) {
        if (result.size() == ticketNum + 1) return true;
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) {
                result.push_back(target.first);
                target.second --;
                if(backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second ++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        for (const auto& vec : tickets) {
            targets[vec[0]][vec[1]] ++;
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution solution;
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> result = solution.findItinerary(tickets);
    for (const string& s : result) {
        cout << s << " ";
    }
}