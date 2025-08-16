typedef void (*voidFunc)(void*);

typedef struct {
    voidFunc command;
    void* args;
    int* xywh;
    bool screen;
} TouchElements;

typedef struct {
    voidFunc command;
    void* args;
    char* buttons; // TODO: can add multiple buttons into a single command
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

    touchElementsAmmt++;
}

void addButtonElement(char* buttons, voidFunc command, void* args, size_t args_size)
{
    buttonElements[buttonElementsAmmt].command = command;
    buttonElements[buttonElementsAmmt].buttons = buttons;

    if (args != NULL && args_size > 0)
    {
        buttonElements[buttonElementsAmmt].args = malloc(args_size);
        memcpy(buttonElements[buttonElementsAmmt].args, args, args_size);
    } else
    {
        buttonElements[buttonElementsAmmt].args = NULL;
    }

    buttonElementsAmmt++;
}


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

#define ADD_BUTTON_ELEMENT_CHAR(buttons, command, value) \
    do { \
        char arg = (value); \
        addTouchElement((buttons), (command), &arg, sizeof(char)); \
    } while(0)