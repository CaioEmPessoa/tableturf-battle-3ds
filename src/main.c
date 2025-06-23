
#include <citro2d.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>

#include "global.h"
#include "general.h"
#include "cards.h"
#include "drawing.h"
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

	// Main loop
	while (aptMainLoop())
	{
		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrClear);
		C2D_TargetClear(bot, clrClear);

		// Utilities Screen (mainly bottom)
		slctScreen =  cursorBot ? 't' : 'b';
		C2D_SceneBegin(cursorBot ? top : bot);

         int startX = -15;
         int startY = -10;

         // draw cards sleeves
         drawSleeve(-84, -86);


         // draw cards
         for (int i = 0; i < cardsAmmt; i++) {

            Card card = cards[i];

            for (int j = 0; j < card.inkAmount; j++) {
               int color = card.inkdSqrs[j] == card.special ? clrOrange : clrPurple; // special point place

               int inkTileX = startX+(card.inkdSqrs[j]%card.width);
               int inkTileY = startY+card.inkdSqrs[j]/card.width;

               drawSquare(inkTileX*btnSqrSize, inkTileY*btnSqrSize, btnSqrSize, btnSqrSize, color);
            }

            startX += card.width+1;
            if (startX >= 15) {
               startX = -10; startY += 5;
            }
         }

		// Drawing Canvas (mainly top screen)
		slctScreen =  cursorBot ? 'b' : 't';
		C2D_SceneBegin(cursorBot ? bot : top);

			drawSquare(-backgroundSizeX*0.5, -backgroundSizeY*0.5, backgroundSizeX, backgroundSizeY, clrOrange);

			drawSquare(playerTileX*topSqrSize, playerTileY*topSqrSize, topSqrSize, topSqrSize, clrPurple);

		// end frame
		C3D_FrameEnd(0);

		//Read the touch screen coordinates
		hidTouchRead(&touch);
		//Scan all the inputs
		hidScanInput();

		u32 kDown = hidKeysDown(), kHeld = hidKeysHeld();

		if (kDown & KEY_START) break;

		if (kDown != kDownOld || kHeld == kHeldOld ||
			posXOld != touch.px || posYOld != touch.py)
		{
			//Clear console
			consoleClear();
			// Line must be rewritten because we cleared the whole console
			printf("\x1b[1;1HPress Start to exit.");

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