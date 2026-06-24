#include <climits>
#include <iostream>
#include <string>
#include <vector>
std::string longestCommonPrefix(std::vector<std::string> strs) {
    std::string result = "";
    int total_strs = static_cast<int>(strs.size());
    if (total_strs == 0) {
        return "";
    }
    if (total_strs == 1) {
        return strs[0];
    }
    int min_size = INT_MAX;
    for (std::string str: strs) {
        int curr_str_size = static_cast<int>(str.length());
        if (curr_str_size < min_size) {
            min_size = curr_str_size;
        }
    }
    for (int i = 0; i < min_size; i++) {
        char curr = strs[0][i];
        bool is_exist = true;
        for (int j = 1; j < total_strs; j++) {
            if (strs[j][i] != curr) {
                is_exist = false;
                break;
            }
        }
        if (is_exist) {
            result += curr;
        }
    }
    return result;
}
int main() {
    std::vector<std::string> strs = {
        "ABCDE",
        "ABC",
        "ABCD"
    };
    std::cout << longestCommonPrefix(strs) << "\n";
    return 0;
}
