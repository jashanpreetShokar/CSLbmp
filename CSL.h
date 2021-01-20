// JASHANPREET SHOKAR 2021 (C)
#ifndef CSLBMP_H
#define CSLBMP_H
#include <stdio.h>
#include <SDL.h>

/*
this code shouldn't be used. Only for learning use. 

*/

typedef struct CSLbmp
{
	SDL_Surface* pixels;
	SDL_PixelFormat* pf;
	int width, height;
	SDL_Color color;
	Uint32 data;
} CSLbmp_t;


// https://stackoverflow.com/questions/53033971/how-to-get-the-color-of-a-specific-pixel-from-sdl-surface
Uint32 getpixel(SDL_Surface* surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp)
	{
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16*)p;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32*)p;
		break;

	default:
		return 0;       /* shouldn't happen, but avoids warnings */
	}
}

CSLbmp_t loadImage(const char* string)
{
	CSLbmp_t get;
	get = { 0 };

	get.pixels = SDL_LoadBMP(string);
	if (get.pixels == NULL) {
		printf("ERROR: %s\n", SDL_GetError());
		exit(100);
	}
 	get.pf = get.pixels->format;
	if (get.pf->BitsPerPixel != 8) {
		printf("ERROR:: Wasn't 8 BITS. \n");
		exit(100);
	}
	SDL_LockSurface(get.pixels);
	get.width = get.pixels->w;
	get.height = get.pixels->h;
	return get;
 }
void DrawImage(CSLbmp_t* structure , SDL_Renderer* renderer) {
	for (int x = 0; x < structure->width; x++) {
		for (int y = 0; y < structure->height; y++) {


			structure->data = getpixel(structure->pixels, x, y);
			SDL_GetRGBA(structure->data, structure->pf, &structure->color.r, &structure->color.g, &structure->color.b,&structure->color.a);
			SDL_SetRenderDrawColor(renderer, structure->color.r, structure->color.g, structure->color.b, structure->color.a);

			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}
#endif
