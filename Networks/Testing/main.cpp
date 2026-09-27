#include <iostream>

using namespace std;

class A {
public:
    void f() {
        cout << "Hello";
    };
};


class b : public A {
public:
    void f() {
        cout << "Test";
    }
};

int main() {
    b test;
    test.f();
    return 0;
}
