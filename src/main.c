
#include <citro2d.h>
#include <3ds.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// global variables
#include "global.h"

// colors and inputs that entitys may depend on
#include "3ds-easy-lib/general.h"
#include "3ds-easy-lib/colors.h"
#include "3ds-easy-lib/inputs.h"
// #include "3ds-easy-lib/inputs.h"

// entity classes
#include "entity/cards.h"
#include "entity/player.h"

// important helpers. draw basic objects, complex, specific math etc
#include "3ds-easy-lib/drawing.h"
#include "drawing_obj.h"
#include "gameplay.h"
#include "scenes.h"

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

	bool commandsValid = false;

	// Create screens
	Screens screens = {
		.top    = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT),
		.bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT)
	};

	// Creating player obj manually
	addDeckCard(&player, cards[0]);
	addDeckCard(&player, cards[0]);
	addDeckCard(&player, cards[1]);
	addDeckCard(&player, cards[2]);
	addDeckCard(&player, cards[3]);
	addDeckCard(&player, cards[4]);
	addDeckCard(&player, cards[5]);
	addDeckCard(&player, cards[6]);

	addHandCards(&player);

	// Main loop
	while (aptMainLoop())
	{
		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

		// START DRAWING

		CombatScene(player, screens, commandsValid);

		// END DRAWING
		C3D_FrameEnd(0);

		// COMMAND FUNCTIONS.
		// CAUTION TO RUN ONLY ONE TIME PER ITERATION
		if(!commandsValid) {
			// ADD_BUTTON_ELEMENT_CHAR(BUTTONS_ARRAY("KEY_Y"), flipScreens, 'n', false);
		}

		commandsValid = true;

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