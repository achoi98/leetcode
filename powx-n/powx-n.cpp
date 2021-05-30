class Solution {
public:
    double myPow(double x, long int n) {
        if (x == 0) return 0;
        if (n == 0) return 1.0;
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        double half = myPow(x, n / 2);
        return (n % 2 == 0) ? half * half : half * half * x;
    }
};