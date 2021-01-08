// Task 7 - Вернитесь к программе из листинга 7.7 и замените три функции обработки
//			массивов версиями, которые работают с диапазоном значений, заданными
//			парой указателей. Функция fill_array() вместо возврата действительного
//			количества прочитанных значений должна возваращать указатель на место,
//			следующее за последним введенным элементом; прочие функции должны
//			использовать его в качестве второго аргумента для идентификации конца
//			диапазона данных


#include <iostream>

constexpr size_t Max = 5;

double * fillArray(double * Arr, const size_t limit);
void showArray(const double * beginArr, const double * endArr);
void revalue(const double ratio, double * beginArr, const double * endArr);

int main()
{
	double properties[Max] {0};

	std::cout << "Fill array :" << std::endl;
	const double * poversize = fillArray(properties, Max);
	showArray(properties, poversize);
	if (poversize != properties)
	{
		std::cout << "Enter revaluation factor: ";
		double factor;
		while (!(std::cin >> factor))
		{
			std::cout << "Bad input. Please try again." << std::endl;
			continue;
		}
		revalue(factor, properties, poversize);
		showArray(properties, poversize);
	}
	std::cout << "Done" << std::endl;

	return 0;
}

double * fillArray(double * Arr, const size_t limit)
{
	size_t size = 0;
	do
	{
		std::cin >> *Arr;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			break;
		}
		++Arr;
		++size;
	}
	while (size < limit);

	return Arr;
}

void showArray(const double * beginArr, const double * endArr)
{
	int index = 0;

	while (beginArr < endArr)
	{
		std::cout << "Arr[" << index << "] = " << *beginArr << std::endl;
		++index;
		++beginArr;
	}
}

void revalue(const double ratio, double * beginArr, const double * endArr)
{
	while (beginArr < endArr)
	{
		*beginArr *= ratio;
		++beginArr;
	}
}

// Task 10 - Спроектируйте функцию calculate(), которая принимает два значения типа double
//			 и указатель на функцию, принимающую два аргумента double и возвращающую
//			 значение double. Функция calculate() также должна иметь тип double и возвращать
//			 значение, вычисленное функцией, которая задана указателем, использую аргумент
//			 double функции calculate(). Например, предположим, что имеется следующее 
//			 определение функции add():
//			 double add(double x, double y)
//			 {
//			 	return x + y;
//			 }
//			 Приведенный ниже вызов функции должен заставить calculate() передать значение
//			 2.5 и 10.4 функции add() и вернуть её результат (12.9):
//
//			 double q = calculate(2.5, 10.4, add);
//
//			 Используйте в программе эти функции и еще хотя бы одну дополнительную, которая
//			 подобна add(). В программе должен быть организован цикл, позволяющий пользователю
//			 вводить пары чисел. Для каждой пары calculate() должна вызвать add() и хотя бы еще
//			 одну функцию такого рода. Если вы чувствуете себя уверенно, попробуйте создать массив
//			 указателей на функции, подобные add(), и организуйте цикл, применяя calculate() для 
//			 вызова этих функций по указателям. Подсказка: вот как можно объявить массив из трёх
//			 таких указателей:
//			 double (*pf[3]) (double, double);
//
//			 Инициализировать такой массив можно с помощью обычного синтаксиса инициализации массивов
//			 и имен функции в качестве аргументов

#include <iostream>

constexpr size_t ArrSize = 2;
//double calculate(double x, double y, double (*pfun) (double, double));
double calculate(double x, double y, const double (*pfun) (double, double));
const double add(double x, double y);
const double sum(double x, double y);

int main()
{
	using namespace std;
	double first, second, result;
	//double sumResult, addResult;
	const double (*pf[ArrSize]) (double, double) {add, sum};
	cout << "Enter two numbers: " << endl;
	cin >> first >> second;
	while (cin.good())
	{
		//addResult = calculate(first, second, add);
		//sumResult = calculate(first, second, sum);
		for (size_t index = 0; index < ArrSize; ++index)
		{
			result = calculate(first, second, pf[index]);
			cout << "Result: " << result << endl;
		}
		
		//cout << "Add: " << addResult << endl;
		//cout << "Sum: " << sumResult << endl;
		cout << "Enter next two numbers: " << endl;
		cin >> first >> second;
	}

	if (cin.fail())
		cerr << "Wrong input!" << endl;
	else
		cout << "Done!" << endl;

	return 0;
}

double calculate(double x, double y, const double (*pfun) (double, double))
{
	return (*pfun) (x, y);
}

const double add(double x, double y)
{
	return (x * y);
}

const double sum(double x, double y)
{
	return (x + y);
}