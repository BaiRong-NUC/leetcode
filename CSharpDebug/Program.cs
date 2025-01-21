namespace CSharpDebug;
using LeetCode;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Debug Start");
        Solution solution = new Solution();
        Console.WriteLine(solution.LengthOfLongestSubsequence(new List<int> { 1, 1, 5, 4, 5 }, 3));
        Console.WriteLine("Debug End");
    }
}
