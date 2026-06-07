#include <iostream>
#include <vector>

/*
 * Key Idea: XOR
 * Since every number appears twice except one, XOR-ing the
 * array makes repeated elements to 0, keep only the element
 * that appears ones
 */
int singleNumber(std::vector<int>& nums) {
    int result = 0;

    for (int num: nums) {
        result ^= num;
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    std::vector<int> nums1 = {1, 2, 2, 3, 3, 4, 4, 5, 5};
    std::vector<int> nums2 = {1};

    std::cout << singleNumber(nums) << std::endl;
    std::cout << singleNumber(nums1) << std::endl;
    std::cout << singleNumber(nums2) << std::endl;

    return 0;
}
