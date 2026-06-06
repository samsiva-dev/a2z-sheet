#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Key Idea: Two Pointers + Hash
 * Two pointers to traverse both the arrays respectively and Hash to keep
 * the track of distinctness.
 * Insert one element at a time (whichever is the smallest) by checking whether
 * it already as part of result or not.
 */
vector<int> unionSortedArray_Using_Hash(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    unordered_map<int, bool> map;
    int arr1_idx = 0;
    int arr2_idx = 0;
    int arr1_length = arr1.size();
    int arr2_length = arr2.size();

    // Merge the possible elements by maintaining distinctness
    while (arr1_idx < arr1_length && arr2_idx < arr2_length) {
        int ele1 = arr1[arr1_idx];
        int ele2 = arr2[arr2_idx];

        if (ele1 <= ele2) {
            if (map.find(ele1) == map.end()) {
                map[ele1] = true;
                result.push_back(ele1);
            }
            arr1_idx++;
        } else {
            if (map.find(ele2) == map.end()) {
                map[ele2] = true;
                result.push_back(ele2);
            }
            arr2_idx++;
        }
    }

    // Append remaining elements at last by maintaining distinctness
    while (arr1_idx < arr1_length) {
        int ele1 = arr1[arr1_idx++];
        if (map.find(ele1) == map.end()) {
            map[ele1] = true;
            result.push_back(ele1);
        }
    }

    while (arr2_idx < arr2_length) {
        int ele2 = arr2[arr2_idx++];
        if (map.find(ele2) == map.end()) {
            map[ele2] = true;
            result.push_back(ele2);
        }
    }

    return result;
}

/*
 * Optimal Solution
 * Key Idea: Two Pointers
 * If arr1[i] < arr2[j]: Append arr1[i] and increment i
 * If arr2[j] < arr1[i]: Append arr2[j] and increment j
 * else: append anyone and increment both i & j.
 */
vector<int> unionSortedArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int arr1_idx = 0;
    int arr2_idx = 0;
    int arr1_length = arr1.size();
    int arr2_length = arr2.size();

    while (arr1_idx < arr1_length && arr2_idx < arr2_length) {
        int ele1 = arr1[arr1_idx];
        int ele2 = arr2[arr2_idx];

        if (ele1 < ele2) {
            result.push_back(ele1);
            arr1_idx++;
        }
        else if (ele2 < ele1) {
            result.push_back(ele2);
            arr2_idx++;
        }
        else {
            result.push_back(ele1);
            arr1_idx++;
            arr2_idx++;
        }
    }

    while (arr1_idx < arr1_length) {
        int ele1 = arr1[arr1_idx++];
        if (result.empty() || result.back() != ele1) {
            result.push_back(ele1);
        }
    }

    while (arr2_idx < arr2_length) {
        int ele2 = arr2[arr2_idx++];
        if (result.empty() || result.back() != ele2) {
            result.push_back(ele2);
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {1, 3, 4, 5};
    vector<int> arr2 = {0, 1, 2, 3, 6};

    vector<int> result = unionSortedArray(arr1, arr2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
