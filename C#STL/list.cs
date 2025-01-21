using System;
using System.Collections.Generic;


//List线程不安全，ImmutableList线程安全
List<int> numbers = new List<int>();
// List<int> numbers = new List<int>(10);
// List<int> numbers = new List<int>(new int[] { 1, 2, 3 });

int[] arr = new int[] { 1, 2, 3 };

foreach (var item in arr)
{
    numbers.Add(item);
}

// 在第一个位置上插入4,第一个参数是索引，第二个参数是值
numbers.Insert(0, 4);
foreach (var item in numbers)
{
    Console.WriteLine(item);
}

Console.WriteLine("-----------------");

//删除元素值为1的元素
numbers.Remove(4);
//删除索引为1的元素
// numbers.RemoveAt(0);
foreach (var item in numbers)
{
    Console.WriteLine(item);
}

Console.WriteLine("-----------------");

bool containsThree = numbers.Contains(3); // 检查列表是否包含值为 3 的元素
int indexOfThree = numbers.IndexOf(3); // 获取值为 3 的元素的索引
int size = numbers.Count;//获取列表大小
Console.WriteLine("Contains 3: " + containsThree + ", index: " + indexOfThree + ", size: " + size);

// numbers.Clear(); // 清空列表中的所有元素