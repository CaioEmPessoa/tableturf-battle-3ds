
// basic functions like drawing text, squares, triangles etc

// xy positions for square // width&height of square // color of the square
void drawSquare(int x, int y, int w, int h, u32 c)
{
	C2D_DrawRectangle(
		convertPos('w', x),
		convertPos('h', y)-h,
		0, w, h,
		c, c, c, c
	);
}