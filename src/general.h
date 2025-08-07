
// convert start position from top-left to middle
int convertPos(char type, int pos)
{
	int offset = (slctScreen == 't') ? ((type == 'w') ? TOP_SCREEN_WIDTH / 2 : TOP_SCREEN_HEIGHT / 2) : // top screen
										((type == 'w') ? BOT_SCREEN_WIDTH / 2 : BOT_SCREEN_HEIGHT / 2); // bottom screen

	return (type == 'h') ? offset - pos : offset + pos;
}

void checkTouchClick() // check and execute if touch is on one of squares.
{
	for (int i = 0; i < touchElementsAmmt; i++)
	{
		TouchElements item = touchElements[i];

		int x0 = item.xyhw[0];
		int x1 = x0 + item.xyhw[2];
		int y0 = item.xyhw[1];
		int y1 = y0 + item.xyhw[3];

		int posX = touch.px - BOT_SCREEN_WIDTH / 2;
		int posY = touch.py - BOT_SCREEN_HEIGHT / 2;

		if ((posX >= x0 && posX <= x1) && (posY >= y0 && posY <= y1))
		{
			item.command();
		};
	}
}