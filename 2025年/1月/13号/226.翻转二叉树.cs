/*
 * @lc app=leetcode.cn id=226 lang=csharp
 *
 * [226] 翻转二叉树
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
public class PrintCur
{
    private int Deep(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }
        int left = Deep(root.left);
        int right = Deep(root.right);
        return Math.Max(left, right) + 1;
    }

    private void Dfs(TreeNode root, List<List<string>> ret, int row, int col, int treeDeep)
    {
        if (root == null)
        {
            return;
        }
        ret[row][col] = root.val.ToString();
        if (root.left != null)
            Dfs(root.left, ret, row + 1, col - (1 << (treeDeep - row - 1)), treeDeep);
        if (root.right != null)
            Dfs(root.right, ret, row + 1, col + (1 << (treeDeep - row - 1)), treeDeep);
    }

    public List<List<string>> PrintTree(TreeNode root)
    {
        int treeDeep = Deep(root) - 1; // 根节点高度为0
        int row = treeDeep + 1;
        int col = (1 << row) - 1;
        List<List<string>> ret = new List<List<string>>();
        for (int i = 0; i < row; i++)
        {
            ret.Add(new List<string>(new string[col]));
        }
        Dfs(root, ret, 0, (col - 1) / 2, treeDeep);
        for (int i = 0; i < ret.Count; i++)
        {
            for (int j = 0; j < ret[i].Count; j++)
            {
                Console.Write(ret[i][j] + " ");
            }
            Console.WriteLine();
        }
        return ret;
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
    public TreeNode InvertTree(TreeNode root)
    {
        if (root == null)
        {
            return null;
        }
        TreeNode left = InvertTree(root.left);
        TreeNode right = InvertTree(root.right);
        var tmp = right;
        root.right = left;
        root.left = tmp;
        return root;
    }
}
// @lc code=end

Solution solution = new Solution();
solution.InvertTree(new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9))));