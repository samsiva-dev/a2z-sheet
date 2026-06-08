#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            // If current element is greater than the
            // next element, swap them both
            if (nums[j] > nums[j+1]) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;

                swapped = true;
            }
        }
        // Already a sorted array
        if (!swapped) {
            break;
        }
    }

    return nums;
}

int main() {
    std::vector<int> nums = { 1, 2, 3, 4, 6, 5, 7, 1 };

    for (int x: bubbleSort(nums)) {
        std::cout << x << " ";
    }

    return 0;
}
