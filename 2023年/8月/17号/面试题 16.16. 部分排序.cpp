#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> subSort(vector<int> &array)
    {
        vector<int> res{-1, -1};
        int n = array.size();
        if (n > 0)
        {
            // 从后往前遍历，得到l
            int currMin = INT_MAX;
            for (int i = n - 1; i >= 0; --i)
            {
                if (array[i] > currMin)
                {
                    res[0] = i;
                }
                else
                {
                    currMin = min(currMin, array[i]);
                }
            }

            // 从前往后遍历，得到r
            int currMax = INT_MIN;
            for (int i = 0; i < n; ++i)
            {
                // cout << array[i] << " vs " << currMax << endl;
                if (array[i] < currMax)
                {
                    res[1] = i;
                }
                else
                {
                    currMax = max(currMax, array[i]);
                }
            }
        }

        return res;
    }
};