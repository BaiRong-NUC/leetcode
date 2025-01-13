using System.Collections.Generic;
using System;

// namespace LeetCode
// {
public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}

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

    public void PrintListNode(ListNode head)
    {
        while (head != null)
        {
            System.Console.Write(head.val + " ");
            head = head.next;
        }
        System.Console.WriteLine();
    }
    public void PrintArray(int[] arr)
    {
        foreach (var item in arr)
        {
            System.Console.Write(item + " ");
        }
        System.Console.WriteLine();
    }
    public void PrintArray<T>(List<T> arr)
    {
        foreach (var item in arr)
        {
            System.Console.Write(item + " ");
        }
        System.Console.WriteLine();
    }
    public void PrintArray(int[][] arr)
    {
        foreach (var item in arr)
        {
            PrintArray(item);
        }
    }

    public void PrintArray<T>(List<List<T>> arr)
    {
        foreach (var item in arr)
        {
            PrintArray(item);
        }
    }
}
// }