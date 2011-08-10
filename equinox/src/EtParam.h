#ifndef ETPARAM_H
#define ETPARAM_H
#include "buf.h"
#include "EtApi.h"
#include "EtTypes.h"
#include "EtGeometry.h"

union EtParamValue {
	EtByte     		BYTE;
	EtBoolean  		BOOL;
	EtInt      		INT;
	EtUInt     		UINT;
	EtFloat    		FLT;
	EtVector		VEC;
	EtPoint			PNT;
	const EtChar	*STR;
	EtVoid     		*PTR;
};
typedef union EtParamValue EtParamValue;

struct EtParam {
	const EtChar 		*name;
	EtInt 				type;
	EtParamValue		def;
	//EtParamValue		val;
};
typedef struct EtParam EtParam;

struct EtList {
	void		*d;
	unsigned int l;
};
typedef struct EtList EtList;

int EiGetParamSize(const EtParam param);

ET_API void EiNodeParamVec(EtParam **params,
						const char *name,
						EtVector defval);

ET_API void EiNodeParamPoint(EtParam **params,
					const char *name,
					double x,double y, double z);

/*
EtParam EiParamByte(const EtChar *name,const EtByte def);
EtParam EiParamBool(const EtChar *name,const EtBoolean def);
EtParam EiParamInt(const EtChar *name,const EtInt def);
EtParam EiParamUInt(const EtChar *name,const EtUInt def);
EtParam EiParamFlt(const EtChar *name,const EtFloat def);
*/

#endif // ETPARAM_H
