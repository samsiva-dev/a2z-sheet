#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string reverseWords(std::string s) {
    std::stringstream ss(s);
    std::string word;
    std::vector<std::string> words;

    // Step 1: Extract all words (stringstream automatically skips spaces)
    while (ss >> word) {
        words.push_back(word);
    }

    // Step 2: Reconstruct the string in reverse order
    std::string result = "";
    for (int i = words.size() - 1; i >= 0; --i) {
        result += words[i];

        // Add a single space between words, but not after the last word
        if (i > 0) {
            result += " ";
        }
    }

    return result;
}

int main() {
    std::string input1 = "the sky is blue";
    std::string input2 = "  hello   world  ";
    std::string input3 = "a good   example";

    std::cout << "'" << reverseWords(input1) << "'\n"; // "blue is sky the"
    std::cout << "'" << reverseWords(input2) << "'\n"; // "world hello"
    std::cout << "'" << reverseWords(input3) << "'\n"; // "example good a"
}
