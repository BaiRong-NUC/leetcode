/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 *
 * [1472] 设计浏览器历史记录
 */
#include <string>
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
class BrowserHistory
{
    // 后退页面
    stack<string> before;
    // 前进页面
    stack<string> next;

    string page;

public:
    BrowserHistory(string homepage)
    {
        page = homepage;
    }

    void visit(string url)
    {
        before.push(page);
        page = url;
        stack<string> emptyStack;
        next.swap(emptyStack);
    }

    string back(int steps)
    {
        for (int i = 0; i < steps && !before.empty(); i++)
        {
            next.push(page);
            page = before.top();
            before.pop();
        }
        return page;
    }

    string forward(int steps)
    {
        for (int i = 0; i < steps && !next.empty(); i++)
        {
            before.push(page);
            page = next.top();
            next.pop();
        }
        return page;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
