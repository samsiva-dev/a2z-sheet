#include <iostream>
#include <vector>

int searchLowerBound(std::vector<int>& nums, int key) {
    int size = static_cast<int>(nums.size());
    int left = 0;
    int right = size-1;
    int lower_bound = -1;

    while (left <= right) {
        int mid = left + (right - left)/2;

        if (nums[mid] < key) {
            left = mid+1;
        }
        else {
            if (nums[mid] == key)
                lower_bound = mid;
            right = mid-1;
        }
    }

    return lower_bound;
}

int main() {
    std::vector<int> nums = { 1, 2, 2, 2, 5, 6, 6, 6 };

    std::cout << searchLowerBound(nums, 2) << "\n";
    std::cout << searchLowerBound(nums, 6) << "\n";
    std::cout << searchLowerBound(nums, 7) << "\n";

    return 0;
}
