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
    float initAngle = 0.0;
    // Condicional para o tamanho do Background
    if (chart->chartWidth >= chart->chartHeight) {
    	for(int i = 0; chart->content[i] != 0; ++i) {
    	    // Estrutura para Desenhar a Pizza
        	Arc arc = { // Posição X do Centro:
        	            (chart->chartWidth/2)-((chart->chartWidth/11)+(chart->chartHeight/11)),
                  	    // Posição Y do Centro:
                  	    chart->chartHeight*0.55,
                  	     // Ângulo Inicial:
                  	    initAngle,
                  	    // Ângulo Final (De acordo com a porcentagem):
                  	    initAngle + chart->content[i]->percentage*2*M_PI,
                  	    // Raio:
                  	    ((chart->chartWidth)+(chart->chartHeight))*0.15,
                  	    // Espessura
                  	    0.5,
                  	    // Cores:
                  	    {Colors[i][0], Colors[i][1], Colors[i][2], 1.0},
                  	    {0.0, 0.0, 0.0, 1.0}
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
    // Dados iniciais para a criação da Pizza
	float cont = 0;
	float initY;
	for(int i = 0; chart->content[i] != 0; ++i) {
		++cont;
	}
	
	// Condiçional para o tamanho do background
	if (chart->chartWidth >= chart->chartHeight) {
		if (cont == 1) {
			initY = chart->chartHeight/2;
		}
		else {
			initY = (chart->chartHeight/2) / (cont*0.6);
		}
		for(int i = 0; chart->content[i] != 0; ++i) {
		    // Estrutura para Desenhar os Quadrados da Label
		    Rectangle rect = {
		                        // Ponto X inicial:
		                        (chart->chartWidth/2)+(chart->chartHeight/5),
		                        // Ponto Y inicial:
						  	    initY + i*(chart->chartHeight/20) + i*(chart->chartHeight/12),
						  	    // Largura do Quadrado:
						  	    chart->chartWidth/10,
						  	    // Altura do Quadrado:
						  	    chart->chartHeight/12,
						  	    // Espeçura:
						  	    0.5,
						  	    // Cores:
						  	    {Colors[i][0], Colors[i][1], Colors[i][2], 1.0},
						  	    {0.0, 0.0, 0.0, 1.0}
			};
			
			// Criação das informações da Label
			char * percentage = malloc(sizeof (char)*20);
			sprintf(percentage, "%d%%", (int)(chart->content[i]->percentage*100));
			/* Estrutura para o Nome e Porcentagem da Label */
			Label lab = {
			                // Label:
			                chart->content[i]->label,
			                // Ponto X da Label:
						    (chart->chartWidth/2)+(chart->chartHeight/2.9),
						    // Ponto Y da Label:
						    initY + chart->chartHeight/20 + i*(chart->chartHeight/20) + i*(chart->chartHeight/12),
						    // Para o tamanho da fonte:
						    chart->chartWidth,
						    // Porcentagem:
						    percentage,
						    // Ponto X da Porcentagem:
						    (chart->chartWidth/2)+(chart->chartHeight/4.35),
						    // Ponto Y da Porcentagem:
						    initY + chart->chartHeight/20 + i*(chart->chartHeight/20) + i*(chart->chartHeight/12),
						    // Cores da Label:
						    1.0,
						    1.0,
						    1.0,
						    // Cores da Porcentagem:
						    0.0,
						    0.0,
				            0.0										
			};
			DrawerDrawRectangle(drawer, rect);
			DrawerDrawLabel(drawer, lab);
		}
	}	
}

void bars(Drawer * drawer, Chart * chart) {
    /* Estrutura para desenhar os Eixos */
	Line lin = {
	            // Posição X(inicial) da Linha Horizontal:
		        chart->chartWidth*0.0625,
		        // Posição Y(inicial) da Linha Horizontal:
		        chart->chartHeight*0.8333,
		        // Define o tamanho da Linha Horizontal (X Final):
		        chart->chartWidth - (chart->chartWidth*0.0625),
		        // Posição Y(inicial) da Linha Vertical:
		        chart->chartHeight*0.9166,
		        // Define a altura da Linha Vertical (Y Final):
		        chart->chartHeight*0.1667,
	};
	DrawerDrawLines(drawer, lin);
	
	/* Dados iniciais para a criação das Barras */
	float initX = chart->chartWidth*0.2;
	float maior_porcentagem = chart->content[0]->percentage;
	const char * maior_legenda;
	int cont = 0;
	for(int i = 0; chart->content[i] != 0; ++i) {
		++cont;
		if (chart->content[i]->percentage >= maior_porcentagem) {
			maior_porcentagem = chart->content[i]->percentage;
			maior_legenda = chart->content[i]->label;
		}
	}

	for(int i = 0; chart->content[i] != 0; ++i) {
        /* Estrutura para criação das Barras */
		Rectangle rect = {  // Pocição das Barras no eixo X:
		                    initX + i*(chart->chartWidth*0.5)/(cont) + i*(chart->chartWidth/20),
		                    // Posição da barra no eixo y (Não Mecher):
					  	    chart->chartHeight*0.8333, 
					  	    // Largura da Barra(Eixo X):
					  	    (chart->chartWidth*0.5)/(cont),
					  	    // Altura da Barra (De acordo com a porcentagem):
					  	    -((chart->content[i]->percentage)*(chart->chartHeight*0.60)/maior_porcentagem),
					  	    0.5, // borderWidth
					  	    {Colors[i][0], Colors[i][1], Colors[i][2], 1.0}, // Color Bg
					  	    {0.0, 0.0, 0.0, 1.0} // Color border
		};
        
        /* Estruturas para criação da label */            
		char * percentage = malloc(sizeof (char)*20);
		sprintf(percentage, "%d%%", (int)(chart->content[i]->percentage*100));

		Label lab = {
		                //Label Nome da Legenda:
		                chart->content[i]->label, 
		                //Posição X da legenda (Corretamente Centralizada):
					    initX + i*(chart->chartWidth*0.5)/(cont) + i*(chart->chartWidth/20) + ((chart->chartWidth*0.5)/(cont))/4,
					    // Posição Y da legenda: 
					    chart->chartHeight*0.88, 
					    // Para o tamanho da fonte
					    chart->chartWidth, 
					    // Porcentagem:
					    percentage, 
					    // Posição X da porcentagem:
					    chart->chartWidth*0.05, 
					    // Posição Y da Porcentagem (Correto):
					    chart->chartHeight*0.8333 - ((chart->content[i]->percentage)*(chart->chartHeight*0.60)/maior_porcentagem),
					    // Cores da Label: 
					    0.0,
					    0.0,
					    0.0,
					    // Cores da Porcentagem:
					    0.0,
					    0.0,
					    0.0	
		};
		
	    /* Chama as funções de Desenho */
		DrawerDrawRectangle(drawer, rect);
		DrawerDrawLabel(drawer, lab);
	}
}

int main() {
	Chart * chart = ChartCreate("test.json");
	Drawer * cairo = DrawerInit(chart->chartWidth, chart->chartHeight, chart->fileType, chart->filePath);
	
	//Estrutura para o Background
	Rectangle base = {0, //x
					  0, //y
					  chart->chartWidth, //width
					  chart->chartHeight, //height
					  0.0, // borderWidth
					  {1.0, 1.0, 1.0, 1.0},// Color Bg
					  {0.0, 0.0, 0.0, 0.0}// Color border (borderless)
	};
	DrawerDrawRectangle(cairo, base);
	
	//Estrutura para o título
	Title titl = {chart->chartName,
				chart->chartWidth,
				chart->chartHeight
	};
	DrawerDrawTitle(cairo, titl);
	
	//bars(cairo, chart);
	pizza(cairo, chart);
	PizzaLabel(cairo, chart);
	DrawerSave(cairo, chart->fileType, chart->filePath);
	DrawerDestroy(cairo);
	return 0;
}
