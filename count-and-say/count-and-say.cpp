class Solution {
public:
    string countAndSay(int n) {
        cout << n << endl;
        if (n == 1) return "1";
        if (n == 2) return "11";
        string oldstring = countAndSay(n - 1);
        string newstring = "";
        int count = 1;
        for (int i = 1; i < oldstring.length(); i++) {
            if (oldstring[i] != oldstring[i - 1]) {
                newstring.push_back('0' + count);
                newstring.push_back(oldstring[i - 1]);
                count = 1;
            } else count++;
            if (i == oldstring.length() - 1) {
                newstring.push_back('0' + count);
                newstring.push_back(oldstring[i]);
            }
        }
        return newstring;
    }
};