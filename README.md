# CSLbmp
This project shouldn't be used at all, it's a fun lil project I made that, if you have a SDL context, it'll allow you to render in a BMP file, it only works with 8-bit BMP

# WARNING
don't use this code, it's mostly for learning purposes.


#SETUP
very easy setup,
```C
CSLbmp_t bmp_img = CSLBMP_loadimage("image_8bit.bmp");
CSLBMP_setposition(100 / 2, 100 / 2,&bmp_img);
 // .... do your renderer code, and everything else.

// SDL_RenderClear
CSLBMP_draw(&bmp_img, win.get_renderer());
// SDL_RenderPresent
```


