#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <stdlib.h>
#include <math.h>

struct _drawer {
	cairo_surface_t *surface;
    cairo_t * context;
};

typedef struct _drawer Drawer;

struct _color {
	float r, g, b, a;
};

typedef struct _color Color;

struct _rectangle {
	int x;
	int y;
	float width;
	float height;
	float borderWidth;
	Color bg;
	Color border;
};

typedef struct _rectangle Rectangle;

struct _arc {
    int x;
    int y;
	float initAngle;
	float endAngle;
	float radius;
	float borderWidth;
	Color bg;
	Color border;
};

typedef struct _arc Arc;

struct _title {
	const char * chartTitle;
	float spacWidth;
	float spacHeidth;
};

typedef struct _title Title;

struct _label {
	const char * chartLabel;
	float spacX;
	float spacY;
	float sizeWidth;
	const char * percentage;
	float spacpercentageX;
	float spacpercentageY;
	float cor1;
	float cor2;
	float cor3;
	float percentage_cor1;
	float percentage_cor2;
	float percentage_cor3;
};

typedef struct _label Label;

struct _line {
	double init_horizontal_x;
	double init_horizontal_y;
	double final_horizontal_x;
	double init_vertical_y;
	double final_vertical_y;
};

typedef struct _line Line;

Drawer * DrawerInit(int width, int height, char fileTypePDF, const char * filePath);
void DrawerDestroy(Drawer * self);
void DrawerDrawRectangle(Drawer * self, Rectangle rect);
void DrawerDrawArc(Drawer * self, Arc arc);
void DrawerDrawTitle(Drawer * self, Title titl);
void DrawerDrawLines(Drawer * self, Line line);
void DrawerDrawLabel(Drawer * self, Label lab);
void DrawerSave(Drawer * self, char fileTypePDF, const char * filePath);
