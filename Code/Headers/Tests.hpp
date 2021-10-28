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

/*
D_Dynamic_SInt a{420};
D_Dynamic_SInt b{"48879554321858363547485554545557454555445"};

if (ToString(a+b) != "+48879554321858363547485554545557454555865") std::cout << "Addition non implemente correctement\n";
if (ToString(a-b) != "-48879554321858363547485554545557454555025") std::cout << "Soustraction non implemente correctement\n";
if (ToString(a*b) != "+20529412815180512689943932909134130913286900") std::cout << "Multiplication non implemente correctement\n";
if (ToString(b/a) != "+116379891242519913208298939394184415608") std::cout << "Division non implemente correctement\n";
*/

#endif // DEF_TESTS_HPP