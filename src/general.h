
// convert start position from top-left to middle
int convertPos(char type, int pos)
{
	int offset = (slctScreen == 't') ? ((type == 'w') ? TOP_SCREEN_WIDTH / 2 : TOP_SCREEN_HEIGHT / 2) : // top screen
										((type == 'w') ? BOT_SCREEN_WIDTH / 2 : BOT_SCREEN_HEIGHT / 2); // bottom screen

	return offset + pos;
}

bool checkTouchSquare(int id) // check if click is on touch square area
{
	int x0 = touchEl[id][0];
	int x1 = x0 + touchEl[id][2];
	int y0 = touchEl[id][1];
	int y1 = y0 + touchEl[id][3];

	int posX = touch.px - BOT_SCREEN_WIDTH / 2;
	int posY = touch.py - BOT_SCREEN_HEIGHT / 2;

	if ((posX >= x0 && posX <= x1) && (posY >= y0 && posY <= y1)) return true;
	else return false;
}

// id being manual is a choice, so that id's have known places on the array, and not 'random' ones
void addTouchSquare(int x, int y, int w, int h, int id) // add an area to the cliclabe list
{
	touchEl[id][0] = x;
	touchEl[id][1] = y;
	touchEl[id][2] = w;
	touchEl[id][3] = h;
}