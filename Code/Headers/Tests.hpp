#ifndef DEF_TESTS_HPP
#define DEF_TESTS_HPP

#include <iosfwd>

#include "./Float.hpp"
#include "./Int.hpp"

template <typename Type> bool PreviousAdd(Type a, Type b, Type result = Type{}) { return a+b == Type{}; }
template <typename Type> bool PreviousSub(Type a, Type b, Type result = Type{}) { return a-b == Type{}; }
template <typename Type> bool PreviousMul(Type a, Type b, Type result = Type{}) { return a*b == Type{}; }
template <typename Type> bool PreviousDiv(Type a, Type b, Type result = Type{}) { return a/b == Type{}; }
template <typename Type> bool PreviousMod(Type a, Type b, Type result = Type{}) { return a%b == Type{}; }

template <typename Type> void ExpressionBySequenceAdd(Type a, Type b) { std::cout << Sequence(a) << " + " << Sequence(b) << " = " << Sequence(a+b); }
template <typename Type> void ExpressionBySequenceSub(Type a, Type b) { std::cout << Sequence(a) << " - " << Sequence(b) << " = " << Sequence(a-b); }
template <typename Type> void ExpressionBySequenceMul(Type a, Type b) { std::cout << Sequence(a) << " * " << Sequence(b) << " = " << Sequence(a*b); }
template <typename Type> void ExpressionBySequenceDiv(Type a, Type b) { std::cout << Sequence(a) << " / " << Sequence(b) << " = " << Sequence(a/b); }
template <typename Type> void ExpressionBySequenceMod(Type a, Type b) { std::cout << Sequence(a) << " % " << Sequence(b) << " = " << Sequence(a%b); }

#endif // DEF_TESTS_HPP