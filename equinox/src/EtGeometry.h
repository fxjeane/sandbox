#ifndef ET_GEOMETRY_H
#define ET_GEOMETRY_H

struct EtPoint2 {
	int x;
	int y;
};
typedef struct EtPoint2 EtPoint2;

/****************
* EtVector
****************/
struct EtVector {
	double x;
	double y;
	double z;
};
typedef struct EtVector EtVector;


/*** EtVector Interface ******/

typedef EtVector EtPoint;
#endif // ET_GEOMETRY_H
