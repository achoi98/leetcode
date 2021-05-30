class Solution {
public:
    unordered_map<int, int> fibs;
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (fibs.count(n) == 0) {
            fibs[n] = fib(n - 1) + fib(n - 2);
        }
        return fibs[n];
    }
};