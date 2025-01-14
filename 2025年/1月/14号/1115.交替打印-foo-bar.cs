/*
 * @lc app=leetcode.cn id=1115 lang=csharp
 *
 * [1115] 交替打印 FooBar
 */

// @lc code=start
using System.Threading;
public class FooBar
{
    private int n;

    //条件变量
    // private AutoResetEvent fooEvent = new AutoResetEvent(true);
    // private AutoResetEvent barEvent = new AutoResetEvent(false);
    //二元信号量
    private SemaphoreSlim fooEvent = new SemaphoreSlim(1, 1);
    private SemaphoreSlim barEvent = new SemaphoreSlim(0, 1);
    public FooBar(int n)
    {
        this.n = n;
    }

    public void Foo(Action printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            //等待fooEvent信号
            // fooEvent.WaitOne();

            //申请fooEvent信号
            fooEvent.Wait();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            //释放barEvent信号
            barEvent.Release();

            //通知barEvent
            // barEvent.Set();
        }
    }

    public void Bar(Action printBar)
    {

        for (int i = 0; i < n; i++)
        {
            //等待barEvent信号
            // barEvent.WaitOne();

            //申请barEvent信号
            barEvent.Wait();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            //释放fooEvent信号
            fooEvent.Release();

            //通知fooEvent
            // fooEvent.Set();
        }
    }
}
// @lc code=end

