#ifndef BITSTRING_H
#define BITSTRING_H

#include "Array.h"

class BitString: public Array {
public:
	static int count;
	BitString();
	explicit BitString(int p_dim);
	BitString(int p_dim, int p_num);
	explicit BitString(const Array& p_ini);
	bool sum(const Array* p_other, Array* o_result) const override;
	//Array operator+(const Array& p_ar) const override;
	BitString operator and (const BitString& p_ar) const;
	BitString operator or (const BitString& p_ar) const;
	BitString operator xor (const BitString& p_ar) const;
	BitString operator not () const;
	BitString operator<< (int p_num) const;
	BitString operator>> (int p_num) const;


	int size() const;
	int GetInt2() const;
	int GetInt10() const;
	~BitString() override;
};

#endif