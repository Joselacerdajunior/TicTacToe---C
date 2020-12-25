// definicoes
#define ALTURA 36 //mantenha 36
#define LARGURA ALTURA*2+1
#define METADE_LOGO  (LARGURA-1)/2

#define X_SE 0
#define Y_SE 0
#define X_SD LARGURA-1
#define Y_SD 0
#define X_IE 0
#define Y_IE ALTURA-1
#define X_ID LARGURA-1
#define Y_ID ALTURA-1

#define QUINA_C 206
#define QUINA_SE 201
#define QUINA_SD 187
#define QUINA_IE 200
#define QUINA_ID 188
#define QUINA_TRIPLA_D 185
#define QUINA_TRIPLA_E 204

#define LINHA_HORIZONTAL 205
#define LINHA_VERTICAL 186

#define SETA_CIMA 56
#define SETA_BAIXO 50
#define SETA_ESQUERDA 52
#define SETA_DIREITA 54
#define BOTAO_ENTER 13
#define BOTAO_ESC 27

#define TECLA_W 87
#define TECLA_w 119
#define TECLA_A 65
#define TECLA_a 97
#define TECLA_S 83
#define TECLA_s 115
#define TECLA_D 68
#define TECLA_d 100

#define PREENCIMENTO 219

// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

// funcoes
void gotoxy(int x, int y);
void desenhaMenu();
void desenhaContorno();
void desenhaInstrucoes();
void desenhaLogo();
void moverCursorParaBaixo();
void desenhaOpcao();
int  pegarQuantidadeCaracteres(char string[]);
void desenhaContornoOpcao(int opcao);
void apagaContornoOpcao(int opcao);
void inicializaFuncoesMenu();
void desenhaTabuleiro();
void limpaTela();
int  selecionaCampo(int x, int y, bool desenhar);
void desenhaContornoJogada(int x, int y);
void apagaContornoJogada(int x, int y);
void iniciarPartida(int modoDeJogo);
bool verificaGanhador(char string[]);
void desenhaMarcacaoJogador(int x, int y, char turno[]);
bool empate(char string[]);


int main() {
	desenhaMenu();
	inicializaFuncoesMenu();
	
	moverCursorParaBaixo();
	return 0;
} // final main

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} // final gotoxy

void desenhaMenu() {
	desenhaContorno();
	desenhaInstrucoes();
	desenhaLogo();
	desenhaOpcao();
	desenhaContornoOpcao(1);
	
	moverCursorParaBaixo();
} // final desenhaMenu

void desenhaContorno() {
	int x, y;
	x=y=0;
	for( x=1; x<(LARGURA-1); x++ ) {
		gotoxy(x, y);		
		printf("%c", LINHA_HORIZONTAL);
		gotoxy(x, ALTURA-1);		
		printf("%c", LINHA_HORIZONTAL);
	}
	
	x=0;
	y=1;
	for( y=1; y<(ALTURA-1); y++ ) {	
		gotoxy(x, y);
		printf("%c", LINHA_VERTICAL);
		gotoxy(LARGURA-1, y);
		printf("%c", LINHA_VERTICAL);
	}	
	
	gotoxy(X_SE, Y_SE);
	printf("%c", QUINA_SE);
	gotoxy(X_SD, Y_SD);
	printf("%c", QUINA_SD);
	gotoxy(X_IE, Y_IE);
	printf("%c", QUINA_TRIPLA_E);
	gotoxy(X_ID, Y_ID);
	printf("%c", QUINA_TRIPLA_D);	
} // final desenhaContorno

void desenhaInstrucoes() {
	int x, y, i;
	x = X_ID;
	y = Y_IE;
	
	gotoxy(0, y + 1); printf("%c", LINHA_VERTICAL);
	gotoxy(x, y + 1); printf("%c", LINHA_VERTICAL);
	gotoxy(0, y + 2); printf("%c", QUINA_IE);
	gotoxy(x, y + 2); printf("%c", QUINA_ID);
	for( i=1; i<X_ID; i++ ) {
		gotoxy(i, y + 2);
		printf("%c", LINHA_HORIZONTAL);
	}
	x = (x-6)/5;
	gotoxy(x - 9, y + 1); printf("W-Cima");
	gotoxy(x * 2 - 9, y + 1); printf("S-Baixo");
	gotoxy(x * 3 - 9, y + 1); printf("A-Esquerda");
	gotoxy(x * 4 - 9, y + 1); printf("D-Direita");
	gotoxy(x * 5 - 9, y + 1); printf("ENTER-Selecionar");	
} // final desenhaInstrucoes

void desenhaLogo() {
	int metade_eixo_x = METADE_LOGO;
	
	gotoxy(metade_eixo_x-18,  3); printf("   %c%c%c%c%c%c   %c%c%c%c    %c%c%c%c%c    %c%c%c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18,  4); printf("       %c%c  %c%c  %c%c  %c%c       %c%c  %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18,  5); printf("       %c%c  %c%c  %c%c  %c%c  %c%c%c  %c%c  %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18,  6); printf("   %c%c  %c%c  %c%c  %c%c  %c%c   %c%c  %c%c  %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18,  7); printf("    %c%c%c%c    %c%c%c%c    %c%c%c%c%c    %c%c%c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	
	gotoxy(metade_eixo_x-18,  9); printf("           %c%c%c%c%c%c      %c%c%c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18, 10); printf("           %c%c   %c%c    %c%c %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18, 11); printf("           %c%c    %c   %c%c  %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18, 12); printf("           %c%c   %c%c  %c%c%c%c%c%c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18, 13); printf("           %c%c%c%c%c%c  %c%c    %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	
	gotoxy(metade_eixo_x-18, 15); printf("   %c%c     %c%c  %c%c%c%c%c%c  %c%c      %c%c%c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18, 16); printf("    %c%c    %c%c  %c%c             %c%c %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18, 17); printf("     %c%c  %c%c   %c%c%c%c%c   %c%c    %c%c  %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18, 18); printf("      %c%c%c%c    %c%c      %c%c   %c%c%c%c%c%c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
	gotoxy(metade_eixo_x-18, 19); printf("       %c%c     %c%c%c%c%c%c  %c%c  %c%c    %c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		
} // final desenhaLogo

void moverCursorParaBaixo() {	
	gotoxy(0, ALTURA+2);
} // final moverCursorParaBaixo

void desenhaOpcao() {
	char opc1[20] = {"Player vs Player"};
	char opc2[20] = {"Player vs Maquina"};
	char opc3[20] = {"Sair"};
	
	int tamanho = pegarQuantidadeCaracteres(opc1);
	gotoxy(METADE_LOGO - (tamanho/2), 23);
	printf("%s", opc1);
	
	tamanho = pegarQuantidadeCaracteres(opc2);
	gotoxy(METADE_LOGO - (tamanho/2), 27);
	printf("%s", opc2);
	
	tamanho = pegarQuantidadeCaracteres(opc3);
	gotoxy(METADE_LOGO - (tamanho/2), 31);
	printf("%s", opc3);
	
} // final desenhaOpcao

int pegarQuantidadeCaracteres(char string[]) {
	int contador = 0;
	while( 1 ) {
		if( string[contador] == '\0' ) {
			break;
		} else {
			contador++;
		}
	}	
	return contador+1;
} // final pegarQuantidadeCaracteres

void desenhaContornoOpcao(int opcao) {
	int x, y;
	x=y=0;
	switch (opcao) {
		case 1: 
			gotoxy(METADE_LOGO - 15, 23 - 2); printf("%c", QUINA_SE);
			gotoxy(METADE_LOGO + 15, 23 - 2); printf("%c", QUINA_SD);
			gotoxy(METADE_LOGO - 15, 23 + 2); printf("%c", QUINA_IE);
			gotoxy(METADE_LOGO + 15, 23 + 2); printf("%c", QUINA_ID);			
			for( x=METADE_LOGO-14; x<=METADE_LOGO+14; x++ ) {
				gotoxy(x, 23-2); printf("%c", LINHA_HORIZONTAL);
				gotoxy(x, 23+2); printf("%c", LINHA_HORIZONTAL);				
			}			
			for( y=23-1; y<=23+1; y++ ) {				
				gotoxy(METADE_LOGO - 15, y); printf("%c", LINHA_VERTICAL);
				gotoxy(METADE_LOGO + 15, y); printf("%c", LINHA_VERTICAL);				
			}						
			break;
			
		case 2: 
			//gotoxy(METADE_LOGO, 23+4);
			gotoxy(METADE_LOGO - 15, 27 - 2); printf("%c", QUINA_SE);
			gotoxy(METADE_LOGO + 15, 27 - 2); printf("%c", QUINA_SD);
			gotoxy(METADE_LOGO - 15, 27 + 2); printf("%c", QUINA_IE);
			gotoxy(METADE_LOGO + 15, 27 + 2); printf("%c", QUINA_ID);			
			for( x=METADE_LOGO-14; x<=METADE_LOGO+14; x++ ) {
				gotoxy(x, 23 + 4 - 2); printf("%c", LINHA_HORIZONTAL);
				gotoxy(x, 23 + 4 + 2); printf("%c", LINHA_HORIZONTAL);				
			}			
			for( y=23+4-1; y<=23+4+1; y++ ) {				
				gotoxy(METADE_LOGO - 15, y); printf("%c", LINHA_VERTICAL);
				gotoxy(METADE_LOGO + 15, y); printf("%c", LINHA_VERTICAL);				
			}						
			break;
			
		case 3: 
			//gotoxy(METADE_LOGO, 23+4+4);
			gotoxy(METADE_LOGO - 15, 31 - 2); printf("%c", QUINA_SE);
			gotoxy(METADE_LOGO + 15, 31 - 2); printf("%c", QUINA_SD);
			gotoxy(METADE_LOGO - 15, 31 + 2); printf("%c", QUINA_IE);
			gotoxy(METADE_LOGO + 15, 31 + 2); printf("%c", QUINA_ID);			
			for( x=METADE_LOGO-14; x<=METADE_LOGO+14; x++ ) {
				gotoxy(x, 31-2); printf("%c", LINHA_HORIZONTAL);
				gotoxy(x, 31+2); printf("%c", LINHA_HORIZONTAL);				
			}			
			for( y=31-1; y<=31+1; y++ ) {				
				gotoxy(METADE_LOGO - 15, y); printf("%c", LINHA_VERTICAL);
				gotoxy(METADE_LOGO + 15, y); printf("%c", LINHA_VERTICAL);				
			}						
			break;	
		
		default:
			break;
	}	
} // final desenhaContornoOpcao


void apagaContornoOpcao(int opcao) {
	int x, y;
	x=y=0;
	switch (opcao) {
		case 1: 
			gotoxy(METADE_LOGO - 15, 23 - 2); printf(" ", QUINA_SE);
			gotoxy(METADE_LOGO + 15, 23 - 2); printf(" ", QUINA_SD);
			gotoxy(METADE_LOGO - 15, 23 + 2); printf(" ", QUINA_IE);
			gotoxy(METADE_LOGO + 15, 23 + 2); printf(" ", QUINA_ID);			
			for( x=METADE_LOGO-14; x<=METADE_LOGO+14; x++ ) {
				gotoxy(x, 23-2); printf(" ", LINHA_HORIZONTAL);
				gotoxy(x, 23+2); printf(" ", LINHA_HORIZONTAL);				
			}			
			for( y=23-1; y<=23+1; y++ ) {				
				gotoxy(METADE_LOGO - 15, y); printf(" ", LINHA_VERTICAL);
				gotoxy(METADE_LOGO + 15, y); printf(" ", LINHA_VERTICAL);				
			}						
			break;
			
		case 2: 
			//gotoxy(METADE_LOGO, 23+4);
			gotoxy(METADE_LOGO - 15, 27 - 2); printf(" ", QUINA_SE);
			gotoxy(METADE_LOGO + 15, 27 - 2); printf(" ", QUINA_SD);
			gotoxy(METADE_LOGO - 15, 27 + 2); printf(" ", QUINA_IE);
			gotoxy(METADE_LOGO + 15, 27 + 2); printf(" ", QUINA_ID);			
			for( x=METADE_LOGO-14; x<=METADE_LOGO+14; x++ ) {
				gotoxy(x, 23 + 4 - 2); printf(" ", LINHA_HORIZONTAL);
				gotoxy(x, 23 + 4 + 2); printf(" ", LINHA_HORIZONTAL);				
			}			
			for( y=23+4-1; y<=23+4+1; y++ ) {				
				gotoxy(METADE_LOGO - 15, y); printf(" ", LINHA_VERTICAL);
				gotoxy(METADE_LOGO + 15, y); printf(" ", LINHA_VERTICAL);				
			}						
			break;
			
		case 3: 
			//gotoxy(METADE_LOGO, 23+4+4);
			gotoxy(METADE_LOGO - 15, 31 - 2); printf(" ", QUINA_SE);
			gotoxy(METADE_LOGO + 15, 31 - 2); printf(" ", QUINA_SD);
			gotoxy(METADE_LOGO - 15, 31 + 2); printf(" ", QUINA_IE);
			gotoxy(METADE_LOGO + 15, 31 + 2); printf(" ", QUINA_ID);			
			for( x=METADE_LOGO-14; x<=METADE_LOGO+14; x++ ) {
				gotoxy(x, 31-2); printf(" ", LINHA_HORIZONTAL);
				gotoxy(x, 31+2); printf(" ", LINHA_HORIZONTAL);				
			}			
			for( y=31-1; y<=31+1; y++ ) {				
				gotoxy(METADE_LOGO - 15, y); printf(" ", LINHA_VERTICAL);
				gotoxy(METADE_LOGO + 15, y); printf(" ", LINHA_VERTICAL);				
			}						
			break;	
		
		default:
			break;
	}		
} // final apagaContornoOpcao

void inicializaFuncoesMenu() {
	bool status = true;
	int opcaoSelecionada = 1;
	int teclaPressionada = 0;
	
	while (status == true) {
		teclaPressionada = getch();
		if( teclaPressionada == TECLA_W || teclaPressionada == TECLA_w ) teclaPressionada = 1;
		//if( teclaPressionada == TECLA_A || teclaPressionada == TECLA_a ) caso = 2;
		if( teclaPressionada == TECLA_S || teclaPressionada == TECLA_s ) teclaPressionada = 3;
		//if( teclaPressionada == TECLA_D || teclaPressionada == TECLA_d ) caso = 4;
		switch(teclaPressionada) {
			case 1:
				apagaContornoOpcao(opcaoSelecionada);
				((opcaoSelecionada>1) ? opcaoSelecionada-- : opcaoSelecionada);
				desenhaContornoOpcao(opcaoSelecionada);
				moverCursorParaBaixo();
				break;
			
			case 3:		
				apagaContornoOpcao(opcaoSelecionada);	
				((opcaoSelecionada<3) ? opcaoSelecionada++ : opcaoSelecionada);
				desenhaContornoOpcao(opcaoSelecionada);	
				moverCursorParaBaixo();
				break;
			
			/*case SETA_ESQUERDA:
				printf("SETA_ESQUERDA");				
				break;
			
			case SETA_DIREITA:
				printf("SETA_DIREITA");				
				break;*/
			
			case BOTAO_ENTER:
				switch(opcaoSelecionada) {
					case 1:
						//inicia partida player vs player
						limpaTela();
						desenhaTabuleiro();
						selecionaCampo(0, 0, true);
						iniciarPartida(1);
						//regra PvsP
						break;
					case 2:
						//inicia partida player vs maquina
						/*limpaTela();
						desenhaTabuleiro();
						selecionaCampo(0, 0, true);
						iniciarPartida(2);*/
						//regra PvsIA
						break;
					case 3:
						// finaliza aplicação
						status = false;
						break;
				}								
				break;
			
			case BOTAO_ESC:
				status = false;				
				break;
			
			default:				
				break;
		}		
	}	
} // final inicializaFuncoesMenu

void limpaTela() {
	int x, y;
	x=y=0;
	
	for( y=1; y<Y_ID-1; y++ ) {
		for( x=1; x<X_ID-1; x++ ) {
			gotoxy(x, y);
			printf(" ");
		}
	}
} // final limpaTela

void desenhaTabuleiro() {
	int x, y, z;
	x=(LARGURA-7)/3+2;
	y=z=5;	
	for( y=5; y<ALTURA-5; y++ ) {		
		gotoxy(x+3, y); printf("%c", LINHA_VERTICAL);
		gotoxy(x*2-3, y); printf("%c", LINHA_VERTICAL);
	}
	x=0;
	y=(ALTURA-6)/3+1;
	for( x=z*2; x<LARGURA-(z*2); x++ ) {		
		gotoxy(x, y+2); printf("%c", LINHA_HORIZONTAL);
		gotoxy(x, y*2); printf("%c", LINHA_HORIZONTAL);
	} 
	gotoxy(27, 13); printf("%c", QUINA_C);
	gotoxy(45, 13); printf("%c", QUINA_C);
	gotoxy(27, 22); printf("%c", QUINA_C);
	gotoxy(45, 22); printf("%c", QUINA_C);
	
	moverCursorParaBaixo();
} // final desenhaTabuleiro

int selecionaCampo(int x, int y, bool desenhar) {
	//10 17 01 17 01 17 10 larg 
	//05 08 01 08 01 08 05 alt
	int caso = 0;
	int j, k;
	
	if( x==0 && y==0 ) caso = 1;
	else if( x==1 && y==0 ) caso = 2;
	else if( x==2 && y==0 ) caso = 3;
	else if( x==0 && y==1 ) caso = 4;
	else if( x==1 && y==1 ) caso = 5;
	else if( x==2 && y==1 ) caso = 6;
	else if( x==0 && y==2 ) caso = 7;
	else if( x==1 && y==2 ) caso = 8;
	else if( x==2 && y==2 ) caso = 9;
	
	switch(caso) {
		case 1:
			j=10;
			k=5;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		case 2:			
			j=28;			
			k=5;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		case 3:
			j=46;						
			k=5;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		case 4:
			j=10;			
			k=14;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		case 5:
			j=28;			
			k=14;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		case 6:
			j=46;			
			k=14;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		case 7:
			j=10;			
			k=23;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		case 8:
			j=28;			
			k=23;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		case 9:
			j=46;			
			k=23;
			((desenhar==true) ? desenhaContornoJogada(j, k) : apagaContornoJogada(j, k));
			break;		
		default:			
			break;
	}	
	return caso;
} // final selecionaCampo

void desenhaContornoJogada(int x, int y) {
	gotoxy(x   , y  ); printf("%c", QUINA_SE);
	gotoxy(x   , y+7); printf("%c", QUINA_IE);
	gotoxy(x+16, y  ); printf("%c", QUINA_SD);
	gotoxy(x+16, y+7); printf("%c", QUINA_ID);
	int i=0;
	for( i=x+1; i<x+16; i++ ) {
		gotoxy(i, y  ); printf("%c", LINHA_HORIZONTAL);		
		gotoxy(i, y+7); printf("%c", LINHA_HORIZONTAL);		
	}
	for( i=y+1; i<y+7; i++ ) {
		gotoxy(x   , i); printf("%c", LINHA_VERTICAL);		
		gotoxy(x+16, i); printf("%c", LINHA_VERTICAL);			
	}
	moverCursorParaBaixo();
} // final desenhaContornoJogada

void apagaContornoJogada(int x, int y) {
	gotoxy(x   , y  ); printf(" ");
	gotoxy(x   , y+7); printf(" ");
	gotoxy(x+16, y  ); printf(" ");
	gotoxy(x+16, y+7); printf(" ");
	int i=0;
	for( i=x+1; i<x+16; i++ ) {
		gotoxy(i, y  ); printf(" ");		
		gotoxy(i, y+7); printf(" ");		
	}
	for( i=y+1; i<y+7; i++ ) {
		gotoxy(x   , i); printf(" ");		
		gotoxy(x+16, i); printf(" ");			
	}
	moverCursorParaBaixo();
} // final apagaContornoJogada

void iniciarPartida(int modoDeJogo) {
	bool statusPartida = true;
	int teclaPressionada;
	char jogadas[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	int caso;
	char turno[1] = {'x'};
	int x, y;
	x=y=0;
	
	while( statusPartida == true ) {
		teclaPressionada = getch();
		if( teclaPressionada == TECLA_W || teclaPressionada == TECLA_w ) teclaPressionada = 1;
		if( teclaPressionada == TECLA_A || teclaPressionada == TECLA_a ) teclaPressionada = 2;
		if( teclaPressionada == TECLA_S || teclaPressionada == TECLA_s ) teclaPressionada = 3;
		if( teclaPressionada == TECLA_D || teclaPressionada == TECLA_d ) teclaPressionada = 4;
		switch(teclaPressionada) {
			case 1:
				selecionaCampo(x, y, false);
				((y>0) ? y-- : y);
				selecionaCampo(x, y, true);
				moverCursorParaBaixo();
				break;
			
			case 3:
				selecionaCampo(x, y, false);		
				((y<2) ? y++ : y);
				selecionaCampo(x, y, true);
				moverCursorParaBaixo();
				break;
			
			case 2:
				selecionaCampo(x, y, false);
				((x>0) ? x-- : x);
				selecionaCampo(x, y, true);				
				moverCursorParaBaixo();				
				break;
			
			case 4:
				selecionaCampo(x, y, false);
				((x<2) ? x++ : x);
				selecionaCampo(x, y, true);
				moverCursorParaBaixo();			
				break;
			
			case BOTAO_ENTER:
				if( modoDeJogo == 1 ) { //Player vs Player
					caso = selecionaCampo(x, y, true) - 1;
					if( jogadas[caso] == ' ' ) {
						jogadas[caso] = turno[0];
						desenhaMarcacaoJogador(x, y, turno);
						
						if( verificaGanhador(jogadas) == true ) {
							limpaTela();
							gotoxy(METADE_LOGO/5*4, ALTURA/2);
							printf("Jogador %c ganhou!", turno[0]);
							gotoxy(METADE_LOGO/5*2, ALTURA/2+1);
							printf("  Pressione qualquer tecla para jogar novamente,  ");
							gotoxy(METADE_LOGO/5*2, ALTURA/2+2);
							printf(" ou pressione ESC para retornar ao menu principal.");
							statusPartida = false;
						} else if( empate(jogadas) == true ) {
							limpaTela();
							gotoxy(METADE_LOGO/5*4, ALTURA/2);
							printf("DEU VEIA!!!", turno[0]);
							gotoxy(METADE_LOGO/5*2, ALTURA/2+1);
							printf("  Pressione qualquer tecla para jogar novamente,  ");
							gotoxy(METADE_LOGO/5*2, ALTURA/2+2);
							printf(" ou pressione ESC para retornar ao menu principal.");
							statusPartida = false;
						}
						
						((turno[0] == 'x') ? (turno[0] = 'o') : (turno[0] = 'x'));
					}					
				} else if( modoDeJogo == 2 ) { // Player vs Maquina
					
				}
				
				moverCursorParaBaixo();	
				break;
			
			case BOTAO_ESC:
				statusPartida = false;
				limpaTela();
				desenhaMenu();			
				break;
			
			default:				
				break;
		}		
	}	
} //final inicializarPartida

bool verificaGanhador(char string[]) {
	bool ganhador = false;
	/*((string[0]==string[1]!=' ' && string[0]==string[2]!=' ') ? ganhador = true : ganhador);
	((string[3]==string[4]!=' ' && string[3]==string[5]!=' ') ? ganhador = true : ganhador);
	((string[6]==string[7]!=' ' && string[6]==string[8]!=' ') ? ganhador = true : ganhador);
	
	((string[0]==string[3]!=' ' && string[0]==string[6]!=' ') ? ganhador = true : ganhador);
	((string[1]==string[4]!=' ' && string[1]==string[7]!=' ') ? ganhador = true : ganhador);
	((string[2]==string[5]!=' ' && string[2]==string[8]!=' ') ? ganhador = true : ganhador);
	
	((string[0]==string[4]!=' ' && string[0]==string[8]!=' ') ? ganhador = true : ganhador);
	((string[2]==string[4]!=' ' && string[2]==string[6]!=' ') ? ganhador = true : ganhador);*/
	
	if( string[0]!= ' ' && string[0]==string[1] && string[0]==string[2]) ganhador = true;
	else if( string[3]!= ' ' && string[3]==string[4] && string[3]==string[5]) ganhador = true;
	else if( string[6]!= ' ' && string[6]==string[7] && string[6]==string[8]) ganhador = true;
	
	else if( string[0]!= ' ' && string[0]==string[3] && string[0]==string[6]) ganhador = true;
	else if( string[1]!= ' ' && string[1]==string[4] && string[1]==string[7]) ganhador = true;
	else if( string[2]!= ' ' && string[2]==string[5] && string[2]==string[8]) ganhador = true;
	
	else if( string[0]!= ' ' && string[0]==string[4] && string[0]==string[8]) ganhador = true;
	else if( string[2]!= ' ' && string[2]==string[4] && string[2]==string[6]) ganhador = true;
	
	return ganhador;	
} //final verificaGanhador

void desenhaMarcacaoJogador(int x, int y, char turno[]) {
	int caso = 0;
	int j, k;
	
	if( x==0 && y==0 ) {
		j=10;
		k=5;
	} else if( x==1 && y==0 ) {	
		j=28;			
		k=5;
	} else if( x==2 && y==0 ) {	
		j=46;						
		k=5;
	} else if( x==0 && y==1 ) {
		j=10;			
		k=14;
	} else if( x==1 && y==1 ) {
		j=28;			
		k=14;
	} else if( x==2 && y==1 ) {
		j=46;			
		k=14;
	} else if( x==0 && y==2 ) {
		j=10;			
		k=23;
	} else if( x==1 && y==2 ) {
		j=28;			
		k=23;
	} else if( x==2 && y==2 ) {
		j=46;			
		k=23;		
	}
	
	if( turno[0] == 'x' ) {		
		gotoxy(j+1, k+1); printf("%c%c%c%c%c     %c%c%c%c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+2); printf("  %c%c%c%c%c %c%c%c%c%c  ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+3); printf("      %c%c%c      ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+4); printf("      %c%c%c      ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+5); printf("  %c%c%c%c%c %c%c%c%c%c  ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+6); printf("%c%c%c%c%c     %c%c%c%c%c", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		
	} else if( turno[0] == 'o' ) {
		gotoxy(j+1, k+1); printf("     %c%c%c%c%c     ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+2); printf("   %c%c%c   %c%c%c   ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+3); printf("   %c%c%c   %c%c%c   ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+4); printf("   %c%c%c   %c%c%c   ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+5); printf("   %c%c%c   %c%c%c   ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		gotoxy(j+1, k+6); printf("     %c%c%c%c%c     ", PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO, PREENCIMENTO);
		
	}
} //final desenharMarcacaoJogador

bool empate(char string[]) {
	bool velha = false;
	bool casasVazias = false;
	int i = 0;
	for( i=0; i<9; i++ ) {
		if( string[i] == ' ' ) {
			casasVazias = true;
		}
	}
	if( casasVazias == false ){
		velha = true;
	}
	return velha;
} // final empate
