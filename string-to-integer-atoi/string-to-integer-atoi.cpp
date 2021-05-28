class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int n = s.length();
        int i = 0;
        bool neg;
        
        // read and ignore whitespace
        while (i < n && isspace(s[i])) i++;
        // check for '+' or '-'
        if (s[i] == 43) {
            neg = false;
            i++;
        }
        else if (s[i] == 45) {
            neg = true;
            i++;
        }
        // read in digits
        while (i < n && isdigit(s[i])) {
            //cout << "res: " << res << endl;
            int polar = (neg) ? res * -1 : res;
            //cout << "polar: " << polar << endl;
            if (polar > INT_MAX / 10 || (polar == INT_MAX / 10 && (s[i] - '0') > 7)) return INT_MAX;
            if (polar < INT_MIN / 10 || (polar == INT_MIN / 10 && (s[i] - '0') > 8)) return INT_MIN;
            res = (neg) ? polar * 10 - (s[i] - '0') : polar * 10 + (s[i] - '0');
            res = abs(res);
            i++;
        }
        return (neg) ? res * -1 : res;
    }
};