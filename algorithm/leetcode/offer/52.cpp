#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// question : 输入两个链表，找出它们的第一个公共节点。

class mySolution_52
{
    public:
        ListNode *getCommonNode(ListNode *head_1, ListNode *head_2)
        {
            unordered_set<ListNode *> nodes_set;
            while (head_1 != nullptr)
            {
                nodes_set.insert(head_1);
                head_1 = head_1->next;
            }
            while (head_2 != nullptr)
            {
                if (nodes_set.find(head_2) != nodes_set.end())
                {
                    return head_2;
                }
                head_2 = head_2->next;
            }
            return nullptr;
        }
};

class offerSolution_52
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};