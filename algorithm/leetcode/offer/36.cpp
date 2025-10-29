#include <bits/stdc++.h>

using namespace std;

// question :

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class mySolution_36
{
    public:
    Node* treeToDoublyList(Node* root)
    {
        if(!root)
            return nullptr;
        Node* dummy = new Node(0);
        unordered_map<int, Node *> mp;
        vector<int> inorder;
        function<void(Node*)> dfs = [&](Node* node)
        {
            if(!node)
                return;
            dfs(node->left);
            inorder.push_back(node->val);
            mp[node->val] = new Node(node->val);
            dfs(node->right);
        };
        dfs(root);
        int n = inorder.size();
        for(int i = 1; i < n - 1; ++i)
        {
            mp[inorder[i]]->left =  mp[inorder[i - 1]];
            mp[inorder[i]]->right = mp[inorder[i + 1]];
        }
        mp[inorder[0]]->left = mp[inorder[n - 1]];
        mp[inorder[0]]->right = mp[inorder[1]];
        mp[inorder[n - 1]]->left = mp[inorder[n - 2]];
        mp[inorder[n - 1]]->right = mp[inorder[0]];
        return mp[inorder[0]];
    }
};
/*
❌ 边界处理不完善：n = 1 时越界
❌ 创建不必要的新节点：浪费内存
❌ 使用了无用的哈希表：增加空间复杂度
❌ 使用了未使用的 dummy 节点：代码混淆
❌ 代码冗长：特殊处理首尾节点*/

class offerSolution_36
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
        {
            return nullptr;
        }
        Node *pre = nullptr;
        Node *head = nullptr;
        function<void(Node *)> dfs = [&](Node *root)
        {
            if (!root)
            {
                return;
            }
            dfs(root->left);
            if (pre)
            {
                pre->right = root;
            }
            else
            {
                head = root;
            }
            root->left = pre;
            pre = root;
            dfs(root->right);
        };

        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};