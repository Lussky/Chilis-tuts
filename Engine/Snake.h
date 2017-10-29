#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "MainWindow.h"
#include <vector>

class Snake
{
private:
	class Element
	{
	public:
		Element(int in_x, int in_y);
		int x;
		int y;
	};
public:
	Snake(int in_x, int in_y, Color in_c);
	void DrawSnake(Graphics& gfx) const;
	void Move();
	void Control(MainWindow& wnd);
	void Growth(Graphics& gfx);
	void ClampBorder();
private:
	int x;
	int y;
	//Element body1[10];
	std::vector <Element> body;
	int elements = 0; //unused yet - amount of body elements
	static constexpr int dim = 20;
	int vx = dim;
	int vy = 0;
	Color c;
	bool PreventReverseMove = false;
};