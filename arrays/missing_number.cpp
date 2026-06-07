#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int n = nums.size();

    // Expected 'n+1' numbers sum
    long long expected_sum =  ((n+1) * (n + 2)) / 2;

    // Current Sum
    long long current_sum = 0;
    for (int i = 0; i < n; i++) {
        current_sum += nums[i];
    }

    return expected_sum - current_sum;
}


int missingNumber_XOR(std::vector<int>& nums) {
    int n = nums.size();
    int xor_full = 0;
    int xor_arr = 0;

    for (int i = 1; i <= n+1; i++) {
        xor_full ^= i;
    }

    for (int x: nums) {
        xor_arr ^= x;
    }

    return xor_full ^ xor_arr;
}


int main() {
    std::vector<int> nums = {1, 2, 4, 5};
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 7, 8, 9, 10};

    std::cout << missingNumber_XOR(nums) << std::endl;
    std::cout << missingNumber_XOR(nums1) << std::endl;
    return 0;
}
