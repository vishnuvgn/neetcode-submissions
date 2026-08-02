class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagrams;
        for (auto& str : strs) {
            std::vector<int> letter_counts(26, 0);    
            for (char c : str) {
                ++letter_counts[c - 'a'];
            }
            std::string representation = "";
            for (int i : letter_counts) {
                representation += std::to_string(i);
                representation += ',';
            }
            anagrams[representation].push_back(str);
        }
        std::vector<std::vector<std::string>> result;
        for (auto [repr, lst] : anagrams) {
            result.push_back(lst);
        }
        return result;
    }
};
