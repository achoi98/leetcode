class Solution {
public:
    int strStr(string haystack, string needle) {
        cout << "----------------------------------\n";
        if (needle.length() == 0) return 0;
        
        int ptr = 0;
        int hL = haystack.length();
        int nL = needle.length();
        
        while (ptr < hL && hL - ptr >= nL) {
            cout << "ptr: " << ptr << endl;
            if (haystack[ptr] == needle[0]) {
                int index = ptr;
                cout << "index: " << index << endl;
                int i = 1;
                ptr++;
                while (i < nL && ptr < hL) {
                    if (needle[i] != haystack[ptr]) break;
                    else {
                        i++;
                        ptr++;
                    }
                }
                cout << "i: " << i << endl;
                if (i == nL) return index;
                ptr = index + 1;
            }
            else ptr++;
        }
        return -1;
        cout << "----------------------------------\n";        
    }
};