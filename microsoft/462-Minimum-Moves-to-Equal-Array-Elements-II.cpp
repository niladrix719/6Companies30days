class Solution {
public:
    int findMedian(vector<int> nums) {
        sort(nums.begin(), nums.end());

        int mid = nums.size() / 2;

        if (nums.size() % 2 != 0) {
            return nums[mid];
        } else {
            if(mid + 1 < nums.size())
            return (nums[mid] + nums[mid - 1]) / 2;
            else
            return nums[mid];
        }
    }
    int minMoves2(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        int median = findMedian(nums);

        int val = nums[0];
        double close = nums[0] - median;
        if (close < 0)
            close *= -1;
        for (int i = 1; i < nums.size(); i++) {
            double diff = nums[i] - median;
            if (diff < 0)
                diff *= -1;
            if (diff < close) {
                close = diff;
                val = nums[i];
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int diff = nums[i] - val;
            if (diff < 0)
                diff *= -1;

            ans += diff;
        }

        return ans;
    }
};
