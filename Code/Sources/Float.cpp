#include "../Headers/Float.hpp"

Static_IEEE754_Binary16_Float::Static_IEEE754_Binary16_Float() {

    

}

Static_IEEE754_Binary16_Float::Static_IEEE754_Binary16_Float(float x) {



}

Static_IEEE754_Binary16_Float Static_IEEE754_Binary16_Float::MakeRand(const Static_IEEE754_Binary16_Float &min, const Static_IEEE754_Binary16_Float &max) {

    

}

bool Static_IEEE754_Binary16_Float::IsNormalized() const {



}

bool Static_IEEE754_Binary16_Float::IsDenormalized() const {



}

bool Static_IEEE754_Binary16_Float::IsInfinity() const {



}

bool Static_IEEE754_Binary16_Float::IsInfinityWithSign(bool s) const {



}

bool Static_IEEE754_Binary16_Float::GetSign() const {



}

Static_Binary_Signed_Int<5> Static_IEEE754_Binary16_Float::GetExponent() const {



}

Static_Binary_Signed_Int<11> Static_IEEE754_Binary16_Float::GetMantissa() const {



}

Static_IEEE754_Binary16_Float Static_IEEE754_Binary16_Float::Suc() {



}

Static_IEEE754_Binary16_Float Static_IEEE754_Binary16_Float::Pred() {



}

int Sgn(const Static_IEEE754_Binary16_Float &x) {

    if (x < 0) {

        return -1;

    } else if (x == 0) {

        return 0;

    } else {

        return 1;

    }

}

Static_IEEE754_Binary16_Float Abs(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Square(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Cube(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Pow(const Static_IEEE754_Binary16_Float &x, std::size_t p) {



}
    
Static_IEEE754_Binary16_Float Cos(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Sin(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Tan(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Csc(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Sec(const Static_IEEE754_Binary16_Float &x) {

    

}

Static_IEEE754_Binary16_Float Cot(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float CosInverse(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float SinInverse(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float TanInverse(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float CscIverse(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float SecInverse(const Static_IEEE754_Binary16_Float &x) {

    

}

Static_IEEE754_Binary16_Float CotInverse(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Cosh(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Sinh(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Tanh(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Csch(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Sech(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Coth(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Sqrt(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float CubeRoot(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float Root(const Static_IEEE754_Binary16_Float &x) {



}

std::string ToString(const Static_IEEE754_Binary16_Float &x) {



}

float ToFloat(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float operator+() {



}

Static_IEEE754_Binary16_Float operator-() {



}

bool operator!() {



}

Static_IEEE754_Binary16_Float& operator++() {



}

Static_IEEE754_Binary16_Float& operator--() {



}

Static_IEEE754_Binary16_Float& operator++(int) {



}

Static_IEEE754_Binary16_Float& operator--(int) {



}

Static_IEEE754_Binary16_Float operator+(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

Static_IEEE754_Binary16_Float operator-(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

Static_IEEE754_Binary16_Float operator*(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

Static_IEEE754_Binary16_Float operator/(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

Static_IEEE754_Binary16_Float operator%(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

Static_IEEE754_Binary16_Float& operator+=(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float& operator-=(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float& operator*=(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float& operator/=(const Static_IEEE754_Binary16_Float &x) {



}

Static_IEEE754_Binary16_Float& operator%=(const Static_IEEE754_Binary16_Float &x) {



}
    
bool operator==(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

bool operator!=(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

bool operator<(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

bool operator<=(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

bool operator>(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {

    

}

bool operator>=(const Static_IEEE754_Binary16_Float &l, const Static_IEEE754_Binary16_Float &r) {



}

friend std::ostream& operator<<(std::ostream &flux, const Static_IEEE754_Binary16_Float &x) {



}

friend std::istream operator>>(std::istream &flux, const Static_IEEE754_Binary16_Float x) {



}

Static_IEEE754_Binary16_Float::operator std::string() {



}

Static_IEEE754_Binary16_Float::operator float() {



}

Static_IEEE754_Binary16_Float::operator bool() {



}