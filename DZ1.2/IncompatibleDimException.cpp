#include "IncompatibleDimException.h"

IncompatibleDimException::IncompatibleDimException() : m_err("\nerror! size is higher than max possible!\n") {};

const char* IncompatibleDimException::what() const noexcept {
	return m_err.c_str();
}