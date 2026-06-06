#include <iostream>
#include <vector>
using namespace std;

/*
 * Key Idea: Use two pointers
 * * currIndex = tells until where all the elements are unique
 * * pivot = helps to find the next unique elements by discarding all duplicates
 * And once new element found, swap with currIndex+1 element
 */
int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1)
        return nums.size();

    int currIndex = 0,
        pivot = 1,
        n = nums.size();

    while (pivot < n) {
        while (pivot < n && nums[pivot] <= nums[currIndex])
            pivot++;

        if (pivot < n) {
            nums[++currIndex] = nums[pivot];
        }

        pivot++;
    }

    return currIndex + 1;
}

void printArray(vector<int>& nums, int length) {
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 5};
    vector<int> nums1 = {1, 2, 2, 2, 3, 3, 4, 5, 5, 6, 7};

    printArray(nums, removeDuplicates(nums));
    printArray(nums1, removeDuplicates(nums1));

    return 0;
}
