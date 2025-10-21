#include <bits/stdc++.h>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

// question : 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

class my_solution_22
{
    public : 
    ListNode* getKnodeFromEnd(ListNode* head,int k)
    {
        int temp = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        if(head == nullptr)
        {
            return nullptr;
        }
        while(fast != nullptr)
        {
            if(temp < k)
            {
                fast = fast->next;
                temp++;
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