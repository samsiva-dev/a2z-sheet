#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& nums, int until) {
    if (until == nums.size())
        return;

    int key = nums[until];
    int j = until - 1;
    while (j >= 0 && nums[j] > key) {
        nums[j+1] = nums[j];
        j--;
    }
    nums[j+1] = key;

    insertion_sort(nums, until+1);
}

int main() {
    std::vector<int> nums = { 1, 3, 2, 5, 4, 7, 6 };

    insertion_sort(nums, 1);

    for(int x: nums) {
        std::cout << x << " ";
    }
}
