#include <bits/stdc++.h>

using namespace std;

// question :给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};
