#ifndef DIRECAO_FIXA_H
#define DIRECAO_FIXA_H
#include "Direction.h"
#include "Exception.h"
#include "NullReferenceException.h"
#include <string>
#include <sstream>

#include "Params.h"

using std::stringstream;
using std::string;

class FixedDirection : public Direction
{
public:
	static FixedDirection* Top() { return top; }
	static FixedDirection* Bottom() { return bottom; }
	static FixedDirection* Left() { return left; }
	static FixedDirection* Right() { return right; }

	static FixedDirection* GetByCode(int cod);
	
	int GetCode() { return cod; }
	string ShortName() { return short_name; }
	FixedDirection* Opposit();

	virtual void SetRandomly(double min_abs)
	{ throw new Exception("Attemp to change FixedDirection at SetRandomly()"); }
	virtual void InvertX()
	{ throw new Exception("Attemp to change FixedDirection at InvertX()"); }
	virtual void InvertY()
	{ throw new Exception("Attemp to change FixedDirection at InvertY()"); }
	virtual void SetX(float x)
	{ throw new Exception("Attemp to change FixedDirection at SetX()"); }
	virtual void SetY(float y)
	{ throw new Exception("Attemp to change FixedDirection at SetY()"); }
	
private:
	static FixedDirection* top;
	static FixedDirection* bottom;
	static FixedDirection* left;
	static FixedDirection* right;
	
	int cod;
	FixedDirection* opposit;
	string short_name;
	void SetOpposit(FixedDirection * opposit) { this->opposit = opposit; }
	

	static bool opposits_settled;
	static void SetOpposit();

	FixedDirection(int cod, float x, float y, string short_name) : Direction(x, y) 
	{ this->cod = cod; opposit = 0; this->short_name = short_name; }
	
	enum COD { TOP, BOTTOM, LEFT, RIGHT };

};

#endif
