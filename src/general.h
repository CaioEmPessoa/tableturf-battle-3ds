
// convert start position from top-left to middle
int convertPos(char type, int pos, void* screen)
{
	char screenToConvert;
	if (screen == NULL) {screenToConvert = slctScreen;}
	else {screenToConvert = *(char*)screen;}

	int offset = (screenToConvert == 't')
	? ((type == 'w') ? TOP_SCREEN_WIDTH / 2 : TOP_SCREEN_HEIGHT / 2)  // top screen
	: ((type == 'w') ? BOT_SCREEN_WIDTH / 2 : BOT_SCREEN_HEIGHT / 2); // bottom screen

	return (type == 'h') ? offset - pos : offset + pos;
}

void checkTouchClick() // check and execute if touch is on one of squares.
{
	for (int i = 0; i < touchElementsAmmt; i++)
	{
		TouchElements item = touchElements[i];

		int x0 = item.xywh[0];
		int x1 = x0 + item.xywh[2];
		int y0 = item.xywh[1];
		int y1 = y0 + item.xywh[3];

		int posX = touch.px - BOT_SCREEN_WIDTH / 2;
		int posY = convertPos('h', touch.py, &(char){'b'});

		if ((posX >= x0 && posX <= x1) && (posY >= y0 && posY <= y1))
		{
			item.command(item.args);
		};
	}
}

void checkButtonClick(char key[], bool repeat) // check and execute if one of the buttons are clicked.
{
	for (int i = 0; i < buttonElementsAmmt; i++)
	{
		ButtonElements item = buttonElements[i];

		if (strcmp(key, item.buttons)==0 && item.repeat == repeat)
		{
			item.command(item.args);
		};
	}
}

void checkFrameKey(char key[]) // check for input in hold every frame
{
	if (strcmp(key, "KEY_TOUCH") == 0) checkTouchClick(); // check in touch functions
	else checkButtonClick(key, true);
}

void checkSingleKey(char key[]) // check for inputs if diff from before
{
	checkButtonClick(key, false);
	// if (strcmp(key, "KEY_Y") == 0) cursorBot = cursorBot ? false : true;
}