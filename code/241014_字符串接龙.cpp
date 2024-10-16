#include <bits/stdc++.h>
using namespace std;
bool isConvert(const string& str1, const string& str2) {
    int count = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i]!= str2[i]) count++;
        if (count > 1) return false;
    }
    return true;
}
//bfs找最短
int main () {
    int n;
    cin >> n;
    string beginStr, endStr, str;
    cin >> beginStr >> endStr;
    unordered_set<string> strSet;
    for (int i = 0; i < n; i++) {
        cin >> str;
        strSet.insert(str);
    }
    strSet.insert(endStr);// 加入endStr，用于下面遍历
    queue<string> q;

    unordered_map<string, int> visitedMap;// 记录当前字符串到beginStr的距离
    q.push(beginStr);
    visitedMap.insert({beginStr, 1});
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        if (cur == endStr) break;
        int path = visitedMap[cur];
        for (const string& ss : strSet) {
            if (ss != cur && visitedMap.find(ss) == visitedMap.end() && isConvert(ss, cur)) {
                q.push(ss);
                visitedMap[ss] = path + 1;
            }
        }
    }
    cout << visitedMap[endStr];
}