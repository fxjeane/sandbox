
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

struct EtParam {
	const EtChar 		*name;
	EtInt 				type;
	EtParamValue		def;
	EtParamValue		val;
};
typedef struct EtParam EtParam;


EtInt EiGetParamSize(const EtParam param);

EtParam EiParamInt(const EtChar *name,const EtInt def);
EtParam EiParamFlt(const EtChar *name,const EtFloat def);
EtParam EiParamBool(const EtChar *name,const EtBoolean def);


#endif // ETPARAM_H
