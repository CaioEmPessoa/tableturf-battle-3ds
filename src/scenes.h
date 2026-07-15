
#include <stdio.h>
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
    int* arena = drawArena(-40, -40, 15);

    drawCardBlocks(player.boardPosX, player.boardPosY, player.hand[player.currentHoldingCard]);

    // Commands
    if(!commandsValid) {

        store_button_command(
            movePlayer, &(parameter_t){.type = PARAM_CHAR, .value = {.char_val = 'N'}},
            1, (char*[]){"KEY_CPAD_UP", "KEY_DUP"}, 2, false
        );
        store_button_command(
            movePlayer, &(parameter_t){.type = PARAM_CHAR, .value = {.char_val = 'S'}},
            1, (char*[]){"KEY_CPAD_DOWN", "KEY_DDOWN"}, 2, false
        );
        store_button_command(
            movePlayer, &(parameter_t){.type = PARAM_CHAR, .value = {.char_val = 'E'}},
            1, (char*[]){"KEY_CPAD_RIGHT", "KEY_DRIGHT"}, 2, false
        );
        store_button_command(
            movePlayer, &(parameter_t){.type = PARAM_CHAR, .value = {.char_val = 'W'}},
            1, (char*[]){"KEY_CPAD_LEFT", "KEY_DLEFT"}, 2, false
        );

        // ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_ZL"), movePlayerCard, 'l', false);
        // ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_ZR"), movePlayerCard, 'r', false);
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
        store_touch_command(upLeft, changePlayerHandCard, &(parameter_t){.type = PARAM_INT, .value = {.int_val = 0}}, 1 );
        store_touch_command(downLeft, changePlayerHandCard, &(parameter_t){.type = PARAM_INT, .value = {.int_val = 1}}, 1 );
        store_touch_command(upRight, changePlayerHandCard, &(parameter_t){.type = PARAM_INT, .value = {.int_val = 2}}, 1 );
        store_touch_command(downRight, changePlayerHandCard, &(parameter_t){.type = PARAM_INT, .value = {.int_val = 3}}, 1 );
    }
}