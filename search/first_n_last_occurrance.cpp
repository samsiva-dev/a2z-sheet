#include <iostream>
#include <vector>

/*
 * Key Idea: Search first and last separately in two different loops
 * First loop, completely searches in left side of the target element while
 * Second loop, completely in the right side
 */
std::vector<int> findFirstAndLastOccurrence(std::vector<int> &nums, int target) {
    int first = -1;
    int last = -1;
    int left = 0;
    int right = nums.size() - 1;

    // Find the first occurrence
    while (left <= right) {
        int mid = left + (right - left)/2;

        if (nums[mid] >= target) {
            if (nums[mid] == target)
                first = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // Find the last occurrence
    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left)/2;

        if (nums[mid] <= target) {
            if (nums[mid] == target)
                last = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return {first, last};
}

void printResult(std::vector<int> nums) {
    for (int x: nums) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 3, 4, 5, 5, 6, 7};

    printResult(findFirstAndLastOccurrence(nums, 5));
    printResult(findFirstAndLastOccurrence(nums, 1));
    printResult(findFirstAndLastOccurrence(nums, 7));

    return 0;
}
