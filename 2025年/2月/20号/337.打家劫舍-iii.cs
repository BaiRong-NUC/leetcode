/*
 * @lc app=leetcode.cn id=337 lang=csharp
 *
 * [337] 打家劫舍 III
 */

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
    //dp[Node]表示从Node节点开始可以偷取的最大金额
    Dictionary<TreeNode, int> dp = new Dictionary<TreeNode, int>();
    //Rob表示从root节点开始可以偷取的最大金额
    public int Rob(TreeNode root)
    {
        if (root == null) return 0;
        if (dp.ContainsKey(root)) return dp[root];
        //偷root节点，不能偷root的左右子节点
        int robRoot = root.val + (root.left == null ? 0 : Rob(root.left.left) + Rob(root.left.right)) + (root.right == null ? 0 : Rob(root.right.left) + Rob(root.right.right));
        //不偷root节点，可以偷root的左右子节点
        int notRobRoot = Rob(root.left) + Rob(root.right);
        dp[root] = Math.Max(robRoot, notRobRoot);
        return dp[root];
    }
}
// @lc code=end

