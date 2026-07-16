#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    PARAM_INT,
    PARAM_DOUBLE,
    PARAM_STRING,
    PARAM_CHAR,
    PARAM_VOID_PTR
} param_type_t;

typedef struct {
    param_type_t type;
    union {
        int int_val;
        double double_val;
        char char_val;
        char* string_val;
        void* void_ptr_val;
    } value;
} parameter_t;

typedef struct {
    void (*function)(parameter_t*, int);
    parameter_t* parameters;
    int param_count;
} command_t;

typedef struct {
    command_t command;
    int xywh[4];
} touch_commands_t;

typedef struct {
    command_t command;
    char** buttons; // can be two pointers if memory to heavy
    int buttonsAmmt;
    bool repeat;
} button_commands_t;

#define MAX_COMMANDS 100
static touch_commands_t  stored_touch_commands [MAX_COMMANDS];
static button_commands_t stored_button_commands[MAX_COMMANDS];
static int stored_touch_count  = 0;
static int stored_button_count = 0;

command_t _mount_command(void (*func)(parameter_t*, int), parameter_t* params, int param_count) {
    command_t cmd = {0}; // zero-initialize
    cmd.function = func;
    cmd.param_count = param_count;

    if (param_count > 0) {
        parameter_t* stored_params = malloc(param_count * sizeof(parameter_t));
        if (!stored_params) {
            cmd.parameters = NULL;
            cmd.param_count = 0;
            return cmd;
        }
        for (int i = 0; i < param_count; i++) {
            stored_params[i] = params[i];
            if (params[i].type == PARAM_STRING && params[i].value.string_val) {
                stored_params[i].value.string_val = strdup(params[i].value.string_val);
            }
        }
        cmd.parameters = stored_params;
    } else {
        cmd.parameters = NULL;
    }
    return cmd;
}

bool store_button_command(void (*func)(parameter_t*, int), parameter_t* params, int param_count,
                          char** buttons, int buttonsAmmt, bool repeat) {
    if (stored_button_count >= MAX_COMMANDS) return false;

    stored_button_commands[stored_button_count].command = _mount_command(func, params, param_count);
    stored_button_commands[stored_button_count].repeat = repeat;
    stored_button_commands[stored_button_count].buttonsAmmt = buttonsAmmt;

    if (buttonsAmmt > 0) {
        stored_button_commands[stored_button_count].buttons =
            malloc(buttonsAmmt * sizeof(char*));
        if (stored_button_commands[stored_button_count].buttons) {
            memcpy(stored_button_commands[stored_button_count].buttons,
                buttons,
                buttonsAmmt * sizeof(char*));
        }
    }

    stored_button_count++;
    return true;
}

bool store_touch_command(int* xywh, void (*func)(parameter_t*, int), parameter_t* params, int param_count) {
    if (stored_touch_count >= MAX_COMMANDS) return false;

    stored_touch_commands[stored_touch_count].command = _mount_command(func, params, param_count);
    memcpy(
        stored_touch_commands[stored_touch_count].xywh, xywh,
        sizeof(stored_touch_commands[stored_touch_count].xywh)
    );

    stored_touch_count++;
    return  true;
}

void clear_touch_commands() {
    for (int i = 0; i < stored_touch_count; i++) {
        for (int j = 0; j < stored_touch_commands[i].command.param_count; j++) {
            if (stored_touch_commands[i].command.parameters[j].type == PARAM_STRING) {
                free(stored_touch_commands[i].command.parameters[j].value.string_val);
            }
        }
        free(stored_touch_commands[i].command.parameters);
    }
    stored_touch_count = 0;
}

void clear_button_commands() {
    for (int i = 0; i < stored_button_count; i++) {
        for (int j = 0; j < stored_button_commands[i].command.param_count; j++) {
            if (stored_button_commands[i].command.parameters[j].type == PARAM_STRING) {
                free(stored_button_commands[i].command.parameters[j].value.string_val);
                free(stored_button_commands[i].buttons);
            }
        }
        free(stored_button_commands[i].command.parameters);
    }
    stored_button_count = 0;
}

void clear_commands() {
    clear_touch_commands();
    clear_button_commands();
}

void checkTouchClick() // check and execute if touch is on one of squares.
{
	for (int i = 0; i < stored_touch_count; i++)
	{
		touch_commands_t item = stored_touch_commands[i];

		int x0 = item.xywh[0];
		int x1 = x0 + item.xywh[2];
		int y0 = item.xywh[1];
		int y1 = y0 + item.xywh[3];

		int posX = touch.px - BOT_SCREEN_WIDTH / 2; // touch and this variable is stored globally
		int posY = convertPosInScreen('h', touch.py, BOTTOM);

		if ((posX >= x0 && posX <= x1) && (posY >= y0 && posY <= y1))
		{
			item.command.function(item.command.parameters, item.command.param_count);
		};
	}
}

void checkButtonClick(char key[], bool repeat) // check and execute if one of the buttons are clicked.
{
	for (int i = 0; i < stored_button_count; i++) // check for each command
	{
		button_commands_t item = stored_button_commands[i];

		for (int j = 0; j < item.buttonsAmmt; j++) // check for each button in the commands array
		{
			if (strcmp(key, item.buttons[j])==0 && item.repeat == repeat)
			{
				item.command.function(item.command.parameters, item.command.param_count);
			};
		}
	}
}

void checkFrameKey(char key[]) // check for input in hold every frame
{
	if (strcmp(key, "KEY_TOUCH") == 0) checkTouchClick(); // check in touch functions
	else checkButtonClick(key, true);
}

void checkSingleKey(char key[]) // check for inputs if diff from before
{
	checkButtonClick(key, false);
}