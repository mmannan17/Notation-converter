//Mustafa Mannan U60366528

#include "NotationConverter.hpp"
#include <stdexcept>
#include <algorithm>

bool NotationConverter::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int NotationConverter::getPrecedence(char c)  {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Postfix to Infix
std::string NotationConverter::postfixToInfix(std::string inStr) {
    LinkedList stack;
    std::string output;
    std::string op1, op2, op;

    for (char c : inStr) {
        
        if (c == ' ') continue;

        // If character is an operand, push to stack
        if (!isOperator(c)) {
            stack.addBack(std::string(1, c));
        } else {
            
            if (!stack.isEmpty()) {
                op2 = stack.removeBack();
            } else {
                throw std::invalid_argument("Invalid postfix expression.");
            }
            if (!stack.isEmpty()) {
                op1 = stack.removeBack();
            } else {
                throw std::invalid_argument("Invalid postfix expression.");
            }

            
            op = "(" + op1 + " " + c + " " + op2 + ")";
            stack.addBack(op);
        }
    }

    
    if (!stack.isEmpty()) {
        output = stack.removeBack();
    } else {
        throw std::invalid_argument("Invalid postfix expression.");
    }

    if (!stack.isEmpty()) {
        throw std::invalid_argument("Invalid postfix expression.");
    }

    return output;
}

// Postfix to Prefix
std::string NotationConverter::postfixToPrefix(std::string postfix) {
    Deque stack;
    std::string token;

    // Iterate over the postfix expression
    for (char ch : postfix) {
        if (isspace(ch)) {
            
            if (!token.empty()) {
                stack.insertFront(token);
                token.clear();
            }
        } else if (isOperator(ch)) {
            
            if (stack.getSize() < 2) {
                
                throw std::invalid_argument("Invalid postfix expression: incorrect number of operands.");
            }
            // Pop two operands from the stack
            std::string rightOperand = stack.getFront();
            stack.removeFront();
            std::string leftOperand = stack.getFront();
            stack.removeFront();
            
            token = ch + " " + leftOperand + " " + rightOperand;
            stack.insertFront(token);
            token.clear();
        } else {
            
            token += ch;
        }
    }

    
    if (!token.empty()) {
        stack.insertFront(token);
    }

    
    if (stack.getSize() != 1) {
        throw std::invalid_argument("Invalid postfix expression: incorrect number of operands.");
    }

    
    return stack.getFront();
}





std::string NotationConverter::infixToPostfix(std::string inStr) {
    
    LinkedList stack;  // Stack for operators
    std::string output;
    std::string token;

    if (!isValidInfix(inStr)) {
        throw std::invalid_argument("Invalid infix expression.");
    }

    for (char c : inStr) {
        if (c == ' ') continue; 

        if (isOperator(c)) {
            // Pop operators with greater or equal precedence and append them to output
            while (!stack.isEmpty() && getPrecedence(stack.getBack()[0]) >= getPrecedence(c)) {
                output += stack.removeBack() + " ";
            }
            stack.addBack(std::string(1, c)); 
        } else if (c == '(') {
            stack.addBack(std::string(1, c)); 
        } else if (c == ')') {
            
            while (!stack.isEmpty() && stack.getBack()[0] != '(') {
                output += stack.removeBack() + " ";
            }
            if (!stack.isEmpty()) stack.removeBack(); 
        } else {
            output += c + std::string(" "); 
        }
    }

    
    while (!stack.isEmpty()) {
        if (stack.getBack()[0] == '(') {
            throw std::invalid_argument("Invalid infix expression.");
        }
        output += stack.removeBack() + " ";
    }

    return output;
}


std::string NotationConverter::infixToPrefix(std::string inStr) {
    
    std::string reversedInfix;

   
    for (auto it = inStr.rbegin(); it != inStr.rend(); ++it) {
        if (*it == '(') {
            reversedInfix += ')';
        } else if (*it == ')') {
            reversedInfix += '(';
        } else {
            reversedInfix += *it;
        }
    }

    
    std::string postfix = infixToPostfix(reversedInfix);

    
    std::string prefix;
    for (auto it = postfix.rbegin(); it != postfix.rend(); ++it) {
        prefix += *it;
    }

    return prefix;
}


bool NotationConverter::isValidInfix(const std::string& inStr) {
    int balance = 0;
    bool lastWasOperator = true; 

    for (char c : inStr) {
        if (c == ' ') continue; 

        if (c == '(') {
            balance++;
            lastWasOperator = true; 
        } else if (c == ')') {
            balance--;
            if (balance < 0) return false; 
            lastWasOperator = false; 
        } else if (isOperator(c)) {
            if (lastWasOperator) return false; 
            lastWasOperator = true;
        } else if (isalpha(c) || isdigit(c)) {
            lastWasOperator = false; 
        } else {
            return false; 
        }
    }

    
    return balance == 0 && !lastWasOperator;
}



// Prefix to Infix
std::string NotationConverter::prefixToInfix(std::string inStr) {
    LinkedList stack;
    std::string op1, op2, op;

    
    
    for (auto it = inStr.rbegin(); it != inStr.rend(); ++it) {
        if (*it == ' ') continue; 

        if (isOperator(*it)) {
            
            if (stack.isEmpty()) {
                throw std::invalid_argument("Invalid prefix expression: not enough operands.");
            }
            op1 = stack.removeBack();

            if (stack.isEmpty()) {
                throw std::invalid_argument("Invalid prefix expression: not enough operands.");
            }
            op2 = stack.removeBack();

            
            op = "(" + op1 + " " + *it + " " + op2 + ")";
            stack.addBack(op);
        } else {
            
            stack.addBack(std::string(1, *it));
        }
    }

    
    op1 = stack.removeBack();
    if (stack.isEmpty()) {
        return op1;
    } else {
        throw std::invalid_argument("Invalid prefix expression: incorrect number of operands or operators.");
    }
}

std::string NotationConverter::prefixToPostfix(std::string inStr) {
    
    std::string infix = prefixToInfix(inStr);

    
    return infixToPostfix(infix);
}

void NotationConverter::reverseString(std::string& str) {
    std::reverse(str.begin(), str.end());
}

