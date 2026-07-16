
#define TOP_SCREEN_WIDTH  400
#define TOP_SCREEN_HEIGHT 240

#define BOT_SCREEN_WIDTH  320
#define BOT_SCREEN_HEIGHT 240

typedef enum {TOP, BOTTOM, NONE} screen_types;

typedef struct {C3D_RenderTarget* top; C3D_RenderTarget* bottom;} Screens;

static screen_types selectedScreen; // screen that is being drawn on
static touchPosition touch; // touch coords, touch.px & touch.py
static bool cursorBot = false; // if cursor (touch) is on bottom or top screen

// macros
#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))
#define UNUSED(x) (void)(x)

// App-specific globals

static int topSqrSize = 10; // top screen sqr size
static int btnSqrSize = 10; // bottom screen sqr size