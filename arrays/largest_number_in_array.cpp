#include <iostream>
#include <vector>
using namespace std;

int largestNumberInArray(vector<int>& arr) {
    // Initialize maximum to the first element of the array
    int maximum = arr[0];
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        // Update maximum if the current element is greater
        if (arr[i] > maximum)
            maximum = arr[i];
    }

    return maximum;
}

int main() {
    // Example 1
    vector<int> arr = {1, 2, 3, 4, 5};
    int result = largestNumberInArray(arr);
    cout << result << endl;

    // Example 2
    vector<int> arr2 = {5, 4, 3, 2, 1};
    int result2 = largestNumberInArray(arr2);
    cout << result2 << endl;

    // Example 3
    vector<int> arr3 = {1, -2, 5, -4, 3};
    int result3 = largestNumberInArray(arr3);
    cout << result3 << endl;

    return 0;
}
