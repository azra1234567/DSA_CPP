class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // First increasing part
        while (i < n - 1 && nums[i] < nums[i + 1]) {
            i++;
        }

        // No increasing part
        if (i == 0) return false;

        // Second decreasing part
        int j = i;
        while (j < n - 1 && nums[j] > nums[j + 1]) {
            j++;
        }

        // No decreasing part or no room for third part
        if (j == i || j == n - 1) return false;

        // Third increasing part
        while (j < n - 1 && nums[j] < nums[j + 1]) {
            j++;
        }

        return j == n - 1;
    }
};