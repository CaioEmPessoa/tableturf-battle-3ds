
// basic functions like drawing text, squares, triangles etc

// xy positions for square // width&height of square // color of the square
int* drawSquare(int x, int y, int w, int h, u32 c)
{
	C2D_DrawRectangle(
		convertPos('w', x, 0),
		convertPos('h', y, 0)-h,
		0, w, h,
		c, c, c, c
	);

	int result[4] = {x, y, w, h};
    int *pResult = malloc(sizeof(int) * 4);
    memcpy(pResult, result, sizeof(int) * 4);
    return pResult;
}