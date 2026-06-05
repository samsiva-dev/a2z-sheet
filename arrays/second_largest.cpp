#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int secondLargestElement(vector<int>& arr) {
    int largest = arr[0];
    int second = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        // Current element is larger than the "largest",
        // Means current largest will become the second largest
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        }
        // Above condition will fail in case of negatives like -3 > -1
        // Here, -1 is largest and -3 is smalled
        // So update the second bound
        else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    // If second still equals to INT_MIN, all elements in the
    // array are same
    return second == INT_MIN ? -1: second;
}

int main() {
    vector<int> arr = {-4, -2, -1};
    cout << secondLargestElement(arr) << endl;
    return 0;
}
