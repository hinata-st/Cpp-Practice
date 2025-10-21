#include <bits/stdc++.h>

using namespace std;

// question : 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

//my solution
class my_Solution_06_1
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> res;
        ListNode *cur = head;
        while(cur!=nullptr)
        {
            res.push_back(cur->val);
            cur = cur->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// 方法一：顺序遍历 + 反转
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class my_Solution_06_2
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> ans;
        for (; head; head = head->next)
        {
            ans.push_back(head->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 方法二：递归
//my solution
class my_Solution_06_3
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> ans;
        recur(head, ans);
        return ans;
    }
private:
    void recur(ListNode *head, vector<int> &ans)
    {
        if (head == nullptr)
            return;
        recur(head->next, ans);
        ans.push_back(head->val);
    }
};
//official solution
class offer_Solution_06
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        if (!head)
        {
            return {};
        }
        vector<int> ans = reversePrint(head->next);
        ans.push_back(head->val);
        return ans;
    }
};
