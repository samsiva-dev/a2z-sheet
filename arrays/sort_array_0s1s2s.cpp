#include <iostream>
#include <utility>
#include <vector>

void sortZeroOneTwo(std::vector<int>& nums) {
    int length = static_cast<int>(nums.size());
    int low = 0;
    int mid = 0;
    int high = length - 1;

    /*
     * 0 to low represents 0
     * low to mid represents 1
     * > high represents 2
     */
    while (mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void printResult(std::vector<int>& nums) {
    for (int x: nums) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {0, 1, 0, 1, 2, 0};
    std::vector<int> nums1 = {0, 0, 0, 1, 1, 2};
    std::vector<int> nums2 = {0, 0, 0, 1, 1, 1};

    sortZeroOneTwo(nums);
    sortZeroOneTwo(nums1);
    sortZeroOneTwo(nums2);

    printResult(nums);
    printResult(nums1);
    printResult(nums2);
}
