#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "MainWindow.h"

class Snake
{
public:
	Snake(int in_x, int in_y, Color in_c);
	void DrawSnake(Graphics& gfx) const;
	void Move(MainWindow& wnd);
	void Growth();
	void ClampScreen();
private:
	int x;
	int y;
	int follow = 5;
	static constexpr int dim = 20;
	int vx = dim;
	int vy = 0;
	Color c;
	bool EnableMove = false;
};