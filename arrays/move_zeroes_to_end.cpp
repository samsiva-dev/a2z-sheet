#include <iostream>
#include <vector>
using namespace std;

void moveZeroesToEnd_Brute_Force(vector<int>& nums) {
    int n = nums.size();
    int i = 0;

    while (i < n) {
        // For every zero, find the non-zero after that zero
        // and then swap them
        if (nums[i] == 0) {
            int j = i;
            while (j < n && nums[j] == 0)
                j++;

            if (i != j && j < n) {
                nums[i] = nums[j];
                nums[j] = 0;
            }
        }
        i++; // Move to next
    }
}

void moveZeroesToEnd(vector<int>& nums) {
    int n = nums.size();
    int write_position = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[write_position++] = nums[i];
        }
    }

    while (write_position < n) {
        nums[write_position++] = 0;
    }
}

void printNums(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 0, 2, 3, 0, 4, 0, 5};
    vector<int> nums1 = {-1, 0, 1, -5, 2, 0, 0, 0};
    vector<int> nums2 = {0, 0, 0, 0, 5, 3, 2};
    vector<int> nums3 = {1, 2, 3, 4, 5, 0, 0, 0, 0};

    moveZeroesToEnd(nums);
    moveZeroesToEnd(nums1);
    moveZeroesToEnd(nums2);
    moveZeroesToEnd(nums3);

    printNums(nums);
    printNums(nums1);
    printNums(nums2);
    printNums(nums3);
}
