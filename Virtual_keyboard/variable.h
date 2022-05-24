
#define MINPRESSURE 200
#define MAXPRESSURE 1000

const int XP = 8, XM = A2, YP = A3, YM = 9; //320x480 ID=0x9486
const int TS_LEFT = 124, TS_RT = 904, TS_TOP = 956, TS_BOT = 89;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

int pixel_x, pixel_y;     //Touch_getXY() updates global vars

/*#define BLACK   0x0000
  #define BLUE    0x001F
  #define RED     0xF800
  #define GREEN   0x07E0
  #define CYAN    0x07FF
  #define MAGENTA 0xF81F
  #define YELLOW  0xFFE0
  #define WHITE   0xFFFF
*/
int color [] = {0x0000, 0x001F, 0xF800, 0x07E0, 0x07FF, 0xF81F, 0xFFE0, 0xFFFF};

char keys[4][10] = {
  { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' },
  { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
  { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ','},
  { '*', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '.', '<'}
};

int xco [40], yco[40];
bool con = false;
int xindex, yindex;
int actualx [10] ={8,40,72,104,136,168,200,232,264,296};
int actualy [4] ={358,391,424,457};

/*int xysheet [4][10] = {//actual generated xy values of the keys.
  {(8, 358), (40, 358), (72, 358), (104, 358), (136, 358), (168, 358), (200, 358), (232, 358), (264, 358), (296, 358)},
  {(8, 391), (40, 391), (72, 391), (104, 391), (136, 391), (168, 391), (200, 391), (232, 391), (264, 391), (296, 391)},
  {(8, 424), (40, 424), (72, 424), (104, 424), (136, 424), (168, 424), (200, 424), (232, 424), (264, 424), (296, 424)},
  {(8, 457), (40, 457), (72, 457), (104, 457), (136, 457), (168, 457), (200, 457), (232, 457), (264, 457), (296, 457)}
};*/

String text;

#include"primary.h"
