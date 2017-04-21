#include <stdlib.h>
#include "bitmap.h"

int main(void)
{
	//Read bitmap pixels, convert to HSV:
	bitmap_pixel_hsv_t* pixels;
	int widthPx, heightPx;

	bitmapReadPixels("test.bmp", (bitmap_pixel_t**)&pixels, &widthPx, &heightPx, BITMAP_COLOR_SPACE_HSV);

	//Write bitmap pixels, assume HSV in soruce:
	bitmap_parameters_t params;

	params.bottomUp = BITMAP_BOOL_TRUE;
	params.widthPx = widthPx;
	params.heightPx = heightPx;
	params.colorDepth = BITMAP_COLOR_DEPTH_32;
	params.compression = BITMAP_COMPRESSION_NONE;
	params.dibHeaderFormat = BITMAP_DIB_HEADER_INFO;
	params.colorSpace = BITMAP_COLOR_SPACE_HSV;

	bitmapWritePixels("test.mod.bmp", BITMAP_BOOL_TRUE, &params, (bitmap_pixel_t*)pixels);

	//Free the pixel array:
	free(pixels);

	return 0;
}
