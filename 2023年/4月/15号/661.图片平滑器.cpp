/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution
{
    int Smoother(vector<vector<int>> &img, int row, int col)
    {
        int ret = 0;
        int num = 0;
        // 一共三行和
        if (row - 1 >= 0)
        {
            if (col - 1 >= 0)
            {
                ret += img[row - 1][col - 1];
                num += 1;
            }
            ret += img[row - 1][col];
            num += 1;
            if (col + 1 < img[row].size())
            {
                ret += img[row - 1][col + 1];
                num += 1;
            }
        }

        if (col - 1 >= 0)
        {
            ret += img[row][col - 1];
            num += 1;
        }
        ret += img[row][col];
        num += 1;
        if (col + 1 < img[row].size())
        {
            ret += img[row][col + 1];
            num += 1;
        }
        if (row + 1 < img.size())
        {
            if (col - 1 >= 0)
            {
                ret += img[row + 1][col - 1];
                num += 1;
            }
            ret += img[row + 1][col];
            num += 1;
            if (col + 1 < img[row].size())
            {
                ret += img[row + 1][col + 1];
                num += 1;
            }
        }
        return ret / num;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        vector<vector<int>> ret;
        for (int i = 0; i < img.size(); i++)
        {
            vector<int> gray;
            for (int j = 0; j < img[i].size(); j++)
            {
                gray.emplace_back(Smoother(img, i, j));
            }
            ret.emplace_back(gray);
        }
        return ret;
    }
};
// @lc code=end
