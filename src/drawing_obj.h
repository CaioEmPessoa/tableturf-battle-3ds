
// complex and program-specific shapes, like the main player, trees etc..

void drawSleeve(int x, int y)
{
    int sleeveW = 60;
    int sleeveH = 60;

    // draw border
    drawSquare(x, y, sleeveW+6, sleeveH+17, getColor("sleeveBackground"));

    // draw card bg
    drawSquare(x+3, y+15, sleeveW, sleeveH, getColor("pink"));

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

void drawSleeve(int x, int y, int cardId)
{

    const int cardSizeX = 70, cardSizeY = 70;
    drawSquare(x, y, cardSizeX, cardSizeY, getColor("sleeveBackground"));

    const int bgX = x+3;
    const int bgY = y+15;

    const int bgW = cardSizeX-6;
    const int bgH = cardSizeY-17;
    drawSquare(bgX, bgY, bgW, bgH, getColor("pink"));

    // TODO: Draw bottom card status text

    const int cbX = x +bgW/2; // cb = card block
    const int cbY = y +bgH/2;
    drawCardBlocks(cbX, cbY, cardId);

}