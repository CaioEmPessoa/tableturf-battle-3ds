// constants
#define TOP_SCREEN_WIDTH  400
#define TOP_SCREEN_HEIGHT 240

#define BOT_SCREEN_WIDTH  320
#define BOT_SCREEN_HEIGHT 240

// macros
#define ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))
#define UNUSED(x) (void)(x)

// board elements
static int maxTileX = 10; // set tile boundaries
static int maxTileY = 10;

static int topSqrSize = 10; // top screen sqr size
static int btnSqrSize = 10; // bottom screen sqr size

static int playerTileX = 1; // player positioning
static int playerTileY = 1;

static bool cursorBot = false;

static char slctScreen; // screen that is being drawn on

// touch elements
static touchPosition touch; // touch coords, touch.px & touch.py

// bottom screen touch elements
static int touchEl[50][4] = {}; // touch elements