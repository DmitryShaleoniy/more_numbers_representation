#ifndef OCTAL_H
#define OCTAL_H

#include "Array.h"

class Octal : public Array {

public:
	static int count;
	Octal();
	Octal(int p_dim, unsigned int p_num);
	explicit Octal(int p_dim);
	explicit Octal(const Array& p_ini);
	bool sum(const Array* p_other, Array* o_result) const override;
	//Array operator+(const Array& p_ar) const override;
	Octal operator-(const Octal& p_ar) const;
	Octal operator*(const Octal& p_ar) const;
	Octal operator/(const Octal& p_ar) const;
	bool operator <(const Octal& p_ar) const;
	bool operator <=(const Octal& p_ar) const;
	bool operator >(const Octal& p_ar) const;
	bool operator >=(const Octal& p_ar) const;
	int size() const;


	int GetInt8() const;
	int GetInt10() const;
	//Octal operator+(const Octal& p_ar) const;
	~Octal() override;
};

#endif 