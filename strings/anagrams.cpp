#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

bool validAnagramUsingSort(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    int length = static_cast<int>(s.length());
    for (int i = 0; i < length; i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }

    return true;
}

bool validAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> s_counter;
    std::unordered_map<char, int> t_counter;

    for (char i: s) {
        if (s_counter.find(i) != s_counter.end()) {
            s_counter[i] += 1;
        } else {
            s_counter[i] = 1;
        }
    }

    for (char i: t) {
        if (t_counter.find(i) != t_counter.end()) {
            t_counter[i] += 1;
        } else {
            t_counter[i] = 1;
        }
    }

    for (const auto& pair : s_counter) {
        if (
            t_counter.find(pair.first) == t_counter.end() ||
            (t_counter.find(pair.first) != t_counter.end() && t_counter[pair.first] != pair.second)
        ) {
            return false;
        }
    }

    return true;
}

bool validAnagramSpaceOptimal(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> counter;

    for (char i: s) {
        if (counter.find(i) != counter.end()) {
            counter[i] += 1;
        } else {
            counter[i] = 1;
        }
    }

    for (char i: t) {
        if (counter.find(i) != counter.end()) {
            counter[i] -= 1;
        } else {
            return false;
        }
    }

    for (const auto& pair : counter) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s = "anagram";
    std::string t = "nagaram";

    std::cout << validAnagramUsingSort(s, t) << "\n";
    std::cout << validAnagram(s, t) << "\n";
    std::cout << validAnagramSpaceOptimal(s, t) << "\n";

    std::string s1 = "hello";
    std::string t1 = "hell";
    std::cout << validAnagramUsingSort(s1, t1) << "\n";
    std::cout << validAnagram(s1, t1) << "\n";
    std::cout << validAnagramSpaceOptimal(s1, t1) << "\n";

    return 0;
}
