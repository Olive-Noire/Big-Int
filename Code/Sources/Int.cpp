#include "../Headers/Int.hpp"

#include <iostream>

Dynamic_Binary_Signed_Int::Dynamic_Binary_Signed_Int() {



}

Dynamic_Binary_Signed_Int::Dynamic_Binary_Signed_Int(bool b) {



}

Dynamic_Binary_Signed_Int::Dynamic_Binary_Signed_Int(std::intmax_t n) {



}

Dynamic_Binary_Signed_Int::Dynamic_Binary_Signed_Int(const std::string &s) {



}

Dynamic_Binary_Signed_Int Dynamic_Binary_Signed_Int::Min() { return -Dynamic_Binary_Signed_Int::Max(); }

Dynamic_Binary_Signed_Int Dynamic_Binary_Signed_Int::Max() {

    Dynamic_Binary_Signed_Int m;
    for (std::size_t i{0}; i < std::numeric_limits<std::size_t>::max(); i++) m.m_sequence.push_back(true);

    return m;

}

bool Dynamic_Binary_Signed_Int::Empty() const { return m_sequence.empty(); }

bool Dynamic_Binary_Signed_Int::Full() const {

    for (bool b : m_sequence) {

        if (!b) return false;

    }

    return true;

}

bool Dynamic_Binary_Signed_Int::LSD() const { return m_sequence.back(); }
bool Dynamic_Binary_Signed_Int::MSD() const { return m_sequence[0]; }
std::size_t Dynamic_Binary_Signed_Int::BitsCount() const { return m_sequence.size(); }
std::size_t Dynamic_Binary_Signed_Int::BytesCount() const { return m_sequence.size()/8; }

Dynamic_Binary_Signed_Int Dynamic_Binary_Signed_Int::operator+() const { return *this; }
Dynamic_Binary_Signed_Int Dynamic_Binary_Signed_Int::operator-() const { return CA2(*this); }

Dynamic_Binary_Signed_Int Dynamic_Binary_Signed_Int::operator~() const {

    Dynamic_Binary_Signed_Int temp{*this};
    for (std::vector<bool>::reference b : temp.m_sequence) b = !b;

    return temp;

}

Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator++(int) { return *this += 1; }
Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator++() { return *this += 1; }
Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator--(int) { return *this -= 1; }
Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator--() { return *this -= 1; }

Dynamic_Binary_Signed_Int operator+(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {



}

Dynamic_Binary_Signed_Int operator-(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {



}

Dynamic_Binary_Signed_Int operator*(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {



}

Dynamic_Binary_Signed_Int operator/(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {



}

Dynamic_Binary_Signed_Int operator%(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {



}

Dynamic_Binary_Signed_Int operator&(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {



}

Dynamic_Binary_Signed_Int operator|(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {



}

Dynamic_Binary_Signed_Int operator^(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {



}

Dynamic_Binary_Signed_Int operator>>(const Dynamic_Binary_Signed_Int &n, std::size_t shift) {



}

Dynamic_Binary_Signed_Int operator<<(const Dynamic_Binary_Signed_Int &n, std::size_t shift) {



}

Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator+=(const Dynamic_Binary_Signed_Int &n) { return *this = *this+n; }
Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator-=(const Dynamic_Binary_Signed_Int &n) { return *this = *this+n; }
Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator*=(const Dynamic_Binary_Signed_Int &n) { return *this = *this+n; }
Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator/=(const Dynamic_Binary_Signed_Int &n) { return *this = *this+n; }
Dynamic_Binary_Signed_Int& Dynamic_Binary_Signed_Int::operator%=(const Dynamic_Binary_Signed_Int &n) { return *this = *this+n; }

bool operator==(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) { return l.m_sign == r.m_sign && l.m_sequence == r.m_sequence; }
bool operator!=(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) { return !(l == r); }

bool operator<(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) {

    if (l == r) {

        return false;

    } else if (l.BitsCount() > r.BitsCount()) {

        return false;

    } else if (l.BitsCount() < r.BitsCount()) {

        return true;

    } else {

        for (std::size_t i{0}; i < l.BitsCount(); i++) {

            if (l.m_sequence[i] && !r.m_sequence[i]) {

                return false;

            } else if (!l.m_sequence[i] && r.m_sequence[i]) {

                return true;

            }

        }

    }

}

bool operator<=(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) { return l < r || l == r; }

bool operator>(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) { return !(l <= r); }
bool operator>=(const Dynamic_Binary_Signed_Int &l, const Dynamic_Binary_Signed_Int &r) { return l > r || l == r; }

bool Dynamic_Binary_Signed_Int::operator[](std::size_t index) const { return m_sequence[index]; }
std::vector<bool>::reference Dynamic_Binary_Signed_Int::operator[](std::size_t index) { return m_sequence[index]; }

bool IsPair(const Dynamic_Binary_Signed_Int &n) { return !n.m_sequence.back(); }

std::string ToString(const Dynamic_Binary_Signed_Int &n) {

    return ConvertBinaryBaseTo(Sequence(*this), 10)

}

std::string Sequence(const Dynamic_Binary_Signed_Int &n) {

    std::string result;
    for (bool b : n.m_sequence) {

        result.push_back('0'+b);

    }

    return result;

}

Dynamic_Binary_Signed_Int Abs(const Dynamic_Binary_Signed_Int &n) {

    Dynamic_Binary_Signed_Int temp{n};
    temp.m_sign = true;

    return temp;

}

Dynamic_Binary_Signed_Int Pow(const Dynamic_Binary_Signed_Int &n, const Dynamic_Binary_Signed_Int &p) {

    if (n == 1) return 1;

    assert(p >= 0);

    if (p == 0) {

        return 1;

    } else if (p == 1) {

        return n;

    } else if (!IsPair(n)) {

        return Pow(n, p-1)*n;

    } else {

        Dynamic_Binary_Signed_Int temp{Pow(n, p/2)};
        return temp*temp;

    }

}

Dynamic_Binary_Signed_Int CA1(const Dynamic_Binary_Signed_Int &n) { return ~n; }
Dynamic_Binary_Signed_Int CA2(const Dynamic_Binary_Signed_Int &n) { return CA1(n)+1; }

std::ostream& operator<<(std::ostream &flux, const Dynamic_Binary_Signed_Int &n) {

    flux << ToString(n);
    return flux;

}

Dynamic_Decimal_Signed_Int::Dynamic_Decimal_Signed_Int() : m_sign{false}, m_value{"0"} {}

Dynamic_Decimal_Signed_Int::Dynamic_Decimal_Signed_Int(const std::string &s) : m_sign{s[0] != '-'}, m_value{LStrip(Strip(s), '0')} {

    if (!IsNumber(Strip(s)) && !((Strip(s)[0] == '-' || Strip(s)[0] == '+') && IsNumber(CopyPopFront(Strip(s))))) {
        
        m_value = "0";
        m_sign = false;

    }

    if (m_value[0] == '-') m_value.erase(m_value.begin());

}

Dynamic_Decimal_Signed_Int::Dynamic_Decimal_Signed_Int(std::intmax_t n) : m_sign{n < 0}, m_value{std::to_string(n)} {

    if (m_value[0] == '-') m_value.erase(m_value.begin());
    
}

Dynamic_Decimal_Signed_Int Dynamic_Decimal_Signed_Int::Min() {

    std::string m;
    for (std::size_t i{0}; i < std::numeric_limits<std::size_t>::max(); i++) m.push_back('9');

    return '-'+m;

}

Dynamic_Decimal_Signed_Int Dynamic_Decimal_Signed_Int::Max() {

    std::string m;
    for (std::size_t i{0}; i < std::numeric_limits<std::size_t>::max(); i++) m.push_back('9');

    return '+'+m;

}

Dynamic_Decimal_Signed_Int Dynamic_Decimal_Signed_Int::operator+() { return *this; }

Dynamic_Decimal_Signed_Int Dynamic_Decimal_Signed_Int::operator-() {

    Dynamic_Decimal_Signed_Int temp{*this};
    temp.m_sign = !m_sign;

    return temp;

}

Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator++(int) { return *this += 1; }
Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator++() { return *this += 1; }
Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator--(int) { return *this -= 1; }
Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator--() { return *this -= 1; }

Dynamic_Decimal_Signed_Int operator+(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) {

    if (l.m_sign != r.m_sign) {

        return l-(-r);

    } else {

        if (r > l) {

            return r+l;

        } else {

            std::string left{l.m_value}, right{r.m_value};

            if (right.size() > left.size()) {

                std::string swap{l.m_value};
                left = right;
                right = swap;

            }

            while (right.size() < left.size()) right.insert(right.begin(), '0');

            bool carry{false};
            std::string operation;

            for (std::size_t i{0}; i < right.size(); i++) {

                char add = left[left.size()-1-i]+right[right.size()-1-i]-'0'+carry;
                carry = false;

                if (add > '9') {

                    add -= 10;
                    carry = true;

                }

                operation.insert(operation.begin(), add);

                if (i == right.size()-1 && carry) {

                    operation.insert(operation.begin(), '1');

                }

            }

            Dynamic_Decimal_Signed_Int result{operation};
            result.m_sign = l.m_sign;

            return result;

        }

    }

}

Dynamic_Decimal_Signed_Int operator-(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) {

    if (l == r) {

        return 0;

    } else if (!l.m_sign && !r.m_sign) {

        return -(Abs(l)-Abs(r));

    } else {

        std::string left{Abs(l).m_value}, right{Abs(r).m_value};

        if (r > l) {

            std::string swap{left};
            left = right;
            right = swap;

        }

        while (right.size() < left.size()) right.insert(right.begin(), '0');

        bool carry{false};
        std::string operation;

        for (std::size_t i{0}; i < right.size(); i++) {

            char sub = left[left.size()-1-i]-(right[right.size()-1-i]-'0')-carry;
            carry = false;

            if (sub < '0') {

                sub += 10;
                carry = true;

            }

            operation.insert(operation.begin(), sub);

            if (i == right.size()-1 && carry) {

                operation.insert(operation.begin(), '1');

            }

        }

        while (operation.size() > 1 && operation[0] == '0') operation.erase(operation.begin());

        Dynamic_Decimal_Signed_Int result{operation};
        result.m_sign = l.m_sign && l <= r;

        return result;

    }

}

Dynamic_Decimal_Signed_Int operator*(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) {

    if (r == 0) {

        return 0;

    } else if (r == 1) {

        return l;

    } else {

        Dynamic_Decimal_Signed_Int left, right;

        {

            std::string tempLeft{l.m_value}, tempRight{r.m_value};
            while (tempRight.size() > 1 && tempRight.back() == '0') {

                tempLeft.push_back('0');
                tempRight.pop_back();

            }

            left = tempLeft;
            right = tempRight;

        }

        if (right > left) {
            
            return right*left;

        } else {

            Dynamic_Decimal_Signed_Int result{left};

            for (Dynamic_Decimal_Signed_Int i{1}; i < right; i++) result += left;
            result.m_sign = (l.m_sign != r.m_sign);

            return result;

        }

    }

}

Dynamic_Decimal_Signed_Int operator/(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) {

    assert(r != 0 && l >= r);

    if (r == l) {

        return 1;

    } else if (r == 1) {

        return l;

    } else {

        Dynamic_Decimal_Signed_Int result{0}, copy{Abs(l)};
        while (copy >= Abs(r)) {
        
            copy -= Abs(r);
            result++;

        }

        result.m_sign = (l.m_sign != r.m_sign);
        return result;

    }

}

Dynamic_Decimal_Signed_Int operator%(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) { return l-l/r*r; }

Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator+=(const Dynamic_Decimal_Signed_Int &n) { return *this = *this+n; }
Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator-=(const Dynamic_Decimal_Signed_Int &n) { return *this = *this-n; }
Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator*=(const Dynamic_Decimal_Signed_Int &n) { return *this = *this*n; }
Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator/=(const Dynamic_Decimal_Signed_Int &n) { return *this = *this/n; }
Dynamic_Decimal_Signed_Int& Dynamic_Decimal_Signed_Int::operator%=(const Dynamic_Decimal_Signed_Int &n) { return *this = *this%n; }

bool operator==(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) { return l.m_sign == r.m_sign && l.m_value == r.m_value; }
bool operator!=(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) { return !(l == r); }

bool operator<(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) {

    if (l == r) {

        return false;

    } else if (l.m_sign != r.m_sign) {

        return l.m_sign;

    } else if (l.m_value.size() != r.m_value.size()) {

        return l.m_value.size() < r.m_value.size();

    } else {

        for (std::size_t i{0}; i < l.m_value.size(); i++) {

            if (l.m_value[i] != r.m_value[i]) return l.m_value[i] < r.m_value[i];

        }

    }

    return true; // no warnings

}

bool operator<=(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) { return l < r || l == r; }
bool operator>(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) { return !(l <= r); }
bool operator>=(const Dynamic_Decimal_Signed_Int &l, const Dynamic_Decimal_Signed_Int &r) { return l > r || l == r; }

bool IsPair(const Dynamic_Decimal_Signed_Int &n) { return !(CharToUInt(n.m_value.back())%2); }
std::string ToString(const Dynamic_Decimal_Signed_Int &n) {

    std::string result{n.m_value};

    if (!n.m_sign) {

        result.insert(result.begin(), '+');

    } else {

        result.insert(result.begin(), '-');

    }

    return result;

}

Dynamic_Decimal_Signed_Int Abs(const Dynamic_Decimal_Signed_Int &n) {

    Dynamic_Decimal_Signed_Int copy{n};
    copy.m_sign = false;

    return copy;

}

Dynamic_Decimal_Signed_Int Pow(Dynamic_Decimal_Signed_Int n, const Dynamic_Decimal_Signed_Int &p) {

    if (n == 1) return 1;

    assert(p >= 0);

    if (p == 0) {

        return 1;

    } else if (p == 1) {

        return n;

    } else if (!IsPair(n)) {

        return Pow(n, p-1)*n;

    } else {

        Dynamic_Decimal_Signed_Int temp{Pow(n, p/2)};
        return temp*temp;

    }

}

Dynamic_Decimal_Signed_Int::operator std::string() { return ToString(*this); }

std::ostream& operator<<(std::ostream &flux, const Dynamic_Decimal_Signed_Int &n) {

    if (n.m_sign) flux << '-';
    flux << n.m_value;

    return flux;

}

std::vector<bool> CA1(std::vector<bool> v) {

    for (std::vector<bool>::reference b : v) b = !b;
    return v;

}

std::vector<bool> CA2(std::vector<bool> v) {

    return CA2(v);

}