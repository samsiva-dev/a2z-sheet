#include <iostream>
#include <string>

std::string isPalindrome(std::string s, int start, int end) {
    if (start >= end) {
        return "";
    }

    int i = start;
    int j = end;
    bool is = true;
    while (i <= j) {
        if (s[i++] != s[j--]) {
            is = false;
        }
    }

    if (!is) {
        return "";
    }

    return s.substr(start, end-start+1);
}

std::string longestPalindrome(std::string s) {
    int length = static_cast<int>(s.length());

    if (length <= 1) {
        return s;
    }

    return isPalindrome(s, 0, length-1);
}

int main() {
    std::string s = "babad";
    // std::string s1 = "cbbd";

    std::cout << longestPalindrome(s) << std::endl;
    // std::cout << longestPalindrome(s1) << std::endl;

    return 0;
}
