#include "Snake.h"
#include "Graphics.h"
#include "Keyboard.h"

Snake::Snake(int in_x, int in_y, Color in_c)
{
	x = in_x;
	y = in_y;
	c = in_c;
}

void Snake::DrawSnake(Graphics& gfx) const
{
	gfx.DrawRectDim(x, y, dim, dim, c);
}

void Snake::Move(MainWindow& wnd)			
{
		x += vx;
		y += vy;
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			vx = 0;
			vy = -dim;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			vx = 0;
			vy = dim;
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			vy = 0;
			vx = dim;
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			vy = 0;
			vx = -dim;
		}
}	   //TODO - rebuild somehow

void Snake::Growth()
{

}

void Snake::ClampScreen()
{
	const int ScreenBottom = Graphics::ScreenHeight - 1;
	const int ScreenRight = Graphics::ScreenWidth - 1;

	const int SnakeBottom = y + dim;
	const int SnakeRight = x + dim;

	if (x < dim)
		x = dim;
	if (SnakeRight > ScreenRight - dim)
		x = ScreenRight - 2 * dim;
	if (y < dim)
		y = dim;
	if (SnakeBottom > ScreenBottom - dim)
		y = ScreenBottom - 2 * dim;
}			//doesnt work properly
