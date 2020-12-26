#pragma once
#include "Board.h"
#include "Snake.h"
#include <ctime>

class Goal
{
public:
	Goal(Board & brd, Snake & snake);
	void Respawn(Board& brd, Snake& snake);
	void Draw(Board brd);

	const Location& GetLocation() const;


private:
	Location m_loc;
	static constexpr Color m_color = Colors::Red;
	  
};
