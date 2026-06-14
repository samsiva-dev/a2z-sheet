#include <iostream>
#include <vector>

int binarySearchKey(std::vector<int>& nums, int key) {
    int size = static_cast<int>(nums.size());
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left)/2;

        if (nums[mid] == key) {
            return mid;
        }
        else if (nums[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
    std::cout << binarySearchKey(nums, 6) << std::endl;
    std::cout << binarySearchKey(nums, 2) << std::endl;
    std::cout << binarySearchKey(nums, 8) << std::endl;

    return 0;
}
