// Copyright 2025 NNTU-CS
#include <string>
#include <sstream>
#include <cctype>
#include "tstack.h"
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;  
}
std::string infx2pstfx(const std::string& inf) {
    std::stringstream postfix;
    TStack<char, 100> stack;
    for (size_t i = 0; i < inf.size(); ++i) {
        char c = inf[i];

        if (c == ' ') continue;
        if (isdigit(c)) {
            while (i < inf.size() && isdigit(inf[i])) {
                postfix << inf[i++];
            }
            postfix << ' ';
            --i; i
        } else if (c == '(') {
            stack.Push(c);
        } else if (c == ')') {
            while (!stack.IsEmpty() && stack.Top() != '(') {
                postfix << stack.Pop() << ' ';
            }
            stack.Pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.IsEmpty() && getPriority(stack.Top()) >= getPriority(c)) {
                postfix << stack.Pop() << ' ';
            }
            stack.Push(c);
        }
    }
    while (!stack.IsEmpty()) {
        postfix << stack.Pop() << ' ';
    }
    
    std::string result = postfix.str();
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}
int eval(const std::string& post) {
    TStack<int, 100> stack;
    std::istringstream iss(post);
    std::string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.Push(std::stoi(token));
        } else {
            int b = stack.Pop();
            int a = stack.Pop();
            switch (token[0]) {
                case '+': stack.Push(a + b); break;
                case '-': stack.Push(a - b); break;
                case '*': stack.Push(a * b); break;
                case '/': stack.Push(a / b); break;
            }
        }
    } 
    return stack.Pop();
}
