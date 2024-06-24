#ifndef APPLICATION_H
#define APPLICATION_H

#include "Octal.h"
#include "BitString.h"

class Application {
	void menu();
	void BitStringMenu();
	void OctalMenu();
	Array* p_1;
	Array* p_2;
	Array* p_3;
public:
	void run();
};

#endif 