#include <bits/stdc++.h>

using namespace std;

// question : 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Mysolution_24
{
    public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr)
        {
            ListNode *next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;
    }
};

class OfferSolution_24
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *ans = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ans;
    }
};