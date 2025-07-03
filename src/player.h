
typedef struct {
    char name[30];
    int inkPoints;
    int specialPoints;
    Card holding;
    Card hand[3];
    Card tmpDeck[30];
    Card deck[30];
} Player;