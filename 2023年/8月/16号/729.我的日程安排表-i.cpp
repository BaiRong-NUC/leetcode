/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

/**
Accepted
107/107 cases passed (76 ms)
Your runtime beats 90.96 % of cpp submissions
Your memory usage beats 78.16 % of cpp submissions (36.9 MB)
 */

// @lc code=start
class MyCalendar
{
    struct Node
    {
        int begin;
        int end;
        Node *next = nullptr;
        Node(int _begin, int _end) : begin(_begin), end(_end) {}
    };

    Node *head = nullptr;

public:
    MyCalendar()
    {
        head = new Node(0, 0);
    }

    bool book(int start, int end)
    {
        Node *prev = head;
        Node *cur = head;
        while (cur != nullptr)
        {
            if (end <= cur->begin)
            {
                break;
            }
            if (cur->end <= start)
            {
                prev = cur;
                cur = cur->next;
            }
            else
            {
                return false;
            }
        }
        prev->next = new Node(start, end);
        prev->next->next = cur;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
