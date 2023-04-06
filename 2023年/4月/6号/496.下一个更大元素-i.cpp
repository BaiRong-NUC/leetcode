/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;
/**
 *
 *
1. 先遍历大数组nums2，首先将第一个元素入栈；
2. 继续遍历，当当前元素小于栈顶元素时，继续将它入栈；当当前元素大于栈顶元素时，栈顶元素出栈，此时应将该出栈的元素与当前元素形成key-value键值对，存入HashMap中；
3. 当遍历完nums2后，得到nums2中元素所对应的下一个更大元素的hash表；
4. 遍历nums1的元素在hashMap中去查找‘下一个更大元素’，当找不到时则为-1。
 *
 */

// @lc code=start
class Solution
{
    unordered_map<int, int> _hash;

public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        vector<int> ret;
        st.push(nums2[0]);
        for (int i = 1; i < nums2.size(); i++)
        {
            if (st.empty() || nums2[i] < st.top())
            {
                st.push(nums2[i]);
            }
            else
            {
                while (!st.empty() && st.top() < nums2[i])
                {
                    // cout << st.top() << ":" << nums2[i] << endl;
                    _hash[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if (_hash.find(nums1[i]) != _hash.end())
            {
                ret.push_back(_hash[nums1[i]]);
            }
            else
            {
                ret.push_back(-1);
            }
        }
        return ret;
    }
};
// @lc code=end
