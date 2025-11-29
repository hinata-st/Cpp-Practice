#include <bits/stdc++.h>

using namespace std;

// question :

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

class offerSolution_58_1
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        int j = 0;
        int n = s.size();
        while (i < n)
        {
            while (i < n && s[i] == ' ')
            {
                ++i;
            }
            if (i < n)
            {
                if (j != 0)
                {
                    s[j++] = ' ';
                }
                int k = i;
                while (k < n && s[k] != ' ')
                {
                    s[j++] = s[k++];
                }
                reverse(s.begin() + j - (k - i), s.begin() + j);
                i = k;
            }
        }
        s.erase(s.begin() + j, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};