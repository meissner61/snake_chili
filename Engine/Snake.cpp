#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	// even though its 3 colors, setting it as 4 is necessary to make it easier to mod(%) calculate through
	static constexpr int nBodyColors = 4;
	static constexpr Color bodyColors[nBodyColors] = 
	{
		{10,100,32},
		{10,130,48},
		{18,160,48},
		{10,130,48}
	};

	for (int i = 0; i < nSegmentMax; ++i)
	{
		segments[i].InitBody(bodyColors[i % nBodyColors]);
	}

	segments[0].InitHead(loc);


}

void Snake::MoveBy(Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i-1]); //loop for all the snake pieces minus the head
	}

	segments[0].MoveBy(delta_loc);

}

void Snake::Grow()
{

	if (nSegments < nSegmentMax)
	{
		//segments[nSegments].InitBody();
		nSegments++;
		
	}
	

}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetLocation() const
{
	return segments[0].GetLocation();
}

Location Snake::GetNextLocation(const Location & delta_loc) const
{
	Location l (segments[0].GetLocation());
	l.Add(delta_loc);

	return l;
}

bool Snake::SelfCollision(const Location & delta_loc) const
{
	Location loc = GetNextLocation(delta_loc);
	for (int i = 0; i < nSegments-1; i++)
	{
		if (loc == segments[i].GetLocation())
		{
			return true;
		}
	}
	return false;
}

bool Snake::SnakeCollision(const Location & in_loc) const
{
	Location loc = in_loc;
	for (int i = 0; i < nSegments - 1; i++)
	{
		if (loc == segments[i].GetLocation())
		{
			return true;
		}
	}
	return false;
}

/////////////////////////////////////////////////////////

void Snake::Segment::InitHead(const Location & loc)
{
	m_loc = loc;
	m_color = Snake::headColor;
}

void Snake::Segment::InitBody(Color c)
{
	m_color = c;
}

void Snake::Segment::Follow(const Segment & next)
{
	m_loc = next.m_loc;
}

void Snake::Segment::MoveBy(Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	m_loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(m_loc, m_color);
}

Location Snake::Segment::GetLocation() const
{
	return m_loc;
}
