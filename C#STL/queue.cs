using System;
using System.Collections.Generic;

//Queue线性不安全，ConcurrentQueue线程安全

//入队列
string[] strs = new string[] { "a", "b", "c", "d" };
Queue<string> queue = new Queue<string>();
foreach (var item in strs)
{
    queue.Enqueue(item);
}

foreach (var item in queue)
{
    Console.WriteLine(item);
}

//判断队列中是否有这个元素
Console.WriteLine(queue.Contains("a"));

Console.WriteLine("-----------------");

//用数组初始化
// Queue<string> queue2 = new Queue<string>(strs);
Queue<string> queue2 = new Queue<string>(queue.ToArray());
//用队列初始化
// Queue<string> queue2 = new Queue<string>(queue);
int size = queue2.Count;
for (int i = 0; i < size; i++)
{
    // Console.WriteLine(queue2.Peek());
    Console.WriteLine(queue2.Dequeue());
}

Console.WriteLine("-----------------");

//队列元素赋值到数组,顺序为出队列顺序
string[] strs2 = new string[queue.Count * 2];
queue.CopyTo(strs2, queue.Count);

foreach (var item in strs2)
{
    Console.WriteLine(item);
}