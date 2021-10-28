#ifndef DEF_STRING_OPERATIONS_HPP
#define DEF_STRING_OPERATIONS_HPP

#include <string>

bool IsNumber(const std::string&);
bool StartWith(const std::string&, const std::string&);
bool EndWith(const std::string&, const std::string&);

char UIntToChar(unsigned int);
unsigned int CharToUInt(char);

std::string Upper(const std::string&);
std::string Lower(const std::string&);

std::string LStrip(std::string, char = ' ');
std::string RStrip(std::string, char = ' ');
std::string Strip(std::string, char = ' ');

std::string RemoveChar(const std::string&, char);
std::string RemoveSpaces(const std::string&);

std::string Reverse(const std::string&);

std::string CopyPopFront(const std::string&, std::size_t = 1);
std::string CopyPopBack(const std::string&, std::size_t = 1);

std::string ConvertBinaryBaseTo(std::string, std::size_t);

#endif // DEF_STRING_OPERATIONS