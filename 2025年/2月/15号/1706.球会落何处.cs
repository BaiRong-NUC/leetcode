/*
 * @lc app=leetcode.cn id=1706 lang=csharp
 *
 * [1706] 球会落何处
 */

// @lc code=start
public class Solution
{
    public int[] FindBall(int[][] grid)
    {
        int row = grid.Length;
        int col = grid[0].Length;
        //所有球最后落下的位置，落不下来为-1
        int[] res = new int[col];
        for (int j = 0; j < col; j++)
        {
            //遍历所有球,每个球都要从0行开始下落
            int curCol = j;
            for (int i = 0; i < row; i++)
            {
                //当前格子的方向 dir=1 表示向右移动一个格子，dir=-1 表示向左移动一个格子
                int dir = grid[i][curCol];
                //下一次要走过格子的列坐标
                curCol += dir;
                if (curCol < 0 || curCol >= col || grid[i][curCol] != dir)
                {
                    //grid[i][curCol]是当前行，沿着下一次要走的方向的相邻格子的方向，如果相同则是\\可以向下走,如果不同则是\/不能走
                    res[j] = -1;
                    break;
                }
            }
            if (res[j] != -1)
            {
                //这个球没被卡住，将这个球模拟落下的位置记录下来
                res[j] = curCol;
            }
        }
        return res;
    }
}
// @lc code=end