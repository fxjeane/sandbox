#include "EtParam.h"
#include <stdio.h>

/****************************
 * Params
 ***************************/

EtInt EiGetParamSize(const EtParam param) {
	switch(param.type) {
		case EI_TYPE_INT:
			return sizeof(EtInt);
		case EI_TYPE_FLOAT:
			return sizeof(EtFloat);
		case EI_TYPE_BOOLEAN:
			return sizeof(EtBoolean);
		default:
			return -1;
	}
}

EtParam EiParamBool(const char *name,const EtBoolean val) {
	EtParam tmp;
	tmp.name 	= name;
	tmp.type	= EI_TYPE_BOOLEAN;
	tmp.def.BOOL= val;
	tmp.val.BOOL= val;
	return tmp;
}

EtParam EiParamInt(const char *name,const EtInt val) {
	EtParam tmp;
	tmp.name 	= name;
	tmp.type	= EI_TYPE_INT;
	tmp.def.INT= val;
	tmp.val.INT= val;
	return tmp;
}

EtParam EiParamFlt(const char *name,const EtFloat val) {
	EtParam tmp;
	tmp.name 	= name;
	tmp.type	= EI_TYPE_FLOAT;
	tmp.def.FLT= val;
	tmp.val.FLT= val;
	return tmp;
}

