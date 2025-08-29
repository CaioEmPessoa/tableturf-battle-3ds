
u32 getColor(const char* colorName)
{
    if (strcmp(colorName, "red") == 0)
        return C2D_Color32(255, 0, 0, 255);

    else if (strcmp(colorName, "sleeveBackground") == 0)
        return C2D_Color32(0, 179, 160, 255);

    else if (strcmp(colorName, "blue") == 0)
        return C2D_Color32(0, 0, 255, 255);

    else if (strcmp(colorName, "green") == 0)
        return C2D_Color32(0, 255, 0, 255);

    else if (strcmp(colorName, "white") == 0)
        return C2D_Color32(255, 255, 255, 255);

    else if (strcmp(colorName, "pink") == 0)
        return C2D_Color32(255, 192, 203, 255);

    else if (strcmp(colorName, "orange") == 0)
        return C2D_Color32(255, 165, 0, 255);

    else if (strcmp(colorName, "purple") == 0)
        return C2D_Color32(128, 0, 128, 255);

    else if (strcmp(colorName, "black") == 0)
        return C2D_Color32(0, 0, 0, 255);

    else if (strcmp(colorName, "clear") == 0)
        return C2D_Color32(255, 216, 176, 255);

    else
        return C2D_Color32(0, 0, 0, 255); // black as default
}