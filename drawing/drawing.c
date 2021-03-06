#include "drawing.h"

Drawer * DrawerInit(int width, int height, char fileTypePDF, const char * filePath) {
	Drawer * self = malloc(sizeof(Drawer));
	if(fileTypePDF) {
		self->surface = cairo_pdf_surface_create(filePath, width, height);
	} else {
		self->surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	}
    self->context = cairo_create(self->surface);
    cairo_set_antialias(self->context, CAIRO_ANTIALIAS_BEST);
    return self;
}

void DrawerDestroy(Drawer * self){
	cairo_destroy(self->context);
    cairo_surface_destroy(self->surface);
    free(self);
}

void DrawerDrawRectangle(Drawer * self, Rectangle rect) {
	cairo_save(self->context);
	cairo_set_line_width(self->context, rect.borderWidth);
	cairo_rectangle (self->context, rect.x, rect.y, rect.width, rect.height);
	cairo_set_source_rgba(self->context,
						  rect.bg.r,
						  rect.bg.g,
						  rect.bg.b,
						  rect.bg.a);
	cairo_fill_preserve(self->context);
 	cairo_set_source_rgba(self->context,
 						  rect.border.r,
 						  rect.border.g,
 						  rect.border.b,
 						  rect.border.a);
 	cairo_stroke(self->context);
 	cairo_restore(self->context);
}


void DrawerDrawLines(Drawer * self, Line line) {
                                   // Inicio            Fim
	cairo_move_to (self->context, line.init_horizontal_x, line.init_horizontal_y);
	                                // Destino X            Destino Y
	cairo_line_to (self->context, line.final_horizontal_x, line.init_horizontal_y);
	cairo_line_to (self->context, line.final_horizontal_x*(0.98), line.init_horizontal_y*(0.99));
	cairo_line_to (self->context, line.final_horizontal_x, line.init_horizontal_y);
	cairo_line_to (self->context, line.final_horizontal_x*(0.98), line.init_horizontal_y*(1/(0.99)));
                                       
	cairo_move_to (self->context, (line.init_horizontal_x)*2, line.init_vertical_y);
	cairo_line_to (self->context, (line.init_horizontal_x)*2, line.final_vertical_y);
	cairo_line_to (self->context, (line.init_horizontal_x)*2*(0.94), line.final_vertical_y*(1.12));
	cairo_line_to (self->context, (line.init_horizontal_x)*2, line.final_vertical_y);
	cairo_line_to (self->context, (line.init_horizontal_x)*2*(1/(0.94)), line.final_vertical_y*(1.12));

	cairo_set_line_width (self->context, 3);
	cairo_set_line_cap (self->context, CAIRO_LINE_CAP_ROUND);
	cairo_stroke (self->context);
}

void DrawerDrawTitle(Drawer * self, Title titl) {
  cairo_text_extents_t extents; //Para centralizar o título
  cairo_set_source_rgb(self->context, 0.0, 0.0, 0.0); // Cor do Texto

  cairo_select_font_face(self->context, "Umpush", //
      CAIRO_FONT_SLANT_NORMAL,			// Fonte
      CAIRO_FONT_WEIGHT_BOLD);			//

  cairo_set_font_size(self->context, titl.spacWidth*0.055);	// Tamanho do Texto
  cairo_text_extents(self->context, titl.chartTitle, &extents); // Título

  cairo_move_to(self->context, titl.spacWidth/2 - extents.width/2, titl.spacHeidth*0.09); //Posição do Título
  cairo_show_text(self->context, titl.chartTitle); 

  cairo_stroke(self->context);
}

void DrawerDrawLabel(Drawer * self, Label lab) {
	cairo_set_source_rgb(self->context, lab.percentage_cor1, lab.percentage_cor2, lab.percentage_cor3);

	cairo_select_font_face(self->context, "Arial",
		CAIRO_FONT_SLANT_NORMAL,
      		CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(self->context, lab.sizeWidth*0.030);

	cairo_move_to(self->context, lab.spacX, lab.spacY); //desenha a legenda
  	cairo_show_text(self->context, lab.chartLabel);

	cairo_set_source_rgb(self->context, lab.cor1, lab.cor2, lab.cor3);
	
	cairo_move_to(self->context, lab.spacpercentageX, lab.spacpercentageY); //desenha a porcentagem da legenda
  	cairo_show_text(self->context, lab.percentage);

	cairo_stroke(self->context);	
}

void DrawerDrawArc(Drawer * self, Arc arc) {
    cairo_save(self->context);
    cairo_set_line_width(self->context, arc.borderWidth);
    cairo_arc (self->context,
               arc.x,
               arc.y,
               arc.radius,
               arc.initAngle,
               arc.endAngle);
    cairo_line_to(self->context, arc.x, arc.y);
    cairo_arc (self->context,
               arc.x,
               arc.y,
               arc.radius,
               arc.initAngle,
               arc.initAngle);
    cairo_line_to(self->context, arc.x, arc.y);
    cairo_set_source_rgba(self->context,
						  arc.bg.r,
						  arc.bg.g,
						  arc.bg.b,
						  arc.bg.a);
	cairo_fill_preserve(self->context);
 	cairo_set_source_rgba(self->context,
 						  arc.border.r,
 						  arc.border.g,
 						  arc.border.b,
 						  arc.border.a);
 	cairo_stroke(self->context);
    cairo_restore(self->context);
}


void DrawerSave(Drawer * self, char fileTypePDF, const char * filePath) {
	if(fileTypePDF) {
		cairo_show_page(self->context);
	} else {
		cairo_surface_write_to_png(self->surface, filePath);
	}
}
