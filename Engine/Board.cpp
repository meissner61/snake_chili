#include "Board.h"
#include <assert.h>

Board::Board(Graphics &gfx)
	:
	gfx(gfx)
{
	
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	gfx.DrawRectDim(((loc.x + boardOffset)*dimension) + padding, ((loc.y + boardOffset)*dimension) + padding, (dimension - (padding * 2) + 1), (dimension - (padding * 2) + 1), c);
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return loc.x >=0 && loc.x < width && 
			loc.y >= 0 && loc.y < height;
}



int Board::getWidth() const
{
	return width;
}

int Board::getHeight() const
{
	return height;
}

int Board::getBoardDimension() const
{
	return dimension;
}
