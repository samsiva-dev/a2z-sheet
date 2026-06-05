#include <iostream>
#include <vector>
using namespace std;

/*
 * Key Idea: For every element, check whether it's future elements
 * are smaller or not. If smaller, return false (means unsorted).
 */
bool is_array_sorted_brute_force(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (nums[i] > nums[j]) {
                return false;
            }
        }
    }

    return true;
}

/*
 * Key Idea: In sorted array, two adjacent elements are always sorted
 * so for each element we check whether it's previous element sorted
 * if not return false, else true
 */
bool is_array_sorted(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums1 = {1, 3, 2, 5, 4};
    vector<int> nums2 = {-5, -4, -3, -2, -1};
    cout << is_array_sorted_brute_force(nums) << endl;
    cout << is_array_sorted_brute_force(nums1) << endl;
    cout << is_array_sorted_brute_force(nums2) << endl;
    cout << is_array_sorted(nums) << endl;
    cout << is_array_sorted(nums1) << endl;
    cout << is_array_sorted(nums2) << endl;
}
