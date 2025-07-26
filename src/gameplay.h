
// ------------ Game-specific functions ------------ //
void movePlayer(char nsew)
{
	switch (nsew)
	{
	case 'N':
		playerTileY -= 1;
		if (playerTileY <= -maxTileY-1) playerTileY += 1;
		break;
	case 'S':
		playerTileY += 1;
		if (playerTileY >= maxTileY) playerTileY -= 1;
		break;
	case 'E':
		playerTileX += 1;
		if (playerTileX >= maxTileX) playerTileX -= 1;
		break;
	case 'W':
		playerTileX -= 1;
		if (playerTileX <= -maxTileX-1) playerTileX += 1;
		break;
	default:
		break;
	}
}

// ---- Adds created functions to input methods ---- //
void checkTouchPos()
{
    // this if check if the screen is "fliped"
    // and add functions to the flipped screen
	if (cursorBot)
	{ } // secondary screen functions
	else
	{
		if (checkTouchSquare(0))
		{
			player.holding = 36;
		}
		else if (checkTouchSquare(1))
		{
			player.holding = 3;
		}
		else if (checkTouchSquare(2))
		{
			player.holding = 113;
		}
		else if (checkTouchSquare(3))
		{
			player.holding = 1;
		}
	} // main touch screen functions
}

void checkFrameKey(char key[]) // check for input in hold every frame
{
	if (strcmp(key, "KEY_TOUCH") == 0) checkTouchPos(); // needed for all touch functions
}

void checkSingleKey(char key[]) // check for inputs if diff from before
{
	if (strcmp(key, "KEY_Y") == 0) cursorBot = cursorBot ? false : true;
	else if (strcmp(key, "KEY_DUP") == 0 || strcmp(key, "KEY_CPAD_UP") == 0) movePlayer('N');
	else if (strcmp(key, "KEY_DDOWN") == 0 || strcmp(key, "KEY_CPAD_DOWN") == 0) movePlayer('S');
	else if (strcmp(key, "KEY_DRIGHT") == 0 || strcmp(key, "KEY_CPAD_RIGHT") == 0) movePlayer('E');
	else if (strcmp(key, "KEY_DLEFT") == 0 || strcmp(key, "KEY_CPAD_LEFT") == 0) movePlayer('W');
}