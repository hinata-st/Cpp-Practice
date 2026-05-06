#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> cnt_t;
        unordered_map <char, int> cnt_s;
        int left = 0,cnt_num = 0;
        int ans_left = -1,ans_right = s.size();
        for (int right = 0; right < t.size(); right++){
            // 哈希记录t串
            cnt_t[t[right]]++;
        }

        for (int right = 0; right < s.size(); right++){
            // t串的字符在s串中出现的次数小于t串中出现的次数
            if (cnt_s[s[right]] < cnt_t[s[right]]){
                cnt_num++;
            }
            // t串中有s中的字符
            if (cnt_t[s[right]] != 0){
                cnt_s[s[right]]++;
            }

            while (cnt_num >= t.size()){
                // 更新结果
                if (right - left < ans_right - ans_left){
                    ans_right = right;
                    ans_left = left;
                }
                if (cnt_s[s[left]] != 0){
                    cnt_s[s[left]]--;
                }
                if (cnt_s[s[left]] < cnt_t[s[left]]){
                    cnt_num--;
                }
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};

int main(){
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << sol.minWindow(s, t) << endl;
    return 0;
}