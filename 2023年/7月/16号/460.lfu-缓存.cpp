/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
/**
Accepted
25/25 cases passed (592 ms)
Your runtime beats 8.08 % of cpp submissions
Your memory usage beats 25.76 % of cpp submissions (178.3 MB)
 */
// @lc code=start
struct Node
{
    int cent, time, key, value;
    Node(int _cent, int _time, int _key, int _value) : cent(_cent), time(_time), key(_key), value(_value) {}

    bool operator<(const Node &self) const
    {
        return cent == self.cent ? time < self.time : cent < self.cent;
    }
};
class LFUCache
{
    int _capacity;
    int _time = 0;
    unordered_map<int, Node> _hash;
    set<Node> _set;

public:
    LFUCache(int capacity)
    {
        _time = 0;
        _capacity = capacity;
        _hash.clear();
        _set.clear();
    }

    int get(int key)
    {
        if (_capacity == 0)
        {
            return -1;
        }

        unordered_map<int, Node>::iterator pos = _hash.find(key);
        if (pos == _hash.end())
        {
            // 哈希表中没有key，返回-1
            return -1;
        }

        // 更新cache缓存
        Node cache = pos->second;
        // set中删除旧的缓存
        _set.erase(cache);
        // 将旧缓存更新
        cache.cent += 1;
        cache.time = ++_time;
        // 将新缓存重新放入哈希表的平衡二叉树
        _set.insert(cache);
        pos->second = cache;
        return cache.value;
    }

    void put(int key, int value)
    {
        if (_capacity == 0)
        {
            return;
        }
        unordered_map<int, Node>::iterator pos = _hash.find(key);
        if (pos == _hash.end())
        {
            if (_hash.size() == _capacity)
            {
                // 删除最少使用的缓存
                _hash.erase(_set.begin()->key);
                _set.erase(_set.begin());
            }
            Node cache = Node(1, ++_time, key, value);

            _hash.insert(make_pair(key, cache));
            _set.insert(cache);
        }
        else
        {
            Node cache = pos->second;
            _set.erase(cache);
            cache.cent += 1;
            cache.time = ++_time;
            cache.value = value;
            _set.insert(cache);
            pos->second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
