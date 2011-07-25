#ifndef ETPARAM_H
#define ETPARAM_H

#include "EtTypes.h"


union EtParamValue {
	EtByte     		BYTE;
	EtBoolean  		BOOL;
	EtInt      		INT;
	EtUInt     		UINT;
	EtFloat    		FLT;
	const EtChar	*STR;
	EtVoid     		*PTR;
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

EtParam EiParamByte(const EtChar *name,const EtByte def);
EtParam EiParamBool(const EtChar *name,const EtBoolean def);
EtParam EiParamInt(const EtChar *name,const EtInt def);
EtParam EiParamUInt(const EtChar *name,const EtUInt def);
EtParam EiParamFlt(const EtChar *name,const EtFloat def);


#endif // ETPARAM_H
