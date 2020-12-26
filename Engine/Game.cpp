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

				if (snek.GetNextLocation(delta_loc) == goal.GetLocation())
				{
					snek.Grow();
					goal.Respawn(brd, snek); // dont forget to add a check to make sure goal doesnt respawn inside snake
				}

				snek.MoveBy(delta_loc);
			}



		}



	}
}



void Game::ComposeFrame()
{
	//if (x == 0 || y == 0 || x == brd.getWidth()-1 || y == brd.getHeight()-1)
	for (int x = 1; x < (brd.getWidth() - 1) * brd.getBoardDimension(); x++)
	{
		for (int y = 1; y < (brd.getHeight() - 1) * brd.getBoardDimension(); y++)
		{
			if (x % brd.getWidth() == 0 || y % brd.getHeight() == 0)
			{
				gfx.PutPixel(x, y, Colors::Gray);
			}
		}
	}


	goal.Draw(brd);
	snek.Draw(brd);
	

}
