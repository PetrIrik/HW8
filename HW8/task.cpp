#include"Task.h"

void Robot::move(direction vdir)
{
	switch (vdir)
	{
	case direction::RIGHT:
		if (++m_card.x>=10)
		{
			--m_card.x;
			throw OffTheField(m_card, vdir);
		}
		break;
	case direction::LEFT:
		if (--m_card.x<0)
		{
			++m_card.x;
			throw OffTheField(m_card, vdir);
		}
		break;
	case direction::DOWN:
		if (++m_card.y>=10)
		{
			--m_card.y;
			throw OffTheField(m_card, vdir);
		}
		break;
	case direction::UP:
		if (--m_card.y<0)
		{
			++m_card.y;
			throw OffTheField(m_card, vdir);
		}
		break;
	default: IllegalCommand();
		break;
	}
}

void Robot::print()
{
	for (size_t i = 0; i < 10; ++i)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (j ==  m_card.x&&i==m_card.y)
			{
				std::cout << "O";
			}
			else
			{
				std::cout << "_";
			}
		}
		std::cout << std::endl;
	}
}