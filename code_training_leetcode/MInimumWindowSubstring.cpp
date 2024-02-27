#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
    unordered_map<char, int> sRecords, tRecords;
public:
    string minWindow(string s, string t) {
        string res = "";
        if (t.size() == 0 || s.size() < t.size()) return res;
        // printf("%d \n", 'A' - 0);

        for (int i = 0;i < t.size();i++) {
            tRecords[t[i]]++;
        }

        int l = 0;
        int r = 0;
        int minWindowSize = INT_MAX;
        int ansL = -1;
        while (r < s.size()) {
            if (t.find(s[r]) >= 0) {
                sRecords[s[r]]++;
            }

            while (l <= r && r - l + 1 >= tRecords.size() && check()) {
                //printf("l : %d, r : %d\n", l, r);
                if (r - l + 1 < minWindowSize) {
                    ansL = l;
                    minWindowSize = r - l + 1;
                }
                l++;
                if (sRecords.find(s[l - 1]) != sRecords.end()) {
                    sRecords[s[l - 1]] -= 1;
                }
            }

            r++;
        }

        // printf("sRecords == tRecords : %d \n", sRecords == tRecords);


        return minWindowSize != INT_MAX ? s.substr(ansL, minWindowSize) : res;
    }

    bool check() {
        for (auto &e:tRecords) {
            if (sRecords[e.first] < e.second) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    printf("%s \n", sol.minWindow(s, t).c_str());
    return 0;
}