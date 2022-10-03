#pragma once
#include<iostream>
#include<string>
//Написать шаблонную функцию div, которая должна вычислять результат деления двух
//параметров и запускать исключение DivisionByZero, если второй параметр равен 0. В
//функции main выводить результат вызова функции div в консоль, а также ловить исключения.

template <class T>
double divtt(T div1, T div2)
{
	if (div2 == 0)
	{
		throw "Division by zero detected!";
	}
	return static_cast<double>(div1) / div2;
}

//Написать класс Ex, хранящий вещественное число x и имеющий конструктор по
//вещественному числу, инициализирующий x значением параметра.Написать класс Bar,
//хранящий вещественное число y(конструктор по умолчанию инициализирует его нулем) и
//имеющий метод set с единственным вещественным параметром a.Если y + a > 100,
//возбуждается исключение типа Ex с данными a* y, иначе в y заносится значение a.В функции
//main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
//Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. В
//обработчике исключения выводить сообщение об ошибке, содержащее данные объекта
//исключения.
class Ex
{
public:
	Ex(double arg) : m_x(arg)
	{};
	double what() const noexcept { return m_x; };

private:
	double m_x;
};

class Bar
{
public:
	Bar() : m_y(0)
	{};

	void set(double a)
	{
		if (m_y + a > 100)
		{
			throw Ex(a * m_y);
		}
		else
		{
			m_y = a;
		}
		
	}

private:
	double m_y;
};

//Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть
//метод, означающий задание переместиться на соседнюю позицию.Эти методы должны
//запускать классы - исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand,
//если подана неверная команда(направление не находится в нужном диапазоне).Объект
//исключения должен содержать всю необходимую информацию — текущую позицию и
//направление движения.Написать функцию main, пользующуюся этим классом и
//перехватывающую все исключения от его методов, а также выводящую подробную
//информацию о всех возникающих ошибках.
struct card
{
	int x, y;
};

enum class direction
{
	RIGHT, LEFT, DOWN, UP, other
};

class Robot
{
public:
	Robot()
		:m_card{}
	{};

	void move(direction dir);
	void print();
private:
	card m_card;
};
class OffTheField : public std::exception
{
public:
	OffTheField(card vcard, direction vdir)
	{
		error = "Текущая позиция робота (";
		error += std::to_string(vcard.x);
		error += ",";
		error += std::to_string(vcard.y);
		error += ") направление движения: ";
		switch (vdir)
		{
		case direction::RIGHT:
			error += "вправо";
			break;
		case direction::LEFT:
			error += "влево";
			break;
		case direction::DOWN:
			error += "вниз";
			break;
		case direction::UP:
			error += "вверх";
			break;
		default:
			break;
		}
	};

	const char* what() const noexcept { return error.c_str(); };

private:
	std::string error;
};

class IllegalCommand : public std::exception
{
public:
	IllegalCommand() = default;
};