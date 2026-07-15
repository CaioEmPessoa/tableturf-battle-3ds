// ------------ Game-specific functions ------------ //

void flipScreens(void* n)
{
    cursorBot = cursorBot ? false : true;
}

// char direction
void movePlayer(parameter_t* params, int param_count) // char type
{
    if (param_count == 1 &&
        params[0].type == PARAM_CHAR
	){
		char direction = params[0].value.char_val;

		if 		(direction == 'N') player.boardPosY += btnSqrSize;
		else if (direction == 'S') player.boardPosY -= btnSqrSize;
		else if (direction == 'E') player.boardPosX += btnSqrSize;
		else if (direction == 'W') player.boardPosX -= btnSqrSize;
	}
}

// int currentHoldingCard
void changePlayerHandCard(parameter_t* params, int param_count)
{
    if (param_count == 1 &&
        params[0].type == PARAM_INT
	){

		int currentHoldingCard = params[0].value.int_val;

		player.currentHoldingCard = currentHoldingCard;
	}
}

void movePlayerCard(void* direction) // need to add player as a parameter later
{
	if (player.cardsOnHand <= 1) return;
	if(*(char*)direction == 'l' && player.currentHoldingCard >= 1) player.currentHoldingCard -= 1;
	if(*(char*)direction == 'r' && player.currentHoldingCard < player.cardsOnHand-1) player.currentHoldingCard += 1;
}

void placeCard() {

}