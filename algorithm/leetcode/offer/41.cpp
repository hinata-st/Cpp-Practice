#include <bits/stdc++.h>

using namespace std;

// question :

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

class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();

        if (minQ.size() > maxQ.size() + 1)
        {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

    double findMedian()
    {
        return minQ.size() == maxQ.size() ? (minQ.top() + maxQ.top()) / 2.0 : minQ.top();
    }

private:
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */