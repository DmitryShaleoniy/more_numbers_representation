#include "Application.h"
#include "IncompatibleDimException.h"
#include "OutOfRangeException.h"
#include "ZeroDivideException.h"
#include <iostream>

void Application::menu() {
	std::cout << "----------------- MENU -----------------" << std::endl;
	std::cout << "1. ������������ ����� Octal" << std::endl;
	std::cout << "2. ������������ ����� BitString" << std::endl;
	std::cout << "3. �����" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

void Application::OctalMenu() {
	int del1 = 1;
	try {
		p_1 = new Octal(4, 1020);
		p_2 = new Octal(3, 510);
		p_3 = new Octal();
	}
	catch (IncompatibleDimException& exep) {
		std::cout << exep.what();
		del1 = 0;
	}

	if (del1) {
		Octal* f1 = dynamic_cast<Octal*>(p_1);
		Octal* f2 = dynamic_cast<Octal*>(p_2);
		Octal* f3 = dynamic_cast<Octal*>(p_3);

		int key = 1;
		while (key != 8) {
			std::cout << "\n------------ OCTAL MENU ------------" << std::endl;
			std::cout << "1. �������� �����" << std::endl;
			std::cout << "2. a + b" << std::endl;
			std::cout << "3. a - b" << std::endl;
			std::cout << "4. a * b" << std::endl;
			std::cout << "5. a / b" << std::endl;
			std::cout << "6. a > b?" << std::endl;
			std::cout << "7. a < b?" << std::endl;
			std::cout << "8. �����" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cin >> key;

			switch (key) {
			case 1: {
				std::cout << "a = " << f1->GetInt10() << " - ���������� �������������, a = " << f1->GetInt8() << " - ������������ �������������" << std::endl;
				std::cout << "b = " << f2->GetInt10() << " - ���������� �������������, b = " << f2->GetInt8() << " - ������������ �������������" << std::endl;
				break;
			}
			case 2: {
				try {
					p_1->sum(p_2, p_3);
					std::cout << "a + b = " << f3->GetInt8() << " - ������������ �������������, " << f3->GetInt10() << "- ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 3: {
				try {
					*f3 = *f1 - *f2;
					std::cout << "a - b = " << f3->GetInt8() << " - ������������ �������������, " << f3->GetInt10() << "- ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 4: {
				try {
					*f3 = *f1 * *f2;
					std::cout << "a * b = " << f3->GetInt8() << " - ������������ �������������, " << f3->GetInt10() << "- ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 5: {
				try {
					*f3 = *f1 / *f2;
					std::cout << "a / b = " << f3->GetInt8() << " - ������������ �������������, " << f3->GetInt10() << "- ���������� �������������" << std::endl;
				}
				catch (ZeroDivideException& exep) {
					std::cout << exep.what();
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 6: {
				if (*f1 > *f2) {
					std::cout << "������ ����� ������ �������" << std::endl;
				}
				else {
					std::cout << "������ ����� �� ������ �������" << std::endl;
				}
				break;
			}
			case 7: {
				if (*f1 < *f2) {
					std::cout << "������ ����� ������ �������" << std::endl;
				}
				else {
					std::cout << "������ ����� �� ������ �������" << std::endl;
				}
				break;
			}
			}
		}
		delete p_1;
		delete p_2;
		delete p_3;
	}
}

void Application::BitStringMenu() {
	int del1 = 1;
	try {
		p_1 = new BitString(6, 46);
		p_2 = new BitString(5, 23);
		p_3 = new BitString();
	}
	catch (IncompatibleDimException& exep) {
		std::cout << exep.what();
		del1 = 0;
	}

	if (del1) {
		BitString* f1 = dynamic_cast<BitString*>(p_1);
		BitString* f2 = dynamic_cast<BitString*>(p_2);
		BitString* f3 = dynamic_cast<BitString*>(p_3);

		int key = 1;
		while (key != 9) {
			std::cout << "------------ BIT STRING MENU ------------" << std::endl;
			std::cout << "1. �������� �����" << std::endl;
			std::cout << "2. a + b" << std::endl;
			std::cout << "3. a or b" << std::endl;
			std::cout << "4. a and b" << std::endl;
			std::cout << "5. a xor b" << std::endl;
			std::cout << "6. not a" << std::endl;
			std::cout << "7. a << x" << std::endl;
			std::cout << "8. a >> x" << std::endl;
			std::cout << "9. �����" << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
			std::cin >> key;

			switch (key) {
			case 1: {
				std::cout << "a = " << f1->GetInt10() << " - ���������� �������������, a = " << f1->GetInt2() << " - �������� �������������" << std::endl;
				std::cout << "b = " << f2->GetInt10() << " - ���������� �������������, b = " << f2->GetInt2() << " - �������� �������������" << std::endl;
				break;
			}
			case 2: {
				try {
					p_1->sum(p_2, p_3);
					std::cout << "a + b = " << f1->GetInt2() << " + " << f2->GetInt2() << " = " << f3->GetInt2() << " - �������� �������������, " << f3->GetInt10() << " - ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 3: {
				try {
					*f3 = *f1 or *f2;
					std::cout << "a or b = " << f1->GetInt2() << " or " << f2->GetInt2() << " = " << f3->GetInt2() << " - �������� �������������, " << f3->GetInt10() << " - ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 4: {
				try {
					*f3 = *f1 and *f2;
					std::cout << "a and b = " << f1->GetInt2() << " and " << f2->GetInt2() << " = " << f3->GetInt2() << " - �������� �������������, " << f3->GetInt10() << " - ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 5: {
				try {
					*f3 = *f1 xor *f2;
					std::cout << "a xor b = " << f1->GetInt2() << " xor " << f2->GetInt2() << " = " << f3->GetInt2() << " - �������� �������������, " << f3->GetInt10() << " - ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 6: {
				try {
					*f3 = not *f1;
					std::cout << "not a = not " << f1->GetInt2() << " = " << f3->GetInt2() << " - �������� �������������, " << f3->GetInt10() << " - ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 7: {
				int x = 0;
				std::cout << "������� ���������� ��� ��� ������: " << std::endl;
				std::cin >> x;
				try {
					*f3 = *f1 << x;
					std::cout << "a << " << x << " = " << f3->GetInt2() << " - �������� �������������, " << f3->GetInt10() << " - ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			case 8: {
				int x = 0;
				std::cout << "������� ���������� ��� ��� ������: " << std::endl;
				std::cin >> x;
				try {
					*f3 = *f1 >> x;
					std::cout << "a >> " << x << " = " << f3->GetInt2() << " - �������� �������������, " << f3->GetInt10() << " - ���������� �������������" << std::endl;
				}
				catch (IncompatibleDimException& exep) {
					std::cout << exep.what();
				}
				break;
			}
			default: {
				key = 9;
			}
			}
		}
		delete p_1;
		delete p_2;
		delete p_3;
	}
}

void Application::run() {
	int k = 1;
	while (k != 3) {
		menu();
		std::cin >> k;
		switch (k) {
		case 1: {
			OctalMenu();
			break;
		}
		case 2: {
			BitStringMenu();
			break;
		}
		}
	}
}