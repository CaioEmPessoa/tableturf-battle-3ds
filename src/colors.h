
// function to convert from decimal to hexadecimal

// TODO: change svd colors to general function where put rgba values

// ------------| COLOR VARIABLES |-----------
u32 svdColors(int cId)
{
	u32 clrRed    = C2D_Color32(0xFF, 0x00, 0x00, 0xFF); // 1
	u32 clrBlue   = C2D_Color32(0x00, 0x00, 0xFF, 0xFF); // 2
	u32 clrGreen  = C2D_Color32(0x00, 0xFF, 0x00, 0xFF); // 3
	u32 clrWhite  = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF); // 4
	u32 clrPink   = C2D_Color32(0xFF, 0xC0, 0xCB, 0xFF); // 5
	u32 clrOrange = C2D_Color32(0xFF, 0xA5, 0x00, 0xFF); // 6
	u32 clrPurple = C2D_Color32(0x80, 0x00, 0x80, 0xFF); // 7
	u32 clrBlack  = C2D_Color32(0x00, 0x00, 0x00, 0xFF); // 8
	u32 clrClear = C2D_Color32(0xFF, 0xD8, 0xB0, 0xFF); // 9

	u32 svdColors[9] = {
		clrRed, clrBlue, clrGreen, clrWhite, clrPink, clrOrange, clrPurple, clrBlack, clrClear
	};

	return svdColors[cId];
}