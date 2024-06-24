#include "BitString.h"
#include "IncompatibleDimException.h"
#include <iostream>

int BitString::count = 0;

BitString::BitString() : Array()
{
	count++;
}

BitString::BitString(int p_dim) : Array(p_dim) {
	count++;
}

BitString::BitString(const Array& p_ini) :
	Array(p_ini)
{
	count++;
}

BitString::BitString(int p_dim, int p_num): Array(p_dim) {
	char* buffer = new char[p_dim + 1];
	buffer[p_dim] = '\0';
	itoa(p_num, buffer, 2);
	for (int j = 0; j < p_dim; j++) {
		(*this)[j] = buffer[p_dim - 1 - j];
	}
	delete[] buffer;
	count++;
}


bool BitString::sum(const Array* p_other, Array* o_result) const {
	char result[99];
	int i = 0, j = 0, ost = 0, num;
	char ch[1];
	while ((*this)[i] != '\0' || (*p_other)[j] != '\0') {
		num = ost;
		if ((*this)[i] != '\0') {
			ch[0] = (*this)[i];
			num += atoi(ch);
			i++;
		}
		if ((*p_other)[j] != '\0') {
			ch[0] = (*p_other)[j];
			num += atoi(ch);
			j++;
		}
		if (num >= 2) {
			num = num - 2;
			ost = 1;
		}
		else
			ost = 0;
		result[std::max(i, j) - 1] = num + 48;
	}
	if (ost != 0) {
		result[std::max(i, j)] = 49;
		i++;
		j++;
	}
	result[std::max(i, j)] = '\0';
	if (o_result->get_dim() != std::max(i, j)) {
		o_result->set_dim(std::max(i, j));
	}
	for (int g = 0; g < std::max(i, j); g++) {
		(*o_result)[g] = result[g];
	}
	return 1;
}

 /*Array BitString::operator+(const Array& p_ar) const {
	char result[99];
	int i = 0, j = 0, ost = 0, num;
	char ch[1];
	while ((*this)[i] != '\0' || p_ar[j] != '\0') {
		num = ost;
		if ((*this)[i] != '\0') {
			ch[0] = (*this)[i];
			num += atoi(ch);
			i++;
		}
		if (p_ar[j] != '\0') {
			ch[0] = (p_ar)[j];
			num += atoi(ch);
			j++;
		}
		if (num >= 2) {
			num = num - 2;
			ost = 1;
		}
		else
			ost = 0;
		result[std::max(i, j) - 1] = num + 48;
	}
	if (ost != 0) {
		result[std::max(i, j)] = 49;
		i++;
		j++;
	}
	result[std::max(i, j)] = '\0';
	Array res(std::max(i, j));
	for (int g = 0; g < std::max(i, j); g++) {
		res[g] = result[g];
	}
	return res;
 }*/

BitString BitString:: operator and (const BitString& p_ar) const {
	char result[99];
	int op = 0;
	int i = 0;
	while ((*this)[i] != '\0' && p_ar[i] != '\0') {
		if ((*this)[i] == '1' && p_ar[i] == '1')
			op = 1;
		else
			op = 0;
		result[i] = op + 48;
		i++;
	}
	result[i] = '\0';
	BitString res(i);
	for (int g = 0; g < i; g++) {
		res[g] = result[g];
	}
	return res;
}

BitString BitString:: operator xor (const BitString& p_ar) const {
	char result[99];
	int num1 = 0;
	int num2 = 0;
	int op = 0;
	int i = 0;
	int j = 0;
	while ((*this)[i] != '\0' || p_ar[j] != '\0') {
		num1 = 0;
		num2 = 0;
		if ((*this)[i] != '\0') {
			num1 = (*this)[i] - 48;
			i++;
		}
		if (p_ar[j] != '\0') {
			num2 = p_ar[j] - 48;
			j++;
		}
		if (num1 == num2)
			result[std::max(i, j) - 1] = 48;
		else
			result[std::max(i, j) - 1] = 49;
	}
	result[std::max(i, j)] = '\0';
	BitString res(std::max(i, j));
	for (int g = 0; g < std::max(i, j); g++) {
		res[g] = result[g];
	}
	return res;
}

BitString BitString:: operator or (const BitString& p_ar) const {
	char result[99];
	int op = 0;
	int i = 0;
	int j = 0;
	while ((*this)[i] != '\0' || p_ar[j] != '\0') {
		op = 0;
		if ((*this)[i] == '1' || p_ar[j] == '1')
			op = 1;
		result[std::max(i, j)] = op + 48;
		if ((*this)[i] != '\0')
			i++;
		if (p_ar[j] != '\0')
			j++;
	}
	result[std::max(i, j)] = '\0';
	BitString res(std::max(i, j));
	for (int g = 0; g < std::max(i, j); g++) {
		res[g] = result[g];
	}
	return res;
}

BitString BitString::operator not() const {
	char result[99];
	int i = 0;
	while ((*this)[i] != '\0') {
		if ((*this)[i] == '0')
			result[i] = '1';
		else
			result[i] = '0';
		i++;
	}
	while (result[i - 1] == '0') {
		i--;
	}
	result[i] = '\0';
	BitString res(i);
	i = 0;
	while (result[i] != '\0') {
		res[i] = result[i];
		i++;
	}
	return res;
}

BitString BitString:: operator<< (int p_num) const {
	if (p_num + (*this).size() >= 99) {
		throw IncompatibleDimException();
	}
	char result[99];
	for (int i = 0; i < p_num; i++) {
		result[i] = '0';
	}
	int j = 0;
	while ((*this)[j] != '\0') {
		result[j + p_num] = (*this)[j];
		j++;
	}
	result[j + p_num] = '\0';
	BitString res(j + p_num);
	int i = 0;
	while (result[i] != '\0') {
		res[i] = result[i];
		i++;
	}
	return res;
}

BitString BitString:: operator>> (int p_num) const {
	if ((*this).size() - p_num <= 0) {
		return BitString(1, 0);
	}
	char result[99];
	int i = 0;
	while ((*this)[i + p_num] != '\0') {
		result[i] = (*this)[i + p_num];
		i++;
	}
	result[i] = '\0';
	BitString res(i);
	i = 0;
	while (result[i] != '\0') {
		res[i] = result[i];
		i++;
	}
	return res;
}

int BitString::GetInt2() const {
	int num = 0;
	char ch[1];
	for (int i = 0; (*this)[i] != '\0'; i++) {
		ch[0] = (*this)[i];
		num += atoi(ch) * pow(10, i);
	}
	return num;
}

int BitString::GetInt10() const {
	int num1 = 0;
	char ch[1];
	for (int i = 0; (*this)[i] != '\0'; i++) {
		ch[0] = (*this)[i];
		num1 += atoi(ch) * pow(2, i);
	}
	return num1;
}

int BitString::size() const {
	int i = 0;
	for (i; (*this)[i] != '\0'; i++);
	return i - 1;
}

BitString::~BitString() {
	count--;
}