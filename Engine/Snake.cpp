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

void Snake::Move()			
{
		x += vx;
		y += vy;
}

void Snake::Control(MainWindow & wnd)
{
	if (!PreventReverseMove)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			vx = 0;
			vy = -dim;
			PreventReverseMove = true;
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			vx = 0;
			vy = dim;
			PreventReverseMove = true;
		}
	}
	if (PreventReverseMove)
	{
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			vx = dim;
			vy = 0;
			PreventReverseMove = false;
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			vx = -dim;
			vy = 0;
			PreventReverseMove = false;
		}
	}
}

void Snake::Growth()
{

}

void Snake::ClampBorder()
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
}
