
typedef struct {
    char name[30];
    int inkPoints;
    int specialPoints;
    int boardPosX;
    int boardPosY;
    Card hand[3];
    int cardsOnHand;
    int currentHoldingCard;
    Card tmpDeck[30];
    Card deck[30];
} Player;

Player player = {
    .name = "Debug Player",
    .deck = {},
    .currentHoldingCard = 3,
    .cardsOnHand = 4,
    .boardPosX = 0,
    .boardPosY = 0,
};

// TODO: Change player function