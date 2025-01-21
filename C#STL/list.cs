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

Console.WriteLine("-----------------");

//List自带的二分搜索,返回索引
List<int> sortedNumbers = new List<int> { 1, 3, 5, 7, 9 };

Console.WriteLine(sortedNumbers.BinarySearch(5));

//传入自定义比较方法
List<string> names = new List<string> { "Alice", "Bob", "Charlie", "David" };

// 创建一个自定义比较器，用于按字符串长度进行比较
IComparer<string> lengthComparer = Comparer<string>.Create((x, y) => x.Length.CompareTo(y.Length));
//搜索长度为4的字符串
//如果未找到，它返回一个负数，该负数是大于item的第一个元素的索引的按位求补。可以使用按位求补运算符~来获取应插入元素的位置。
int index = names.BinarySearch("1234", lengthComparer);
if (index >= 0)
{
    Console.WriteLine($"找到长度为4的字符串在索引{index}");
}
else
{
    Console.WriteLine($"未找到长度为4的字符串,插入位置为{~index}");
}