/*
 * @lc app=leetcode.cn id=1114 lang=csharp
 *
 * [1114] 按序打印
 */

// @lc code=start
using System.Threading;
public class Foo
{

    //C# 条件变量 false代表线程需等待，true表示线程不需要等待
    private AutoResetEvent _waitFirst = new AutoResetEvent(false);
    private AutoResetEvent _waitSecond = new AutoResetEvent(false);
    public Foo()
    {

    }

    public void First(Action printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        //设置为true，唤醒等待的线程
        _waitFirst.Set();
    }

    public void Second(Action printSecond)
    {
        //等待_waitFirst被设置为true
        _waitFirst.WaitOne();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        //设置为true，唤醒等待的线程
        _waitSecond.Set();
    }

    public void Third(Action printThird)
    {
        //等待_waitSecond被设置为true
        _waitSecond.WaitOne();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
}
// @lc code=end

