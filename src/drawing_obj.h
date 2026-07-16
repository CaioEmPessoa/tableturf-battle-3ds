
// complex and program-specific shapes, like the main player, trees etc..

void drawCardBlocks(int x, int y, Card card)
{
    for (int j = 0; j < card.inkAmount; j++) {
        int color = card.inkdSqrs[j] == card.special ? getColor("purple") : getColor("orange"); // special point place

        const int sqrCoordX = card.inkdSqrs[j]%card.width;
        const int sqrCoordY = card.inkdSqrs[j]/card.width; // converting from 1d array to 2d

        const int relX = sqrCoordX*btnSqrSize;
        const int relY = sqrCoordY*btnSqrSize;

        const int centerX = relX - (card.width/2) * btnSqrSize;

        const int lastInk = card.inkdSqrs[card.inkAmount-1]; // last ink shuold be farthest ink from y
        int centerY = relY - (lastInk/card.width) * btnSqrSize;

        const int inkTileX = x+centerX;
        const int inkTileY = y-centerY;

        // void drawSquare(int x, int y, int w, int h, u32 color)
        drawSquare(inkTileX, inkTileY, btnSqrSize, btnSqrSize, color);
    }
}

int* drawSleeve(int x, int y, Card card)
{
    // Sleeve
    const int cardWidth = 70, cardHeight = 70;
    drawSquare(x, y, cardWidth, cardHeight, getColor("sleeveBackground"));

    // Card image
    const int bgX = x+3;
    const int bgY = y+15;

    const int bgW = cardWidth-6;
    const int bgH = cardHeight-17;
    drawSquare(bgX, bgY, bgW, bgH, getColor("pink"));

    // Card image blocks
    const int cbX = x +bgW/2; // cb = card block
    const int cbY = y +bgH/2;
    drawCardBlocks(cbX, cbY, card);

    // Card bottom status
    const int statusX = bgX;
    const int statusY = -bgY;
    drawText(statusX, statusY, card.name, 0.6f);

    int result[4] = {x, y, cardWidth, cardHeight};
    int *pResult = malloc(sizeof(int) * 4);
    memcpy(pResult, result, sizeof(int) * 4);

    return pResult;
}

int* drawArena(int x, int y, int tilesAmmount)
{

    int arenaTiles = tilesAmmount;
    int arenaSize = tilesAmmount*btnSqrSize;

    int arenaBorderSize = arenaSize+btnSqrSize*2;

    int* arenaBorder = drawSquare(x-btnSqrSize, y-btnSqrSize, arenaBorderSize, arenaBorderSize, getColor("green")); // arena border
    int* arenaSquare = drawSquare(x, y, arenaSize, arenaSize, getColor("black")); // arena tiles

    return arenaBorder;
}