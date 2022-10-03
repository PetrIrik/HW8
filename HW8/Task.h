#pragma once
#include<iostream>
#include<string>
//�������� ��������� ������� div, ������� ������ ��������� ��������� ������� ����
//���������� � ��������� ���������� DivisionByZero, ���� ������ �������� ����� 0. �
//������� main �������� ��������� ������ ������� div � �������, � ����� ������ ����������.

template <class T>
double divtt(T div1, T div2)
{
	if (div2 == 0)
	{
		throw "Division by zero detected!";
	}
	return static_cast<double>(div1) / div2;
}

//�������� ����� Ex, �������� ������������ ����� x � ������� ����������� ��
//������������� �����, ���������������� x ��������� ���������.�������� ����� Bar,
//�������� ������������ ����� y(����������� �� ��������� �������������� ��� �����) �
//������� ����� set � ������������ ������������ ���������� a.���� y + a > 100,
//������������ ���������� ���� Ex � ������� a* y, ����� � y ��������� �������� a.� �������
//main ������� ���������� ������ Bar � � ����� � ����� try ������� � ���������� ����� n.
//������������ ��� � �������� ��������� ������ set �� ��� ���, ���� �� ����� ������� 0. �
//����������� ���������� �������� ��������� �� ������, ���������� ������ �������
//����������.
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

//�������� ����� ������, ������������ ����������� ������ �� ����� 10x10, � �������� ����
//�����, ���������� ������� ������������� �� �������� �������.��� ������ ������
//��������� ������ - ���������� OffTheField, ���� ����� ������ ���� � �����, � IllegalCommand,
//���� ������ �������� �������(����������� �� ��������� � ������ ���������).������
//���������� ������ ��������� ��� ����������� ���������� � ������� ������� �
//����������� ��������.�������� ������� main, ������������ ���� ������� �
//��������������� ��� ���������� �� ��� �������, � ����� ��������� ���������
//���������� � ���� ����������� �������.
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
		error = "������� ������� ������ (";
		error += std::to_string(vcard.x);
		error += ",";
		error += std::to_string(vcard.y);
		error += ") ����������� ��������: ";
		switch (vdir)
		{
		case direction::RIGHT:
			error += "������";
			break;
		case direction::LEFT:
			error += "�����";
			break;
		case direction::DOWN:
			error += "����";
			break;
		case direction::UP:
			error += "�����";
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