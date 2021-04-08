class Solution {
public:
    string removeVowels(string s) {
        vector<char> vowels{'a','e','i','o','u'};
        string r = "";
        for (char c : s) {
            if (!count(vowels.begin(), vowels.end(), c)) r = r + c;
        }
        return r;
    }
};