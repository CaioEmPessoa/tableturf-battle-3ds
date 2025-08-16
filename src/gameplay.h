
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