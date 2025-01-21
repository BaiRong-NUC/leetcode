namespace CSharpDebug;
using LeetCode;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Debug Start");
        Solution solution = new Solution();
        Console.WriteLine(solution.LengthOfLongestSubsequence(new List<int> { 1, 2, 3, 4, 5 }, 9));
        Console.WriteLine("Debug End");
    }
}
