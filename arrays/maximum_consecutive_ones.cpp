#include <algorithm>
#include <iostream>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int maximum = 0;
    int n = nums.size();

    int windowStart = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1 && windowStart == -1) {
            windowStart = i;
        }

        if (nums[i] == 0 && windowStart != -1) {
            maximum = std::max(maximum, i - windowStart);
            windowStart = -1;
        }
    }

    if (windowStart != -1) {
        maximum = std::max(maximum, n - windowStart);
    }

    return maximum;
}

int main() {
    std::vector<int> nums = { 0, 0 };
    std::cout << findMaxConsecutiveOnes(nums) << std::endl;
    return 0;
}
