#pragma once
struct Location
{
	void Add(const Location& value)
	{
		x += value.x;
		y += value.y;
	}

	bool operator == (const Location& rhs)const
	{
		return x == rhs.x && y == rhs.y;
	}
	int x, y;
};