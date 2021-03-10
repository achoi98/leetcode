class Solution {
public:
    int maxArea(vector<int>& height) {
        int a = 0;
        int b = height.size()-1;
        int max = 0;
        
        while (a < b) {
            if ((b-a)*min(height[a], height[b]) > max) max = (b-a)*min(height[a],height[b]);
            if (height[a]==height[b]) {
                a++;
                b--;
            }
            else {
                if (height[a] < height[b]) {
                    a++;
                }
                else {
                    b--;
                }
            }
        }
        return max;
    }
};