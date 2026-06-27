#include <iostream>
#include <string>
#include <unordered_map>

bool isomorphicString(std::string s, std::string t) {
    std::unordered_map<char, char> s_map;
    std::unordered_map<char, char> t_map;

    int s_len = static_cast<int>(s.length());
    int t_len = static_cast<int>(t.length());

    if (s_len != t_len)
        return false;

    for (int i = 0; i < s_len; i++) {
        char s_curr_char = s[i];
        char t_curr_char = t[i];

        if (
            s_map.find(s_curr_char) == s_map.end()
            && t_map.find(t_curr_char) == t_map.end()
        ) {
            s_map[s_curr_char] = t_curr_char;
            t_map[t_curr_char] = s_curr_char;
        }
        else if (
            s_map[s_curr_char] != t_curr_char
            || t_map[t_curr_char] != s_curr_char
        ) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s = "egg";
    std::string t = "add";

    std::cout << isomorphicString(s, t) << "\n";

    std::string s1 = "egb";
    std::string t1 = "add";

    std::cout << isomorphicString(s1, t1) << "\n";

    return 0;
}
