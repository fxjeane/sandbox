
#ifndef ETPARAM_H
#define ETPARAM_H

#include "EtTypes.h"

union EtParamValue {
	EtByte     		BYTE;
	EtInt      		INT;
	EtUInt     		UINT;
	EtBoolean  		BOOL;
	EtFloat    		FLT;
//	EtRGB      		RGB;
//	EtRGBA     		RGBA;
//	EtVector   		VEC;
//	EtPoint    		PNT;
//	EtPoint2   		PNT2;
	const EtChar	*STR;
	EtVoid     		*PTR;
//	EtArray    		*ARRAY;
//	EtMatrix   		*pMTX;
};
typedef union EtParamValue EtParamValue;

struct EtParamDef {
	const EtChar 		*name;
	EtInt 				type;
	EtParamValue		defVal;
};
typedef struct EtParamDef EtParamDef;

struct EtParamData {
	EtParamValue	val;
};
typedef struct EtParamData EtParamData;

EtInt EiGetParamDefSize(const EtParamDef param);

EtParamDef EiParamDefInt(const EtChar *name,const EtInt def);

#endif // ETPARAM_H
