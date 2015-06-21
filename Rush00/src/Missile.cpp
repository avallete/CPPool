#include "Missile.hpp"


Missile::Missile(int N, std::string form)
{
	m_max = N;
	m_index = 0;
	m_missiles = new Missile[N];
	for (int i = 0; i < N; i++)
	{
		m_missiles[i].setForm(form);
		m_missiles[i].setDir(0, -1);
		m_missiles[i].setHP(0);
	}
}

Missile::Missile(void): AObject()
{
	return;
}


Missile::Missile(Missile const & src): AObject(src)
{
	*this = src;
	return;
}

Missile::~Missile(void)
{
	if (m_missiles)
		delete [] m_missiles;
	return;
}

Missile* Missile::getMissile(void) const
{
	return (m_missiles);
}

int			 Missile::getIndex(void) const
{
	return (m_index);
}

int			 Missile::getMax(void) const
{
	return (m_max);
}

void		Missile::activate(int xpos, int ypos, int input)
{
	if (input == 32)
	{
		for (int i = m_index; i < m_max; i++)
		{
			if (m_missiles[i].getHP() == 0)
			{
				m_missiles[i].setPos(xpos, ypos - 1);
				m_missiles[i].setHP(1);
		 		m_index++;
			}
		}
	}
}

void		Missile::checkDamages(EnnemyHorde* horde, int N, Window& win)
{
	int center;
	int centerv;
	for (int i = 0; i < m_max; i++)
	{
		for (int e = 0; e < N; e++)
		{
			if (m_missiles[i].getHP() > 0 && horde[e].getHP() > 0)
			{
				if (abs(m_missiles[i].getY() - horde[e].getY()) <= 3)
				{
					center = horde[e].getX() + (horde[e].getsizeX() / 2);
					centerv = m_missiles[i].getX();
					centerv -= center;
					if (abs(centerv) <= 3)
					{
						m_missiles[i].colision(horde[e]);
						m_missiles[i].explode(win);
						horde[e].die(win);
						m_missiles[i].setHP(0);
						m_missiles[i].setPos(0, 0);
					}
				}
			}
		}
	}
}

void		Missile::printit(Window& win) const
{
	for (int i = 0; i < m_max; i++)
		m_missiles[i].AObject::printit(win);
}

void		Missile::move(Window& win)
{
	for (int i = 0; i < m_max; i++)
	{
		if (m_missiles[i].getY() <= 0)
		{
			m_missiles[i].setHP(0);
			m_index = i;
		}
		m_missiles[i].AObject::move(win);
	}
}

Missile& Missile::operator=(Missile const & rhs)
{
	AObject::operator=(rhs);
	return (*this);
}