#include <iostream>
#include <stack>
using namespace std;

// 括号匹配
bool isMatch(char str[], int length)
{
    // 定义一个栈
    stack<char> st;
    for (int i = 0; i < length; i++)
    {
        // cout << "Debug str[i]: " << str[i] << endl;
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            // 出栈来进行匹配
            if (!st.empty())
            {
                // 栈不为空，进行匹配 匹配元素是top 和 str[i]
                char top = st.top(); // 取出栈顶元素
                st.pop();
                cout << "top: " << top << " str[i]: " << str[i] << endl;
                if ((top == '{' && str[i] != '}') || (top == '[' && str[i] != ']') || (top == '(' && str[i] != ')'))
                {
                    return false; // 匹配失败，直接返回false
                }
            }
            else
            {
                // 栈为空，说明没有左括号，匹配失败
                return false;
            }
        }
        else
        {
            // 其他字符
            continue;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    // 括号匹配
    // 输入一个字符串，判断括号是否匹配
    // 定义一个字符串
    char str[20] = "([{}])";
    cout << isMatch(str, 20);
    // A+B*(C-D)-E/F 中缀
    // ABCD-*+EF/- 后缀
    return 0;
}