#pragma once

#include "Location.h"
#include "Graphics.h"

class Board
{
public:

	Board(Graphics &gfx);
	void DrawCell( const Location& loc, Color c);
	bool IsInsideBoard(const Location& loc) const;
	int getWidth() const;
	int getHeight() const;
	int getBoardDimension() const;
	void DrawGrid();
	static constexpr int boardOffset = 5;
	static constexpr int padding = 3;
	Graphics &gfx;

private:

	//width and height of the squares in the board, no rectangular board pieces
	static constexpr int dimension = 20;

	//width and height of the whole board not the squares
	static constexpr int width = 30;
	static constexpr int height = 20;

	

	
	
};