#include <bits/stdc++.h>

using namespace std;

// question : 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};

class My_solution 
{
    public:
        ListNode* deleteNode(ListNode* head, int val)
        {
            if (head == nullptr)
            {
                return nullptr;
            }
            if (head->val == val)
            {
                return head->next;
            }
            ListNode *curren = head;
            ListNode *previous = nullptr;
            while (curren != nullptr)
            {
                if (curren->val == val)
                {
                    previous->next = curren->next;
                    break;
                }
                previous = curren;
                curren = curren->next;
            }
            return head;
        }
};

class offer_Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0, head);
        for (ListNode *cur = dummy; cur->next; cur = cur->next)
        {
            if (cur->next->val == val)
            {
                cur->next = cur->next->next;
                break;
            }
        }
        return dummy->next;
    }
};

