#include <iostream>
#include <vector>

/*
 * Key Idea: Save the first element and then shift
 * the remaining element between 1..n-2 to left
 * and store the saved element at first
 */
void rotateArrayByOne(std::vector<int>& nums) {
    int n = nums.size();

    if (n <= 1)
        return;

    int start = nums[0];
    for (int i = 0; i < n-1; i++) {
        nums[i] = nums[i+1];
    }
    nums[n-1] = start;
}

void printArr(std::vector<int>& nums) {
    for (int x: nums) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> nums1 = { 1, 0, 2 };

    rotateArrayByOne(nums);
    rotateArrayByOne(nums1);

    printArr(nums);
    printArr(nums1);
}
