#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s = "abaaabba";
    string t = "abbaaa";
    int len1 = s.length(), len2 = t.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    int ans = 0, pos = 0;

    string ret;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > ans)
                {
                    ans = dp[i][j];
                    pos = i - ans;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    ret = s.substr(pos, ans);
    cout << "AllStr:" << ret << endl;

    return 0;
}