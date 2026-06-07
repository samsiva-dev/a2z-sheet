#include <iostream>
#include <vector>

int linearSearch(std::vector<int>& nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (nums[i] == target)
            return i;
    }

    return -1;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 2, 4, 5};

    std::cout << linearSearch(nums, 2) << std::endl;
    std::cout << linearSearch(nums, 6) << std::endl;

    return 0;
}
