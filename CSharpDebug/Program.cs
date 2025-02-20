namespace CSharpDebug;
using LeetCode;

class Program
{
    static void Main(string[] args)
    {
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.Put(2, 6); 
        lRUCache.Put(1, 5); 
        Console.WriteLine(lRUCache.Get(1));    
        lRUCache.Put(1, 2); 
        Console.WriteLine(lRUCache.Get(1));    
    }
}
