#include <stdio.h>
#include <string.h>
#define M_PI  3.14159265358979323846
#include "drawing.h"
#include "storage.h" 
float Colors[5][3]={1.0, 0.0, 0.0, 
                        0.0, 1.0, 0.0, 
                        0.0, 0.0, 1.0, 
                        1.0, 1.0, 0.0, 
                        1.0, 0.0, 1.0};

void pizza(Drawer * drawer, Chart * chart) {
    float initAngle = 0.0;//
    if (chart->chartWidth >= chart->chartHeight) {
    	for(int i = 0; chart->content[i] != 0; ++i) {
        	Arc arc = {(chart->chartWidth/2)-((chart->chartWidth/11)+(chart->chartHeight/11)), //x
                  	chart->chartHeight*0.55, //y  calculo:(h/2 + h/20 = 11h/20)
                  	initAngle, //initAngle"
                  	initAngle + chart->content[i]->percentage*2*M_PI, //endAngle
                  	((chart->chartWidth)+(chart->chartHeight))*0.15,   //radius
                  	0.5, // borderWidth
                  	{Colors[i][0], Colors[i][1], Colors[i][2], 1.0}, // Color Bg
                  	{0.0, 0.0, 0.0, 1.0} // Color border
        	};
        	DrawerDrawArc(drawer, arc);
        	initAngle += chart->content[i]->percentage*2*M_PI;
		}
	}
    else {
	for(int i = 0; chart->content[i] != 0; ++i) {
        	Arc arc = {(chart->chartWidth/2), //x
                  	chart->chartHeight/2.3, //y  calculo:(h/2 + h/20 = 11h/20)
                  	initAngle, //initAngle"
                  	initAngle + chart->content[i]->percentage*2*M_PI, //endAngle
                  	((chart->chartWidth)+(chart->chartHeight))*0.18,   //radius
                  	0.5, // borderWidth
                  	{Colors[i][0], Colors[i][1], Colors[i][2], 1.0}, // Color Bg
                  	{0.0, 0.0, 0.0, 1.0} // Color border
        	};
        	DrawerDrawArc(drawer, arc);
        	initAngle += chart->content[i]->percentage*2*M_PI;
		}
    
    }		
}

void PizzaLabel(Drawer * drawer, Chart * chart) {
	float cont = 0;
	float initY;
	for(int i = 0; chart->content[i] != 0; ++i) {
		++cont;
	}
	if (chart->chartWidth >= chart->chartHeight) {
		if (cont == 1) {
			initY = chart->chartHeight/2;
		}
		else {
			initY = (chart->chartHeight/2) / (cont*0.6);
		}
		for(int i = 0; chart->content[i] != 0; ++i) {
			Rectangle rect = {(chart->chartWidth/2)+(chart->chartHeight/5), //x
						  	initY + i*(chart->chartWidth/10), //y
						  	chart->chartWidth/10, //width
						  	chart->chartHeight/10, //height
						  	0.5, // borderWidth
						  	{Colors[i][0], Colors[i][1], Colors[i][2], 1.0}, // Color Bg
						  	{0.0, 0.0, 0.0, 1.0} // Color border
			};
			char * percentage = malloc(sizeof (char)*20);
			sprintf(percentage, "%d%%", (int)(chart->content[i]->percentage*100));
			Label lab = {chart->content[i]->label, //Label
						(chart->chartWidth/2)+(chart->chartHeight/2.85), //x
						initY + (chart->chartWidth/20) + i*(chart->chartWidth/10), //y
						chart->chartWidth, //para o tamanho da fonte
						percentage, // porcentagem
						(chart->chartWidth/2)+(chart->chartHeight/4.35) //x percentage
			};
			DrawerDrawRectangle(drawer, rect);
			DrawerDrawPizzaLabel(drawer, lab);
		}
	}	
}

void bars(Drawer * drawer, Chart * chart) {
	Line lin = {
		chart->chartWidth*0.0625, // x horizontal
		chart->chartHeight*0.8333, // y horizontal
		chart->chartHeight*0.9166, // y da vertical
		chart->chartWidth - (chart->chartWidth*0.0625), // largura x
		chart->chartHeight*0.1667, //  y
		chart->chartHeight*0.14,
		3	// tamanho da fonte	
	};
	DrawerDrawLines(drawer, lin);
	float initY;
	for(int i = 0; chart->content[i] != 0; ++i) {
			Rectangle rect = {chart->chartWidth*0.2, //x
						  	chart->chartHeight*0.8333, //y NÃO MECHER
						  	chart->chartWidth*0.650, //width
						  	-chart->chartHeight/10, //height
						  	0.5, // borderWidth
						  	{Colors[i][0], Colors[i][1], Colors[i][2], 1.0}, // Color Bg
						  	{0.0, 0.0, 0.0, 1.0} // Color border
			};
			DrawerDrawRectangle(drawer, rect);
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
	bars(cairo, chart);
	//pizza(cairo, chart);
	//PizzaLabel(cairo, chart);
	DrawerSave(cairo, chart->fileType, chart->filePath);
	DrawerDestroy(cairo);
	return 0;
}
