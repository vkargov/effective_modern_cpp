#import <iostream>
#include <utility>
#import <vector>

template<typename T>
void f1(T&& param) {
    std::cout << sizeof param << '\n';
}

template<typename T>
void f2(std::vector<T>&& param) {
    std::cout << sizeof param << '\n';
}

int main() {
    std::cout << "Hi\n";
    {
        int x = 123;
        f1(x);
        f1(3lu);
    }
    {
        std::vector<int> v = {123};
        f2(std::vector<int>{1, 2, 3});
        // f2(v);
        // Error: No matching function for call to 'f2'clang(ovl_no_viable_function_in_call)
        //        main.cpp(10, 6): Candidate function [with T = int] not viable: expects an rvalue for 1st argument
        // (p.166)
        f2(std::move(v));
    }
}
