#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H
#include "NullReferenceException.h"
#include "ICollidable.h"
#include "Params.h"
#include "CollisionDetection.h"

#include <vector>

class CollisionDetection
{
public:
	void Detect();
	void Add(ICollidable *object);
	static CollisionDetection* Instance();
	void SetPacman(ICollidable *p) { pacman = p; }
	void Reset();

private:
	CollisionDetection() 
	{ last_pacman_position = 0; largest_position = new Position(); }

	std::vector<ICollidable*> collidables;
	bool DetectCollision(ICollidable*);
	ICollidable * pacman;
	static CollisionDetection *instance;
	Position * last_pacman_position;
	
	int largest_width, largest_height;
	Position * largest_position;
};

#endif
