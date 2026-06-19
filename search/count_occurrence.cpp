#include <iostream>
#include <vector>

int countOccurrence(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    int first_occurrence = -1;
    int last_occurrence = -1;

    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] >= target) {
            if (nums[mid] == target)
                first_occurrence = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (nums[mid] <= target) {
            if (nums[mid] == target)
                last_occurrence = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Element not found
    if (first_occurrence == -1 && last_occurrence == -1) {
        return 0;
    }

    // Only one occurrence
    if (first_occurrence == -1 || last_occurrence == -1) {
        return 1;
    }

    return last_occurrence - first_occurrence + 1;
}

int main() {
    std::vector<int> nums = {0,0,1,1,1,2,2,2,2,4};

    std::cout << countOccurrence(nums, 1) << std::endl;
    std::cout << countOccurrence(nums, 2) << std::endl;
    std::cout << countOccurrence(nums, 3) << std::endl;
    std::cout << countOccurrence(nums, 4) << std::endl;

    return 0;
}
