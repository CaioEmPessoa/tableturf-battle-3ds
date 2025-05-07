typedef struct {
   char name[30];
   int id;
   char imgLocation[30];
   int inkdSqrs[18];
   int width;
   int special;
   int cost;
   int inkAmount;
} Card; // creating card obj

static Card cards[102] = {
   {
      .name = "Hero Shot",
      .id = 1,
      .imgLocation = "Hero Shot.png",
      .inkdSqrs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 15},
      .width = 5,
      .special = 8,
      .inkAmount = 12
   },
   {
      .name = "Splattershot Jr.",
      .id = 3,
      .imgLocation = "Splattershot Jr.png",
      .inkdSqrs = {0, 1, 2, 3},
      .width = 3,
      .special = 1,
      .inkAmount = 4
   },
   {
      .name = "Splattershot Pro",
      .id = 9,
      .imgLocation = "Splattershot Pro.png",
      .inkdSqrs = {3, 4, 6, 7, 8, 9, 10, 11, 14},
      .width = 6,
      .special = 4,
      .cost = 4,
      .inkAmount = 9
   },
   {
      .name = "Sloshing Machine",
      .id = 36,
      .imgLocation = "Sloshing Machine.png",
      .inkdSqrs = {0, 1, 2, 4, 5, 7, 8},
      .width = 3,
      .special = 1,
      .inkAmount = 7
   },
   {
      .name = "Burst Bomb",
      .id = 58,
      .imgLocation = "Burst Bomb.png",
      .inkdSqrs = {0},
      .width = 1,
      .special = 0,
      .inkAmount = 1
   },
   {
      .name = "Tentatek",
      .id = 113,
      .imgLocation = "Tentatek.png",
      .inkdSqrs = {1, 2},
      .width = 2,
      .special = 1,
      .inkAmount = 2
   }
};

static int cardsAmmt = sizeof(cards) / sizeof(cards[0]);

