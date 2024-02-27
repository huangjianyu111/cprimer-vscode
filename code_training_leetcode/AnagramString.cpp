#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() < 1 || p.size() > s.size()) return res;
        vector<int> sCount(26);
        vector<int> pCount(26);
        // 记录p中出现的字母以及个数
        for(int i = 0;i < p.size();i++) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        // True if the size and elements of the vectors are equal.
        if (sCount == pCount) {
            res.push_back(0);
        }

        for (int i = 0;i < s.size() - p.size();++i) {
            // remove first ele
            --sCount[s[i] - 'a'];
            ++sCount[s[i+p.size()] - 'a'];
            if (sCount == pCount) {
                res.push_back(i + 1);
            }
        }
        
        return res;
    }


};

int main() {
    string s = "aaaaaaaaaaaaaaaaaaaa";
    string p = "aaaaaaaaaaaaa";
    Solution sol;
    for (const auto ele : sol.findAnagrams(s, p)) {
        printf(" %d", ele);
    }
    printf("\n");
    return 0;
}