class Solution {
public:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    
    string reverseWords(string s) {
        int front = 0;
        int back = 0;
        int l = s.length();
        while (front < l && back < l) {
            back = front + 1;
            while (back < l && s[back] != ' ') {
                back++;
            }
            reverse(s, front, back - 1);
            front = back + 1;
        }
        return s;
    }
};