typedef void (*voidFunc)(void*);

typedef struct {
    voidFunc command;
    void* args;
    int* xywh;
    bool screen;
} TouchElements;

typedef struct {
    voidFunc command;
    char buttons[20][30]; // can add multiple buttons into a single command
    bool screen;
} ButtonElements;

static int touchElementsAmmt  = 0;
static int buttonElementsAmmt = 0;

static TouchElements touchElements[30];
static ButtonElements buttonElements[30];

void addTouchElement(int* xywh, voidFunc command, void* args, size_t args_size)
{
    if (touchElementsAmmt >= 30) return;

    touchElements[touchElementsAmmt].command = command;
    touchElements[touchElementsAmmt].xywh = xywh;

    if (args != NULL && args_size > 0)
    {
        touchElements[touchElementsAmmt].args = malloc(args_size);
        memcpy(touchElements[touchElementsAmmt].args, args, args_size);
    } else
    {
        touchElements[touchElementsAmmt].args = NULL;
    }

    touchElementsAmmt+=1;
}

/*
void addButtonElement(char buttons[20][30], voidFunc command, bool screen)
{
    buttonElements[buttonElementsAmmt].command = command;
    buttonElements[buttonElementsAmmt].screen = screen;
    for(int i = 0; i < 20; i++) {
        strncpy(buttonElements[buttonElementsAmmt].buttons[i], buttons[i], 30);
    }
    buttonElementsAmmt+=1;
}
*/

// MACROS FOR USING THIS FUNCTIONS
#define ADD_TOUCH_ELEMENT_INT(xywh, command, value) \
    do { \
        int arg = (value); \
        addTouchElement((xywh), (command), &arg, sizeof(int)); \
    } while(0)

#define ADD_TOUCH_ELEMENT_CHAR(xywh, command, value) \
    do { \
        char arg = (value); \
        addTouchElement((xywh), (command), &arg, sizeof(char)); \
    } while(0)