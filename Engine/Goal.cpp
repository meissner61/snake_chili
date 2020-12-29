#include "Goal.h"

Goal::Goal(Board & brd, Snake & snake)
{
	Respawn(brd,snake);
}

void Goal::Respawn(Board & brd, Snake & snake)
{
	srand(time(NULL));

	do
	{
		int x_loc = rand() % (brd.getWidth() - 1);
		int y_loc = rand() % (brd.getHeight() - 1);
		m_loc = { x_loc,y_loc };

	} while (snake.SnakeCollision(m_loc));

	

}

void Goal::Draw(Board brd)
{
	brd.DrawCell(m_loc, m_color);
}

const Location & Goal::GetLocation() const
{
	return m_loc;
}
