/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{

    int order(vector<int> &vet, int left, int right)
    {
        int target = vet[left];
        while (left < right)
        {
            while (right > left && vet[right] >= target)
            {
                right -= 1;
            }
            vet[left] = vet[right];
            while (left < right && vet[left] <= target)
            {
                left += 1;
            }
            vet[right] = vet[left];
        }
        vet[left] = target;
        return left;
    }

    //[left-right]
    void _sort(vector<int> &vet, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = order(vet, left, right);
        _sort(vet, left, mid - 1);
        _sort(vet, mid + 1, right);
    }

    void _sort(vector<int> &nums)
    {
        _sort(nums, 0, nums.size() - 1);
    }

public:
    int maximumProduct(vector<int> &nums)
    {
        _sort(nums);
        int size = nums.size();
        return max(nums[size - 1] * nums[size - 2] * nums[size - 3], nums[0] * nums[1] * nums[size - 1]);
    }
};
// @lc code=end
