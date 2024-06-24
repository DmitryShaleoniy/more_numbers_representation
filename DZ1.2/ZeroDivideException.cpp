#include "ZeroDivideException.h"

ZeroDivideException::ZeroDivideException() : m_err("\nError: division by 0!\n") {}

const char* ZeroDivideException::what() const noexcept {
    return m_err.c_str();
}