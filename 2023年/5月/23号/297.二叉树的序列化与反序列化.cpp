/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
    TreeNode *creatNode(string &data, int &begin, int &end)
    {
        begin = data.find('(', begin);
        end = data.find(')', end);
        string del = data.substr(begin + 1, end - begin - 1);
        begin = end + 1;
        end = begin;
        if (del == "#")
        {
            return nullptr;
        }
        int val = atoi(del.c_str());
        TreeNode *root = new TreeNode(val);
        root->left = creatNode(data, begin, end);
        root->right = creatNode(data, begin, end);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // 前序序列化
        TreeNode *node = root;
        stack<TreeNode *> st;
        string ret = "";
        while (node != nullptr || !st.empty())
        {
            while (node != nullptr)
            {
                ret += "(";
                ret += to_string(node->val);
                ret += ")";
                st.push(node);
                node = node->left;
            }
            ret += "(#)";
            node = st.top();
            st.pop();
            node = node->right;
        }
        ret += "(#)";
        cout << ret << endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int begin = 0;
        int end = 0;
        return creatNode(data, begin, end);
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
