// Act 7 Homework - Functions

// Task 1 - Напишите программу, которая многократно запрашивает у пользователя
//			пару чисел до тех пор, пока хотя бы одно из этой пары не будет равно 0.
//			С каждой парой программа должна использовать функцию для вычисления
//			среднего гармонического этих чисел. Функция должна возвращать ответ main()
//			для отображения результата. Среднее гармоническое чисел - это инверсия
//			среднего значения их инверсий:
//			Среднее гармоническое = 2.0 * x * y / (x + y)

#include <iostream>

double AvgGarmonic(const double x, const double y);

int main()
{
	int x, y;
	double result;

	std::cout << "Enter two numbers (enter '0' to one of the number for quit): ";
	std::cin >> x >> y;
	while(x != 0 && y != 0)
	{
		result = AvgGarmonic(x, y);
		std::cout << "Result: " << result << std::endl;
		std::cout << "Enter next two numbers (0 for quit): ";
		std::cin >> x >> y;
	}
	std::cout << "Executed" << std::endl;

	return 0;
}

double AvgGarmonic(const double x, const double y)
{
	return 2.0 * x * y / (x + y);
}


// Task 2 - Напишите программу, которая запрашивает у пользователя 10 результатов игры
//			в гольф, сохраняя их в массиве. При этом необходимо обеспечить возможность
//			прекращения ввода до ввода всех 10 результатов. Программа должна отобразить
//			все результаты в одной строке и сообщить их среднее значение. Реализуйте
//			ввод, отображение и вычисление среднего в трёъ отдельных функциях, работающих
//			с массивами.

#include <iostream>

const size_t ArrSize = 10;

int fillArray(int * arr, const size_t n);
double calculateAvg(int * arr, const size_t n);
void showArray(int * arr, const size_t n, double average);

int main()
{
	using namespace std;
	double avgValue;
	short currentSize;
	int golf[ArrSize] {0};

	cout << "Fill the array" << endl;
	currentSize = fillArray(golf, ArrSize);
	avgValue = calculateAvg(golf, currentSize);
	showArray(golf, currentSize, avgValue);

	return 0;
}

int fillArray(int * arr, const size_t n)
{
	int temp;
	size_t count = 0;

	while(std::cin >> temp && count < n)
	{
		arr[count] = temp;
		++count;
	}
	return count;
}

double calculateAvg(int * arr, const size_t n)
{
	double sum = 0;

	for (size_t index = 0; index < n; ++index)
	{
		sum += arr[index];
	}

	return sum / (n - 1);
}

void showArray(int * arr, const size_t n, double average)
{
	std::cout << "Array: ";

	for (size_t index = 0; index < n; ++index)
	{
		std::cout << arr[index] << "[" << index << "] ";
	}
	std::cout << std::endl;
	std::cout << "Average value current content of array: " << average << std::endl;
}

// Task 3 - Пусть имеется следующее объявление структуры:
//			struct box
//			{
//				char maker[40];
//				float height;
//				float width;
//				float length;
//				float volume;
//			};
//
//			а. Напишите функцию, принимающую структуру box по значению и отображающую	
//			все её члены.
//
//			б. Напишите функцию, принимающую адрес структуры box и устанавливающую
//			значение члена volume равным произведению остальных трёх членов.
//
//			в. Напишите простую программу, которая использует две эти функции.

#include <iostream>
#include <windows.h>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;	
};

void showStruct(const box Form);
void changeStruct(box * Form);

int main()
{
	using namespace std;
	box Shape {"Cube", 3, 3, 3};

	showStruct(Shape);
	std::cout << "Calulating: " << std::endl;
	Sleep(5000);
	changeStruct(&Shape);
	std::cout << "Shape.volume: " << Shape.volume;

	return 0;

}

void showStruct(const box Form)
{
	std::cout << "maker: " << Form.maker << std::endl;
	std::cout << "height: " << Form.height << std::endl;
	std::cout << "width: " << Form.width << std::endl;
	std::cout << "length: " << Form.length << std::endl;
	std::cout << "volume: " << Form.volume << std::endl;
}

void changeStruct(box * Form)
{
	Form->volume = Form->height * Form->width * Form->length;
}