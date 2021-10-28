#include "../Headers/StringUtils.hpp"

#include <algorithm>
#include <cassert>
#include <cctype>

bool IsNumber(const std::string &s) {

    for (char c : s) {

        if (!std::isdigit(c)) return false;

    }

    return true;

}

bool StartWith(const std::string &s, const std::string &start) {

    if (start.size() > s.size()) {

        return false;

    } else if (start.size() == s.size()) {

        return start == s;

    } else {

        for (std::size_t i{0}; i < start.size(); i++) {

            if (s[i] != start[i]) return false;

        }

        return true;

    }

}

bool EndWith(const std::string &s, const std::string &end) {

    if (end.size() > s.size()) {

        return false;

    } else if (end.size() == s.size()) {

        return end == s;

    } else {

        for (std::size_t i{0}; i < end.size(); i++) {

            if (s[s.size()-1-(end.size()-1-i)] != end[i]) return false;

        }

        return true;

    }

}

char UIntToChar(unsigned int i) {

    assert(i <= 9);
    return i+'0';

}

unsigned int CharToUInt(char c) {

    assert(std::isdigit(c));
    return c-'0';

}

std::string Upper(const std::string &s) {

    std::string result;
    for (char c : s) result.push_back(std::toupper(c));

    return result;

}

std::string Lower(const std::string &s) {

    std::string result;
    for (char c : s) result.push_back(std::tolower(c));

    return result;

}

std::string LStrip(std::string s, char c) {

    while (!s.empty() && s[0] == c) s.erase(s.begin());
    return s;

}

std::string RStrip(std::string s, char c) {

    while (!s.empty() && s.back() == c) s.pop_back();
    return s;

}

std::string Strip(std::string s, char c) { return RStrip(LStrip(s, c)); }

std::string RemoveChar(const std::string &s, char c) {

    std::string result;
    for (char ch : s) {

        if (ch != c) result.push_back(ch);

    }

    return result;

}

std::string RemoveSpaces(const std::string &s) {

    std::string result;
    for (char c : s) {

        if (!std::isspace(c)) result.push_back(c);

    }

    return result;

}

std::string Reverse(const std::string &s) {

    std::string r;
    for (std::size_t i{s.size()}; i > 0; i--) r.push_back(s[i-1]);

    return r;

}

std::string CopyPopFront(const std::string &s, std::size_t repeat) {

    if (repeat > s.size()) {

        return std::string{};

    } else {

        std::string copy{s};
        for (std::size_t i{0}; i < repeat; i++) copy.erase(copy.begin());

        return copy;

    }

}

std::string CopyPopBack(const std::string &s, std::size_t repeat) {

    if (repeat > s.size()) {

        return std::string{};

    } else {

        std::string copy{s};
        for (std::size_t i{0}; i < repeat; i++) copy.pop_back();

        return copy;

    }

}

std::string ConvertBinaryBaseTo(std::string binary, std::size_t base) {

    std::string result;

    do {

        unsigned int remainder{0};
        std::string temp;

        for (const char bit : binary) {

            remainder = remainder*2+(bit-'0');

            if (remainder >= base) {

                remainder -= base;
                temp += "1";

            } else {

                temp += "0";

            }
                
        } 

        binary = temp;
        result.insert(0, 1, '0'+remainder);

    } while (std::count(binary.begin(), binary.end(), '1'));

    return result;

}