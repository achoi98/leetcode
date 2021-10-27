class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        
        for (char c : s1) {
            if (m1.count(c) > 0) {
                m1[c]++;
            }
            else {
                m1.insert(make_pair(c, 1));
            }
        }
        
        int start = 0;
        int end = s1.size();
        while (end <= s2.size()) {
            //if (!m2.empty()) m2.clear();
            
            for (int i = start; i < end; i++) {
                if (m2.count(s2[i]) > 0) {
                    m2[s2[i]]++;
                }
                else {
                    m2.insert(make_pair(s2[i], 1));
                }
            }
            for (auto m : m2) {
                if (m.second != m1[m.first]) {
                    m2.clear();
                    break;
                }
            }
            if (!m2.empty()) 
            {
                cout << "start: " << start << "     end: " << end << endl;
                return true;
            }
            
            start++;
            end++;
            
        }
        
        return false;
    }
};