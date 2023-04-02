/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image)
    {
        for (int i = 0; i < image.size(); i++)
        {
            std::reverse(image[i].begin(), image[i].end());
            for (int j = 0; j < image[i].size(); j++)
            {
                image[i][j] = image[i][j] ^ 1;
            }
        }
        return image;
    }
};
// @lc code=end
