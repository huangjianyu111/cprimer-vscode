#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> groupMap;

        for (auto & str:strs) {
            string key(str);
            sort(key.begin(), key.end());
            auto iter = groupMap.find(key);
            if (iter != groupMap.end()) {
                groupMap.at(key).push_back(str);
            } else {
                vector<string> vec{str};
                groupMap.emplace(std::make_pair(key, vec));
            }
        }

        for (auto iter = groupMap.begin();iter != groupMap.end();iter++) {
            res.push_back(iter->second);
        }

        return res;
    }
};

int main() {

    return 0;
}