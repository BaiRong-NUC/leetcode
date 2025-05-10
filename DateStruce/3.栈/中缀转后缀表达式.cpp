#include <iostream>
#include <stack>
using namespace std;
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op)
{
    if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '(')
    {
        return 0;
    }
    return -1;
}

// 中缀表达式转后缀表达式
string infixToPostfix(string infix)
{
    string postfix = ""; // 定义一个字符串，用来存储后缀表达式
    stack<char> st;      // 定义一个栈
    for (int i = 0; i < infix.length(); i++)
    {
        if (priority(infix[i]) == -1 && infix[i] != ')') // 如果是操作数，直接输出
        {
            postfix += infix[i]; // 输出操作数
        }
        else
        {
            if (st.empty())
            {
                st.push(infix[i]); // 入栈
            }
            else
            {
                // 当前栈不为空
                if (infix[i] == ')') // 如果是右括号，一直出栈，直到遇到左括号
                {
                    while (st.top() != '(')
                    {
                        postfix += st.top(); // 输出操作符
                        st.pop();            // 出栈
                    }
                    //'('还在栈里,后缀表达式没有括号
                    st.pop();
                }
                else
                {
                    // 栈不为空，且当前字符不是数子和右括号
                    // 如果是左括号，直接入栈
                    if (infix[i] == '(')
                    {
                        st.push(infix[i]); // 入栈
                    }
                    else
                    {
                        // 栈顶元素的优先级大于等于当前元素的优先级则一直出栈
                        while (!st.empty() && priority(st.top()) >= priority(infix[i]))
                        {
                            postfix += st.top(); // 输出操作符
                            st.pop();            // 出栈
                        }
                        // 栈为空或者栈顶元素的优先级小于当前元素的优先级
                        st.push(infix[i]); // 入栈
                    }
                }
            }
        }
    }
    // 栈不为空，一直出栈
    while (!st.empty())
    {
        postfix += st.top(); // 输出操作符
        st.pop();            // 出栈
    }
    return postfix;
}

// 后缀表达式求值
int evaluatePostfix(const string &postfix)
{
    stack<int> st; // 定义一个栈
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9') // 如果是操作数，直接入栈
        {
            st.push(postfix[i] - '0'); // 入栈
        }
        else
        {
            // 如果是操作符，出栈两个操作数，进行运算，然后将结果入栈
            int right = st.top(); // 右操作数
            st.pop();
            int left = st.top(); // 左操作数
            st.pop();
            switch (postfix[i])
            {
            case '+':
                st.push(left + right); // 入栈
                break;
            case '-':
                st.push(left - right); // 入栈
                break;
            case '*':
                st.push(left * right); // 入栈
                break;
            case '/':
                if (right == 0) // 如果除数为0，返回-1
                {
                    printf("error: divide by zero\n"); // 输出错误信息
                    return -1;
                }
                st.push(left / right); // 入栈
                break;
            }
        }
    }
    return st.top(); // 返回栈顶元素
}
int main(int argc, char const *argv[])
{
    string infix = "2+3*(5-2)-4/2"; // 定义一个中缀表达式
    cout << infixToPostfix(infix) << endl;
    cout << evaluatePostfix(infixToPostfix(infix)) << endl;
    return 0;
}
