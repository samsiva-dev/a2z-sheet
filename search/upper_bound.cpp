#include <iostream>
#include <vector>

int searchUpperBound(std::vector<int>& nums, int key) {
    int size = static_cast<int>(nums.size());
    int left = 0;
    int right = size-1;
    int upper_bound = -1;

    while (left <= right) {
        int mid = left + (right - left)/2;

        if (nums[mid] > key) {
            right = mid-1;
        }
        else {
            if (nums[mid] == key)
                upper_bound = mid;
            left = mid+1;
        }
    }

    return upper_bound;
}

int main() {
    std::vector<int> nums = { 1, 2, 2, 2, 5, 6, 6, 6 };

    std::cout << searchUpperBound(nums, 2) << "\n";
    std::cout << searchUpperBound(nums, 6) << "\n";
    std::cout << searchUpperBound(nums, 7) << "\n";

    return 0;
}
