/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */
/**
Accepted
16/16 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 73.53 % of cpp submissions (7 MB)
*/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
int timeStamp = 0;
struct Tweet
{
    int id;
    int time;
    Tweet *next;
    Tweet(int id)
    {
        this->id = id;
        this->time = timeStamp++;
        next = nullptr;
    }
};

struct User
{
    int id;
    Tweet *tweet;
    unordered_set<int> followed;
    User(int id)
    {
        this->id = id;
        tweet = nullptr;
        followed.insert(id);
    }

    void follow(int followId)
    {
        if (followId == id)
        {
            return;
        }
        followed.insert(followId);
    }

    void unfollow(int followId)
    {
        if (!followed.count(followId) || followId == id)
        {
            return;
        }
        followed.erase(followId);
    }

    void post(int contentId)
    {
        Tweet *tweet = new Tweet(contentId);
        tweet->next = this->tweet;
        this->tweet = tweet;
    }
};

class Twitter
{
    unordered_map<int, User *> userMap;

    bool find(int userId)
    {
        return userMap.find(userId) != userMap.end();
    }

public:
    Twitter()
    {
        userMap.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        if (!find(userId))
        {
            userMap[userId] = new User(userId);
        }
        userMap[userId]->post(tweetId);
    }

    vector<int> getNewsFeed(int userId)
    {
        if (!find(userId))
        {
            return {};
        }

        struct CompareTweets
        {
            bool operator()(const Tweet *left, const Tweet *right) const
            {
                return left->time < right->time; // 按照时间从大到小排序
            }
        };

        priority_queue<Tweet *, vector<Tweet *>, CompareTweets> tweetQueue;
        for (int followId : userMap[userId]->followed)
        {
            if (!find(followId))
            {
                userMap[followId] = new User(followId);
            }
            Tweet *head = userMap[followId]->tweet;
            if (head != nullptr)
                tweetQueue.push(head);
        }
        vector<int> ret;
        while (!tweetQueue.empty())
        {
            Tweet *tweet = tweetQueue.top();
            tweetQueue.pop();
            ret.push_back(tweet->id);
            if (ret.size() == 10)
            {
                return ret;
            }
            if (tweet->next != nullptr)
            {

                tweetQueue.push(tweet->next);
            }
        }
        return ret;
    }

    void follow(int followerId, int followeeId)
    {
        if (!find(followerId))
        {
            userMap[followerId] = new User(followerId);
        }
        userMap[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (!find(followeeId))
        {
            return;
        }
        userMap[followerId]->unfollow(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
