#ifndef DEF_INT_HPP
#define DEF_INT_HPP

#include <iostream>
#include <cassert>
#include <cstdint>
#include <sstream>
#include <iosfwd>
#include <limits>
#include <string>
#include <vector>
#include <array>
#include <cmath>

#include "./StringUtils.hpp"

template <std::size_t Bits> class Static_Binary_Unsigned_Int {

    public:

    Static_Binary_Unsigned_Int() {

        for (bool &b : m_sequence) b = false;

    }

    Static_Binary_Unsigned_Int(const Static_Binary_Unsigned_Int&) = default;
    Static_Binary_Unsigned_Int(Static_Binary_Unsigned_Int&&) noexcept = default;

    template <std::size_t Bits_Other> Static_Binary_Unsigned_Int(const Static_Binary_Unsigned_Int<Bits_Other> &n) {

        std::size_t writeLimit{Bits};
        if (Bits_Other < Bits) writeLimit = Bits_Other;

        for (std::size_t i{0}; i < Bits; i++) {

            m_sequence[Bits-1-i] = false;

            if (i <= writeLimit) {
                
                m_sequence[Bits-1-i] = n[Bits_Other-1-i];

            }

        }

    }

    explicit Static_Binary_Unsigned_Int(std::int8_t n) : Static_Binary_Unsigned_Int{static_cast<std::uintmax_t>(n)} {}
    explicit Static_Binary_Unsigned_Int(std::int16_t n) : Static_Binary_Unsigned_Int{static_cast<std::uintmax_t>(n)} {}
    explicit Static_Binary_Unsigned_Int(std::int32_t n) : Static_Binary_Unsigned_Int{static_cast<std::uintmax_t>(n)} {}
    explicit Static_Binary_Unsigned_Int(std::intmax_t n) : Static_Binary_Unsigned_Int{static_cast<std::uintmax_t>(n)} {}

    explicit Static_Binary_Unsigned_Int(std::uint8_t n) : Static_Binary_Unsigned_Int{static_cast<std::uintmax_t>(n)} {}
    explicit Static_Binary_Unsigned_Int(std::uint16_t n) : Static_Binary_Unsigned_Int{static_cast<std::uintmax_t>(n)} {}
    explicit Static_Binary_Unsigned_Int(std::uint32_t n) : Static_Binary_Unsigned_Int{static_cast<std::uintmax_t>(n)} {}

    Static_Binary_Unsigned_Int(std::uintmax_t n) {

        if (n == 0) {

            for (bool &b : m_sequence) b = false;

        } else {

            if (Bits <= 64 && n >= std::pow(2, Bits)-1) {

                for (bool &b : m_sequence) b = true;

            } else {

                for (std::size_t i{0}; i < Bits; i++) {

                    if (n > 0) {

                        m_sequence[Bits-1-i] = n%2;
                        n /= 2;

                    } else {

                        m_sequence[Bits-1-i] = false;

                    }

                }

            }

        }

    }

    explicit Static_Binary_Unsigned_Int(const std::string &s) {

        if (IsNumber(s)) {

            std::uintmax_t n;
            std::istringstream{s} >> n;

            *this = Static_Binary_Unsigned_Int<Bits>{n};

        } else {

            *this = 0;

        }

    }

    ~Static_Binary_Unsigned_Int() = default;

    static Static_Binary_Unsigned_Int Min() { return 0; }

    static Static_Binary_Unsigned_Int Max() {

        Static_Binary_Unsigned_Int result{0};
        for (bool &b : result.m_sequence) b = true;

        return result;

    }

    static Static_Binary_Unsigned_Int MakeRand(Static_Binary_Unsigned_Int min = 0, Static_Binary_Unsigned_Int max = Static_Binary_Unsigned_Int::Max()) {

        if (min == max) {
            
            return min;

        } else if (max < min) {

            return 0;

        } else {

            Static_Binary_Unsigned_Int r;

            for (bool &b : r.m_sequence) {
            
                b = std::rand()%2;

            }

            return min+(r%max);

        }

    }

    bool Empty() const { return Bits == 0; }

    bool Full() const {

        for (bool b : m_sequence) {

            if (!b) return false;

        }

        return true;

    }

    bool LSD() const { return m_sequence.back(); }
    bool MSD() const { return m_sequence[0]; }

    constexpr std::size_t BitsCount() { return Bits; }
    constexpr std::size_t BytesCount() { return Bits/8; }

    Static_Binary_Unsigned_Int operator+() { return *this; }
     Static_Binary_Unsigned_Int operator!() { return *this == 0; }

    Static_Binary_Unsigned_Int operator~() {

        Static_Binary_Unsigned_Int temp{*this};
        for (bool &b : temp) b = !b;

        return temp;

    }

    Static_Binary_Unsigned_Int& operator++(int) { return *this += 1; }
    Static_Binary_Unsigned_Int& operator++() { return *this += 1; }

    Static_Binary_Unsigned_Int& operator--(int) { return *this -= 1; }
    Static_Binary_Unsigned_Int& operator--() { return *this -= 1; }

    friend Static_Binary_Unsigned_Int operator+(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) {

        Static_Binary_Unsigned_Int<Bits> result;

        bool carry{false};
        for (std::size_t i{0}; i < Bits; i++) {

            const std::size_t index{Bits-1-i};

            if (l[index] && r[index]) {

                result[index] = carry;
                carry = true;

            } else if (l[index] != r[index]) {

                result[index] = !carry;

            } else if (carry) {

                result[index] = true;
                carry = false;

            }

        }

        return result;

    }

    friend Static_Binary_Unsigned_Int operator-(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) {

        if (l == r) {

            return 0;

        } else {

            Static_Binary_Unsigned_Int<Bits> result;

            bool carry{false};
            for (std::size_t i{0}; i < Bits; i++) {

                const std::size_t index{Bits-1-i};

                if (carry) {

                    if (l[index]) {

                        if (r[index]) {

                            result[index] = true;

                        } else {

                            result[index] = carry = false;

                        }

                    } else {

                        carry = true;
                        result[index] = !r[index];

                    }

                } else {

                    if (l[index] == r[index]) {

                        result[index] = false;

                    } else {

                        if (r[index]) {

                            result[index] = carry = true;

                        } else {

                            result[index] = l[index]-r[index];

                        }

                    }

                }

            }

            return result;

        }

    }

    friend Static_Binary_Unsigned_Int operator*(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) {

        if (r > l) {

            return r*l;

        } else if (r == 0) {

            return 0;
            
        } else if (r == 1) {

            return l;

        } else {

            if (IsPair(r)) {

                Static_Binary_Unsigned_Int<Bits> divide{l*(r/2)};
                return divide+divide;

            } else {

                return l*(r-1)+l;

            }

        }

    }

    friend Static_Binary_Unsigned_Int operator/(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) {

        assert(r != 0);

        Static_Binary_Unsigned_Int<Bits> count{0}, temp{l};
        while (temp >= r) {
            
            temp -= r;
            count++;

        }

        return count;

    }

    friend Static_Binary_Unsigned_Int operator%(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) {

        if (l < r) {

            return l;

        } else if (l == r) {

            return 0;

        } else {

            return l-l/r*r;

        }
        
    }

    friend Static_Binary_Unsigned_Int operator&(const Static_Binary_Unsigned_Int &n, std::size_t) {

        return n;

    }

    friend Static_Binary_Unsigned_Int operator|(const Static_Binary_Unsigned_Int &n, std::size_t) {

        return n;

    }

    friend Static_Binary_Unsigned_Int operator^(const Static_Binary_Unsigned_Int &n, std::size_t) {

        return n;

    }

    Static_Binary_Unsigned_Int& operator>>(std::size_t shift) {

        Static_Binary_Unsigned_Int copy;

        if (shift < Bits) {

            for (std::size_t i{shift}; i < Bits; i++) {

                copy.m_sequence[i] = m_sequence[i-shift];

            }

        }

        *this = copy;
        return *this;

    }

    Static_Binary_Unsigned_Int& operator<<(std::size_t shift) {

        Static_Binary_Unsigned_Int copy;

        if (shift < Bits) {

            for (std::size_t i{shift}; i < Bits; i++) {

                const std::size_t index{Bits-1-i};
                copy.m_sequence[index] = m_sequence[index+shift];

            }

        }

        *this = copy;
        return *this;

    }

    Static_Binary_Unsigned_Int& operator+=(const Static_Binary_Unsigned_Int &n) { return *this = *this+n; }
    Static_Binary_Unsigned_Int& operator-=(const Static_Binary_Unsigned_Int &n) { return *this = *this-n; }
    Static_Binary_Unsigned_Int& operator*=(const Static_Binary_Unsigned_Int &n) { return *this = *this*n; }
    Static_Binary_Unsigned_Int& operator/=(const Static_Binary_Unsigned_Int &n) { return *this = *this/n; }
    Static_Binary_Unsigned_Int& operator%=(const Static_Binary_Unsigned_Int &n) { return *this = *this%n; }

    friend bool operator==(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) { return l.m_sequence == r.m_sequence; }
    friend bool operator!=(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) { return !(l == r); }

    friend bool operator<(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) {

        if (l == r) {

            return false;

        } else if (l == 0 && r != l) {

            return true;

        } else {

            for (std::size_t i{0}; i < Bits; i++) {

                if (l[i] < r[i]) {

                    return true;

                } else if (l[i] > r[i]) {

                    return false;

                }

            }

        }

    }

    friend bool operator<=(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) { return l < r || l == r; }

    friend bool operator>(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) { return !(l <= r); }
    friend bool operator>=(const Static_Binary_Unsigned_Int &l, const Static_Binary_Unsigned_Int &r) { return !(l < r); }

    bool operator[](std::size_t index) const { return m_sequence[index]; }
    bool& operator[](std::size_t index) { return m_sequence[index]; }

    template <std::size_t Base = __CHAR_BIT__> friend constexpr std::size_t MemorySize(const Static_Binary_Unsigned_Int &n) {

        return Bits*8/Base;
        
    }

    friend bool IsPair(const Static_Binary_Unsigned_Int &n) { return !n.LSD(); }

    friend std::string Sequence(const Static_Binary_Unsigned_Int &n) {

        std::string result;
        for (bool b : n.m_sequence) {

            result.push_back('0'+b);

        }

        return result;

    }

    friend std::string ToString(Static_Binary_Unsigned_Int n) {

        return ConvertBinaryBaseTo(Sequence(n), 10);

    }

    friend std::uintmax_t ToULL(const Static_Binary_Unsigned_Int &n) {

        std::uintmax_t result{0};
        for (std::size_t i{0}; i < n.m_sequence.size(); i++) {
            
            if (n.m_sequence[Bits-1-i]) result += std::pow(2, i);

        }

        return result;

    }

    friend Static_Binary_Unsigned_Int Pow(const Static_Binary_Unsigned_Int &n, const Static_Binary_Unsigned_Int &p) {

        if (p == 0) {

            return 1;

        } else if (p == 1) {

            return n;

        } else if (p%2) {

            return Pow(n, p-1)*n;

        } else {

            Static_Binary_Unsigned_Int temp{Pow(n, p/2)};
            return temp*temp;

        }

    }

    friend Static_Binary_Unsigned_Int CA1(const Static_Binary_Unsigned_Int &n) { return ~n; }
    friend Static_Binary_Unsigned_Int CA2(const Static_Binary_Unsigned_Int &n) { return ~n+1; }
    template<std::size_t Base> friend Static_Binary_Unsigned_Int CA(const Static_Binary_Unsigned_Int &n) { return CA1(n)+(Base-1); }

    Static_Binary_Unsigned_Int& operator=(const Static_Binary_Unsigned_Int&) = default;
    Static_Binary_Unsigned_Int& operator=(Static_Binary_Unsigned_Int&&) noexcept = default;

    operator std::uintmax_t() { return ToULL(*this); }
    operator bool() { return *this != 0; }

    friend std::ostream& operator<<(std::ostream &flux, const Static_Binary_Unsigned_Int &n) {

        flux << ToString(n);
        return flux;

    }

    private:

    std::array<bool, Bits> m_sequence;

};

template <std::size_t Bits> class Static_Binary_Signed_Int {

    public:

    private:

};

class Dynamic_Binary_Unsigned_Int {

    public:

    Dynamic_Binary_Unsigned_Int();

    Dynamic_Binary_Unsigned_Int(const Dynamic_Binary_Unsigned_Int&) = default;
    Dynamic_Binary_Unsigned_Int(Dynamic_Binary_Unsigned_Int&&) noexcept = default;

    ~Dynamic_Binary_Unsigned_Int() = default;

    Dynamic_Binary_Unsigned_Int& operator=(const Dynamic_Binary_Unsigned_Int&) = default;
    Dynamic_Binary_Unsigned_Int& operator=(Dynamic_Binary_Unsigned_Int&&) noexcept = default;

    private:

};

class Dynamic_Binary_Signed_Int {

    public:

    Dynamic_Binary_Signed_Int();

    Dynamic_Binary_Signed_Int(const Dynamic_Binary_Signed_Int&) = default;
    Dynamic_Binary_Signed_Int(Dynamic_Binary_Signed_Int&&) noexcept = default;

    explicit Dynamic_Binary_Signed_Int(bool);
    Dynamic_Binary_Signed_Int(std::intmax_t);
    explicit Dynamic_Binary_Signed_Int(const std::string&);

    ~Dynamic_Binary_Signed_Int() = default;

    static Dynamic_Binary_Signed_Int Min();
    static Dynamic_Binary_Signed_Int Max();

    bool Empty() const;
    bool Full() const;
    bool LSD() const;
    bool MSD() const;

    std::size_t BitsCount() const;
    std::size_t BytesCount() const;

    Dynamic_Binary_Signed_Int operator+() const;
    Dynamic_Binary_Signed_Int operator-() const;
    Dynamic_Binary_Signed_Int operator~() const;

    Dynamic_Binary_Signed_Int& operator++(int);
    Dynamic_Binary_Signed_Int& operator++();

    Dynamic_Binary_Signed_Int& operator--(int);
    Dynamic_Binary_Signed_Int& operator--();

    friend Dynamic_Binary_Signed_Int operator+(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator-(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator*(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator/(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator%(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator&(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator|(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator^(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator>>(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int operator<<(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);

    Dynamic_Binary_Signed_Int& operator+=(const Dynamic_Binary_Signed_Int&);
    Dynamic_Binary_Signed_Int& operator-=(const Dynamic_Binary_Signed_Int&);
    Dynamic_Binary_Signed_Int& operator*=(const Dynamic_Binary_Signed_Int&);
    Dynamic_Binary_Signed_Int& operator/=(const Dynamic_Binary_Signed_Int&);
    Dynamic_Binary_Signed_Int& operator%=(const Dynamic_Binary_Signed_Int&);

    friend bool operator==(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend bool operator!=(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);

    friend bool operator<(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend bool operator<=(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);

    friend bool operator>(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);
    friend bool operator>=(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);

    bool operator[](std::size_t) const;
    std::vector<bool>::reference operator[](std::size_t);

    friend bool IsPair(const Dynamic_Binary_Signed_Int&);
    friend std::string ToString(const Dynamic_Binary_Signed_Int&);

    friend std::string Sequence(const Dynamic_Binary_Signed_Int&);

    friend Dynamic_Binary_Signed_Int Abs(const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int Pow(const Dynamic_Binary_Signed_Int&, const Dynamic_Binary_Signed_Int&);

    friend Dynamic_Binary_Signed_Int CA1(const Dynamic_Binary_Signed_Int&);
    friend Dynamic_Binary_Signed_Int CA2(const Dynamic_Binary_Signed_Int&);
    template<std::size_t Base> friend Dynamic_Binary_Signed_Int CA(const Dynamic_Binary_Signed_Int &n) { return CA1(n)+(Base-1); }

    Dynamic_Binary_Signed_Int& operator=(const Dynamic_Binary_Signed_Int&) = default;
    Dynamic_Binary_Signed_Int& operator=(Dynamic_Binary_Signed_Int&&) noexcept = default;

    friend std::ostream& operator<<(std::ostream&, const Dynamic_Binary_Signed_Int&);

    private:

    bool m_sign;
    std::vector<bool> m_sequence;

};

template <std::size_t Digits> class Static_Octal_Unsigned_Int {

    public:

    private:

};

template <std::size_t Digits> class Static_Octal_Signed_Int {

    public:

    private:

};

class Dynamic_Octal_Unsigned_Int {

    public:

    private:

};

class Dynamic_Octal_Signed_Int {

    public:

    private:

};

template <std::size_t Digits> class Static_Decimal_Unsigned_Int {

    public:

    private:

};

template <std::size_t Digits> class Static_Decimal_Signed_Int {

    public:

    private:

};

class Dynamic_Decimal_Unsigned_Int {

    public:

    Dynamic_Decimal_Unsigned_Int();

    Dynamic_Decimal_Unsigned_Int(const Dynamic_Decimal_Unsigned_Int&) = default;
    Dynamic_Decimal_Unsigned_Int(Dynamic_Decimal_Unsigned_Int&&) noexcept = default;

    ~Dynamic_Decimal_Unsigned_Int() = default;

    Dynamic_Decimal_Unsigned_Int& operator=(const Dynamic_Decimal_Unsigned_Int&) = default;
    Dynamic_Decimal_Unsigned_Int& operator=(Dynamic_Decimal_Unsigned_Int&&) noexcept = default;

    private:

};

class Dynamic_Decimal_Signed_Int {

    public:

    Dynamic_Decimal_Signed_Int();

    Dynamic_Decimal_Signed_Int(const Dynamic_Decimal_Signed_Int&) = default;
    Dynamic_Decimal_Signed_Int(Dynamic_Decimal_Signed_Int&&) noexcept = default;

    Dynamic_Decimal_Signed_Int(const std::string&);

    Dynamic_Decimal_Signed_Int(std::intmax_t);

    ~Dynamic_Decimal_Signed_Int() = default;

    static Dynamic_Decimal_Signed_Int Min();
    static Dynamic_Decimal_Signed_Int Max();

    Dynamic_Decimal_Signed_Int operator+();
    Dynamic_Decimal_Signed_Int operator-();

    Dynamic_Decimal_Signed_Int& operator++(int);
    Dynamic_Decimal_Signed_Int& operator++();

    Dynamic_Decimal_Signed_Int& operator--(int);
    Dynamic_Decimal_Signed_Int& operator--();

    friend Dynamic_Decimal_Signed_Int operator+(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);
    friend Dynamic_Decimal_Signed_Int operator-(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);
    friend Dynamic_Decimal_Signed_Int operator*(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);
    friend Dynamic_Decimal_Signed_Int operator/(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);
    friend Dynamic_Decimal_Signed_Int operator%(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);

    Dynamic_Decimal_Signed_Int& operator+=(const Dynamic_Decimal_Signed_Int&);
    Dynamic_Decimal_Signed_Int& operator-=(const Dynamic_Decimal_Signed_Int&);
    Dynamic_Decimal_Signed_Int& operator*=(const Dynamic_Decimal_Signed_Int&);
    Dynamic_Decimal_Signed_Int& operator/=(const Dynamic_Decimal_Signed_Int&);
    Dynamic_Decimal_Signed_Int& operator%=(const Dynamic_Decimal_Signed_Int&);

    friend bool operator==(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);
    friend bool operator!=(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);

    friend bool operator<(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);
    friend bool operator<=(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);

    friend bool operator>(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);
    friend bool operator>=(const Dynamic_Decimal_Signed_Int&, const Dynamic_Decimal_Signed_Int&);

    friend bool IsPair(const Dynamic_Decimal_Signed_Int&);
    friend std::string ToString(const Dynamic_Decimal_Signed_Int&);

    friend Dynamic_Decimal_Signed_Int Abs(const Dynamic_Decimal_Signed_Int&);
    friend Dynamic_Decimal_Signed_Int Pow(Dynamic_Decimal_Signed_Int, const Dynamic_Decimal_Signed_Int&);

    Dynamic_Decimal_Signed_Int& operator=(const Dynamic_Decimal_Signed_Int&) = default;
    Dynamic_Decimal_Signed_Int& operator=(Dynamic_Decimal_Signed_Int&&) noexcept = default;

    operator std::string();

    friend std::ostream& operator<<(std::ostream&, const Dynamic_Decimal_Signed_Int&);

    private:

    bool m_sign;
    std::string m_value;

};

template <std::size_t Digits> class Static_Hexadecimal_Unsigned_Int {

    public:

    private:

};

template <std::size_t Digits> class Static_Hexadecimal_Signed_Int {

    public:

    private:

};

class Dynamic_Hexadecimal_Unsigned_Int {

    public:

    private:

};

class Dynamic_Hexadecimal_Signed_Int {

    public:

    private:

};

template <std::size_t Base, std::size_t Digits> class Static_Custom_Base_Unsigned_Int {

    public:

    private:

};

template <std::size_t Base, std::size_t Digits> class Static_Custom_Base_Signed_Int {

    public:

    private:

};

template <std::size_t Base = 2> class Dynamic_Custom_Base_Unsigned_Int {

    public:

    private:

};

template <std::size_t Base = 2> class Dynamic_Custom_Base_Signed_Int {

    public:

    private:

};

std::vector<bool> CA1(std::vector<bool>);
std::vector<bool> CA2(std::vector<bool>);
// template <std::size_t Base> std::vector<bool> CA(const std::vector<bool> &v) { return CA1(v)+Base; }

template <std::size_t Bits> using B_Static_SInt = Static_Binary_Signed_Int<Bits>;
template <std::size_t Bits> using B_Static_UInt = Static_Binary_Unsigned_Int<Bits>;

using B_Dynamic_SInt = Dynamic_Binary_Signed_Int;
using B_Dynamic_UInt = Dynamic_Binary_Unsigned_Int;

template <std::size_t Digits> using O_Static_SInt = Static_Octal_Signed_Int<Digits>;
template <std::size_t Digits> using O_Static_UInt = Static_Octal_Unsigned_Int<Digits>;

using O_Dynamic_SInt = Dynamic_Octal_Signed_Int;
using O_Dynamic_UInt = Dynamic_Octal_Unsigned_Int;

template <std::size_t Digits> using D_Static_SInt = Static_Decimal_Signed_Int<Digits>;
template <std::size_t Digits> using D_Static_UInt = Static_Decimal_Unsigned_Int<Digits>;

using D_Dynamic_SInt = Dynamic_Decimal_Signed_Int;
using D_Dynamic_UInt = Dynamic_Decimal_Unsigned_Int;

template <std::size_t Digits> using H_Static_SInt = Static_Hexadecimal_Signed_Int<Digits>;
template <std::size_t Digits> using H_Static_UInt = Static_Hexadecimal_Unsigned_Int<Digits>;

using H_Dynamic_SInt = Dynamic_Hexadecimal_Unsigned_Int;
using H_Dynamic_UInt = Dynamic_Hexadecimal_Signed_Int;

template <std::size_t Base, std::size_t Digits> using Custom_Static_SInt = Static_Custom_Base_Signed_Int<Base, Digits>;
template <std::size_t Base, std::size_t Digits> using Custom_Static_UInt = Static_Custom_Base_Unsigned_Int<Base, Digits>;

template <std::size_t Base> using Custom_Dynamic_SInt = Dynamic_Custom_Base_Signed_Int<Base>;
template <std::size_t Base> using Custom_Dynamic_UInt = Dynamic_Custom_Base_Unsigned_Int<Base>;

#endif // DEF_INT_HPP