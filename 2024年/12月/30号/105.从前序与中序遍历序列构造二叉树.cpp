/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <D:\CppCode\leetcode\global\global.h>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int find(vector<int> &inorder, int inStart, int inEnd, int target)
    {
        int pos=inStart;
        while(inorder[pos]!=target){
            pos++;
        }
        return pos;
    }
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if ((preStart > preEnd) || (inStart > inEnd))
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        // 分割inorder为左树，右树
        int pos=this->find(inorder,inStart,inEnd,preorder[preStart]);
        root->left = buildTree(preorder, preStart + 1, preEnd, inorder, inStart, pos - 1);
        root->right = buildTree(preorder, preStart + pos - inStart + 1, preEnd, inorder, pos + 1, inEnd);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int>preorder={3,9,20,15,7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    PrintCur().printTree(Solution().buildTree(preorder, inorder));
    return 0;
}
