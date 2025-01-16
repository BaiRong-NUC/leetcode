/*
 * @lc app=leetcode.cn id=95 lang=csharp
 *
 * [95] 不同的二叉搜索树 II
 */
public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    //递归
    public List<TreeNode> GenerateTrees(int start, int end)
    {
        List<TreeNode> result = new List<TreeNode>();
        //递归出口
        if (start > end)
        {
            result.Add(null);
            return result;
        }
        for (int i = start; i <= end; i++)
        {
            //递归
            List<TreeNode> lefts = GenerateTrees(start, i - 1);
            List<TreeNode> rights = GenerateTrees(i + 1, end);
            //穷举所有可能的左右子树
            foreach (var left in lefts)
            {
                foreach (var right in rights)
                {
                    TreeNode root = new TreeNode(i, left, right);
                    root.left = left;
                    root.right = right;
                    result.Add(root);
                }
            }
        }
        return result;
    }
    public IList<TreeNode> GenerateTrees(int n)
    {
        if (n == 0) { return new List<TreeNode>(); }
        return GenerateTrees(1, n);
    }
}
// @lc code=end

