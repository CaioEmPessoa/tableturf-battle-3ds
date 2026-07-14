
// ------------ Game-specific functions ------------ //

void flipScreens(void* n)
{
    cursorBot = cursorBot ? false : true;
}

void movePlayer(void* nsew) // char type
{
	if (nsew == NULL) return;

	char direction = *(char*)nsew;
	if 		(direction == 'N') player.boardPosY += btnSqrSize;
	else if (direction == 'S') player.boardPosY -= btnSqrSize;
	else if (direction == 'E') player.boardPosX += btnSqrSize;
	else if (direction == 'W') player.boardPosX -= btnSqrSize;
}

void changePlayerHandCard(void* currentHoldingCard) // int type
{
    player.currentHoldingCard = *(int*)currentHoldingCard;
}

void movePlayerCard(void* direction) // need to add player as a parameter later
{
	if (player.cardsOnHand <= 1) return;
	if(*(char*)direction == 'l' && player.currentHoldingCard >= 1) player.currentHoldingCard -= 1;
	if(*(char*)direction == 'r' && player.currentHoldingCard < player.cardsOnHand-1) player.currentHoldingCard += 1;
}