ALLEGRO=-Iinclude -Llib  `allegro-config --cflags --libs`
CC= clang++ -Iinclude  

pacman: main.cpp Allegro.o Bitmap.o Exception.o Keyboard.o Screen.o Position.o Food.o Color.o FileNotFoundException.o NullArgumentException.o NullReferenceException.o DrawingElement.o Maze.o Corner.o FoodComposition.o CornerCollection.o Pacman.o WalkingElement.o FixedDirection.o CollisionDetection.o Cronometer.o Random.o GhostComposition.o RandomGhost.o Ghost.o Direction.o PillComposition.o Pill.o Animation.o GreedyFollower.o Box.o LifeController.o Text.o

	$(CC) main.cpp *.o -Llib  $(ALLEGRO)  -o pacman

run: pacman
	./pacman

Allegro.o: Allegro.cpp Allegro.h 
	$(CC) Allegro.cpp -c

Random.o: Random.cpp Random.h
	$(CC) Random.cpp -c

Animation.o: Animation.cpp Animation.h IDrawable.h Cronometer.o NullReferenceException.o Bitmap.o Exception.o Params.h
	$(CC) Animation.cpp -c

Approximator.o: Approximator.h Approximator.cpp Position.o FixedDirection.o WalkingElement.o
	$(CC) Approximator.cpp -c

GreedyFollower.o: GreedyFollower.h GreedyFollower.cpp WalkingElement.o FixedDirection.o Corner.o Approximator.o
	$(CC) GreedyFollower.cpp -c

Subject.o: Subject.cpp Subject.h IObserver.h
	$(CC) Subject.cpp -c

Bitmap.o: Bitmap.cpp Bitmap.h Allegro.o IDrawable.h FileNotFoundException.o NullArgumentException.o NullReferenceException.o Position.o Color.o Screen.o Params.h
	$(CC) Bitmap.cpp -c 

Bonus.o: Bonus.cpp Bonus.h IObserver.h DrawingElement.o CollisionDetection.o
	$(CC) Bonus.cpp -c

BonusSlowMotion.o: BonusSlowMotion.cpp BonusSlowMotion.h Bonus.o
	$(CC) BonusSlowMotion.cpp -c

BonusLife.o: BonusLife.cpp BonusLife.h Bonus.o Bitmap.o
	$(CC) BonusLife.cpp -c

Box.o: Box.cpp Box.h Position.h
	$(CC) Box.cpp -c

Cronometer.o: Cronometer.cpp Cronometer.h
	$(CC) Cronometer.cpp -c

CornerCollection.o: CornerCollection.cpp CornerCollection.h Corner.o Params.h FixedDirection.o
	$(CC) CornerCollection.cpp -c

Food.o: Food.cpp Food.h Position.o DrawingElement.o NullReferenceException.o Color.o Bitmap.o Params.h Reconstruction.o
	$(CC) Food.cpp -c 

GhostComposition.o: GhostComposition.cpp GhostComposition.h IGhost.h RandomGhost.o Params.h Position.o GreedyGhost.o NullReferenceException.o Pacman.o Exception.o Reconstruction.o
	$(CC) GhostComposition.cpp -c

FoodComposition.o: FoodComposition.cpp FoodComposition.h Food.o IObserver.h GhostComposition.o Reconstruction.o Allegro.o
	$(CC) FoodComposition.cpp -c

PillComposition.o: PillComposition.cpp PillComposition.h Pill.o Params.h  FoodComposition.o
	$(CC) PillComposition.cpp -c 

CollisionDetection.o: CollisionDetection.cpp CollisionDetection.h IDrawable.h NullReferenceException.o  Params.h
	$(CC) CollisionDetection.cpp -c

LifeController.o: LifeController.cpp LifeController.h Params.h NullReferenceException.o Pacman.o BonusLife.o Text.o Position.o Screen.o Allegro.o CollisionDetection.o 
	$(CC) LifeController.cpp -c

Color.o: Color.cpp Color.h
	$(CC) Color.cpp -c

AlarmClock.o: AlarmClock.cpp AlarmClock.h Subject.o 
	$(CC) AlarmClock.cpp -c

AlarmClocks.o: AlarmClocks.cpp AlarmClocks.h IObserver.h AlarmClock.o
	$(CC) AlarmClocks.cpp -c

FixedDirection.o: FixedDirection.cpp FixedDirection.h Direction.o Exception.o Params.h NullReferenceException.o
	$(CC) FixedDirection.cpp -c

Direction.o: Direction.cpp Direction.h Random.o
	$(CC) Direction.cpp -c

WalkingElement.o: WalkingElement.cpp WalkingElement.h FixedDirection.o DrawingElement.o Corner.o Params.h
	$(CC) WalkingElement.cpp -c  

DrawingElement.o: DrawingElement.cpp DrawingElement.h ICollidable.h Position.o NullReferenceException.o  Params.h
	$(CC) DrawingElement.cpp -c

Corner.o: Corner.cpp Corner.h Position.o FixedDirection.o NullArgumentException.o Params.h Random.o
	$(CC) Corner.cpp -c

Exception.o: Exception.cpp Exception.h
	$(CC) Exception.cpp -c

NullArgumentException.o: NullArgumentException.cpp Exception.o
	$(CC) NullArgumentException.cpp -c

NullReferenceException.o: NullReferenceException.cpp Exception.o
	$(CC) NullReferenceException.cpp -c

FileNotFoundException.o: FileNotFoundException.cpp FileNotFoundException.h Exception.o
	$(CC) FileNotFoundException.cpp -c

Ghost.o: Ghost.cpp Ghost.h IGhost.h WalkingElement.o FixedDirection.o maze Cronometer.o Position.o CollisionDetection.o GreedyFollower.o Box.o LifeController.o Reconstruction.o
	$(CC) Ghost.cpp -c

RandomGhost.o: RandomGhost.cpp RandomGhost.h Ghost.o FixedDirection.o IDrawable.h 
	$(CC) RandomGhost.cpp -c

SmartGhost.o: SmartGhost.cpp SmartGhost.h Ghost.o IDrawable.h 
	$(CC) SmartGhost.cpp -c

GreedyGhost.o: GreedyGhost.cpp GreedyGhost.h Ghost.o Position.o FixedDirection.o Random.o GreedyFollower.o IDrawable.h 
	$(CC) GreedyGhost.cpp -c

Smart.o: Smart.cpp Smart.h FixedDirection.o Position.o i
	$(CC) Smart.cpp -c

Pacman.o: Pacman.cpp Pacman.h WalkingElement.o Bitmap.o Keyboard.o Params.h FixedDirection.o IDrawable.h IObserver.h
	$(CC) Pacman.cpp -c

Pill.o: Pill.cpp Pill.h Bonus.o Animation.o Params.h IGhost.h NullReferenceException.o Reconstruction.o
	$(CC) Pill.cpp -c
	
Position.o: Position.cpp Position.h
	$(CC) Position.cpp -c

Maze.o: Maze.cpp Maze.h Bitmap.o FixedDirection.o Corner.o Params.h DrawingElement.o FileNotFoundException.o Exception.o NullArgumentException.o FoodComposition.o CornerCollection.o Box.o
	$(CC) Maze.cpp -c

Keyboard.o: Keyboard.cpp Keyboard.h Subject.o Allegro.o
	$(CC) Keyboard.cpp -c

Screen.o: Screen.cpp Screen.h IDrawable.h Allegro.o Color.o
	$(CC) Screen.cpp -c

Text.o: Text.cpp Text.h IDrawable.h Color.o Screen.o Position.o
	$(CC) Text.cpp -c

Reconstruction.o: Reconstruction.cpp Reconstruction.h Subject.o
	$(CC) Reconstruction.cpp -c

clean: 
	rm *.o pacman

teste:
	$(CC) teste.c -o teste $(ALLEGRO)
