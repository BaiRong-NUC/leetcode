/*
 * @lc app=leetcode.cn id=150 lang=csharp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
// public class Solution
// {
//     public int EvalRPN(string[] tokens)
//     {
//         var stack = new Stack<int>();
//         foreach (var token in tokens)
//         {
//             if (int.TryParse(token, out var num))
//             {
//                 stack.Push(num);
//             }
//             else
//             {
//                 var right = stack.Pop();
//                 var left = stack.Pop();
//                 switch (token)
//                 {
//                     case "+": stack.Push(left + right); break;
//                     case "-": stack.Push(left - right); break;
//                     case "*": stack.Push(left * right); break;
//                     case "/": stack.Push(left / right); break;
//                 }
//             }
//         }
//         return stack.Pop();
//     }
// }
public class Solution
{
    public int EvalRPN(string[] tokens)
    {
        var stack = new Stack<int>();
        var operations = new Dictionary<string, Func<int, int, int>>
        {
            {"+", (a, b) => a + b},
            {"-", (a, b) => a - b},
            {"*", (a, b) => a * b},
            {"/", (a, b) => a / b}
        };

        foreach (var token in tokens)
        {
            if (int.TryParse(token, out var num))
            {
                stack.Push(num);
            }
            else
            {
                var right = stack.Pop();
                var left = stack.Pop();
                stack.Push(operations[token](left, right));
            }
        }
        return stack.Pop();
    }
}
// @lc code=end

