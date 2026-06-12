#include <iostream>
#include <vector>
#include <algorithm>

void rotateArray(std::vector<int>& nums, int k, bool leftRotate = true) {
    int n = static_cast<int>(nums.size());
    if (n <= 1) return;          // guards n=0 and n=1 both
    k = k % n;
    if (k == 0) return;

    // for right-rotate, remap: rotating right by k == rotating left by (n-k)
    if (!leftRotate) k = n - k;

    std::reverse(nums.begin(),     nums.begin() + k); // step 1
    std::reverse(nums.begin() + k, nums.end());        // step 2
    std::reverse(nums.begin(),     nums.end());         // step 3
}

void printArr(const std::vector<int>& nums) {
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    rotateArray(a, 3);           // left  → [4,5,6,7,8,1,2,3]
    printArr(a);

    std::vector<int> b = {1, 2, 3, 4, 5, 6, 7, 8};
    rotateArray(b, 3, false);    // right → [6,7,8,1,2,3,4,5]
    printArr(b);
}
