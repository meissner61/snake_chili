#pragma once
#include "Location.h"
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody(Color c);
		void Follow(const Segment& next);
		void MoveBy(Location& delta_loc);
		void Draw(Board& brd) const;
		Location GetLocation() const;

	private:
		Location m_loc;
		Color m_color;
	};


public:

	Snake(const Location& loc);
	void MoveBy(Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
	Location GetLocation() const;
	Location GetNextLocation(const Location& delta_loc) const;
	bool SelfCollision(const Location& delta_loc)const;
	bool SnakeCollision(const Location& in_loc) const;


private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;

	static constexpr int nSegmentMax = 100;
	Segment segments[nSegmentMax];
	int nSegments = 1; // how many elements of the array were using

};