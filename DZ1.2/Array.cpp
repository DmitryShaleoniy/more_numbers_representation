#include "Array.h"
#include "OutOfRangeException.h"
#include "IncompatibleDimException.h"

Array::Array() :
	m_dimension(0),
	m_char(nullptr)
{}

Array::Array(int p_dim) :
	m_dimension(p_dim)
{
	if (p_dim > max) {
		throw IncompatibleDimException();
	}
	m_char = new unsigned char[100];
	for (int i = 0; i < m_dimension; i++)
		m_char[i] = '0';
	m_char[m_dimension] = '\0';
}

Array::Array(const Array& p_val):
	Array(p_val.m_dimension)
{
	for (int i = 0; i < m_dimension; i++)
		m_char[i] = p_val.m_char[i];
}

Array& Array::operator=(const Array& p_other) {
	if (m_dimension == 0) {
		delete[] m_char;
		m_char = new unsigned char[100];
	}
	m_dimension = p_other.m_dimension;
	for (int i = 0; i < p_other.m_dimension; i++)
		m_char[i] = p_other[i];
	m_char[p_other.m_dimension] = '\0';
	return *this;
}

const unsigned char& Array::operator[](int p_num) const {
	if (p_num > m_dimension) {
		throw OutOfRangeException();
	}
	return m_char[p_num];
}

unsigned char& Array::operator[](int p_num) {
	if (p_num > m_dimension) {
		throw OutOfRangeException();
	}
	return m_char[p_num];
}

int Array::get_dim() const {
	return m_dimension;
}

void Array::set_dim(int p_val) {
	if (m_dimension != p_val) {
		if (m_dimension == 0) {
			delete[] m_char;
			m_char = new unsigned char[100];
		}
		for (int i = m_dimension; i < p_val; i ++)
			m_char[i] = '0';
		m_char[p_val] = '\0';
		m_dimension = p_val;
	}
}

/*Array Array::operator+(const Array& p_ar) const {

	Array result(m_dimension);
	for (int i = 0; i < m_dimension; i++) {
		result.m_char[i] = m_char[i] + p_ar.m_char[i];
	}
	return result;
}*/

bool Array::sum(const Array* p_other, Array* o_result) const {
	if (m_dimension != p_other->m_dimension)
		throw OutOfRangeException();
	if (o_result->m_dimension != m_dimension) {
		delete[] o_result->m_char;
		o_result->m_dimension = m_dimension;
		o_result->m_char = new unsigned char[o_result->m_dimension];
	}
	for (int i = 0; i < o_result->m_dimension; i++) {
		o_result->m_char[i] = m_char[i];
	}
}

Array::~Array() {
	delete[] m_char;
}