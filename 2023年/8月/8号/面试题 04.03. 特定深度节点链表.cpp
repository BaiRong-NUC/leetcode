/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <queue>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<ListNode *> listOfDepth(TreeNode *tree)
    {
        queue<TreeNode *> queue;
        vector<ListNode *> ret;
        queue.push(tree);
        while (!queue.empty())
        {
            int size = queue.size();
            ListNode *head = new ListNode(-1);
            ListNode *tail = head;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                tail->next = new ListNode(node->val);
                tail = tail->next;
                if (node->left != nullptr)
                {
                    queue.push(node->left);
                }
                if (node->right != nullptr)
                {
                    queue.push(node->right);
                }
            }
            ret.push_back(head->next);
        }
        return ret;
    }
};