func maxRotateFunction(nums []int) int {
    sum := 0;
    max := 0;
    for i, val := range nums {
        sum += val;
        max += i * val;
    }

    curr := max

    for i := len(nums) - 1; i >= 1; i-- {
        minus := (nums[i] * (len(nums) - 1));
        val := sum - nums[i] - minus;

        val += curr;
        curr = val;

        if val > max {
            max = val
        }
    } 

    return max
}
