using System;
using System.Collections.Generic;

//优先级队列

// 入队元素，第一个参数是元素，第二个参数是优先级，默认优先级从小到大
// var pq = new PriorityQueue<string, int>();

//优先级从大到小
var pq = new PriorityQueue<string, int>(Comparer<int>.Create((x, y) => y - x));

//优先级相同时，默认按照插入顺序出队列
pq.Enqueue("a", 1);
pq.Enqueue("b", 3);
pq.Enqueue("d", 2);
pq.Enqueue("c", 2);
pq.Enqueue("e", 4);

while (pq.Count > 0)
{
    string item = pq.Dequeue();
    Console.WriteLine(item);
}

Console.WriteLine("--------------");