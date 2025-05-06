#include <string>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

// 使用KMP算法返回src第一个匹配dst的位置,下标从0开始,从src的pos位置开始匹配
void InitNext(const string &dst, vector<int> &next)
{
    next[0] = -1;
    next[1] = 0;
    int k = 0;
    for (int i = 2; i < dst.size(); i++)
    {
        k = next[i - 1];
        while (k != -1 && dst[i - 1] != dst[k])
        {
            k = next[k];
        }
        next[i] = k + 1;
    }
}

// 在InitNext函数的基础上优化得到nextval数组
// 计算优化后的next数组，即nextval数组
void InitNextval(const string &dst, vector<int> &nextval)
{
    vector<int> next(nextval.size(), -1);
    next[0] = -1;
    next[1] = 0;
    nextval[0] = -1, nextval[1] = 0;
    int k = 0;
    for (int i = 2; i < dst.size(); i++)
    {
        k = next[i - 1];
        while (k != -1 && dst[i - 1] != dst[k])
        {
            k = next[k];
        }
        next[i] = k + 1;
        if (i < dst.size() && dst[i] == dst[next[i]])
        {
            nextval[i] = nextval[next[i]];
        }
        else
        {
            nextval[i] = next[i];
        }
    }
}

void Next(const string &dst, vector<int> &next)
{
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < dst.length())
    {
        if (k == -1 || dst[j] == dst[k])
        {
            j += 1;
            k += 1;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

void Nextval(const string &dst, vector<int> &nextval)
{
    // 初始化nextval[0]为-1，这是KMP算法的标准做法
    nextval[0] = -1;
    // k表示当前最长相等前后缀的长度减1，初始为-1
    int k = -1;
    // j是当前正在处理的位置
    int j = 0;

    // 循环处理整个模式串，直到倒数第二个字符
    while (j < dst.size() - 1)
    {
        // 两种情况下需要向前移动：
        // 1. k为-1，说明需要重新开始匹配
        // 2. 当前字符与前缀的对应字符相等
        if (k == -1 || dst[j] == dst[k])
        {
            j++;
            k++;
            // 优化点：比较下一个字符
            // 如果下一个字符不同，则直接使用k值
            // 如果下一个字符相同，则使用前缀位置的nextval值
            // 这样可以避免重复的失配比较
            if (dst[j] != dst[k])
            {
                nextval[j] = k;
            }
            else
            {
                nextval[j] = nextval[k];
            }
        }
        else
        {
            // 当字符不匹配时，k回退到nextval[k]的位置
            k = nextval[k];
        }
    }
}

int KMP(const string &src, const string &dst, int pos)
{
    assert(pos >= 0 && pos < src.length() && src.size() > 0 && dst.size() > 0);
    int i = pos;
    int j = 0;
    int srcSize = src.size();
    int dstSize = dst.size();
    vector<int> next(dst.size(), -1);
    cout << dst << endl;
    // InitNext(dst, next);
    Next(dst, next);
    // 打印next数组
    cout << "next: ";
    for (int i = 0; i < next.size(); i++)
    {
        cout << next[i] << " ";
    }
    cout << "\n";

    vector<int> nextValue(dst.size(), -1);
    // InitNextval(dst, nextValue);
    Nextval(dst, nextValue);
    // 打印nextvalue数组
    cout << "nextvalue: ";
    for (int i = 0; i < next.size(); i++)
    {
        cout << nextValue[i] << " ";
    }
    cout << "\n";
    while (i < srcSize && j < dstSize)
    {
        if (j == -1 || src[i] == dst[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == dst.size())
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // cout << KMP("abcabcabcdabcde", "abcd", 0) << endl;
    // cout << KMP("abcdabcabcdabcde", "abcd", 0) << endl;
    cout << KMP("abcdabcabcdabcde", "ababaaababaa", 1) << endl;

    return 0;
}
