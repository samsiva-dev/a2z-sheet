#include <iostream>
#include <utility>
#include <vector>

std::vector<int> selectionSort(std::vector<int> nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[min_idx])
                min_idx = j;
        }
        std::swap(nums[min_idx], nums[i]);
    }

    return nums;
}

int main() {
    std::vector<int> nums = { 1, 2, 4, 3, 6, 7, 5, 9, 0 };

    for (int x: selectionSort(nums)) {
        std::cout << x << " ";
    }

    return 0;
}
