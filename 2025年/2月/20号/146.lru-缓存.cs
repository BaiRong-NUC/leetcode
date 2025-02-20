/*
 * @lc app=leetcode.cn id=146 lang=csharp
 *
 * [146] LRU 缓存
 */

// @lc code=start
public class LRUCache
{
    private class LinkedNode
    {
        public int Key { get; set; }
        public int Value { get; set; }
        public LinkedNode Prev { get; set; }
        public LinkedNode Next { get; set; }

        public LinkedNode(int key, int value)
        {
            Key = key;
            Value = value;
        }
    }

    private Dictionary<int, LinkedNode> _cache;
    private LinkedNode _head;
    private LinkedNode _tail;
    private int _capacity;

    // 头插,最近使用的节点在前
    private void AddToHead(LinkedNode node)
    {
        node.Prev = _head;
        node.Next = _head.Next;
        node.Next.Prev = node;
        _head.Next = node;
    }

    //删除node节点
    private void RemoveNode(LinkedNode node)
    {
        node.Prev.Next = node.Next;
        node.Next.Prev = node.Prev;
    }

    public LRUCache(int capacity)
    {
        _cache = new Dictionary<int, LinkedNode>();
        //双头节点
        _head = new LinkedNode(0, 0);
        _tail = new LinkedNode(0, 0);
        _head.Next = _tail;
        _tail.Prev = _head;
        _head.Prev = _tail;
        _tail.Next = _head;
        _capacity = capacity;
    }

    public int Get(int key)
    {
        if (!_cache.ContainsKey(key))
        {
            return -1;
        }
        //移动节点
        var node = _cache[key];
        RemoveNode(node);
        AddToHead(node);
        return node.Value;
    }

    public void Put(int key, int value)
    {
        if (_cache.ContainsKey(key))
        {
            //命中，将Cache提前
            var node = _cache[key];
            RemoveNode(node);
            node.Value = value;
            AddToHead(node);
        }
        else
        {
            LinkedNode node = null;
            //未命中，判断是否需要删除最久未使用的节点
            if (_cache.Count == _capacity)
            {
                //已满,删除最久未使用的节点
                node = _cache[_tail.Prev.Key];
                RemoveNode(_tail.Prev);
                _cache.Remove(node.Key);
            }
            //未满或已经删除了最久未使用的节点
            node = new LinkedNode(key, value);
            _cache.Add(key, node);
            AddToHead(node);
        }
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

