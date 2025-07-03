
#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>

#include "global.h"
#include "cards.h"
#include "player.h"
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

	// -------| INITIAL VARIABLES |------

	// BACKGROUND POSITION
	int backgroundSizeX = (maxTileX*topSqrSize)*2;
	int backgroundSizeY = (maxTileY*topSqrSize)*2;

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

	// COLORS:
	u32 clrRed    = C2D_Color32(255, 0, 0, 255);
	u32 clrBlue   = C2D_Color32(0, 0, 255, 255);
	u32 clrGreen  = C2D_Color32(0, 255, 0, 255);
	u32 clrWhite  = C2D_Color32(255, 255, 255, 255);
	u32 clrPink   = C2D_Color32(255, 192, 203, 255);
	u32 clrOrange = C2D_Color32(255, 165, 0, 255);
	u32 clrPurple = C2D_Color32(128, 0, 128, 255);
	u32 clrBlack  = C2D_Color32(0, 0, 0, 255);
	u32 clrClear  = C2D_Color32(255, 216, 176, 255);

	// to check if keys are pressed in the next frame
	u32 kDownOld = 0, kHeldOld = 0;
	int posXOld = 0, posYOld = 0;

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	C3D_RenderTarget* bot = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	Player player = {
		.name = "Debug Player",
		.deck = {}
	};

	player.deck[0] = cards[0];
	player.deck[1] = cards[0];
	player.deck[2] = cards[2];
	player.deck[3] = cards[5];
	player.deck[4] = cards[1];
	player.deck[5] = cards[3]; // the player will eventually have to choose the cards they want to add

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
		C2D_TargetClear(top, clrClear);
		C2D_TargetClear(bot, clrClear);

		// START DRAWING
		// Utilities Screen (mainly bottom)
		slctScreen =  cursorBot ? 't' : 'b';
		C2D_SceneBegin(cursorBot ? top : bot);

			drawSleeve(0, 0);

		// Drawing Canvas (mainly top screen)
		slctScreen =  cursorBot ? 'b' : 't';
		C2D_SceneBegin(cursorBot ? bot : top);

		C3D_FrameEnd(0);
		// END DRAWING

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