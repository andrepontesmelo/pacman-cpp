#ifndef PARAMS
#define PARAMS

#define LARGURA_TELA 800
#define ALTURA_TELA 600

// Labirinto
#define LABIRINTO_BITMAP_ARQUIVO "img/labirinto.bmp"
#define LABIRINTO_TRANSITAVEL_ARQUIVO "labirinto_transitavel"
#define LABIRINTO_LARGURA_BOCA_PRISAO 0

//#define CONSTRUINDO_LABIRINTO
#define DEBUG
	
#define DISTANCIA_COMIDAS 32
#define COMIDA_RAIO 2

#define COMIDA_COR_R 255
#define COMIDA_COR_G 255
#define COMIDA_COR_B 255 

#define PILULA_RAIO 3
#define PILULA_RAIO_MAX 7

#define PILULA_COR_R 250
#define PILULA_COR_G 155
#define PILULA_COR_B 155 

// Velocidade na animacao da pilula
#define PILULA_ANIMACAO_PERIODO 50000

// Duracao da pilula (sem contar no tempo piscando)
#define PILULA_DURACAO 10000000

// Tempo que o fantasma espera piscando antes de acabar a pilula
#define PILULA_DURACAO_ACABANDO 2000000

// Pacman (1 / velocidade) 9000
#define PACMAN_PERIODO 9000
#define PACMAN_PERIODO_BOCA 25000
#define PACMAN_QTD_VIDAS_INCIAL 3

// Velocidade da animaçao fantasma piscando 
#define FANTASMA_PERIODO_PISCANDO_ACABANDO_PILULA 100000

// Velocidade do fantasma andando procurando o pacman
#define FANTASMA_PERIODO 10000

// Velocidade dos 'olhinhos' buscando a area central
#define FANTASMA_PERIODO_VOLTANDO 5000

#define FANTASMAS_QTD 4

// Velocidae do fantasma quando sobre efeito da pilula
#define FANTASMA_PERIODO_PILULA 20000

// Tempo em Msegundos de intervalo entre saidas dos fantasmas.
#define INTERVALO_PRESO 3350000
#define TEMPO_MIN_PRESO 350000

#define CONTROLADOR_VIDAS_POS_X 600
#define CONTROLADOR_VIDAS_POS_Y 10
#endif

