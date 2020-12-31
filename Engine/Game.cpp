/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	snek({ 5,5 }),
	goal(brd, snek)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();

}

void Game::UpdateModel()
{
	if (!gameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_loc = { 0,-1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}

		snakeMoveCounter++;
		if (snakeMoveCounter >= snakeMovePeriod)
		{
			snakeMoveCounter = 0;

			if ( ( !brd.IsInsideBoard(snek.GetNextLocation(delta_loc)) ) || ( snek.SelfCollision(delta_loc) ) )
			{
				gameOver = true;
			}

			else
			{
				const bool eating = snek.GetNextLocation(delta_loc) == goal.GetLocation();
				if (eating)
				{
					snek.Grow();
				}

				snek.MoveBy(delta_loc);

				if (eating)
				{
					goal.Respawn(brd, snek);
				}

				
			}



		}



	}
}



void Game::ComposeFrame()
{
	goal.Draw(brd);
	snek.Draw(brd);
	//if (x == 0 || y == 0 || x == brd.getWidth()-1 || y == brd.getHeight()-1)
	for (int x = (brd.boardOffset * brd.getBoardDimension())+1; x < (brd.getWidth()+ brd.boardOffset) * brd.getBoardDimension(); x++)
	{
		for (int y = (brd.boardOffset * brd.getBoardDimension())+1; y < (brd.getHeight()+ brd.boardOffset) * brd.getBoardDimension(); y++)
		{
			if (x % brd.getBoardDimension() == 0 || y % brd.getBoardDimension() == 0)
			{
				gfx.PutPixel(x, y, Colors::Green);
			}
		}
	}



	

}
