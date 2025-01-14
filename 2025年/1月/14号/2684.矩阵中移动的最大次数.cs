/*
 * @lc app=leetcode.cn id=2684 lang=csharp
 *
 * [2684] 矩阵中移动的最大次数
 */

// @lc code=start
public class Solution
{
    bool[,] visited;
    //存储方向
    int[,] directoions = new int[3, 2] { { -1, 1 }, { 0, 1 }, { 1, 1 } };
    //存储步骤
    List<int> ret = new List<int>();
    bool Check(int[][] grid, int row, int col)
    {
        //越界
        if (row < 0 || row >= grid.Length || col < 0 || col >= grid[0].Length)
        {
            return false;
        }
        return true;
    }
    //深度优先搜索（超时）
    void DFS(int[][] grid, int row, int col, int step)
    {
        //每种方向
        for (int i = 0; i < directoions.GetLength(0); i++)
        {
            int newRow = row + directoions[i, 0];
            int newCol = col + directoions[i, 1];
            if (Check(grid, newRow, newCol) && grid[newRow][newCol] > grid[row][col])
            {
                string key = newRow.ToString() + newCol.ToString();
                // Console.WriteLine("grid[row][col]" + grid[row][col] + "->grid[newRow][newCol]" + grid[newRow][newCol] + "step:" + step);
                step++;
                DFS(grid, newRow, newCol, step);
                step--;//回溯

            }
            else
            {
                //记录当前步数
                ret.Add(step);
            }
        }
    }
    public int MaxMoves(int[][] grid)
    {
        //从第一列任意位置开始
        for (int i = 0; i < grid.Length; i++)
        {
            for (int j = 0; j < 1; j++)
            {
                DFS(grid, i, j, 0);
            }
        }
        //打印结果
        return ret.Max();
    }
}
// @lc code=end

