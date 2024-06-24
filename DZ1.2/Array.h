#ifndef ARRAY_H
#define ARRAY_H

class Array {
	unsigned char* m_char;
	unsigned int m_dimension;
	const static int max = 99;
public:
	Array();
	explicit Array(int p_dim);
	Array(const Array& p_val);
	Array& operator=(const Array& p_other);
	const unsigned char& operator[](int p_num) const;
	unsigned char& operator[](int p_num);
	int get_dim() const;
	void set_dim(int p_val);


	//virtual Array operator+(const Array& p_ar) const;
	virtual bool sum(const Array* p_other, Array* o_result) const;

	virtual ~Array();
};

#endif 