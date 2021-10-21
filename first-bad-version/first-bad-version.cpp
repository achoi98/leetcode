// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (isBadVersion(mid) && !isBadVersion(mid+1)) return mid;
            else if (!isBadVersion(mid)) { left = mid + 1; }
            else { right = mid; } // isBadVersion(mid) && isBadVersion(mid+1);
        }
        if (left <= n && isBadVersion(left)) return left;
        return -1;
    }
};