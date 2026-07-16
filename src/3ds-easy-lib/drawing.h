
// basic functions like drawing text, squares, triangles etc

// xy positions for square // width&height of square // color of the square
int* drawSquare(int x, int y, int w, int h, u32 c)
{
	C2D_DrawRectangle(
		convertPos('w', x),
		convertPos('h', y)-h,
		0, w, h,
		c, c, c, c
	);

	int result[4] = {x, y, w, h};
    int *pResult = malloc(sizeof(int) * 4);
    memcpy(pResult, result, sizeof(int) * 4);
    return pResult;
}

int* drawText(float x, float y, char* text, float fontSize) {
	C2D_Text txt;
	C2D_TextBuf textBuffer = C2D_TextBufNew(128); // TODO: Change to dynamic value

	C2D_TextParse(&txt, textBuffer, text);
	C2D_TextOptimize(&txt);

	C2D_DrawText(
		&txt, 0,
		convertPos('w', x), convertPos('y', y),
		0.0f,
		fontSize, fontSize
	);

	return 0;
}