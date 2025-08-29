typedef struct {
    voidFunc command;
    void* args;
    int posX;
    int posY;
} MenusElements;

typedef struct {
    int xMenuAmmt;
    int yMenuAmmt;
    char loadedScreen;
    MenusElements* menuElements;   
} Menu;

// TODO:
// Abrir os menus automaticamente em outro codigo ..?

static MenusElements menusElements[50]; // vai ter que ser malloc

void addMenuElement(voidFunc command, void* args, size_t args_size)
{

}

// +1 or -1 to move one menu to the right, left, up and right
void changeCurrentMenu(int x, int y)
{
    int currentX = currentMenu.gridX;
    int currentY = currentMenu.gridY;

    if (currentX += 1 >= )

    currentMenu.gridX = 
}