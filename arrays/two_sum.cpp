#include <cstddef>
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> lookup;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        // Check for any pair
        int looking_for = target - nums[i];
        auto it = lookup.find(looking_for);
        if (it != lookup.end() && it->second != i) {
            return {i, it->second};
        }

        // If not found, add value:index pair to map
        lookup[nums[i]] = i;
    }

    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15, 14};
    int target = 25;
    std::vector<int> result = twoSum(nums, target);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
