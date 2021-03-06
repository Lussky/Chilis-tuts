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
#include "Graphics.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	snek(100,100,Colors::Yellow)
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
	snek.Control(wnd);
	if (DelayMove == 0)
	{
		snek.Move();
		++DelayMove;
	}
	else
	{
		if (DelayMove == 20)
		{
			DelayMove = 0;
		}
		else
		{
			++DelayMove;
		}
	}

	snek.ClampBorder();
}

void Game::ComposeFrame()
{
	gfx.DrawRect(19, 19, gfx.ScreenWidth - 20, 20, Colors::White);
	gfx.DrawRect(19, 19, 20, gfx.ScreenHeight - 20, Colors::White);
	gfx.DrawRect(20, gfx.ScreenHeight - 20, gfx.ScreenWidth - 20,
		gfx.ScreenHeight - 21, Colors::White);
	gfx.DrawRect(gfx.ScreenWidth - 20, 20,
		gfx.ScreenWidth - 21, gfx.ScreenHeight - 20, Colors::White);

	snek.DrawSnake(gfx);
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		snek.Growth(gfx);
	}
}
