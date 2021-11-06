#ifndef DEF_FLOAT_HPP
#define DEF_FLOAT_HPP

#include "./Int.hpp"

class Static_IEEE754_Binary16_Float {

    public:

    Static_IEEE754_Binary16_Float();

    Static_IEEE754_Binary16_Float(float);

    Static_IEEE754_Binary16_Float(const Static_IEEE754_Binary16_Float&) = default;
    Static_IEEE754_Binary16_Float(Static_IEEE754_Binary16_Float&&) = default;

    ~Static_IEEE754_Binary16_Float() = default;

    static Static_IEEE754_Binary16_Float PositifInfinity() {

        Static_IEEE754_Binary16_Float inf;
        // inf.m_exponent = Static_Binary_Signed_Int<5>::Min();

        return inf;

    }

    static Static_IEEE754_Binary16_Float NegatifInfinity() { return -PositifInfinity(); }

    static Static_IEEE754_Binary16_Float Max() {

        Static_IEEE754_Binary16_Float m;

        // m.m_exponent = Static_Binary_Signed_Int<5>::Max()-1;
        m.m_mantissa = Static_Binary_Unsigned_Int<11>::Max();

        return m;

    }

    static Static_IEEE754_Binary16_Float Min() { return -Max(); }

    static Static_IEEE754_Binary16_Float AbsMinNormalized() {

        Static_IEEE754_Binary16_Float m;
        // m.m_exponent = Static_Binary_Signed_Int<5>::Min()+1;

        return m;

    }

    static Static_IEEE754_Binary16_Float AbsMinDenormalized() {

        Static_IEEE754_Binary16_Float m;

        // m.m_exponent = Static_Binary_Signed_Int<5>::Min();
        m.m_mantissa = 1;

        return m;

    }

    static Static_IEEE754_Binary16_Float Pi();
    static Static_IEEE754_Binary16_Float Exp();
    static Static_IEEE754_Binary16_Float Phi();

    static Static_IEEE754_Binary16_Float MakeRand(const Static_IEEE754_Binary16_Float& = 0, const Static_IEEE754_Binary16_Float& = Max());

    bool IsNormalized() const;
    bool IsDenormalized() const;

    bool IsInfinity() const;
    bool IsInfinityWithSign(bool) const;

    bool GetSign() const;
    Static_Binary_Signed_Int<5> GetExponent() const;
    Static_Binary_Signed_Int<11> GetMantissa() const;

    Static_IEEE754_Binary16_Float Suc();
    Static_IEEE754_Binary16_Float Pred();

    friend int Sgn(const Static_IEEE754_Binary16_Float&);

    friend Static_IEEE754_Binary16_Float Abs(const Static_IEEE754_Binary16_Float&);

    friend Static_IEEE754_Binary16_Float Square(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Cube(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Pow(const Static_IEEE754_Binary16_Float&, std::size_t);
    
    friend Static_IEEE754_Binary16_Float Cos(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Sin(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Tan(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Csc(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Sec(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Cot(const Static_IEEE754_Binary16_Float&);

    friend Static_IEEE754_Binary16_Float CosInverse(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float SinInverse(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float TanInverse(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float CscIverse(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float SecInverse(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float CotInverse(const Static_IEEE754_Binary16_Float&);

    friend Static_IEEE754_Binary16_Float Cosh(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Sinh(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Tanh(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Csch(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Sech(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Coth(const Static_IEEE754_Binary16_Float&);

    friend Static_IEEE754_Binary16_Float Sqrt(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float CubeRoot(const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float Root(const Static_IEEE754_Binary16_Float&);

    friend std::string ToString(const Static_IEEE754_Binary16_Float&);
    friend float ToFloat(const Static_IEEE754_Binary16_Float&);

    template <std::size_t Base = 2> friend Static_IEEE754_Binary16_Float Log(const Static_IEEE754_Binary16_Float&) {



    }

    Static_IEEE754_Binary16_Float operator+();
    Static_IEEE754_Binary16_Float operator-();

    bool operator!();

    Static_IEEE754_Binary16_Float& operator++();
    Static_IEEE754_Binary16_Float& operator--();

    Static_IEEE754_Binary16_Float& operator++(int);
    Static_IEEE754_Binary16_Float& operator--(int);

    friend Static_IEEE754_Binary16_Float operator+(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float operator-(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float operator*(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float operator/(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);
    friend Static_IEEE754_Binary16_Float operator%(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);

    Static_IEEE754_Binary16_Float& operator+=(const Static_IEEE754_Binary16_Float&);
    Static_IEEE754_Binary16_Float& operator-=(const Static_IEEE754_Binary16_Float&);
    Static_IEEE754_Binary16_Float& operator*=(const Static_IEEE754_Binary16_Float&);
    Static_IEEE754_Binary16_Float& operator/=(const Static_IEEE754_Binary16_Float&);
    Static_IEEE754_Binary16_Float& operator%=(const Static_IEEE754_Binary16_Float&);
    
    friend bool operator==(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);
    friend bool operator!=(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);

    friend bool operator<(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);
    friend bool operator<=(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);

    friend bool operator>(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);
    friend bool operator>=(const Static_IEEE754_Binary16_Float&, const Static_IEEE754_Binary16_Float&);

    Static_IEEE754_Binary16_Float& operator=(const Static_IEEE754_Binary16_Float&) = default;
    Static_IEEE754_Binary16_Float& operator=(Static_IEEE754_Binary16_Float&&) = default;

    friend std::ostream& operator<<(std::ostream&, const Static_IEEE754_Binary16_Float&);
    friend std::istream operator>>(std::istream&, const Static_IEEE754_Binary16_Float);

    operator float();
    operator bool();

    private:

    bool m_sign;

    Static_Binary_Signed_Int<5> m_exponent;
    Static_Binary_Unsigned_Int<10> m_mantissa;

};

class Static_IEEE754_Binary32_Float {

    public:

    private:

    bool m_sign;

    Static_Binary_Signed_Int<8> m_exponent;
    Static_Binary_Unsigned_Int<23> m_mantissa;

};

class Static_IEEE754_Extend_Binary44_Float {

    public:

    private:

    bool m_sign;

    Static_Binary_Signed_Int<11> m_exponent;
    Static_Binary_Unsigned_Int<32> m_mantissa;

};

class Static_IEEE754_Binary64_Float {

    public:

    private:

    bool m_sign;

    Static_Binary_Signed_Int<11> m_exponent;
    Static_Binary_Unsigned_Int<52> m_mantissa;

};

class Static_IEEE754_Extend_Binary80_Float {

    public:

    private:

    bool m_sign;

    Static_Binary_Signed_Int<15> m_exponent;
    Static_Binary_Unsigned_Int<64> m_mantissa;

};

class Static_IEEE754_Binary128_Float {

    public:

    private:

    bool m_sign;

    Static_Binary_Signed_Int<15> m_exponent;
    Static_Binary_Unsigned_Int<112> m_mantissa;

};

template <bool Signed, std::size_t Exponent_Bits, std::size_t Mantissa_Bits> class Static_Custom_Precision_IEEE_Model_Binary_Float {

    public:

    bool IsSigned() const { return Signed; }
    bool IsUnsigned() const { return !Signed; }

    private:

    bool m_sign;

    Static_Binary_Signed_Int<Exponent_Bits> m_exponent;
    Static_Binary_Unsigned_Int<Mantissa_Bits> m_mantissa;

};

class Static_IEEE754_Decimal32_Float {};

class Static_IEEE754_Decimal64_Float {};

class Static_Binary_Unsigned_Float {};
class Static_Binary_Signed_Float {};

class Dynamic_Binary_Unsigned_Float {};
class Dynamic_Binary_Signed_Float {};

class Static_Octal_Unsigned_Float {};
class Static_Octal_Signed_Float {};

class Dynamic_Octal_Unsigned_Float {};
class Dynamic_Octal_Signed_Float {};

class Static_Decimal_Unsigned_Float {};
class Static_Decimal_Signed_Float {};

class Dynamic_Decimal_Unsigned_Float {};
class Dynamic_Decimal_Signed_Float {};

class Static_Hexadecimal_Unsigned_Float {};
class Static_Hexadecimal_Signed_Float {};

class Dynamic_Hexadecimal_Unsigned_Float {};
class Dynamic_Hexadecimal_Signed_Float {};

class Static_Custom_Base_Unsigned_Float {};
class Static_Custom_Base_Signed_Float {};

class Dynamic_Custom_Base_Unsigned_Float {};
class Dynamic_Custom_Base_Signed_Float {};

using Binary16 = Static_IEEE754_Binary16_Float;
using Binary32 = Static_IEEE754_Binary32_Float;
using Binary44 = Static_IEEE754_Binary44_Float;
using Binary64 = Static_IEEE754_Binary64_Float;
using Binary80 = Static_IEEE754_Binary80_Float;
using Binary128 = Static_IEEE754_Binary128_Float;

#endif // DEF_FLOAT_HPP