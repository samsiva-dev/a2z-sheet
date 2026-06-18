#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    // Binary Search
    // Time: O(log n), Space: O(1)
    // If the target is found, return its index
    // If not, return the index where it would be inserted i.e left
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    std::cout << searchInsert(nums, 5) << std::endl;
    std::cout << searchInsert(nums, 2) << std::endl;
    return 0;
}
