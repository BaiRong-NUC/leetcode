/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
        {
            return {1};
        }
        vector<vector<int>> bf;
        bf.resize(rowIndex + 1);
        bf[0].push_back(1);
        bf[1].push_back(1);
        bf[1].push_back(1);

        for (int i = 2; i <= rowIndex; i++)
        {
            bf[i].resize(i + 1, 1);
            for (int j = 1; j < bf[i].size() - 1; j++)
            {
                bf[i][j] = bf[i - 1][j - 1] + bf[i - 1][j];
            }
        }
        return bf[rowIndex];
    }
};
// @lc code=end
