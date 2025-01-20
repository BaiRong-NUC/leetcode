using System;
using System.Collections.Generic;


// Stack线程不安全
string[] strs = new string[] { "a", "b", "c", "d" };
//栈初始化
// Stack<string> stack = new Stack<string>();

Stack<string> stack = new Stack<string>(strs);

//依次出栈,数字仍然在栈中
foreach (var item in stack)
{
    Console.WriteLine(item);
}

//判断数字是否在栈中
Console.WriteLine(stack.Contains("a"));

Console.WriteLine("-----------------");

//出栈，入栈，栈大小，拷贝构造等
Stack<string> stack2 = new Stack<string>(stack);
// Stack<string> stack2 = new Stack<string>(stack.ToArray());
int size = stack2.Count;
for (int i = 0; i < size; i++)
{
    Console.WriteLine(stack2.Peek());
    stack2.Pop();
}

//清空栈
stack2.Clear();

Console.WriteLine("-----------------");

//将栈的数字放到数组中
string[] strs2 = new string[stack.Count * 2];
//CopyTo方法 参数1：数组 参数2：从数组的第几个位置开始放.顺序为出栈顺序
stack.CopyTo(strs2, stack.Count);

for (int i = 0; i < strs2.Length; i++)
{
    Console.WriteLine(strs2[i]);
}