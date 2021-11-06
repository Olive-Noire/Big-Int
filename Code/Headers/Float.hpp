#ifndef DEF_FLOAT_HPP
#define DEF_FLOAT_HPP

#include "./Int.hpp"

class Static_IEEE754_Binary16_Float {

    public:

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

#endif // DEF_FLOAT_HPP