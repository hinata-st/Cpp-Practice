#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

// question : 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

class MySolution22
{
    public : 
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        int count = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        if(head == nullptr || k <= 0)
        {
            return nullptr;
        }
        while(fast != nullptr)
        {
            if(count < k)
            {
                fast = fast->next;
                count++;
            }
            else
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};

class offer_Solution_22
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *slow = head, *fast = head;
        while (k--)
        {
            fast = fast->next;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};