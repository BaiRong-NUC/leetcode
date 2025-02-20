using System;
using System.Collections.Generic;

namespace LeetCode
{
    public class Solution
    {
        public int LengthOfLongestSubsequence(IList<int> nums, int target)
        {
            // dp[i][j]表示前i个物品，背包容量为j时的所有情况,最后结果为dp[nums.Count][target]
            int[,] dp = new int[nums.Count + 1, target + 1];
            // dp[0][0]=0;dp[0][j]=-1(不存在)
            for (int j = 1; j <= target; j++)
                dp[0, j] = -1;

            for (int i = 1; i <= nums.Count; i++)
            {
                for (int j = 0; j <= target; j++)
                {
                    // 第i个物品的重量为nums[i-1]大于j，一定不能选择。此外，dp[i-1,j-nums[i-1]]<0表示没有办法使用i-1个物品凑出j-nums[i-1]，所以也不能选择
                    if (j - nums[i - 1] < 0 || dp[i - 1, j - nums[i - 1]] < 0)
                        dp[i, j] = dp[i - 1, j];
                    else
                        //可以选，可以不选
                        dp[i, j] = Math.Max(dp[i - 1, j], dp[i - 1, j - nums[i - 1]] + 1);
                }
            }
            return dp[nums.Count, target];
        }

    }

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
}