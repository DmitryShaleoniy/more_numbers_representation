#ifndef ZERODEVIDEEXEPTION_H
#define ZERODEVIDEEXEPTION_H

#include <iostream>
#include <exception>

using namespace std;
class ZeroDivideException : exception {
    string m_err;
public:
    ZeroDivideException();

    const char* what() const noexcept override;
};
#endif