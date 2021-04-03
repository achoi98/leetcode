/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            int g1 = guess(mid1);
            int g2 = guess(mid2);
            if (g1 == 0) return mid1;
            if (g2 == 0) return mid2;
            else if (g1 < 0) {
                right = mid1 - 1;
            }
            else if (g2 > 0) {
                left = mid2 + 1;
            }
            else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }
        return -1;
    }
};