#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& nums, int n) {
    if (n == 1)
        return;

    bool didSwapped = false;

    for (int j = 0; j <= n-2; j++) {
        if (nums[j] > nums[j+1]) {
            std::swap(nums[j], nums[j+1]);
            didSwapped = true;
        }
    }

    if (!didSwapped)
        return;

    bubble_sort(nums, n-1);
}

int main() {
    std::vector<int> nums = { 1, 3, 2, 5, 4, 6, 8, 7 };
    bubble_sort(nums, nums.size());

    for (int x: nums) {
        std::cout << x << " ";
    }
}
