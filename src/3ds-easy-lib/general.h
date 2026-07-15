
// convert start position from top-left to middle
// TODO: Change this to use screen_type variable type insted
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