//Mustafa Mannan U60366528


#ifndef NOTATION_CONVERTER_HPP
#define NOTATION_CONVERTER_HPP
#include "deque.hpp"

#include <string>
#include "NotationConverterInterface.hpp"


class NotationConverter : public NotationConverterInterface {
public:
    Deque deque;

    bool isOperator(char c) const;
    int getPrecedence(char c) const;

    // Conversion methods with some modifications in parameters and return types
    std::string postfixToInfix(std::string postfix);
    std::string postfixToPrefix(std::string postfix);
    std::string infixToPostfix(std::string infix);
    std::string infixToPrefix(std::string infix);
    std::string prefixToInfix(std::string prefix);
    std::string prefixToPostfix(std::string prefix);
    

    
    bool isOperand(char character);
    int getPrecedence(char c);
    void reverseString(std::string& str);


private:
    bool isValidInfix(const std::string& inStr);
    bool isValidPrefix(const std::string& inStr);
};

#endif  // NOTATION_CONVERTER_HPP
