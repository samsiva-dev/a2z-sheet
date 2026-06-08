#include <iostream>
#include <vector>

// Conquer
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int left_idx = left;
    int right_idx = mid + 1;
    std::vector<int> temp;

    while (left_idx <= mid && right_idx <= right) {
        if (arr[left_idx] < arr[right_idx]) {
            temp.push_back(arr[left_idx++]);
        } else {
            temp.push_back(arr[right_idx++]);
        }
    }

    while (left_idx <= mid) {
        temp.push_back(arr[left_idx++]);
    }

    while (right_idx <= right) {
        temp.push_back(arr[right_idx++]);
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

// Divide
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    mergeSort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
