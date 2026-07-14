
void clearScene(Screens screens) {
    C2D_TargetClear(screens.top, getColor("clear"));
    C2D_TargetClear(screens.bottom, getColor("clear"));

    // clear inputs etc..

}

void CombatScene(Player player, Screens screens, bool commandsValid) {
    clearScene(screens);

    // ----- TOP SCREEN -----
    C2D_SceneBegin(screens.top);

    // Drawing elements
    int* arena = drawArena(-10, -10);

    drawCardBlocks(player.boardPosX, player.boardPosY, player.hand[player.currentHoldingCard]);

    // Commands
    if(!commandsValid) {
        ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_CPAD_UP", "KEY_DUP"), movePlayer, 'N', false);
        ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_CPAD_DOWN", "KEY_DDOWN"), movePlayer, 'S', false);
        ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_CPAD_RIGHT", "KEY_DRIGHT"), movePlayer, 'E', false);
        ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_CPAD_LEFT", "KEY_DLEFT"), movePlayer, 'W', false);

        ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_ZL"), movePlayerCard, 'l', false);
        ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_ZR"), movePlayerCard, 'r', false);
    }

    // ----- BOTTOM SCREEN -----
    C2D_SceneBegin(screens.bottom);

    // Drawing elements
    int* upLeft = drawSleeve(-145, 10, player.hand[0]);
    int* downLeft = drawSleeve(-145, -87, player.hand[1]);
    int* upRight = drawSleeve(0, 10, player.hand[2]);
    int* downRight = drawSleeve(0, -87, player.hand[3]);

    // Commands
    if(!commandsValid) {
        ADD_TOUCH_ELEMENT_INT(upLeft, changePlayerHandCard, 0);
        ADD_TOUCH_ELEMENT_INT(downLeft, changePlayerHandCard, 1);
        ADD_TOUCH_ELEMENT_CHAR(upRight, changePlayerHandCard, 2);
        ADD_TOUCH_ELEMENT_CHAR(downRight, changePlayerHandCard, 3);
    }
}