
typedef struct {
    char name[30];
    int inkPoints;
    int specialPoints;
    int holding;
    Card hand[3];
    Card tmpDeck[30];
    Card deck[30];
} Player;

Player player = {
    .name = "Debug Player",
    .deck = {},
    .holding = 3
};