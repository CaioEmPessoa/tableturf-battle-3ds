

// xy positions for square // width&height of square // color of the square
void drawSquare(int x, int y, int w, int h, u32 c)
{
	C2D_DrawRectangle(
		convertPos('w', x),
		convertPos('h', y), // should be negative but whatever
		0, w, h,
		c, c, c, c
	);
}


void drawSleeve(int x, int y)
{
    // draw border
    drawSquare(x, y, 66, 77, 0);

    // draw card bg
    drawSquare(x+3, y+3, 60, 60, 1);

    // draw bottom stats part
}