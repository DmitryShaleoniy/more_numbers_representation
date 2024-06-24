#include "Octal.h"
#include "ZeroDivideException.h"
#include <iostream>


int Octal::count = 0;


 Octal::Octal(): Array()
 {
	 count++;
 }

 Octal::Octal(int p_dim): Array(p_dim) 
 {
	 count++;
 }

Octal::Octal(int p_dim, unsigned int p_num): Array(p_dim) {
	char* buffer = new char[p_dim + 1];
	buffer[p_dim] = '\0';
	itoa(p_num, buffer, 8);
	for (int j = 0; j < p_dim; j++) {
		(*this)[j] = buffer[p_dim-1-j];
	}
	delete[] buffer;
	count++;
}

Octal::Octal(const Array& p_ini): 
	Array(p_ini)
{
	count++;
}

bool Octal::sum(const Array* p_other, Array* o_result) const {
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
		if (num >= 8) {
			num = num - 8;
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

 /*Array Octal::operator+(const Array& p_ar) const {
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
		if (num >= 8) {
			num = num - 8;
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

Octal Octal::operator-(const Octal& p_ar) const {
	int res = this->GetInt10() - p_ar.GetInt10();
	char razr[100];
	itoa(res, razr, 8);
	return Octal(strlen(razr), res);
}

Octal Octal::operator*(const Octal& p_ar) const {
	int res = this->GetInt10() * p_ar.GetInt10();
	char razr[100];
	itoa(res, razr, 8);
	return Octal(strlen(razr), res);
}

Octal Octal::operator/(const Octal& p_ar) const {
	if (p_ar.GetInt10() == 0) {
		throw ZeroDivideException();
	}
	int res = this->GetInt10() / p_ar.GetInt10();
	char razr[100];
	itoa(res, razr, 8);
	return Octal(strlen(razr), res);
}

bool Octal:: operator <(const Octal& p_ar) const {
	return (this->GetInt10() < p_ar.GetInt10());
}

bool Octal:: operator <=(const Octal& p_ar) const {
	return (this->GetInt10() <= p_ar.GetInt10());
}

bool Octal:: operator >(const Octal& p_ar) const {
	return (this->GetInt10() > p_ar.GetInt10());
}

bool Octal:: operator >=(const Octal& p_ar) const {
	return (this->GetInt10() >= p_ar.GetInt10());
}

int Octal::GetInt8() const {
	int num = 0;
	char ch[1];
	for (int i = 0; (*this)[i] != '\0'; i++) {
		ch[0] = (*this)[i];
		num += atoi(ch) * pow(10, i);
	}
	return num;
}

int Octal::GetInt10() const {
	int num1 = 0;
	char ch[1];
	for (int i = 0; (*this)[i] != '\0'; i++) {
		ch[0] = (*this)[i];
		num1 += atoi(ch) * pow(8, i);
	}
	return num1;
}

int Octal::size() const {
	int i = 0;
	for (i; (*this)[i] != '\0'; i++);
	return i;
}

Octal::~Octal() {
	count--;
}