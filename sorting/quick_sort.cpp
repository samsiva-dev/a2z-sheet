#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[high], arr[i+1]);

    return i+1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int partition_idx = partition(arr, low, high);
        quickSort(arr, low, partition_idx-1);
        quickSort(arr, partition_idx+1, high);
    }
}

int main() {
    std::vector<int> nums = { 5, 3, 2, 4, 1, 6 };

    quickSort(nums, 0, nums.size()-1);

    for (int x: nums) {
        std::cout << x << " ";
    }

    return 0;
}
