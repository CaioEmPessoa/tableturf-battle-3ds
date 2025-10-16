
typedef struct {
    char name[30];          // Player's name
    int inkPoints;          // Ammount of inkpoints player have
    int specialPoints;      // Ammount of special points player have
    int boardPosX;          // Player PosX on board
    int boardPosY;          // Player PosY on board
    Card hand[4];           // List of cards on hand
    int cardsOnHand;        // Ammount of cards on hand
    int currentHoldingCard; // Index of current card player are holding from its hand
    Card deck[30];          // List of all player cards
    int deckCardsAmnt       // Ammount of cards in deck
} Player;

Player player = { // need to remove this from here URGENTE.
    .name = "Debug Player",
    .deck = {},
    .currentHoldingCard = 0,
    .cardsOnHand = 0,
    .boardPosX = 0,
    .boardPosY = 0,
    .deckCardsAmnt = 0
};

void addDeckCard(Player *player, Card card)
{
    player->deck[player->deckCardsAmnt] = card;
    player->deckCardsAmnt+=1;
}

void addDeckCards(Player player, Card cards[30], int cardAmnt)
{
    memcpy(player.deck, cards, cardAmnt);
    player.deckCardsAmnt=cardAmnt;
}

void addHandCards(Player *player)
{
    int rndCardId;
    Card rndCard;
    int i = player->cardsOnHand;

    srand (time(NULL));

    while (i <= 3)
    {
        rndCardId = rand() % (player->deckCardsAmnt - 1);

        rndCard = player->deck[rndCardId];

        if (rndCard.active == false) {
            continue;
        }

        player->hand[i] = rndCard;
        player->cardsOnHand +=1;

        player->deck[rndCardId].active = false;
        i++;
    }
}