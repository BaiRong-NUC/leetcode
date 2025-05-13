// 字符串的暴力匹配算法
#include <iostream>
#include <string>
using namespace std;

// 字符串的暴力匹配算法,返回src中dst的第一个匹配位置,如果没有匹配,返回-1
int BF(string &src, string &dst)
{
    if (src.size() == 0 || dst.size() == 0 || src.size() < dst.size())
    {
        return -1;
    }
    int posSrc = 0;
    int posDst = 0;
    while (posSrc < src.size() && posDst < dst.size())
    {
        if (src[posSrc] == dst[posDst])
        {
            posSrc++;
            posDst++;
        }
        else
        {
            // 不匹配，已经匹配的长度posDst
            posSrc = posSrc - posDst + 1;
            posDst = 0;
        }
    }
    if (posDst == dst.size())
    { // 匹配成功
        return posSrc - posDst;
    }
    else
    {
        // 匹配失败
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    std::string src = "detabcdetdet";
    std::string dst = "def";
    int pos = BF(src, dst);
    cout << pos << endl;
    return 0;
}
