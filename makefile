ALLEGRO=-Iinclude -Llib  `allegro-config --cflags --libs`
CC= c++ -fpermissive -Iinclude  

pacman: main.cpp Allegro.o Bitmap.o Excessao.o Teclado.o Tela.o Posicao.o Comida.o Cor.o ExcessaoArquivoNaoEncontrado.o ExcessaoArgumentoNulo.o ExcessaoReferenciaNula.o ElementoRepresentavel.o Labirinto.o Esquina.o ComposicaoComida.o ColecaoEsquinas.o Pacman.o ElementoAmbulante.o DirecaoFixa.o ControladorColisoes.o Cronometro.o Aleatorio.o ComposicaoFantasma.o FantasmaAleatorio.o Fantasma.o Direcao.o ComposicaoPilula.o Pilula.o Animacao.o AproximadorGuloso.o Caixa.o ControladorVidas.o Texto.o

	$(CC) main.cpp *.o -Llib  $(ALLEGRO)  -o pacman
# c++ -fpermissive -Iinclude  main.cpp  *.o -Llib `allegro-config --cflags --libs`

run: pacman
	./pacman

Allegro.o: Allegro.cpp Allegro.h 
	$(CC) Allegro.cpp -c

Aleatorio.o: Aleatorio.cpp Aleatorio.h
	$(CC) Aleatorio.cpp -c

Animacao.o: Animacao.cpp Animacao.h IDesenhavel.h Cronometro.o ExcessaoReferenciaNula.o Bitmap.o Excessao.o Params.h
	$(CC) Animacao.cpp -c

Aproximador.o: Aproximador.h Aproximador.cpp Posicao.o DirecaoFixa.o ElementoAmbulante.o
	$(CC) Aproximador.cpp -c

AproximadorGuloso.o: AproximadorGuloso.h AproximadorGuloso.cpp ElementoAmbulante.o DirecaoFixa.o Esquina.o Aproximador.o
	$(CC) AproximadorGuloso.cpp -c

Assunto.o: Assunto.cpp Assunto.h IObservador.h
	$(CC) Assunto.cpp -c

Bitmap.o: Bitmap.cpp Bitmap.h Allegro.o IDesenhavel.h ExcessaoArquivoNaoEncontrado.o ExcessaoArgumentoNulo.o ExcessaoReferenciaNula.o Posicao.o Cor.o Tela.o Params.h
	$(CC) Bitmap.cpp -c 

Bonus.o: Bonus.cpp Bonus.h IObservador.h ElementoRepresentavel.o ControladorColisoes.o
	$(CC) Bonus.cpp -c

BonusRetardador.o: BonusRetardador.cpp BonusRetardador.h Bonus.o
	$(CC) BonusRetardador.cpp -c

BonusVida.o: BonusVida.cpp BonusVida.h Bonus.o Bitmap.o
	$(CC) BonusVida.cpp -c

Caixa.o: Caixa.cpp Caixa.h Posicao.h
	$(CC) Caixa.cpp -c

Cronometro.o: Cronometro.cpp Cronometro.h
	$(CC) Cronometro.cpp -c

ColecaoEsquinas.o: ColecaoEsquinas.cpp ColecaoEsquinas.h Esquina.o Params.h DirecaoFixa.o
	$(CC) ColecaoEsquinas.cpp -c

Comida.o: Comida.cpp Comida.h Posicao.o ElementoRepresentavel.o ExcessaoReferenciaNula.o Cor.o Bitmap.o Params.h Reconstrucao.o
	$(CC) Comida.cpp -c 

ComposicaoFantasma.o: ComposicaoFantasma.cpp ComposicaoFantasma.h IFantasma.h FantasmaAleatorio.o Params.h Posicao.o FantasmaGuloso.o ExcessaoReferenciaNula.o Pacman.o Excessao.o Reconstrucao.o
	$(CC) ComposicaoFantasma.cpp -c

ComposicaoComida.o: ComposicaoComida.cpp ComposicaoComida.h Comida.o IObservador.h ComposicaoFantasma.o Reconstrucao.o Allegro.o
	$(CC) ComposicaoComida.cpp -c

ComposicaoPilula.o: ComposicaoPilula.cpp ComposicaoPilula.h Pilula.o Params.h  ComposicaoComida.o
	$(CC) ComposicaoPilula.cpp -c 

ControladorColisoes.o: ControladorColisoes.cpp ControladorColisoes.h IDesenhavel.h ExcessaoReferenciaNula.o  Params.h
	$(CC) ControladorColisoes.cpp -c

ControladorVidas.o: ControladorVidas.cpp ControladorVidas.h Params.h ExcessaoReferenciaNula.o Pacman.o BonusVida.o Texto.o Posicao.o Tela.o Allegro.o ControladorColisoes.o 
	$(CC) ControladorVidas.cpp -c

Cor.o: Cor.cpp Cor.h
	$(CC) Cor.cpp -c

Despertador.o: Despertador.cpp Despertador.h Assunto.o 
	$(CC) Despertador.cpp -c

Despertadores.o: Despertadores.cpp Despertadores.h IObservador.h Despertador.o
	$(CC) Despertadores.cpp -c

DirecaoFixa.o: DirecaoFixa.cpp DirecaoFixa.h Direcao.o Excessao.o Params.h ExcessaoReferenciaNula.o
	$(CC) DirecaoFixa.cpp -c

Direcao.o: Direcao.cpp Direcao.h Aleatorio.o
	$(CC) Direcao.cpp -c

ElementoAmbulante.o: ElementoAmbulante.cpp ElementoAmbulante.h DirecaoFixa.o ElementoRepresentavel.o Esquina.o Params.h
	$(CC) ElementoAmbulante.cpp -c  

ElementoRepresentavel.o: ElementoRepresentavel.cpp ElementoRepresentavel.h IColidivel.h Posicao.o ExcessaoReferenciaNula.o  Params.h
	$(CC) ElementoRepresentavel.cpp -c

Esquina.o: Esquina.cpp Esquina.h Posicao.o DirecaoFixa.o ExcessaoArgumentoNulo.o Params.h Aleatorio.o
	$(CC) Esquina.cpp -c

Excessao.o: Excessao.cpp Excessao.h
	$(CC) Excessao.cpp -c

ExcessaoArgumentoNulo.o: ExcessaoArgumentoNulo.cpp Excessao.o
	$(CC) ExcessaoArgumentoNulo.cpp -c

ExcessaoReferenciaNula.o: ExcessaoReferenciaNula.cpp Excessao.o
	$(CC) ExcessaoReferenciaNula.cpp -c

ExcessaoArquivoNaoEncontrado.o: ExcessaoArquivoNaoEncontrado.cpp ExcessaoArquivoNaoEncontrado.h Excessao.o
	$(CC) ExcessaoArquivoNaoEncontrado.cpp -c

Fantasma.o: Fantasma.cpp Fantasma.h IFantasma.h ElementoAmbulante.o DirecaoFixa.o labirinto_transitavel Cronometro.o Posicao.o ControladorColisoes.o AproximadorGuloso.o Caixa.o ControladorVidas.o Reconstrucao.o
	$(CC) Fantasma.cpp -c

FantasmaAleatorio.o: FantasmaAleatorio.cpp FantasmaAleatorio.h Fantasma.o DirecaoFixa.o IDesenhavel.h 
	$(CC) FantasmaAleatorio.cpp -c

FantasmaEsperto.o: FantasmaEsperto.cpp FantasmaEsperto.h Fantasma.o IDesenhavel.h 
	$(CC) FantasmaEsperto.cpp -c

FantasmaGuloso.o: FantasmaGuloso.cpp FantasmaGuloso.h Fantasma.o Posicao.o DirecaoFixa.o Aleatorio.o AproximadorGuloso.o IDesenhavel.h 
	$(CC) FantasmaGuloso.cpp -c

InteligenciaEsperto.o: InteligenciaEsperto.cpp InteligenciaEsperto.h DirecaoFixa.o Posicao.o i
	$(CC) InteligenciaEsperto.cpp -c

Pacman.o: Pacman.cpp Pacman.h ElementoAmbulante.o Bitmap.o Teclado.o Params.h DirecaoFixa.o IDesenhavel.h IObservador.h
	$(CC) Pacman.cpp -c

Pilula.o: Pilula.cpp Pilula.h Bonus.o Animacao.o Params.h IFantasma.h ExcessaoReferenciaNula.o Reconstrucao.o
	$(CC) Pilula.cpp -c
	
Posicao.o: Posicao.cpp Posicao.h
	$(CC) Posicao.cpp -c

Labirinto.o: Labirinto.cpp Labirinto.h Bitmap.o DirecaoFixa.o Esquina.o Params.h ElementoRepresentavel.o ExcessaoArquivoNaoEncontrado.o Excessao.o ExcessaoArgumentoNulo.o ComposicaoComida.o ColecaoEsquinas.o Caixa.o
	$(CC) Labirinto.cpp -c

Teclado.o: Teclado.cpp Teclado.h Assunto.o Allegro.o
	$(CC) Teclado.cpp -c

Tela.o: Tela.cpp Tela.h IDesenhavel.h Allegro.o Cor.o
	$(CC) Tela.cpp -c

Texto.o: Texto.cpp Texto.h IDesenhavel.h Cor.o Tela.o Posicao.o
	$(CC) Texto.cpp -c

Reconstrucao.o: Reconstrucao.cpp Reconstrucao.h Assunto.o
	$(CC) Reconstrucao.cpp -c

clean: 
	rm *.o

#Arquivo de teste do allegro
teste:
	$(CC) teste.c -o teste $(ALLEGRO)
