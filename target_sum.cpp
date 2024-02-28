int target_sum(int n, int s, vector<int>& nums) {
    if (n == 0) {
        if (s == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    if (nums[n - 1] <= s) {
        int opt1 = target_sum(n - 1, s - nums[n - 1], nums);
        int opt2 = target_sum(n - 1, s, nums);
        return opt1 + opt2;
    } else {
        int opt2 = target_sum(n - 1, s, nums);
        return opt2;
    }
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int s = (sum + target) / 2;

        if ((sum + target) % 2 == 0) {
            return target_sum(n, s, nums);
        } else {
            return 0;
        }
    }
};