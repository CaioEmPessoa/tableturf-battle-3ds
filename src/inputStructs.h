
typedef void (*voidFunc)(void);

typedef struct {
    voidFunc voidFunc;
    int xyhw[4];
    bool screen;
} TouchElements;

typedef struct {
    voidFunc voidFunc;
    char buttons[20][30]; // can add multiple buttons into a single command
    bool screen;
} ButtonElements;

static int touchElementsAmmt  = 0;
static int buttonElementsAmmt = 0;

static TouchElements touchElements[30];
static ButtonElements buttonElements[30];

void addTouchElement(voidFunc command, int xyhw[4], bool screen)
{
    touchElements[touchElementsAmmt].voidFunc = command;
    touchElements[touchElementsAmmt].screen = screen;
    for(int i = 0; i < 4; i++) {
        touchElements[touchElementsAmmt].xyhw[i] = xyhw[i];
    }
    touchElementsAmmt+=1;
}

void addButtonElement(voidFunc command, char buttons[20][30], bool screen)
{
    buttonElements[buttonElementsAmmt].voidFunc = command;
    buttonElements[buttonElementsAmmt].screen = screen;
    for(int i = 0; i < 20; i++) {
        strncpy(buttonElements[buttonElementsAmmt].buttons[i], buttons[i], 30);
    }
    buttonElementsAmmt+=1;
}