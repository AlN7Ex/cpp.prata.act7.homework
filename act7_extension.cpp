// Task 5 - Определите рекурсивную функцию, принимающую целый аргумент и возвращающую
//			его факториал. Вспомните, что факториал 3 записывается, как 3!
//			и вычисляется как 3 * 2! и т.д., причем 0! равно 1. В общем случае, если n
//			больше нуля, то n! = n * (n - 1)!. Протестируйте функцию в программе,
//			использующей цикл, где пользователь может вводить различные значения,
//			для которых программа вычисляет и отображает факториалы.

#include <iostream>

unsigned long long factorial(int n);

int main()
{
	int number;

	std::cout << "Enter a number for factorize: ";
	std::cin >> number;
	while(number)
	{
		std::cout << "Factorial: " << factorial(number) << std::endl;
		std::cout << "Enter a number for factorize: ";
		std::cin >> number;
	}

	return 0;
}

unsigned long long factorial(int n)
{
	unsigned long long total = 1;
	if (n > 1)
	{
		total = n * factorial(n - 1);
	}
	return total;
}

// Task 6 - Напишите программу, использующую следующие функции:

//			fillArray() принимает в качестве аргумента имя массива элементов типа
//			double и размер этого массива. Она приглашает пользователя ввести
//			значения типа double для помещения их в массив. Ввод прекращается
//			при наполнении массива либо когда пользователь вводит нечисловое значение
//			и вовзращает действительное количество элементов
//
//			showArray() принимает в качестве аргументов имя массива значений
//			double, а также его размер, и отображает содержимое массива.
//
//			reverseArray() принимает в качестве аргумента имя массива значений
//			double, а также его размер, и изменяет порядок его элементов
//			на противоположный.
//
//			Программа должна использовать эти функции для наполнения массива,
//			обращения порядка его элементов, кроме первого и последнего, с
//			последующим отображением.

#include <iostream>
#include <windows.h>

constexpr size_t ArrSize = 10;

int fillArray(double * arr, const size_t ArrSize);
void reverseArray(double * beginArr, double * endArr, const size_t currentSize);
void showArray(const double * arr, size_t currentSize);

int main()
{
	double myArr[ArrSize] {0};

	std::cout << "Fill the array by double numbers: " << std::endl;
	const int currentSize = fillArray(myArr, ArrSize);
	std::cout << "Source array:" << std::endl;
	showArray(myArr, currentSize);
	std::cout << "Reversing ..." << std::endl;
	reverseArray(myArr + 1, myArr + currentSize - 1, currentSize);
	Sleep(3000);
	std::cout << "Reversed array:" << std::endl;
	showArray(myArr, currentSize);

	return 0;
}

int fillArray(double * arr, const size_t ArrSize)
{
	double number;
	int actualSize = 1;
	std::cin >> number;

	while(number && actualSize != ArrSize)
	{
		*arr = number;
		++arr;
		++actualSize;
		std::cin >> number;
	}

	return actualSize;
}

void reverseArray(double * beginArr, double * endArr, const size_t currentSize)
{
	while (*beginArr != *endArr)
	{
		double temp;
		temp = *beginArr;
		*beginArr = *endArr;
		*endArr = temp;
		++beginArr;
		--endArr;
	}
}

void showArray(const double * arr, size_t currentSize)
{
	int index = 0;
	while(currentSize--)
	{
		std::cout << "Arr [" << index << "]" << *arr << std::endl;
		++arr;
		++index;
	}
}