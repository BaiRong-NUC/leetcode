/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        // 贪心算法
        int ret = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0))
            {
                ret += 1;
                flowerbed[i] = 1;
            }
        }
        return ret >= n;
    }
};
// @lc code=end
// struct flags
// {
//     vector<bool> _flag;
//     flags(int size) { _flag.resize(size, true); };

//     void operator[](int pos)
//     {
//         _flag[pos] = false;
//         if (pos - 1 >= 0)
//         {
//             _flag[pos - 1] = false;
//         }
//         else if (pos + 1 < _flag.size())
//         {
//             _flag[pos + 1] = false;
//         }
//     }
// };

// class Solution
// {
// public:
//     bool canPlaceFlowers(vector<int> &flowerbed, int n)
//     {
//         flags flag(flowerbed.size());
//         for (int i = 0; i < flowerbed.size(); i++)
//         {
//             if (flowerbed[i] == 1)
//             {
//                 flag[i];
//             }
//         }

//         auto &vet = flag._flag;
//         int vive = 0;
//         for (int i = 0; i < vet.size(); i++)
//         {
//             if (vet[i] == true)
//             {
//                 vive += 1;
//             }
//         }
//         cout << vive << endl;
//         return vive - 1 >= n;
//     }
// };