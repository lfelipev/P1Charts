#include <stdio.h>
#include <string.h>
#define M_PI  3.14159265358979323846

#include "drawing.h"
#include "storage.h" 

void pizza(Drawer * drawer, Chart * chart) {
    float initAngle = 0.0;
    float Colors[5][3]={1.0, 0.0, 0.0, 
                        0.0, 1.0, 0.0, 
                        0.0, 0.0, 1.0, 
                        1.0, 1.0, 0.0, 
                        1.0, 0.0, 1.0};
    for(int i = 0; chart->content[i] != 0; ++i) {
        Arc arc = {chart->chartWidth/3.3, //x
                  chart->chartHeight/1.8, //y
                  initAngle, //initAngle"
                  initAngle + chart->content[i]->percentage*2*M_PI, //endAngle
                  ((chart->chartWidth)+(chart->chartHeight))*0.16,   //radius
                  0.5, // borderWidth
                  {Colors[i][0], Colors[i][1], Colors[i][2], 1.0}, // Color Bg
                  {0.0, 0.0, 0.0, 1.0} // Color border
        };
        DrawerDrawArc(drawer, arc);
        initAngle += chart->content[i]->percentage*2*M_PI;
	}
}

void PizzaLabel(Drawer * drawer, Chart * chart) {
	int initY = (chart->chartHeight/4);
	float Colors[5][3]={1.0, 0.0, 0.0, 
			    0.0, 1.0, 0.0, 
                            0.0, 0.0, 1.0, 
                            1.0, 1.0, 0.0, 
			    1.0, 0.0, 1.0};
	for(int i = 0; chart->content[i] != 0; ++i) {
		Rectangle rect = {(chart->chartWidth/2)+(chart->chartHeight/5), //x
					  	initY + i*(chart->chartWidth/10), //y
					  	chart->chartWidth/10, //width
					  	chart->chartHeight/10, //height
					  	0.5, // borderWidth
					  	{Colors[i][0], Colors[i][1], Colors[i][2], 1.0}, // Color Bg
					  	{0.0, 0.0, 0.0, 1.0} // Color border
		};
		Label lab = {chart->content[i]->label, //Label
					(chart->chartWidth/2)+(chart->chartHeight/2.85), //x
					initY + (chart->chartWidth/20) + i*(chart->chartWidth/10), //y
					chart->chartWidth //para o tamanho da fonte
		};
		DrawerDrawRectangle(drawer, rect);
		DrawerDrawPizzaLabel(drawer, lab);
	}	
}

int main() {
	Chart * chart = ChartCreate("test.json");
	Drawer * cairo = DrawerInit(chart->chartWidth, chart->chartHeight, chart->fileType, chart->filePath); //cria o background
	Rectangle base = {0, //x
					  0, //y
					  chart->chartWidth, //width
					  chart->chartHeight, //height
					  0.0, // borderWidth
					  {1.0, 1.0, 1.0, 1.0},// Color Bg
					  {0.0, 0.0, 0.0, 0.0}// Color border (borderless)
	};
	DrawerDrawRectangle(cairo, base);
	
		
	
	Title titl = {chart->chartName,
				chart->chartWidth,
				chart->chartHeight
	};
	
	DrawerDrawTitle(cairo, titl);
	pizza(cairo, chart);
	PizzaLabel(cairo, chart);
	DrawerSave(cairo, chart->fileType, chart->filePath);
	DrawerDestroy(cairo);
	return 0;
}
