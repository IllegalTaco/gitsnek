#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	gfx.DrawRectDim(loc.x * dimension + off_x + cellPadding, loc.y * dimension + off_y + cellPadding, dimension - cellPadding * 2, dimension - cellPadding * 2, c);
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimension;
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimension;

	// top
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
	// left
	gfx.DrawRect(left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
	// right
	gfx.DrawRect(right - borderWidth, top + borderWidth, right, bottom, borderColor);
	// bottom
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}

void Board::DrawGrid() const
{
	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	Color c = { 10,10,10 };
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			gfx.DrawRectDim(x * dimension + off_x, y * dimension + off_y, dimension, 1, c);
			gfx.DrawRectDim(x * dimension + off_x, y * dimension + off_y, 1, dimension, c);
			gfx.DrawRectDim(x * dimension + dimension + off_x, y * dimension + off_y, 1, dimension, c);
			gfx.DrawRectDim(x * dimension + off_x, y * dimension + dimension + off_y, dimension, 1, c);
		}
	}
}

Location Board::GetMid()
{
	Location loc;
	loc.x = width * dimension / 2 + x + borderWidth + borderPadding;
	loc.y = height * dimension / 2 + y + borderWidth + borderPadding;
	return loc;
}
