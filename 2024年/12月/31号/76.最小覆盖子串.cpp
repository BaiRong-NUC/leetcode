/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <D:\CppCode\leetcode\global\global.h>
// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, window;
        for (auto &ch : t)
        {
            need[ch] += 1;
        }
        int left = 0, right = 0;      //[left,right)
        int valid = 0;                // 判断窗口中是否已经包含了t中所有字符
        int start = 0, len = INT_MAX; // start 记录最小覆盖子串的起始索引，len记录最小覆盖子串的长度
        while (right < s.size())
        {
            // 因为是[left,right)，所ch是将要进入窗口的字符
            char ch = s[right];
            right++;
            if (need.count(ch))
            {
                window[ch]++;
                if (window[ch] == need[ch])
                {
                    valid++;
                }
            }
            // 收缩左区间
            while (valid == need.size())
            {
                // 更新最小覆盖子串
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                // 将要移出窗口的字符
                char ch = s[left];
                left++;
                if (need.count(ch))
                {
                    if (window[ch] == need[ch])
                    {
                        // 移除了必须字符，且移除前这个字符的数量正好满足匹配need，所以valid--
                        valid--;
                    }
                    window[ch]--;
                }
            }
        }
        // 返回最小覆盖子串
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    s.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}
