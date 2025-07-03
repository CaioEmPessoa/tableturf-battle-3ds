
// complex and program-specific shapes, like the main player, trees etc..

void drawSleeve(int x, int y)
{
    int sleeveW = 60;
    int sleeveH = 60;

    // draw border
    drawSquare(x, y, sleeveW+6, sleeveH+17, getColor("sleeveBackground"));

    // draw card bg
    drawSquare(x+3, y+15, sleeveW, sleeveH, getColor("pink"));

    // draw bottom stats part
}