
#include <citro2d.h>
#include <3ds.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "global.h"

#include "colors.h"
#include "cards.h"
#include "player.h"
#include "inputStructs.h"

#include "general.h"
#include "drawing.h"
#include "drawing_obj.h"
#include "gameplay.h"

int main(int argc, char* argv[])
{
	// Initialize services
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	gfxInitDefault();
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();

	// -------| VARIABLES |------

	// ARRAY WITH ALL KEY
	char keysNames[32][32] = {
		"KEY_A", "KEY_B", "KEY_SELECT", "KEY_START",
		"KEY_DRIGHT", "KEY_DLEFT", "KEY_DUP", "KEY_DDOWN",
		"KEY_R", "KEY_L", "KEY_X", "KEY_Y",
		"", "", "KEY_ZL", "KEY_ZR",
		"", "", "", "",
		"KEY_TOUCH", "", "", "",
		"KEY_CSTICK_RIGHT", "KEY_CSTICK_LEFT", "KEY_CSTICK_UP", "KEY_CSTICK_DOWN",
		"KEY_CPAD_RIGHT", "KEY_CPAD_LEFT", "KEY_CPAD_UP", "KEY_CPAD_DOWN"
	};

	// to check if keys are pressed in the next frame
	u32 kDownOld = 0, kHeldOld = 0;
	int posXOld = 0, posYOld = 0;

	bool commandsRan = false;

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	C3D_RenderTarget* bot = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	player.deck[0] = cards[0];
	player.deck[1] = cards[0];
	player.deck[2] = cards[2];
	player.deck[3] = cards[5];
	player.deck[4] = cards[1];
	player.deck[5] = cards[3]; // Adding player cards manually

	memcpy(player.tmpDeck, player.deck, sizeof(player.deck));

	for (int i = 0; i < 3; i++)
	{
		int rndCard = rand() % (ARRAY_LEN(player.tmpDeck) - 0 + 1) + 0; // lenght = max, 0 = min

		player.hand[i] = player.tmpDeck[i];

		removeCard(player.tmpDeck, rndCard, ARRAY_LEN(player.tmpDeck));
	}


	// Main loop
	while (aptMainLoop())
	{
		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, getColor("clear"));
		C2D_TargetClear(bot, getColor("clear"));

		// START DRAWING
		// Utilities Screen (mainly bottom)
		slctScreen =  cursorBot ? 't' : 'b';
		C2D_SceneBegin(cursorBot ? top : bot);

			int* upLeft = drawSleeve(-145, 10, 3);
			int* downLeft = drawSleeve(-145, -87, 36);
			int* upRight = drawSleeve(0, 10, 1);
			int* downRight = drawSleeve(0, -87, 113);

		// Drawing Canvas (mainly top screen)
		slctScreen =  cursorBot ? 'b' : 't';
		C2D_SceneBegin(cursorBot ? bot : top);

			drawCardBlocks(player.boardPosX, player.boardPosY, player.holding);

		C3D_FrameEnd(0);
		// END DRAWING

		// COMMAND FUNCTIONS, RUN ONLY ON FIRST ITERATION.
		if(!commandsRan) {
			ADD_TOUCH_ELEMENT_INT(upLeft, changePlayerCard, 3);
			ADD_TOUCH_ELEMENT_INT(downLeft, changePlayerCard, 36);
			ADD_TOUCH_ELEMENT_CHAR(upRight, movePlayer, 'N');
			ADD_TOUCH_ELEMENT_CHAR(downRight, movePlayer, 'S');

			ADD_BUTTON_ELEMENT_CHAR("KEY_X", movePlayer, 'N');
			ADD_BUTTON_ELEMENT_CHAR("KEY_A", movePlayer, 'W');
			ADD_BUTTON_ELEMENT_CHAR("KEY_Y", movePlayer, 'E');
			ADD_BUTTON_ELEMENT_CHAR("KEY_B", movePlayer, 'S');
		}
		commandsRan = true;

		//Read the touch screen coordinates
		hidTouchRead(&touch);
		//Scan all the inputs
		hidScanInput();

		u32 kDown = hidKeysDown(), kHeld = hidKeysHeld();

		if (kDown & KEY_START) break;

		if (kDown != kDownOld || kHeld == kHeldOld ||
			posXOld != touch.px || posYOld != touch.py)
		{
			int i;
			for (i = 0; i < 32; i++)
			{
				if (kDown & BIT(i)) checkSingleKey(keysNames[i]);
				if (kHeld & BIT(i)) checkFrameKey(keysNames[i]);
			}
		}

		//Set keys old values for the next frame
		kDownOld = kDown;
		kHeldOld = kHeld;
		posXOld = touch.px;
		posYOld = touch.py;
	}

	// Exit services
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}