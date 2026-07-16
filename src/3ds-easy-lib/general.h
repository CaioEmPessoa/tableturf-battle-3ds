
// convert start position from top-left to middle
// TODO: Change this to use screen_type variable type insted
int convertPos(char type, int pos)
{
	int offset = (selectedScreen == TOP )
	? ((type == 'w') ? TOP_SCREEN_WIDTH / 2 : TOP_SCREEN_HEIGHT / 2)  // top screen
	: ((type == 'w') ? BOT_SCREEN_WIDTH / 2 : BOT_SCREEN_HEIGHT / 2); // bottom screen

	return (type == 'h') ? offset - pos : offset + pos;
}

int convertPosInScreen(char type, int pos, screen_types screen)
{
	int result = 0;
	screen_types oldSelectedScreen = selectedScreen;

	selectedScreen = screen;

	result = convertPos(type, pos);

	selectedScreen = oldSelectedScreen;

	return result;
}