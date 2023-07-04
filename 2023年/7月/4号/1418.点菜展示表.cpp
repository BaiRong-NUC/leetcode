/*
 * @lc app=leetcode.cn id=1418 lang=cpp
 *
 * [1418] 点菜展示表
 */
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
/**
Accepted
53/53 cases passed (188 ms)
Your runtime beats 66.67 % of cpp submissions
Your memory usage beats 48 % of cpp submissions (73.3 MB)
 */
// @lc code=start
class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        // 统计点餐名称
        unordered_set<string> nameSet;
        // 记录每桌的点餐信息 桌号:点餐名称+点餐数目
        unordered_map<int, unordered_map<string, int>> foodMap;
        for (int i = 0; i < orders.size(); i++)
        {
            nameSet.insert(orders[i][2]);
            foodMap[atoi(orders[i][1].c_str())][orders[i][2]] += 1;
        }

        vector<string> foodName;
        for (string food : nameSet)
        {
            foodName.push_back(food);
        }
        sort(foodName.begin(), foodName.end());

        vector<int> tableId;
        for (auto &[id, _] : foodMap)
        {
            tableId.push_back(id);
        }
        sort(tableId.begin(), tableId.end());

        // 填写表单
        vector<vector<string>> Menu(tableId.size() + 1, vector<string>(foodName.size() + 1));
        Menu[0][0] = "Table";
        std::copy(foodName.begin(), foodName.end(), Menu[0].begin() + 1);
        for (int i = 0; i < tableId.size(); i++)
        {
            int id = tableId[i];
            unordered_map<string, int> foods = foodMap[id];
            Menu[i + 1][0] = to_string(id);
            for (int j = 0; j < foodName.size(); j++)
            {
                Menu[i + 1][j + 1] = to_string(foods[foodName[j]]);
            }
        }
        return Menu;
    }
};
// @lc code=end
