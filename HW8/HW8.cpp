#include<locale>
#include <iostream>
#include<conio.h>
#include"Task.h"
int main()
{
	int a, b{0};
	double  result;
	
	try
	{
		setlocale(LC_ALL, "rus");
		std::cout << "Введите два числа через пробел : ";
		std::cin >> a >> b;
		result = divtt(a, b);
		std::cout << a << " / " << b << " = " << result << std::endl;
	}
	catch (const char* exception)
	{
		std::cerr << " Error : " << exception << std::endl;
	}
	catch (...)// обработка catch-all
	{
		std::cout << "We caught an excepyion of an undetermined type!\n";
	}
	std::cout << std::endl;

	std::cout << "Работа с классом Bar:" << std::endl;
	Bar bar;
	double n;
	try
	{
		do
		{
			std::cout << "Введите n = ";
			std::cin >> n;
			bar.set(n);
			std::cout << std::endl;
		} while (n != 0);
	}
	catch (const Ex& ex)
	{
		std::cerr << "Возникла ошибка: Ex с параметром (" << ex.what() << ")" << std::endl;
		_getch();
	}
	catch (...)
	{
		std::cerr << "Возникла не известная ошибка!" << std::endl;
		_getch();
	}


	system("cls");
	Robot ro;
	char c;
	do
	{
		std::cout << "Работа с классом Робот:" << std::endl ;
		ro.print();
		std::cout << std::endl << "Для перемещения используйте WASD, для выхода X" << std::endl;
		std::cin.clear();
		std::cin.get(c);
		system("cls");
		try
		{
			switch (c)
			{
			case 'D':
				ro.move(direction::RIGHT);
				break;
			case 'A':
				ro.move(direction::LEFT);
				break;
			case 'W':
				ro.move(direction::UP);
				break;
			case 'S':
				ro.move(direction::DOWN);
				break;

			case 'X':
				break;
			default:
				ro.move(direction::other);
			}
		}
		catch (const OffTheField& ex)
		{
			std::cerr << "Попытка выхода за пределы поля! " << ex.what() << std::endl;
			_getch();
		}
		catch (const IllegalCommand& ex)
		{
			std::cerr << "Указано неизвестное направление!" << std::endl;
			_getch();
		}
		catch (...)
		{
			std::cerr << "Неизвестная ошибка!" << std::endl;
			_getch();
		}
	} while (c != 'x' && c != 'X');

}
