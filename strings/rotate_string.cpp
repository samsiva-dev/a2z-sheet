#include <iostream>
#include <string>

bool rotateString(std::string s, std::string goal) {
    int s_len = static_cast<int>(s.length());
    int goal_len = static_cast<int>(goal.length());

    if (s_len != goal_len)
        return false;

    std::string doubled = s + s;
    return doubled.find(goal) != std::string::npos;
}

int main() {
    std::string s = "abcde";
    std::string goal = "bcdea";

    std::cout << rotateString(s, goal) << std::endl;

    std::string s1 = "abcde";
    std::string goal1 = "abced";

    std::cout << rotateString(s1, goal1) << std::endl;

    return 0;
}
