/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

#include <vector>
#include <stack>
using namespace std;

/**
Accepted
43/43 cases passed (8 ms)
Your runtime beats 71.94 % of cpp submissions
Your memory usage beats 9.52 % of cpp submissions (15.1 MB)
 */
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// @lc code=start
class NestedIterator
{
    stack<NestedInteger> val;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            val.push(nestedList[i]);
        }
    }

    int next()
    {
        NestedInteger integer = val.top();
        val.pop();
        return integer.getInteger();
    }

    bool hasNext()
    {
        // 如果遇到列表需要摊平
        while (!val.empty())
        {
            NestedInteger integer = val.top();
            if (integer.isInteger())
            {
                return true;
            }
            val.pop();
            auto list = integer.getList();
            for (int i = list.size() - 1; i >= 0; i--)
            {
                val.push(list[i]);
            }
        }
        return false;
    }
};
// @lc code=end

// dfs展开嵌套的列表，但是这个设计提前在调用next前生成了序列，并不能称为迭代器
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
    vector<int> val;
    int pos = 0;

    void dfs(const vector<NestedInteger> &nestedList)
    {
        for (const NestedInteger &list : nestedList)
        {
            if (list.isInteger())
            {
                val.push_back(list.getInteger());
            }
            else
            {
                dfs(list.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        dfs(nestedList);
    }

    int next()
    {
        return val[pos++];
    }

    bool hasNext()
    {
        return pos != val.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
