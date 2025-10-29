#include <bits/stdc++.h>    

using namespace std;

// question :请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class mySolution_35
{
    public:
        Node *copyRandomList(Node *head)
        {
            if(!head) return nullptr;
            Node *newHead = head, *dummy = new Node(0);
            Node *curr = dummy;
            unordered_map<Node*, Node*> mp;
            while(head)
            {
                curr->next = new Node(head->val);
                curr = curr->next;
                mp[head] = curr;
                head = head->next;
            }
            curr = dummy->next;
            head = newHead;
            while(head)
            {
                if(head->random)
                {
                    curr->random = mp[head->random];
                }
                curr = curr->next;
                head = head->next;
            }
            return dummy->next;
        }
};

class offerSolution_35_1
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> d;
        Node *dummy = new Node(0);
        Node *tail = dummy;
        for (auto cur = head; cur; cur = cur->next)
        {
            tail->next = new Node(cur->val);
            tail = tail->next;
            d[cur] = tail;
        }
        tail = dummy->next;
        for (auto cur = head; cur; cur = cur->next)
        {
            tail->random = d[cur->random];
            tail = tail->next;
        }
        return dummy->next;
    }
};

class offerSolution_35_2
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }
        for (Node *cur = head; cur;)
        {
            Node *node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        for (Node *cur = head; cur; cur = cur->next->next)
        {
            if (cur->random)
            {
                cur->next->random = cur->random->next;
            }
        }
        Node *ans = head->next;
        for (Node *cur = head; cur;)
        {
            Node *nxt = cur->next;
            if (nxt)
            {
                cur->next = nxt->next;
            }
            cur = nxt;
        }
        return ans;
    }
};