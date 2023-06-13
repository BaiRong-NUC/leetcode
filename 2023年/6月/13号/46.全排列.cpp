#include <vector>
using namespace std;
// @lc code=start
class Solution
{

    vector<vector<int>> ret;

    void display(vector<int> &num, int left, int right)
    {
        if (left == right)
        {
            ret.push_back(num);
            return;
        }
        for (int i = left; i <= right; i++)
        {
            swap(num[i], num[left]);
            display(num, left + 1, right);
            swap(num[i], num[left]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        display(nums, 0, nums.size() - 1);
        return ret;
    }
};
//@lc code=end