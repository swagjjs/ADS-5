#include <string>
#include <sstream>
#include <cctype>

template <typename T, int SIZE>
class SimpleStack {
    T data[SIZE];
    int topIndex = -1;
public:
    void push(T value) { data[++topIndex] = value; }
    T pop() { return data[topIndex--]; }
    T top() const { return data[topIndex]; }
    bool isEmpty() const { return topIndex == -1; }
};
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
std::string infx2pstfx(const std::string& inf) {
    std::stringstream postfix;
    SimpleStack<char, 100> stack;
}

int eval(const std::string& post) {
    SimpleStack<int, 100> stack;
}
