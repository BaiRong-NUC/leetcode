/*
 * @lc app=leetcode.cn id=590 lang=csharp
 *
 * [590] N 叉树的后序遍历
 */
public class Node
{
    public int val;
    public IList<Node> children;

    public Node() { }

    public Node(int _val)
    {
        val = _val;
    }

    public Node(int _val, IList<Node> _children)
    {
        val = _val;
        children = _children;
    }
}
// @lc code=start
/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/

public class Solution
{
    List<int> result = new List<int>();
    public IList<int> Postorder(Node root)
    {
        if (root == null) return result;
        foreach (var child in root.children)
        {
            Postorder(child);
        }
        result.Add(root.val);
        return result;
    }
}
// @lc code=end

