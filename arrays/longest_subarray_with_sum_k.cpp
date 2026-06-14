#include <iostream>
#include <vector>

/*
 * Key Idea:
 * Find the longest subarray with sum equal to k using a sliding window approach.
 * If any subarray with sum equal to k is found, update the maxLength.
 * If the currentSum exceeds k, shrink the window from the left by moving the start pointer.
 * If the currentSum equals k, update the maxLength.
 */
int longestSubarrayWithSumK(std::vector<int>& arr, int k) {
    int maxLength = 0;
    int currentSum = 0;
    int start = 0;

    for (int end = 0; end < arr.size(); ++end) {
        currentSum += arr[end];

        while (currentSum > k) {
            currentSum -= arr[start];
            ++start;
        }

        if (currentSum == k) {
            maxLength = std::max(maxLength, end - start + 1);
        }
    }

    return maxLength;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int k = 10;
    std::cout << longestSubarrayWithSumK(arr, k) << std::endl;
    return 0;
}
