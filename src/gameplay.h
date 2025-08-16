
// ------------ Game-specific functions ------------ //
void movePlayer(void* nsew)
{
	if (nsew == NULL) return;

	char direction = *(char*)nsew;
	if (direction == 'N') player.boardPosY += 1;
	else if (direction == 'S') player.boardPosY -= 1;
	else if (direction == 'E') player.boardPosX += 1;
	else if (direction == 'W') player.boardPosX -= 1;
}

void changePlayerCard(void* holding)
{
    player.holding = *(int*)holding;
}

void checkFrameKey(char key[]) // check for input in hold every frame
{
	if (strcmp(key, "KEY_TOUCH") == 0) checkTouchClick(); // check in touch functions
}

void checkSingleKey(char key[]) // check for inputs if diff from before
{
	if (strcmp(key, "KEY_Y") == 0) cursorBot = cursorBot ? false : true;
}