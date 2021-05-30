class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = { 1 };
        for (int i = 1; i <= rowIndex; i++) {
            res.push_back((int)((res.back() * (long long)(rowIndex - i + 1)) / i));
        }
    
        return res;
    }
};