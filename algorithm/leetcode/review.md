# 1.Knowledge

> Grouped by algorithm tags. Fallback rule for official section: offer_Solution -> Solution -> mySolution -> any class in file.

## 哈希

### offer.03 (easy)

#### Idea
- Knowledge: 哈希集合查找(哈希)
- Question: 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
- Code: algorithm/leetcode/offer/03.cpp
- Current classes: Solution, Solution2, Solution3

#### Official
- Selected class: Solution
```cpp
class Solution
{
    public:
        int findRepeatNumber(vector<int> &nums)
        {
            unordered_set<int> vis;
            for (int i = 0;; ++i)
            {
                if(vis.count(nums[i]))
                {
                    return nums[i];
                }
                vis.insert(nums[i]);
            }
        }
};
```

### offer.07 (middle)

#### Idea
- Knowledge: 重建二叉树(分治+哈希)
- Question: 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
- Code: algorithm/leetcode/offer/07.cpp
- Current classes: Solution1, Solution2, Solution_review_1, Solution_review_2

#### Official
- Selected class: Solution1
```cpp
class Solution1
{
public:
    TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, int i, int l, int r)
    {
        // 子树区间为空时终止
        if (r - l < 0)
        {
            return NULL;
        }
        // 初始化根节点
        TreeNode *root = new TreeNode(preorder[i]);
        // 查询 m , 从而划分左右子树
        int m = inorderMap[preorder[i]];
        // 子问题：构建左子树
        root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
        // 子问题：构建右子树
        root->right = dfs(preorder, inorderMap, i + m - l + 1, m + 1, r);
        // 返回根节点
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 初始化哈希表，储存 inorder 元素到索引的映射
        unordered_map<int, int> inorderMap;
        for (vector<int>::size_type i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        TreeNode *root = dfs(preorder, inorderMap, 0, 0, inorder.size() - 1);
        return root;
    }
};
```

### offer.13 (middle)

#### Idea
- Knowledge: 机器人的运动范围(DFS+哈希)
- Question: 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
- Code: algorithm/leetcode/offer/13.cpp
- Current classes: my_solution_13, Solution, Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        bool vis[m][n];
        memset(vis, false, sizeof vis);
        auto f = [](int x)
        {
            return x / 10 + x % 10;
        };
        function<int(int i, int j)> dfs = [&](int i, int j) -> int
        {
            if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || f(i) + f(j) > k)
            {
                return false;
            }
            vis[i][j] = true;
            return 1 + dfs(i + 1, j) + dfs(i, j + 1);
        };
        return dfs(0, 0);
    }
};*/
```

### offer.35 (middle)

#### Idea
- Knowledge: 复杂链表的复制(链表+哈希)
- Question: 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
- Code: algorithm/leetcode/offer/35.cpp
- Current classes: Node, mySolution_35, offerSolution_35_1, offerSolution_35_2

#### Official
- Selected class: mySolution_35
```cpp
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
```

### offer.48 (middle)

#### Idea
- Knowledge: 最长不含重复子串的子字符串(哈希)
- Code: algorithm/leetcode/offer/48.cpp
- Current classes: mySolution_48, offerSolution_48

#### Official
- Selected class: mySolution_48
```cpp
class mySolution_48
{
    public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> mp;
        int left = 0, right = 0;
        int ans = 0;
        while (right < s.size())
        {
            if (mp.find(s[right]) == mp.end())
            {
                mp.insert(s[right]);
                right++;
                ans = max(ans, right - left);
            }
            else
            {
                mp.erase(s[left]);
                left++;
            }
        }

        return ans;
    }
};
```

### offer.50 (easy)

#### Idea
- Knowledge: 第一个只出现一次的字符(哈希)
- Question: 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
- Code: algorithm/leetcode/offer/50.cpp
- Current classes: mySolution_50, offerSolution_50

#### Official
- Selected class: mySolution_50
```cpp
class mySolution_50
{
    public:
    char firstUniqChar(string s)
    {
        if (s.size() == 0)
            return ' ';
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        for (char c : s)
        {
            if (mp[c] == 1)
                return c;
        }
        return ' ';
    }
};
```

### offer.52 (easy)

#### Idea
- Knowledge: 两个链表的第一个节点(哈希 or 双指针)
- Question: 输入两个链表，找出它们的第一个公共节点。
- Code: algorithm/leetcode/offer/52.cpp
- Current classes: mySolution_52, offerSolution_52

#### Official
- Selected class: mySolution_52
```cpp
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
```

### leetcode.3 (middle)

#### Idea
- Knowledge: 字母异位词分组(哈希)
- Question: 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
- Code: algorithm/leetcode/leco/3.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.empty())
            return {};
        unordered_map<string, vector<string>> mp;
        for (auto &s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].emplace_back(s);
        }
        vector<vector<string>> result;
        for (auto &p : mp)
        {
            result.emplace_back(move(p.second));
        }
        return result;
    }
};
```

### leetcode.4 (middle)

#### Idea
- Knowledge: 最长连续序列(哈希)
- Question: 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。请你设计并实现时间复杂度为 O(n)的算法解决此问题。
- Code: algorithm/leetcode/leco/4.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
    public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longest_streak = 0;

        for (const int& num : num_set)
        {
            // 仅在num是序列的起点时开始计数
            if (num_set.find(num - 1) == num_set.end())
            {
                int current_num = num;
                int current_streak = 1;

                // 向后查找连续的数字
                while (num_set.find(current_num + 1) != num_set.end())
                {
                    current_num += 1;
                    current_streak += 1;
                }

                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};
```

## 二分查找

### offer.04 (easy)

#### Idea
- Knowledge: 二维二分查找(二分查找)
- Question: 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
- Code: algorithm/leetcode/offer/04.cpp
- Current classes: Solution, Solution2

#### Official
- Selected class: Solution
```cpp
class Solution
{
    public:
        bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
        {
            for(auto &row : matrix)
            {
                int j = lower_bound(row.begin(), row.end(), target) - row.begin();
                if(j < matrix[0].size() && row[j] == target)
                {
                    return true;
                }
            }
            return false;
        }
};
```

### offer.53-1 (easy)

#### Idea
- Knowledge: 在排序数组中查找数字(二分查找)
- Question: 统计一个数字在排序数组中出现的次数。
- Code: algorithm/leetcode/offer/53-1.cpp
- Current classes: mySolutoin_53_1

#### Official
- Selected class: mySolutoin_53_1
```cpp
class mySolutoin_53_1
{
    public:
    int search(vector<int>& nums,int target)
    {
        auto l = lower_bound(nums.begin(),nums.end(),target);
        auto r = upper_bound(nums.begin(),nums.end(),target);
        return r - l;
    }
};
```

### offer.53-2 (easy)

#### Idea
- Knowledge: ~n-1中缺失的数字(二分查找)
- Question: 一个长度为 n-1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
- Code: algorithm/leetcode/offer/53-2.cpp
- Current classes: mySolution_53_2, offerSolution_53_2

#### Official
- Selected class: mySolution_53_2
```cpp
class mySolution_53_2
{
    public:
    int missingNum(vector<int>& nums)
    {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j)
        {
            int m = i + (j - i) / 2;
            if (nums[m] > m)
            {
                j = m - 1;
            }
            else
            {
                i = m + 1;
            }
        }
        return i;
    }
};
```

## 字符串

### offer.05 (easy)

#### Idea
- Knowledge: 字符串替换(字符串)
- Question: s: 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
- Code: algorithm/leetcode/offer/05.cpp
- Current classes: no class detected

#### Official
- No class block available in this file.

### offer.67 (middle)

#### Idea
- Knowledge: 把字符串转换为整数(字符串)
- Question: 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。在任何情况下，若函数不能进行有效的转换时，请返回 0。
- Code: algorithm/leetcode/offer/67.cpp
- Current classes: mySolution_67, offerSolution_67

#### Official
- Selected class: mySolution_67
```cpp
class mySolution_67
{
    public:
    int strToInt(string str)
    {
        // 清除前面空格
        while (str.size() && str[0] == ' ')
        {
            str.erase(str.begin());
        }
        // 不合法的字符串
        if (str.empty() || !isdigit(str[0]) && str[0] != '+' && str[0] != '-')
        {
            return 0;
        }
        if (str.size() == 1 && !isdigit(str[0]))
        {
            return 0;
        }
        // 确定符号
        int sign = 1;
        if (str[0] == '-')
        {
            sign = -1;
            str.erase(str.begin());
        }
        else if (str[0] == '+')
        {
            str.erase(str.begin());
        }
        // 计算数值
        long long unsigned int result = 0;
        for (char c : str)
        {
            if (!isdigit(c))
            {
                break;
            }
            result = result * 10 + (c - '0');
            if (result > INT_MAX)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        return sign * result;
    }
};
```

## 链表

### offer.06 (easy)

#### Idea
- Knowledge: 链表倒序输出(链表)
- Question: 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
- Code: algorithm/leetcode/offer/06.cpp
- Current classes: my_Solution_06_1, my_Solution_06_2, my_Solution_06_3, offer_Solution_06

#### Official
- Selected class: offer_Solution_06
```cpp
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
```

### offer.18 (easy)

#### Idea
- Knowledge: 删除链表节点(链表)
- Question: 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
- Code: algorithm/leetcode/offer/18.cpp
- Current classes: My_solution, offer_Solution

#### Official
- Selected class: offer_Solution
```cpp
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
```

### offer.22 (easy)

#### Idea
- Knowledge: 链表中倒数第k个节点(链表)
- Question: 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
- Code: algorithm/leetcode/offer/22.cpp
- Current classes: MySolution22, offer_Solution_22

#### Official
- Selected class: offer_Solution_22
```cpp
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
```

### offer.20#2 (easy)

#### Idea
- Knowledge: 翻转链表(链表)
- Question: 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
- Code: algorithm/leetcode/offer/24.cpp
- Current classes: Mysolution_24, OfferSolution_24

#### Official
- Selected class: Mysolution_24
```cpp
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
```

### offer.25 (easy)

#### Idea
- Knowledge: 合并链表(链表)
- Code: algorithm/leetcode/offer/25.cpp
- Current classes: mySolution_25, offerSolution_25

#### Official
- Selected class: mySolution_25
```cpp
class mySolution_25
{
    public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;               
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return head->next;
    }
};
```

### offer.35 (middle)

#### Idea
- Knowledge: 复杂链表的复制(链表+哈希)
- Question: 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
- Code: algorithm/leetcode/offer/35.cpp
- Current classes: Node, mySolution_35, offerSolution_35_1, offerSolution_35_2

#### Official
- Selected class: mySolution_35
```cpp
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
```

### offer.36 (middle)

#### Idea
- Knowledge: 二叉搜索树与双向链表(链表+树)
- Code: algorithm/leetcode/offer/36.cpp
- Current classes: Node, mySolution_36, offerSolution_36

#### Official
- Selected class: mySolution_36
```cpp
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
```

### leetcode.11 (easy)

#### Idea
- Knowledge: 翻转链表(链表)
- Question: 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
- Code: algorithm/leetcode/leco/11.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
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
```

## 分治

### offer.07 (middle)

#### Idea
- Knowledge: 重建二叉树(分治+哈希)
- Question: 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
- Code: algorithm/leetcode/offer/07.cpp
- Current classes: Solution1, Solution2, Solution_review_1, Solution_review_2

#### Official
- Selected class: Solution1
```cpp
class Solution1
{
public:
    TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, int i, int l, int r)
    {
        // 子树区间为空时终止
        if (r - l < 0)
        {
            return NULL;
        }
        // 初始化根节点
        TreeNode *root = new TreeNode(preorder[i]);
        // 查询 m , 从而划分左右子树
        int m = inorderMap[preorder[i]];
        // 子问题：构建左子树
        root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
        // 子问题：构建右子树
        root->right = dfs(preorder, inorderMap, i + m - l + 1, m + 1, r);
        // 返回根节点
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 初始化哈希表，储存 inorder 元素到索引的映射
        unordered_map<int, int> inorderMap;
        for (vector<int>::size_type i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        TreeNode *root = dfs(preorder, inorderMap, 0, 0, inorder.size() - 1);
        return root;
    }
};
```

## 队列

### offer.08 (easy)

#### Idea
- Knowledge: 两个栈实现一个队列(队列)
- Question: 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
- Code: algorithm/leetcode/offer/09.cpp
- Current classes: MyQueue, CQueue

#### Official
- Selected class: MyQueue
```cpp
class MyQueue
{
    private: 
        stack<int> stack1;
        stack<int> stack2;
    public:
        void appendTail(int value)
        {
            stack2.push(value);
        }
        int deleteHead()
        {
            if(stack2.empty())
            {
                return -1;
            }
            while(!stack2.empty())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
            int result = stack1.top();
            stack1.pop();
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            return result;
        }
};
```

## dp

### offer.10-I (easy)

#### Idea
- Knowledge: 斐波那契数列(dp)
- Question: 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：F(0) = 0,   F(1) = 1  F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
- Code: algorithm/leetcode/offer/10-I.cpp
- Current classes: my_Solution_10_1, offer_Solution_10_1

#### Official
- Selected class: offer_Solution_10_1
```cpp
class offer_Solution_10_1
{
public:
    int fib(int n)
    {
        int a = 0, b = 1;
        while (n--)
        {
            int c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return a;
    }
};
```

### offer.10-2 (easy)

#### Idea
- Knowledge: 跳楼梯(dp)
- Question: 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。
- Code: algorithm/leetcode/offer/10-2.cpp
- Current classes: my_solution, my_solutin_refavtor, Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int numWays(int n)
    {
        int a = 1, b = 1;
        while (n--)
        {
            int c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return a;
    }
};
```

### offer.14-1 (middle)

#### Idea
- Knowledge: 剪绳子(贪心+dp)
- Question: 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
- Code: algorithm/leetcode/offer/14-1.cpp
- Current classes: My_solution_14_1, offer_Solution_14_1, offer_Solution

#### Official
- Selected class: offer_Solution_14_1
```cpp
class offer_Solution_14_1
{
public:
    int cuttingRope(int n)
    {
        vector<int> f(n + 1);
        f[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                f[i] = max({f[i], f[i - j] * j, (i - j) * j});
            }
        }
        return f[n];
    }
};
```

### offer.14-2 (middle)

#### Idea
- Knowledge: 剪绳子(贪心+dp)
- Question: 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。
- Code: algorithm/leetcode/offer/14-2.cpp
- Current classes: My_solution_14_2, offer_Solution

#### Official
- Selected class: offer_Solution
```cpp
class offer_Solution
{
public:
    int cuttingRope(int n)
    {
        if (n < 4)
        {
            return n - 1;
        }
        const int mod = 1e9 + 7;
        auto qpow = [&](long long a, long long n)
        {
            long long ans = 1;
            for (; n; n >>= 1)
            {
                if (n & 1)
                {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int)ans;
        };
        if (n % 3 == 0)
        {
            return qpow(3, n / 3);
        }
        if (n % 3 == 1)
        {
            return qpow(3, n / 3 - 1) * 4L % mod;
        }
        return qpow(3, n / 3) * 2 % mod;
    }
};
```

### offer.46 (middle)

#### Idea
- Knowledge: 把数字翻译成字符串(dp)
- Code: algorithm/leetcode/offer/46.cpp
- Current classes: mySolution_46, offerSolution_46_dp, offerSolution_46_dfs

#### Official
- Selected class: mySolution_46
```cpp
class mySolution_46
{
    public:
    int translateNum(int num)
    {
        string s = to_string(num);
        int n = s.size();  
        int a = 1, b = 1; 
        for (int i = 1; i < n; ++i)
        {
            int c = b;
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 && two_digit <= 25)
            {
                c += a;
            }
            a = b;
            b = c;
        }
        return b;
    }
};
```

### offer.47 (middle)

#### Idea
- Knowledge: 礼物的最大价值(dp)
- Question: 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
- Code: algorithm/leetcode/offer/47.cpp
- Current classes: mySolution_47

#### Official
- Selected class: mySolution_47
```cpp
class mySolution_47
{
    public:
    int maxValue(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

### offer.49 (middle)

#### Idea
- Knowledge: 丑数(dp or 优先队列)
- Question: 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
- Code: algorithm/leetcode/offer/49.cpp
- Current classes: mySolution_49, offerSolution_49_dp, offerSolution_49_heap

#### Official
- Selected class: mySolution_49
```cpp
class mySolution_49
{
    public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(2, 0);
        dp[1] = 1;
        int i = 2;
        for(; i <= 1690; i++ )
        {
            if(dp.size() > n)
            {
                break;
            }
            if (!(i % 2) || !(i % 3) || !(i % 5))
            {
                dp.push_back(i);
            }
        }  
        return dp[dp.size() - 1];
    }
    int nthUglyNumber_review(int n)
    {
        int p1 = 0, p2 = 0, p3 = 0;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int a = dp[p1] * 2;
            int b = dp[p2] * 3; 
            int c = dp[p3] * 5;
            dp[i] = min(a, min(b, c));
            if (dp[i] == a) p1++;
            if (dp[i] == b) p2++;
            if (dp[i] == c) p3++;
        }
        return dp[n - 1];
    }
};
```

### offer.60 (easy)

#### Idea
- Knowledge: n个骰子的点数(dp)
- Question: 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
- Code: algorithm/leetcode/offer/60.cpp
- Current classes: mySolution_60, offerSolution_60, mySolution_60_2

#### Official
- Selected class: mySolution_60
```cpp
class mySolution_60
{
    public:
    vector<float> dicesProbability(int n)
    {
        vector<float> dp(5 * n + 1,0.0);
        int total = pow(6,n);
        dp[0] = 1.0 / total;
        for (int i = 1; i < 6; ++i)
        {
            if (n == 1)
            {
                dp[i] = 1.0 / total;
            }
            else 
            {
                dp[i] = dp[i - 1] + 1.0 / total;
            }
        }
        for (int i = 7; i < 5 * n + 1 - 5; ++i)
        {
            dp[i] = dp[i - 1];
        }
        for (int i = 5 * n + 1 - 5; i < 5 * n + 2 && n != 1; ++i)
        {
            dp[i] = dp[i - 1] - 1.0 / total;
        }
        return dp;
    }
};
```

### offer.63 (middle)

#### Idea
- Knowledge: 股票的最大利润(dp)
- Question: 设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
- Code: algorithm/leetcode/offer/63.cpp
- Current classes: mySolution_63, offerSolution_63, offerSolution_63_2

#### Official
- Selected class: mySolution_63
```cpp
class mySolution_63
{
    public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1];
            for (int j = 0; j < i; j++)
            {
                dp[i] = max(dp[i], prices[i] - prices[j]);
            }
        }
        return dp[n - 1];
    }
};
```

### leetcode.8 (easy)

#### Idea
- Knowledge: 爬楼梯(dp)
- Question: 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
- Code: algorithm/leetcode/leco/8.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++)
        {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};
```

## 二分

### offer.11 (easy)

#### Idea
- Knowledge: 选择数组最小数字(二分)
- Question: 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组[3, 4, 5, 1, 2] 为[1, 2, 3, 4, 5] 的一次旋转，该数组的最小值为1。
- Code: algorithm/leetcode/offer/11.cpp
- Current classes: my_Solution, offer_Solution

#### Official
- Selected class: offer_Solution
```cpp
class offer_Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (numbers[mid] > numbers[r])
            {
                l = mid + 1;
            }
            else if (numbers[mid] < numbers[r])
            {
                r = mid;
            }
            else
            {
                --r;
            }
        }
        return numbers[l];
    }
};
```

## 回溯

### offer.12 (middle)

#### Idea
- Knowledge: 网格寻找字符串(回溯)
- Question: 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
- Code: algorithm/leetcode/offer/12.cpp
- Current classes: My_solution_12, offer_Solution, My_solution_12_Fixed, My_solution_12_MinimalFix, mySolution_12_2, mySolution_12_3, mySolution_12_4

#### Official
- Selected class: offer_Solution
```cpp
class offer_Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool
        {
            if (k == word.size())
            {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
            {
                return false;
            }
            board[i][j] = '.';
            bool ans = 0;
            for (int l = 0; l < 4; ++l)
            {
                ans |= dfs(i + dirs[l], j + dirs[l + 1], k + 1);
            }
            board[i][j] = word[k];
            return ans;
        };
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
```

### offer.38 (middle)

#### Idea
- Knowledge: 字符串的排列(回溯+哈希表)
- Question: 输入一个字符串，打印出该字符串中字符的所有排列.你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
- Code: algorithm/leetcode/offer/38.cpp
- Current classes: mySolution_38, offerSolution_38

#### Official
- Selected class: mySolution_38
```cpp
class mySolution_38
{
    public:
        void backtrack(vector<char> &state, const string &choices, vector<bool> &selected, vector<vector<char>> &result)
        {
            if (state.size() == choices.size())
            {
                result.push_back(state);
                return;
            }
            unordered_set<char> duplicated;
            for (int i = 0; i < choices.size(); i++)
            {
                char choice = choices[i];
                if (!selected[i] && duplicated.find(choice) == duplicated.end())
                {
                    state.push_back(choice);
                    //重复选择剪枝：整个搜索过程中只有一个 selected 。它记录的是当前状态中包含哪些元素，其作用是避免某个元素在 state 中重复出现。
                    selected[i] = true;
                    //相等元素剪枝：每轮选择（每个调用的 backtrack 函数）都包含一个 duplicated 。它记录的是在本轮遍历（for 循环）中哪些元素已被选择过，其作用是保证相等元素只被选择一次。   
                    duplicated.emplace(choice);
                    backtrack(state, choices, selected, result);
                    state.pop_back();
                    selected[i] = false;
                }
            }
    }
    vector<vector<char>> permute(const string &choices)
    {
        vector<char> state;
        vector<bool> selected(choices.size(), false);
        vector<vector<char>> result;
        backtrack(state, choices, selected, result);
        return result;
    }
};
```

## DFS

### offer.13 (middle)

#### Idea
- Knowledge: 机器人的运动范围(DFS+哈希)
- Question: 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
- Code: algorithm/leetcode/offer/13.cpp
- Current classes: my_solution_13, Solution, Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        bool vis[m][n];
        memset(vis, false, sizeof vis);
        auto f = [](int x)
        {
            return x / 10 + x % 10;
        };
        function<int(int i, int j)> dfs = [&](int i, int j) -> int
        {
            if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || f(i) + f(j) > k)
            {
                return false;
            }
            vis[i][j] = true;
            return 1 + dfs(i + 1, j) + dfs(i, j + 1);
        };
        return dfs(0, 0);
    }
};*/
```

### offer.19 (hard)

#### Idea
- Knowledge: 正则表达式匹配(dfs)
- Question: 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
- Code: algorithm/leetcode/offer/19.cpp
- Current classes: my_solution_19, my_solution_19_fixed, offer_Solution_19, my_solution_19_second

#### Official
- Selected class: offer_Solution_19
```cpp
class offer_Solution_19
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        function<bool(int, int)> dfs = [&](int i, int j) -> bool
        {
            if (j >= n)
            {
                return i == m;
            }
            if (f[i][j])
            {
                return f[i][j] == 1;
            }
            int res = -1;
            if (j + 1 < n && p[j + 1] == '*')
            {
                if (dfs(i, j + 2) or (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j)))
                {
                    res = 1;
                }
            }
            else if (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j + 1))
            {
                res = 1;
            }
            f[i][j] = res;
            return res == 1;
        };
        return dfs(0, 0);
    }
};
```

### offer.26 (middle)

#### Idea
- Knowledge: 树的子结构(树+dfs)
- Question: 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构),B是A的子结构， 即 A中有出现和B相同的结构和节点值。
- Code: algorithm/leetcode/offer/26.cpp
- Current classes: mySolution_26, offerSolution_26, mySolution_26_2

#### Official
- Selected class: mySolution_26
```cpp
class mySolution_26
{
    public:
    // root     n
    // left     n/2+1
    // right    n/2+2
    bool treeChildstructure(vector<int> &a, vector<int> &b)
    {
        int treeB_index = 0;
        int i = 0;
        for (i = 0; i < a.size(); i++)
        {
            if (a[i] == b[0])
            {
                treeB_index = i;
                break;
            }
        }
        if(i == a.size())
        {
            return false;
        }
        function<bool(int, int)> dfs = [&](int a_rootindex, int b_rootindex)->bool
        {
            bool root_equal = false;
            if(b_rootindex >= b.size())
            {
                return true;
            }
            else if(a_rootindex >= a.size())
            {
                return false;
            }
            else if(a[a_rootindex] == b[b_rootindex])
            {
                root_equal = true;
            }
            else
            {
                return false;
            }
            bool left = dfs(2 * a_rootindex + 1, 2 * b_rootindex + 1);
            bool right = dfs(2 * a_rootindex + 2, 2 * b_rootindex + 2);
            return left && right && root_equal;
        };
        return dfs(treeB_index, 0);
    }
};
```

### offer.34 (middle)

#### Idea
- Knowledge: 二叉树中和为某一值的路径(二叉树+dfs)
- Code: algorithm/leetcode/offer/34.cpp
- Current classes: mySolution_34, offerSolution_34

#### Official
- Selected class: mySolution_34
```cpp
class mySolution_34
{
    public:
    vector<vector<int>> pathInTree(TreeNode* root, int target)
    {
        vector<int> path;
        vector<vector<int>> res;
        function<void(TreeNode * root, int s)> dfs = [&](TreeNode *root, int s) -> void
        {
            //mySolution_34 加了(s - root->val) < 0 的提前剪枝，若树节点或 target 存在负数，会误删合法路径 → 不安全。
             if (root == nullptr || (s - root -> val) < 0)
            {
                return;
            }
            s -= root->val;
            path.push_back(root->val);
            if (root->left == nullptr && root->right == nullptr && s == 0)
            {
                res.push_back(path);
            }
            dfs(root->left, s);
            dfs(root->right, s);
            path.pop_back();
        };
        dfs(root, target);
        return res;
    }
};
```

## 贪心

### offer.14-1 (middle)

#### Idea
- Knowledge: 剪绳子(贪心+dp)
- Question: 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
- Code: algorithm/leetcode/offer/14-1.cpp
- Current classes: My_solution_14_1, offer_Solution_14_1, offer_Solution

#### Official
- Selected class: offer_Solution_14_1
```cpp
class offer_Solution_14_1
{
public:
    int cuttingRope(int n)
    {
        vector<int> f(n + 1);
        f[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                f[i] = max({f[i], f[i - j] * j, (i - j) * j});
            }
        }
        return f[n];
    }
};
```

### offer.14-2 (middle)

#### Idea
- Knowledge: 剪绳子(贪心+dp)
- Question: 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。
- Code: algorithm/leetcode/offer/14-2.cpp
- Current classes: My_solution_14_2, offer_Solution

#### Official
- Selected class: offer_Solution
```cpp
class offer_Solution
{
public:
    int cuttingRope(int n)
    {
        if (n < 4)
        {
            return n - 1;
        }
        const int mod = 1e9 + 7;
        auto qpow = [&](long long a, long long n)
        {
            long long ans = 1;
            for (; n; n >>= 1)
            {
                if (n & 1)
                {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int)ans;
        };
        if (n % 3 == 0)
        {
            return qpow(3, n / 3);
        }
        if (n % 3 == 1)
        {
            return qpow(3, n / 3 - 1) * 4L % mod;
        }
        return qpow(3, n / 3) * 2 % mod;
    }
};
```

## 位运算

### offer.15 (easy)

#### Idea
- Knowledge: 二进制中1的个数(位运算)
- Code: algorithm/leetcode/offer/15.cpp
- Current classes: My_solution_15, offer_Solution_1, offer_Solution_2

#### Official
- Selected class: offer_Solution_1
```cpp
class offer_Solution_1
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            n &= (n - 1);
            ++ans;
        }
        return ans;
    }
};
```

### offer.65 (easy)

#### Idea
- Knowledge: 不用加减乘除做加法(位运算)
- Question: 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
- Code: algorithm/leetcode/offer/65.cpp
- Current classes: offerSolution_65

#### Official
- Selected class: offerSolution_65
```cpp
class offerSolution_65
{
public:
    int add(int a, int b)
    {
        while (b)
        {
            unsigned int c = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};
```

## 快速幂

### offer.16 (middle)

#### Idea
- Knowledge: 数值的整数次方(快速幂)
- Question: 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
- Code: algorithm/leetcode/offer/16.cpp
- Current classes: my_solution, offer_Solution, mySolution_16_2

#### Official
- Selected class: offer_Solution
```cpp
class offer_Solution
{
public:
    double myPow(double x, int n)
    {
        auto qpow = [](double a, long long n)
        {
            double ans = 1;
            for (; n; n >>= 1)
            {
                if (n & 1)
                {
                    ans *= a;
                }
                a *= a;
            }
            return ans;
        };
        return n >= 0 ? qpow(x, n) : 1 / qpow(x, -(long long)n);
    }
};
```

### offer.17 (easy)

#### Idea
- Knowledge: 打印从1到最大的n位数(快速幂)
- Question: 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
- Code: algorithm/leetcode/offer/17.cpp
- Current classes: my_solution, offer_Solution

#### Official
- Selected class: offer_Solution
```cpp
class offer_Solution
{
public:
    vector<int> printNumbers(int n)
    {
        vector<int> ans(pow(10, n) - 1);
        iota(ans.begin(), ans.end(), 1);
        return ans;
    }

    vector<string> print(int n)
    {
        vector<string> ans;
        string s;
        function<void(int, int)> dfs = [&](int i, int j)
        {
            if (i == j)
            {
                ans.push_back(s);
                return;
            }
            int k = i ? 0 : 1;
            for (; k < 10; ++k)
            {
                s.push_back(k + '0');
                dfs(i + 1, j);
                s.pop_back();
            }
        };
        for (int i = 1; i <= n; ++i)
        {
            dfs(0, i);
        }
        return ans;
    }
};
```

## 数组

### offer.21 (easy)

#### Idea
- Knowledge: 调整数组顺序(数组)
- Question: 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
- Code: algorithm/leetcode/offer/21.cpp
- Current classes: My_solution, offer_Solution

#### Official
- Selected class: offer_Solution
```cpp
class offer_Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] & 1)
            {
                swap(nums[i], nums[j++]);
            }
        }
        return nums;
    }
};
```

## dfs

### offer.13 (middle)

#### Idea
- Knowledge: 机器人的运动范围(DFS+哈希)
- Question: 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
- Code: algorithm/leetcode/offer/13.cpp
- Current classes: my_solution_13, Solution, Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        bool vis[m][n];
        memset(vis, false, sizeof vis);
        auto f = [](int x)
        {
            return x / 10 + x % 10;
        };
        function<int(int i, int j)> dfs = [&](int i, int j) -> int
        {
            if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || f(i) + f(j) > k)
            {
                return false;
            }
            vis[i][j] = true;
            return 1 + dfs(i + 1, j) + dfs(i, j + 1);
        };
        return dfs(0, 0);
    }
};*/
```

### offer.19 (hard)

#### Idea
- Knowledge: 正则表达式匹配(dfs)
- Question: 请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
- Code: algorithm/leetcode/offer/19.cpp
- Current classes: my_solution_19, my_solution_19_fixed, offer_Solution_19, my_solution_19_second

#### Official
- Selected class: offer_Solution_19
```cpp
class offer_Solution_19
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
        function<bool(int, int)> dfs = [&](int i, int j) -> bool
        {
            if (j >= n)
            {
                return i == m;
            }
            if (f[i][j])
            {
                return f[i][j] == 1;
            }
            int res = -1;
            if (j + 1 < n && p[j + 1] == '*')
            {
                if (dfs(i, j + 2) or (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j)))
                {
                    res = 1;
                }
            }
            else if (i < m and (s[i] == p[j] or p[j] == '.') and dfs(i + 1, j + 1))
            {
                res = 1;
            }
            f[i][j] = res;
            return res == 1;
        };
        return dfs(0, 0);
    }
};
```

### offer.26 (middle)

#### Idea
- Knowledge: 树的子结构(树+dfs)
- Question: 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构),B是A的子结构， 即 A中有出现和B相同的结构和节点值。
- Code: algorithm/leetcode/offer/26.cpp
- Current classes: mySolution_26, offerSolution_26, mySolution_26_2

#### Official
- Selected class: mySolution_26
```cpp
class mySolution_26
{
    public:
    // root     n
    // left     n/2+1
    // right    n/2+2
    bool treeChildstructure(vector<int> &a, vector<int> &b)
    {
        int treeB_index = 0;
        int i = 0;
        for (i = 0; i < a.size(); i++)
        {
            if (a[i] == b[0])
            {
                treeB_index = i;
                break;
            }
        }
        if(i == a.size())
        {
            return false;
        }
        function<bool(int, int)> dfs = [&](int a_rootindex, int b_rootindex)->bool
        {
            bool root_equal = false;
            if(b_rootindex >= b.size())
            {
                return true;
            }
            else if(a_rootindex >= a.size())
            {
                return false;
            }
            else if(a[a_rootindex] == b[b_rootindex])
            {
                root_equal = true;
            }
            else
            {
                return false;
            }
            bool left = dfs(2 * a_rootindex + 1, 2 * b_rootindex + 1);
            bool right = dfs(2 * a_rootindex + 2, 2 * b_rootindex + 2);
            return left && right && root_equal;
        };
        return dfs(treeB_index, 0);
    }
};
```

### offer.34 (middle)

#### Idea
- Knowledge: 二叉树中和为某一值的路径(二叉树+dfs)
- Code: algorithm/leetcode/offer/34.cpp
- Current classes: mySolution_34, offerSolution_34

#### Official
- Selected class: mySolution_34
```cpp
class mySolution_34
{
    public:
    vector<vector<int>> pathInTree(TreeNode* root, int target)
    {
        vector<int> path;
        vector<vector<int>> res;
        function<void(TreeNode * root, int s)> dfs = [&](TreeNode *root, int s) -> void
        {
            //mySolution_34 加了(s - root->val) < 0 的提前剪枝，若树节点或 target 存在负数，会误删合法路径 → 不安全。
             if (root == nullptr || (s - root -> val) < 0)
            {
                return;
            }
            s -= root->val;
            path.push_back(root->val);
            if (root->left == nullptr && root->right == nullptr && s == 0)
            {
                res.push_back(path);
            }
            dfs(root->left, s);
            dfs(root->right, s);
            path.pop_back();
        };
        dfs(root, target);
        return res;
    }
};
```

## 逻辑判断

### offer.20 (middle)

#### Idea
- Knowledge: 判断字符串是否表示数值(逻辑判断)
- Question: 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
- Code: algorithm/leetcode/offer/20.cpp
- Current classes: Mysolution_20

#### Official
- Selected class: Mysolution_20
```cpp
class Mysolution_20
{
    public:
    bool isNumb(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while(i < j && s[i] == ' ')
        {
            i++;
        }
        while(i < j && s[j] == ' ')
        {
            j--;
        }
        if(i > j)
        {
            return false;
        }
        bool digit = false, dot = false, e = false;
        for (; i <= j; ++i)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                if (i && s[i - 1] != ' ' && s[i - 1] != 'e' && s[i - 1] != 'E')
                {
                    return false;
                }
            }
            else if (isdigit(s[i]))
            {
                digit = true;
            }
            else if (s[i] == '.')
            {
                if (dot || e)
                {
                    return false;
                }
                dot = true;
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (!digit || e)
                {
                    return false;
                }
                e = true;
                digit = false;
            }
            else
            {
                return false;
            }
        }
        return digit;
    }
};
```

## 树

### offer.26 (middle)

#### Idea
- Knowledge: 树的子结构(树+dfs)
- Question: 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构),B是A的子结构， 即 A中有出现和B相同的结构和节点值。
- Code: algorithm/leetcode/offer/26.cpp
- Current classes: mySolution_26, offerSolution_26, mySolution_26_2

#### Official
- Selected class: mySolution_26
```cpp
class mySolution_26
{
    public:
    // root     n
    // left     n/2+1
    // right    n/2+2
    bool treeChildstructure(vector<int> &a, vector<int> &b)
    {
        int treeB_index = 0;
        int i = 0;
        for (i = 0; i < a.size(); i++)
        {
            if (a[i] == b[0])
            {
                treeB_index = i;
                break;
            }
        }
        if(i == a.size())
        {
            return false;
        }
        function<bool(int, int)> dfs = [&](int a_rootindex, int b_rootindex)->bool
        {
            bool root_equal = false;
            if(b_rootindex >= b.size())
            {
                return true;
            }
            else if(a_rootindex >= a.size())
            {
                return false;
            }
            else if(a[a_rootindex] == b[b_rootindex])
            {
                root_equal = true;
            }
            else
            {
                return false;
            }
            bool left = dfs(2 * a_rootindex + 1, 2 * b_rootindex + 1);
            bool right = dfs(2 * a_rootindex + 2, 2 * b_rootindex + 2);
            return left && right && root_equal;
        };
        return dfs(treeB_index, 0);
    }
};
```

### offer.27 (easy)

#### Idea
- Knowledge: 二叉树的镜像(树+递归)
- Question: 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
- Code: algorithm/leetcode/offer/27.cpp
- Current classes: TreeNode, mySolution_27, mySolution_27_2

#### Official
- Selected class: mySolution_27
```cpp
class mySolution_27
{
    public:
    TreeNode* mirrorTree(TreeNode* root)
    {
        if(!root)
        {
            return root;
        }
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
```

### offer.28 (easy)

#### Idea
- Knowledge: 对称的二叉树(树+递归)
- Question: 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
- Code: algorithm/leetcode/offer/28.cpp
- Current classes: mySolution_28, offerSolution_28, mySolution_28_2

#### Official
- Selected class: mySolution_28
```cpp
class mySolution_28
{
    public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        vector<int> rightTree;
        vector<int> leftTree;
        function<void(TreeNode *, vector<int> &, int)> preOrder = [&](TreeNode *node, vector<int> &res, int side) {
            if (node == nullptr)
            {
                res.push_back(-101);
                return;
            }
            if(side == 0) // left
            {
                preOrder(node->left, res, 0);
                res.push_back(node->val);
                preOrder(node->right, res, 0);
            }
            else // right
            {
                preOrder(node->right, res, 1);
                res.push_back(node->val);
                preOrder(node->left, res, 1);
            }
        };
        preOrder(root->left, leftTree, 0);
        preOrder(root->right, rightTree, 1);
        for (int i = 0; i < leftTree.size(); i++)
        {
            if (leftTree[i] != rightTree[i])
            {
                return false;
            }
        }
        return true;
    }
};
```

### offer.36 (middle)

#### Idea
- Knowledge: 二叉搜索树与双向链表(链表+树)
- Code: algorithm/leetcode/offer/36.cpp
- Current classes: Node, mySolution_36, offerSolution_36

#### Official
- Selected class: mySolution_36
```cpp
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
```

### offer.68-1 (easy)

#### Idea
- Knowledge: 二叉搜索树的最近公共祖先(树)
- Question: 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
- Code: algorithm/leetcode/offer/68-1.cpp
- Current classes: mySolution_68_1, offerSolution_68_1

#### Official
- Selected class: mySolution_68_1
```cpp
class mySolution_68_1
{
    public:
        TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
        {
            if (root == nullptr || root == p || root == q)
            {
                return root;
            }
            if (p->val < root->val && q->val < root->val)
            {
                return lowestCommonAncestor(root->left, p, q);
            }
            else if (p->val > root->val && q->val > root->val)
            {
                return lowestCommonAncestor(root->right, p, q);
            }
            else
            {
                return root;
            }
        }
};
```

### leetcode.2 (easy)

#### Idea
- Knowledge: 翻转二叉树(树)
- Question: 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
- Code: algorithm/leetcode/leco/2.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
    public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }
        swap(root->right, root->left);
        invertTree(root->right);
        invertTree(root->left);
        return root;
    }
};
```

### leetcode.10 (easy)

#### Idea
- Knowledge: 二叉树的最大深度(树)
- Question: 给定一个二叉树 root ，返回其最大深度。二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
- Code: algorithm/leetcode/leco/10.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};
```

## 递归

### offer.27 (easy)

#### Idea
- Knowledge: 二叉树的镜像(树+递归)
- Question: 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
- Code: algorithm/leetcode/offer/27.cpp
- Current classes: TreeNode, mySolution_27, mySolution_27_2

#### Official
- Selected class: mySolution_27
```cpp
class mySolution_27
{
    public:
    TreeNode* mirrorTree(TreeNode* root)
    {
        if(!root)
        {
            return root;
        }
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
```

### offer.28 (easy)

#### Idea
- Knowledge: 对称的二叉树(树+递归)
- Question: 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
- Code: algorithm/leetcode/offer/28.cpp
- Current classes: mySolution_28, offerSolution_28, mySolution_28_2

#### Official
- Selected class: mySolution_28
```cpp
class mySolution_28
{
    public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        vector<int> rightTree;
        vector<int> leftTree;
        function<void(TreeNode *, vector<int> &, int)> preOrder = [&](TreeNode *node, vector<int> &res, int side) {
            if (node == nullptr)
            {
                res.push_back(-101);
                return;
            }
            if(side == 0) // left
            {
                preOrder(node->left, res, 0);
                res.push_back(node->val);
                preOrder(node->right, res, 0);
            }
            else // right
            {
                preOrder(node->right, res, 1);
                res.push_back(node->val);
                preOrder(node->left, res, 1);
            }
        };
        preOrder(root->left, leftTree, 0);
        preOrder(root->right, rightTree, 1);
        for (int i = 0; i < leftTree.size(); i++)
        {
            if (leftTree[i] != rightTree[i])
            {
                return false;
            }
        }
        return true;
    }
};
```

### offer.55-1 (easy)

#### Idea
- Knowledge: 二叉树的深度(递归)
- Code: algorithm/leetcode/offer/55-1.cpp
- Current classes: mySolution_55_1, offerSolution_55_1

#### Official
- Selected class: mySolution_55_1
```cpp
class mySolution_55_1
{
    public:
    int maxDepth(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};
```

### offer.55-2 (easy)

#### Idea
- Knowledge: 平衡二叉树(递归)
- Question: 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
- Code: algorithm/leetcode/offer/55-2.cpp
- Current classes: mySolution_55_2, offerSolution_55_2, mySolutoin_55_2_2

#### Official
- Selected class: mySolution_55_2
```cpp
class mySolution_55_2
{
    public:
    int depth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left_depth = depth(root->left);
        if (left_depth == -1)
        {
            return -1;
        }
        int right_depth = depth(root->right);
        if (right_depth == -1)
        {
            return -1;
        }
        if (abs(left_depth - right_depth) > 1)
        {
            return -1;
        }
        return max(left_depth, right_depth) + 1;
    }
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return depth(root) != -1;
    }
};
```

### offer.62 (easy)

#### Idea
- Knowledge: 圆圈中剩下的数字(数学 + 递归)
- Question: 0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
- Code: algorithm/leetcode/offer/62.cpp
- Current classes: mySolution_62, offerSolution_62, offerSolution_62_2

#### Official
- Selected class: mySolution_62
```cpp
class mySolution_62
{
    public:
    int lastRemaining(int n, int m)
    {
        int rest = n;
        int dex = 0;
        int i = 0;
        unordered_set<int> st;
        while(rest > 1)
        {        
            if (i == m - 1)
            {
                st.insert(dex);
                dex = dex + 1;
                if (dex >= n)
                {
                    dex = 0;
                }
                while (st.find(dex) != st.end())
                {
                    dex++;
                    if (dex >= n)
                    {
                        dex = 0;
                    }
                }
                i = 0;
                rest--;
            }
            else
            {
                dex++;
                if (dex >= n)
                {
                    dex = 0;
                }
                while(st.find(dex) != st.end())
                {
                    dex++;
                    if (dex >= n)
                    {
                        dex = 0;
                    }
                }
                i++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (st.find(j) == st.end())
            {
                return j;
            }
        }
        return -1;
    }
};
```

### offer.64 (middle)

#### Idea
- Knowledge: 求1+2+...+n(递归+短路求值)
- Question: 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
- Code: algorithm/leetcode/offer/64.cpp
- Current classes: mySolution_64, offerSolution_64

#### Official
- Selected class: mySolution_64
```cpp
class mySolution_64
{
    public:
    int sumNums(int n)
    {
        int sum = 0;
        (n == 1) && (sum += 1);
        (n > 1) && (sum += sumNums(n - 1) + n);
        return sum;
    }
};
```

## 顺时针打印矩阵

### offer.29 (easy)

#### Idea
- Knowledge: 顺时针打印矩阵
- Code: algorithm/leetcode/offer/29.cpp
- Current classes: mySolution_29, offerSolution_29

#### Official
- Selected class: mySolution_29
```cpp
class mySolution_29
{
    public:
        void printmatrix(vector<vector<int>> &matrix)
        {
            if (matrix.size() == 0)
            {
                return;
            }
            int n = matrix.size();
            int m = matrix[0].size();
            vector<int> dir = {1, 0, 0, 1, -1, 0, 0, -1};// right, down, left, up
            int direction = 0;
            int count = n * m;
            int x = 0, y = 0;
            int visited[n][m];
            memset(visited, 0, sizeof(visited));
            while(1)
            {
                cout << matrix[y][x] << " ";
                count--;
                if (count == 0)
                {
                    return;
                }
                visited[y][x] = 1;
                while (x + dir[2 * direction] >= m || y + dir[2 * direction + 1] >= n || x + dir[2 * direction] < 0 || y + dir[2 * direction + 1] < 0 || visited[y + dir[2 * direction + 1]][x + dir[2 * direction]] == 1)
                {
                    direction = (direction + 1) % 4;
                }
                x += dir[2 * direction];
                y += dir[2 * direction + 1];
            }
        }
};
```

## 栈

### offer.30 (easy)

#### Idea
- Knowledge: 包含min函数的(栈)
- Question: 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
- Code: algorithm/leetcode/offer/30.cpp
- Current classes: myMinStack, MinStack

#### Official
- Selected class: myMinStack
```cpp
class myMinStack
{
    stack<int> dataStack;
    stack<int> minStack;
    public:
    myMinStack()
    {
        
    }
    void push(int x)
    {
        dataStack.push(x);
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
    }
    void pop()
    {
        if (dataStack.top() == minStack.top())
        {
            minStack.pop();
        }
        dataStack.pop();
    }
    int top()
    {
        return dataStack.top();
    }
    int min()
    {
        return minStack.top();
    }
};
```

### offer.31 (easy)

#### Idea
- Knowledge: 判断是否为弹出序列(栈)
- Question: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
- Code: algorithm/leetcode/offer/31.cpp
- Current classes: mySolution_31, Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> stk;
        int j = 0;
        for (int v : pushed)
        {
            stk.push(v);
            while (!stk.empty() && stk.top() == popped[j])
            {
                stk.pop();
                ++j;
            }
        }
        return j == pushed.size();
    }
};
```

## 树的遍历

### offer.32-1 (easy)

#### Idea
- Knowledge: 从上到下打印二叉树I(树的遍历)
- Question: 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
- Code: algorithm/leetcode/offer/32-1.cpp
- Current classes: mySolution_32_1, offerSolution_32_1

#### Official
- Selected class: mySolution_32_1
```cpp
class mySolution_32_1
{
    public:
    vector<int> levelOrder(TreeNode* root)
    {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return res;
    }
};
```

### offer.32-2 (easy)

#### Idea
- Knowledge: 从上到下打印二叉树II(树的遍历)
- Question: 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
- Code: algorithm/leetcode/offer/32-2.cpp
- Current classes: mySolution_32_2, offerSolution_32_2

#### Official
- Selected class: mySolution_32_2
```cpp
class mySolution_32_2
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
```

### offer.32-3 (middle)

#### Idea
- Knowledge: 从上到下打印二叉树III(树的遍历)
- Question: 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
- Code: algorithm/leetcode/offer/32-3.cpp
- Current classes: mySolution_32_3, offerSolution_32_3

#### Official
- Selected class: mySolution_32_3
```cpp
class mySolution_32_3
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            vector<int> level;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if( leftToRight )
                {
                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                else
                {
                    if (node->right)
                        q.push(node->right);
                    if (node->left)
                        q.push(node->left);
                }
            }
            res.push_back(level);
            leftToRight = !leftToRight;
        }
        return res;
    }
};
```

## 二叉搜索树

### offer.33 (middle)

#### Idea
- Knowledge: 二叉搜索树的后序遍历序列(二叉搜索树)
- Question: 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
- Code: algorithm/leetcode/offer/33.cpp
- Current classes: mySolution_33, offerSolution_33, mySolution_33_2

#### Official
- Selected class: mySolution_33
```cpp
class mySolution_33
{
    public:
    bool isPostorder(vector<int>& sequence)
    {
        int last = sequence.size() - 1;
        // 找不到根节点与左右子树节点的关系

    }

};
```

## 二叉树

### offer.34 (middle)

#### Idea
- Knowledge: 二叉树中和为某一值的路径(二叉树+dfs)
- Code: algorithm/leetcode/offer/34.cpp
- Current classes: mySolution_34, offerSolution_34

#### Official
- Selected class: mySolution_34
```cpp
class mySolution_34
{
    public:
    vector<vector<int>> pathInTree(TreeNode* root, int target)
    {
        vector<int> path;
        vector<vector<int>> res;
        function<void(TreeNode * root, int s)> dfs = [&](TreeNode *root, int s) -> void
        {
            //mySolution_34 加了(s - root->val) < 0 的提前剪枝，若树节点或 target 存在负数，会误删合法路径 → 不安全。
             if (root == nullptr || (s - root -> val) < 0)
            {
                return;
            }
            s -= root->val;
            path.push_back(root->val);
            if (root->left == nullptr && root->right == nullptr && s == 0)
            {
                res.push_back(path);
            }
            dfs(root->left, s);
            dfs(root->right, s);
            path.pop_back();
        };
        dfs(root, target);
        return res;
    }
};
```

## 哈希表

### offer.38 (middle)

#### Idea
- Knowledge: 字符串的排列(回溯+哈希表)
- Question: 输入一个字符串，打印出该字符串中字符的所有排列.你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
- Code: algorithm/leetcode/offer/38.cpp
- Current classes: mySolution_38, offerSolution_38

#### Official
- Selected class: mySolution_38
```cpp
class mySolution_38
{
    public:
        void backtrack(vector<char> &state, const string &choices, vector<bool> &selected, vector<vector<char>> &result)
        {
            if (state.size() == choices.size())
            {
                result.push_back(state);
                return;
            }
            unordered_set<char> duplicated;
            for (int i = 0; i < choices.size(); i++)
            {
                char choice = choices[i];
                if (!selected[i] && duplicated.find(choice) == duplicated.end())
                {
                    state.push_back(choice);
                    //重复选择剪枝：整个搜索过程中只有一个 selected 。它记录的是当前状态中包含哪些元素，其作用是避免某个元素在 state 中重复出现。
                    selected[i] = true;
                    //相等元素剪枝：每轮选择（每个调用的 backtrack 函数）都包含一个 duplicated 。它记录的是在本轮遍历（for 循环）中哪些元素已被选择过，其作用是保证相等元素只被选择一次。   
                    duplicated.emplace(choice);
                    backtrack(state, choices, selected, result);
                    state.pop_back();
                    selected[i] = false;
                }
            }
    }
    vector<vector<char>> permute(const string &choices)
    {
        vector<char> state;
        vector<bool> selected(choices.size(), false);
        vector<vector<char>> result;
        backtrack(state, choices, selected, result);
        return result;
    }
};
```

### leetcode.1 (easy)

#### Idea
- Knowledge: 两数之和(哈希表)
- Question: 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。你可以按任意顺序返回答案。
- Code: algorithm/leetcode/leco/1.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = target - nums[i];
            if (num_map.find(num) != num_map.end())
            {
                return {num_map[num], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};
```

## 树的层序遍历

### offer.37 (hard)

#### Idea
- Knowledge: 序列化二叉树(树的层序遍历)
- Question: 请实现两个函数，分别用来序列化和反序列化二叉树。你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
- Code: algorithm/leetcode/offer/37.cpp
- Current classes: mySolution_37, offerSolution_37

#### Official
- Selected class: mySolution_37
```cpp
class mySolution_37
{
    public:
    string TreetoSequence(TreeNode* root)
    {
        if(root == nullptr)
            return "";
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node != nullptr)
            {
                res += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                res += "# ";
            }
        }
        res.pop_back();
        return res;
    }

    vector<int> stringToVector(const string &data)
    {
        vector<int> res;
        stringstream ss(data);
        string t;
        while(ss >> t)
        {
            if(t == "#")
            {
                res.push_back(INT_MAX);
            }
            else
            {
                res.push_back(stoi(t));
            }
        }
        return res;
    }


    // 0 1 2 3 4 5 6 root : n , left : 2n+1 , right : 2n+2
    TreeNode* SequencetoTree(string &data)
    {
        if (data.empty())
            return nullptr;
        vector<int> data_vec = stringToVector(data);
        TreeNode* root = new TreeNode(data_vec[0]);
        function<void(TreeNode *, int)> buildTree = [&](TreeNode *node, int root_index)
        {
            if (data_vec[2 * root_index + 1] == INT_MAX)
            {
                node->left = nullptr;
            }
            else
            {
                node->left = new TreeNode(data_vec[2 * root_index + 1]);
                buildTree(node->left, 2 * root_index + 1);
            }

            if (data_vec[2 * root_index + 2] == INT_MAX)
            {
                node->right = nullptr;
            }
            else
            {
                node->right = new TreeNode(data_vec[2 * root_index + 2]);
                buildTree(node->right, 2 * root_index + 2);
            }
        };
        buildTree(root, 0);
        return root;
    }
};
```

## 摩尔投票法

### offer.39 (easy)

#### Idea
- Knowledge: 数组中出现次数超过数组长度一半的数字(摩尔投票法)
- Question: 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。你可以假设数组是非空的，并且给定的数组总是存在多数元素。
- Code: algorithm/leetcode/offer/39.cpp
- Current classes: mySolution_39, offerSolution_39

#### Official
- Selected class: mySolution_39
```cpp
class mySolution_39
{
    public:
    int morethanhalfElement(vector<int>& nums)
    {
        int size = nums.size();
        unordered_map<int, int> countMap;
        for (int num : nums)
        {
            countMap[num]++;
            if (countMap[num] > size / 2)
            {
                return num;
            }
        }
        return -1;  
    }
};
```

## 优先队列

### offer.40 (easy)

#### Idea
- Knowledge: 最小的k个数(优先队列)
- Code: algorithm/leetcode/offer/40.cpp
- Current classes: mySolution_40, offerSolution_40

#### Official
- Selected class: mySolution_40
```cpp
class mySolution_40
{
    public:
    vector<int> getsmallestK(vector<int>& arr, int k)
    {
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
```

### offer.49 (middle)

#### Idea
- Knowledge: 丑数(dp or 优先队列)
- Question: 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
- Code: algorithm/leetcode/offer/49.cpp
- Current classes: mySolution_49, offerSolution_49_dp, offerSolution_49_heap

#### Official
- Selected class: mySolution_49
```cpp
class mySolution_49
{
    public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(2, 0);
        dp[1] = 1;
        int i = 2;
        for(; i <= 1690; i++ )
        {
            if(dp.size() > n)
            {
                break;
            }
            if (!(i % 2) || !(i % 3) || !(i % 5))
            {
                dp.push_back(i);
            }
        }  
        return dp[dp.size() - 1];
    }
    int nthUglyNumber_review(int n)
    {
        int p1 = 0, p2 = 0, p3 = 0;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int a = dp[p1] * 2;
            int b = dp[p2] * 3; 
            int c = dp[p3] * 5;
            dp[i] = min(a, min(b, c));
            if (dp[i] == a) p1++;
            if (dp[i] == b) p2++;
            if (dp[i] == c) p3++;
        }
        return dp[n - 1];
    }
};
```

## 动态规划

### offer.42 (easy)

#### Idea
- Knowledge: 连续子数组的最大和(动态规划)
- Code: algorithm/leetcode/offer/42.cpp
- Current classes: mySolution_42, offerSolution_42

#### Official
- Selected class: mySolution_42
```cpp
class mySolution_42
{
    public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        int res = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
```

## 小顶堆

### offer.41 (hard)

#### Idea
- Knowledge: 数据流中的中位数(小顶堆+大顶堆)
- Code: algorithm/leetcode/offer/41.cpp
- Current classes: mySolution_41, MedianFinder

#### Official
- Selected class: mySolution_41
```cpp
class mySolution_41
{
    private:
        vector<int> nums;
    public:
        void addNUm(int num)
        {
            nums.push_back(num);
        }
        double findMedian()
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            if (n % 2 == 1)
            {
                return nums[n / 2];
            }
            else
            {
                return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
            }
        }
};
```

## 大顶堆

### offer.41 (hard)

#### Idea
- Knowledge: 数据流中的中位数(小顶堆+大顶堆)
- Code: algorithm/leetcode/offer/41.cpp
- Current classes: mySolution_41, MedianFinder

#### Official
- Selected class: mySolution_41
```cpp
class mySolution_41
{
    private:
        vector<int> nums;
    public:
        void addNUm(int num)
        {
            nums.push_back(num);
        }
        double findMedian()
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            if (n % 2 == 1)
            {
                return nums[n / 2];
            }
            else
            {
                return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
            }
        }
};
```

## 数位dp

### offer.43 (middle)

#### Idea
- Knowledge: 1 ~ n 整数中1出现的次数(数位dp)
- Question: 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
- Code: algorithm/leetcode/offer/43.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int countDigitOne(int n)
    {
        int a[12]{};
        int f[12][12];
        memset(f, -1, sizeof f);
        int i = -1;
        for (; n; n /= 10)
        {
            a[++i] = n % 10;
        }
        function<int(int, int, bool)> dfs = [&](int pos, int cnt, bool limit) -> int
        {
            if (pos < 0)
            {
                return cnt;
            }
            if (!limit && f[pos][cnt] != -1)
            {
                return f[pos][cnt];
            }
            int up = limit ? a[pos] : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i)
            {
                ans += dfs(pos - 1, cnt + (i == 1), limit && i == up); 
            }
            return f[pos][cnt] = ans;
        };
        return dfs(i, 0, true);
    }

    int countDigitOne2(int n)
    {
        int a[12]{};
        int f[12][12];
        memset(f, -1, sizeof f);
        int i = -1;
        for (; n; n /= 10)
        {
            a[++i] = n % 10;
        }
        function<int(int, int, bool)> dfs = [&](int pos, int cnt, bool limit) -> int
        {
            if (pos < 0)
            {
                return cnt;
            }
            if (!limit && f[pos][cnt] != -1)
            {
                return f[pos][cnt];
            }
            int up = limit ? a[pos] : 9;
            int ans = 0;
            for (int i = 0; i <= up; i++)
            {
                ans += dfs(pos - 1, cnt + (i == 1), limit && i == up);

            }
            return f[pos][cnt] = ans;
        };

    }
};
```

## 数学

### offer.44 (middle)

#### Idea
- Knowledge: 数字序列中某一位的数字(数学)
- Code: algorithm/leetcode/offer/44.cpp
- Current classes: mySoulution_44

#### Official
- Selected class: mySoulution_44
```cpp
class mySoulution_44
{
    public:
        int nPositonNumber(int n)
        {
            int k = 1, cnt = 9;
            while(1ll * k * cnt < n)
            {
                n -= k * cnt;
                k++;
                cnt *= 10;
            }
            int num = pow(10, k - 1) + (n - 1) / k;
            int idx = (n - 1) % k;
            return to_string(num)[idx] - '0';
        }
};
```

### offer.62 (easy)

#### Idea
- Knowledge: 圆圈中剩下的数字(数学 + 递归)
- Question: 0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
- Code: algorithm/leetcode/offer/62.cpp
- Current classes: mySolution_62, offerSolution_62, offerSolution_62_2

#### Official
- Selected class: mySolution_62
```cpp
class mySolution_62
{
    public:
    int lastRemaining(int n, int m)
    {
        int rest = n;
        int dex = 0;
        int i = 0;
        unordered_set<int> st;
        while(rest > 1)
        {        
            if (i == m - 1)
            {
                st.insert(dex);
                dex = dex + 1;
                if (dex >= n)
                {
                    dex = 0;
                }
                while (st.find(dex) != st.end())
                {
                    dex++;
                    if (dex >= n)
                    {
                        dex = 0;
                    }
                }
                i = 0;
                rest--;
            }
            else
            {
                dex++;
                if (dex >= n)
                {
                    dex = 0;
                }
                while(st.find(dex) != st.end())
                {
                    dex++;
                    if (dex >= n)
                    {
                        dex = 0;
                    }
                }
                i++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (st.find(j) == st.end())
            {
                return j;
            }
        }
        return -1;
    }
};
```

## 自定义排序

### offer.45 (middle)

#### Idea
- Knowledge: 把数组排成最小的数(自定义排序)
- Question: 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
- Code: algorithm/leetcode/offer/45.cpp
- Current classes: offerSolution_45

#### Official
- Selected class: offerSolution_45
```cpp
class offerSolution_45
{
    public:
    string minNumber(vector<int> &nums)
    {
        vector<string> arr;
        for (int& x : nums)
        {
            arr.emplace_back(to_string(x));
        }
        sort(arr.begin(), arr.end(), [](const string& a, const string& b)
             {
                 return a + b < b + a;
             });
        string ans;
        for (auto& x : arr)
        {
            ans += x;
        }
        return ans; 
    }
};
```

## 双指针

### offer.52 (easy)

#### Idea
- Knowledge: 两个链表的第一个节点(哈希 or 双指针)
- Question: 输入两个链表，找出它们的第一个公共节点。
- Code: algorithm/leetcode/offer/52.cpp
- Current classes: mySolution_52, offerSolution_52

#### Official
- Selected class: mySolution_52
```cpp
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
```

### offer.57-2 (easy)

#### Idea
- Knowledge: 和为s的连续正数序列(双指针)
- Question: 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
- Code: algorithm/leetcode/offer/57-2.cpp
- Current classes: offerSolution_57_2

#### Official
- Selected class: offerSolution_57_2
```cpp
class offerSolution_57_2
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> ans;
        int l = 1, r = 2;
        while (l < r)
        {
            int s = (l + r) * (r - l + 1) / 2;
            if (s == target)
            {
                vector<int> t(r - l + 1);
                iota(t.begin(), t.end(), l);
                ans.emplace_back(t);
                ++l;
            }
            else if (s < target)
            {
                ++r;
            }
            else
            {
                ++l;
            }
        }
        return ans;
    }
};
```

### offer.57 (easy)

#### Idea
- Knowledge: 和为s的两个数字(双指针 or hash)
- Question: 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
- Code: algorithm/leetcode/offer/57.cpp
- Current classes: mySolution_57, offerSolution_57

#### Official
- Selected class: mySolution_57
```cpp
class mySolution_57
{
    public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_set<int> hashset;
        for (int num : nums)
        {
            int complement = target - num;
            if (hashset.count(complement))
            {
                return {complement, num};
            }
            hashset.insert(num);
        }
        return {};
    }
};
```

### offer.58-1 (easy)

#### Idea
- Knowledge: 翻转单词顺序(双指针)
- Code: algorithm/leetcode/offer/58-1.cpp
- Current classes: mySolution_58_1, offerSolution_58_1

#### Official
- Selected class: mySolution_58_1
```cpp
class mySolution_58_1
{
    public:
    string reverseWords(string s)
    {
        istringstream iss(s);
        string word;
        vector<string> words;
        while (iss >> word)
        {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result;
        for (int i = 0; i < words.size(); ++i)
        {
            result += words[i];
            if (i != words.size() - 1)
            {
                result += " ";
            }
        }
        return result;
    }
    string reverseWords_2(string s)
    {
        int i = 0, j = 0;
        int n = s.size();
        string word;
        vector<string> words;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
            {
                ++i;
            }
            j = i;
            while (j < n && s[j] != ' ')
            {
                ++j;
            }
            if (i < n)
            {
                word = s.substr(i, j - i);
                words.push_back(word);
            }
            i = j;
        }
        reverse(words.begin(), words.end());
        string result;
        for (int i = 0; i < words.size(); ++i)
        {
            result += words[i];
            if (i != words.size() - 1)
            {
                result += " ";
            }
        }
        return result;
    }
};
```

### leetcode.5 (easy)

#### Idea
- Knowledge: 移动零(双指针)
- Question: 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。请注意 ，必须在不复制数组的情况下原地对数组进行操作。
- Code: algorithm/leetcode/leco/5.cpp
- Current classes: Solution, offer_Solution

#### Official
- Selected class: offer_Solution
```cpp
class offer_Solution
{
    public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size(), left = 0, right = 0;
        while(right < n)
        {
            if(nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
```

### leetcode.6 (hard)

#### Idea
- Knowledge: 接雨水(双指针)
- Question: 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
- Code: algorithm/leetcode/leco/6.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int size = height.size();
        if (size < 3)
        {
            return 0;
        }
        vector<int> left_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        vector<int> right_max(size);
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i > -1; i--)
        {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        unsigned int sum = 0;
        for (int i = 0; i < size - 1; i++)
        {
            sum += min(right_max[i], left_max[i]) - height[i];
        }
        return sum;
    }
};
```

### leetcode.7 (middle)

#### Idea
- Knowledge: 盛水最多的容器(双指针)
- Question: 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水返回容器可以储存的最大水量。说明：你不能倾斜容器。
- Code: algorithm/leetcode/leco/7.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int max_area = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
```

## 归并排序

### offer.51 (hard)

#### Idea
- Knowledge: 数组中的逆序对(归并排序)
- Code: algorithm/leetcode/offer/51.cpp
- Current classes: mySolution_51, offerSolution_51

#### Official
- Selected class: mySolution_51
```cpp
class mySolution_51
{
    public:
    int reversePairs(vector<int> &nums)
    {
        int size = nums.size();
        long count = 0;
        if(size == 0)
        {
            return 0;
        }
        function<void(vector<int> &, int, int, int)> merge = [&](vector<int> &nums, int left, int mid, int right) -> void
        {
            // 左子数组区间为 [left, mid], 右子数组区间为 [mid+1, right]
            // 创建一个临时数组 tmp ，用于存放合并后的结果
            vector<int> tmp(right - left + 1);
            // 初始化左子数组和右子数组的起始索引
            int i = left, j = mid + 1, k = 0;
            // 当左右子数组都还有元素时，进行比较并将较小的元素复制到临时数组中
            while (i <= mid && j <= right)
            {
                if (nums[i] <= nums[j])
                    tmp[k++] = nums[i++];
                else
                {
                    tmp[k++] = nums[j++];
                    count += mid - i + 1;
                }
            }
            // 将左子数组和右子数组的剩余元素复制到临时数组中
            while (i <= mid)
            {
                tmp[k++] = nums[i++];
            }
            while (j <= right)
            {
                tmp[k++] = nums[j++];
            }

            // 将临时数组 tmp 中的元素复制回原数组 nums 的对应区间
            for (k = 0; k < tmp.size(); k++)
            {
                nums[left + k] = tmp[k];
            }
        };
        function<void(vector<int> &,int, int)> merge_sort = [&](vector<int> &nums, int left, int right) -> void
        {

            // 终止条件
            if (left >= right)
                return; // 当子数组长度为 1 时终止递归
            // 划分阶段
            int mid = left + (right - left) / 2; // 计算中点
            merge_sort(nums, left, mid);         // 递归左子数组
            merge_sort(nums, mid + 1, right);    // 递归右子数组
            // 合并阶段
            merge(nums, left, mid, right);
        };
        merge_sort(nums, 0, size - 1);
        return count;
    }
};
```

## 树的中序遍历

### offer.54 (easy)

#### Idea
- Knowledge: 二叉搜索树的第k大节点(树的中序遍历)
- Code: algorithm/leetcode/offer/54.cpp
- Current classes: mySolution_54, Solution, offerSolution_54

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int kthLargest(TreeNode *root, int k)
    {
        int ans = 0;
        function<void(TreeNode *)> dfs = [&](TreeNode *root)
        {
            if (!root || !k)
            {
                return;
            }
            dfs(root->right);
            if (--k == 0)
            {
                ans = root->val;
            }
            dfs(root->left);
        };
        dfs(root);
        return ans;
    }
};
```

## hash

### offer.57 (easy)

#### Idea
- Knowledge: 和为s的两个数字(双指针 or hash)
- Question: 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
- Code: algorithm/leetcode/offer/57.cpp
- Current classes: mySolution_57, offerSolution_57

#### Official
- Selected class: mySolution_57
```cpp
class mySolution_57
{
    public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_set<int> hashset;
        for (int num : nums)
        {
            int complement = target - num;
            if (hashset.count(complement))
            {
                return {complement, num};
            }
            hashset.insert(num);
        }
        return {};
    }
};
```

## 字符操作

### offer.58-2 (easy)

#### Idea
- Knowledge: 左旋转字符串(字符操作)
- Question: 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
- Code: algorithm/leetcode/offer/58-2.cpp
- Current classes: mySolution_58_2

#### Official
- Selected class: mySolution_58_2
```cpp
class mySolution_58_2
{
    public:
    string reversestring(string s, int n)
    {
        return s.substr(n) + s.substr(0,n);
    }
};
```

## 位操作

### offer.56-1 (middle)

#### Idea
- Knowledge: 数组中数组出现的次数(位操作)
- Question: 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
- Code: algorithm/leetcode/offer/56-1.cpp
- Current classes: mySolution_56_1, offerSolution_56_1

#### Official
- Selected class: mySolution_56_1
```cpp
class mySolution_56_1
{
    public:
    //O(t): O(n) space: O(n)
    vector<int> singleNumbers(vector<int>& nums)
    {
        unordered_map<int, int> hash_map;
        for (const int &num : nums)
        {
            hash_map[num]++;
        }
        vector<int> result;
        for (const auto &entry : hash_map)
        {
            if (entry.second == 1)
            {
                result.push_back(entry.first);
            }
        }
        return result;
    }
};
```

### offer.56-2 (middle)

#### Idea
- Knowledge: 数组中数组出现的次数II(位操作)
- Question: 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
- Code: algorithm/leetcode/offer/56-2.cpp
- Current classes: mySolution_56_2, offerSolution_56_2

#### Official
- Selected class: mySolution_56_2
```cpp
class mySolution_56_2
{
    public:
    // O(t) = O(n), O(s) = O(n)
    int singleNumber_hash(vector<int>& nums)
    {
        unordered_map<int, int> hash_map;
        for (const int num : nums)
        {
            hash_map[num]++;
        }
        for (const auto val : hash_map)
        {
            if (val.second == 1)
            {
                return val.first;
            }
        }
        return -1; // or throw an exception if no single number is found
    }
    int singleNumber_bit(vector<int>& nums)
    {
        int result = 0;
        int a[32] = {0};
        for (const int num : nums)
        {
            for (int i = 0; i < 32; ++i)
            {
                a[i] += (num >> i) & 1;
            }
        }
        for (int i = 0; i < 32; ++i)
        {
            if (a[i] % 3 != 0)
            {
                result |= (1 << i);
            }
        }
        return result;
    }
};
```

## 单调队列

### offer.59-1 (easy)

#### Idea
- Knowledge: 滑动窗口的最大值(单调队列)
- Question: 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
- Code: algorithm/leetcode/offer/59-1.cpp
- Current classes: mySolution_59_1, offerSolution_59_1

#### Official
- Selected class: mySolution_59_1
```cpp
class mySolution_59_1
{
    public:
    // O(t): O(nk) space: O(k)
    vector<int> maxslidingwindow(vector<int> & nums, int k)
    {
        vector<int> result;
        queue<int> window;
        int max_val = INT_MIN;
        int size = nums.size();
        if (k == 0 || size == 0)
        {
            return result;
        }
        for (int i = 0; i < size; ++i)
        {
            if (i < k)
            {
                window.push(nums[i]);
                max_val = max(max_val, nums[i]);
                if (i == k - 1)
                {
                    result.push_back(max_val);
                }
            }
            else
            {
                int tmep = window.front();
                window.pop();
                window.push(nums[i]);
                max_val = max(max_val, nums[i]);
                if (tmep == max_val)
                {
                    // need to recalculate max_val
                    max_val = INT_MIN;
                    queue<int> temp_queue = window;
                    while (!temp_queue.empty())
                    {
                        max_val = max(max_val, temp_queue.front());
                        temp_queue.pop();
                    }
                }
                result.push_back(max_val);
            }
        }
        return result;
    }
};
```

## 双队列

### offer.59-2 (middle)

#### Idea
- Knowledge: 队列的最大值(双队列)
- Question: 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
- Code: algorithm/leetcode/offer/59-2.cpp
- Current classes: mySolution_59_2, MaxQueue, mySolutoin_59_2_v2

#### Official
- Selected class: mySolution_59_2
```cpp
class mySolution_59_2
{
    private:
    queue<int> max_queue;
    public:
    void push_back(int value)
    {
        max_queue.push(value);
    }
    int pop_front()
    {
        if (max_queue.empty())
        {
            return -1;
        }
        return max_queue.front();
    }
    int max_value()
    {
        if (max_queue.empty())
        {
            return -1;
        }

    }
};
```

## 遍历

### offer.61 (easy)

#### Idea
- Knowledge: 扑克牌中的顺子(遍历)
- Question: 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
- Code: algorithm/leetcode/offer/61.cpp
- Current classes: mySolution_61, offerSolution_61

#### Official
- Selected class: mySolution_61
```cpp
class mySolution_61
{
public:
    // o(t) : O(nlogn) o(s): O(1)
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int zero_count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                ++zero_count;
            }
        }
        for (int i = zero_count + 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                return false; // 有重复牌，不可能是顺子
            }
            if (nums[i] - nums[i - 1] != 1)
            {
                if (zero_count >= nums[i] - nums[i - 1] - 1)
                {
                    zero_count -= (nums[i] - nums[i - 1] - 1);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
```

## 短路求值

### offer.64 (middle)

#### Idea
- Knowledge: 求1+2+...+n(递归+短路求值)
- Question: 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
- Code: algorithm/leetcode/offer/64.cpp
- Current classes: mySolution_64, offerSolution_64

#### Official
- Selected class: mySolution_64
```cpp
class mySolution_64
{
    public:
    int sumNums(int n)
    {
        int sum = 0;
        (n == 1) && (sum += 1);
        (n > 1) && (sum += sumNums(n - 1) + n);
        return sum;
    }
};
```

## 前缀积

### offer.66 (easy)

#### Idea
- Knowledge: 构建乘积数组(前缀积/后缀积)
- Code: algorithm/leetcode/offer/66.cpp
- Current classes: mySolution_66, offerSolution_66

#### Official
- Selected class: mySolution_66
```cpp
class mySolution_66
{
    public:
    vector<int> buildMulMatir(vector<int> a)
    {
        int size = a.size();
        vector<int> b(size, 1);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i != j)
                {
                    b[i] = b[i] * a[j];
                }
                else
                {
                    continue;
                }
            }
        }
        return b;
    }
};
```

## 后缀积

### offer.66 (easy)

#### Idea
- Knowledge: 构建乘积数组(前缀积/后缀积)
- Code: algorithm/leetcode/offer/66.cpp
- Current classes: mySolution_66, offerSolution_66

#### Official
- Selected class: mySolution_66
```cpp
class mySolution_66
{
    public:
    vector<int> buildMulMatir(vector<int> a)
    {
        int size = a.size();
        vector<int> b(size, 1);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i != j)
                {
                    b[i] = b[i] * a[j];
                }
                else
                {
                    continue;
                }
            }
        }
        return b;
    }
};
```

## 位

### leetcode.9 (easy)

#### Idea
- Knowledge: 只出现一次的数字(位)
- Question: 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
- Code: algorithm/leetcode/leco/9.cpp
- Current classes: Solution

#### Official
- Selected class: Solution
```cpp
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            num = num ^ nums[i];
        }
        return num;
    }
};
```


