#include <stdio.h>
#include <string.h>
#define M_PI  3.14159265358979323846
#include "drawing.h"
#include "storage.h" 

/* Cores Fixas: Red, Green, Blue, Yellow, Mangenta */
float Colors[5][3]={1.0, 0.0, 0.0, 
                        0.0, 1.0, 0.0, 
                        0.0, 0.0, 1.0, 
                        1.0, 1.0, 0.0, 
                        1.0, 0.0, 1.0};

void pizza(Drawer * drawer, Chart * chart) {
    float initAngle = 0.0;
	for(int i = 0; chart->content[i] != 0; ++i) {
	    /* Estrutura para Desenhar a Pizza */
    	Arc arc = { // Posição X do Centro:
    	            chart->chartWidth/3,
              	    // Posição Y do Centro:
              	    chart->chartHeight*0.55,
              	     // Ângulo Inicial:
              	    initAngle,
              	    // Ângulo Final (De acordo com a porcentagem):
              	    initAngle + chart->content[i]->percentage*2*M_PI,
              	    // Raio:
              	    chart->chartWidth*0.30,
              	    // Espessura
              	    0.09,
              	    // Cores:
              	    {Colors[i][0], Colors[i][1], Colors[i][2], 1.0},
              	    {0.0, 0.0, 0.0, 1.0}
    	};
    	DrawerDrawArc(drawer, arc);
    	initAngle += chart->content[i]->percentage*2*M_PI;
	}	
}

    
void pizzaLabel(Drawer * drawer, Chart * chart) {
	/* Dados iniciais para a criação da Pizza */
	float cont = 0;
	float initY;
	for(int i = 0; chart->content[i] != 0; ++i) {
		++cont;
	}
    if (cont == 1 || cont == 2) {
	    initY = chart->chartHeight/2.25;
    }
    else {
	    initY = (chart->chartHeight/1.6) / (cont*0.6);
    }
    
    /* Criação da Pizza */
    for(int i = 0; chart->content[i] != 0; ++i) {
        /* Estrutura para Desenhar os Quadrados da Label */
        Rectangle rect = {
                            // Ponto X inicial:
                            (chart->chartWidth/1.49),
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
	
	    /* Estrutura para o Nome e Porcentagem da Label */
	    char * percentage = malloc(sizeof (char)*20);
	    sprintf(percentage, "%d%%", (int)(chart->content[i]->percentage*100));
	    Label lab = {
	                    // Label:
	                    chart->content[i]->label,
	                    // Ponto X da Label:
				        chart->chartWidth/1.28,
				        // Ponto Y da Label:
				        initY + chart->chartHeight/20 + i*(chart->chartHeight/20) + i*(chart->chartHeight/12),
				        // Para o tamanho da fonte:
				        chart->chartWidth,
				        // Porcentagem:
				        percentage,
				        // Ponto X da Porcentagem:
				        chart->chartWidth/1.445,
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
	    /* Chama as funções de Desenho */
	    DrawerDrawRectangle(drawer, rect);
	    DrawerDrawLabel(drawer, lab);
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
        
        /* Dados para criação da label */            
		char * percentage = malloc(sizeof (char)*20);
		sprintf(percentage, "%d%%", (int)(chart->content[i]->percentage*100));
        /* Estrutura para criação da label */
		Label lab = {
		                //Label Nome da Legenda:
		                chart->content[i]->label, 
		                //Posição X da legenda:
					    initX + i*(chart->chartWidth*0.5)/(cont) + i*(chart->chartWidth/20) + ((chart->chartWidth*0.5)/(cont))/(cont+1),
					    // Posição Y da legenda: 
					    chart->chartHeight*0.88, 
					    // Para o tamanho da fonte
					    chart->chartWidth, 
					    // Porcentagem:
					    percentage, 
					    // Posição X da porcentagem:
					    chart->chartWidth*0.04, 
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

int main(int argc, char *argv[]) {
    int contador;
	Chart * chart = ChartCreate(argv[1]);
	Drawer * cairo = DrawerInit(chart->chartWidth, chart->chartHeight, chart->fileType, chart->filePath);	
	/* Estrutura para o Background */
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
	/* Estrutura para o título */
				chart->chartWidth,
				chart->chartHeight
	};
	DrawerDrawTitle(cairo, titl);
	
	/* Condicional: Barras ou Pizza? */
	if((strcmp(chart->chartType, "pizza")) == 0) {
	    pizza(cairo, chart);
	    pizzaLabel(cairo, chart);
	}
	else {
	    bars(cairo, chart);
	}
    
	DrawerSave(cairo, chart->fileType, chart->filePath);
	DrawerDestroy(cairo);
	return 0;
}
