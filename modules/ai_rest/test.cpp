#include<iostream>

class Base {
protected:
    int protectedValue;

public:
    Base(int value) : protectedValue(value) {}
};

class Derived : public Base {
public:
    Derived(int value) : Base(value) {}

    void showValue() {
        // Accessing protected member from the base class
        std::cout << "Protected Value: " << protectedValue << std::endl;
    }
};

int main() {
    Derived obj(42);
    obj.showValue();

    // Error: 'protectedValue' is a protected member of 'Base'
    //std::cout << obj.protectedValue << std::endl;

    return 0;
}
