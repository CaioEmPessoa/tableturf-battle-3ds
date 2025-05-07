

// xy positions for square // width&height of square
// color code in list 	  // bool r (unused) if xy are relative to middle or top-left
void drawSquare(int x, int y, int w, int h, int c)
{
	C2D_DrawRectangle(
		convertPos('w', x),
		convertPos('h', y), // should be negative but whatever
		0, w, h,
		svdColors(c), svdColors(c), svdColors(c), svdColors(c)
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