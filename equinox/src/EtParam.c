#include "EtParam.h"
#include <stdio.h>

/****************************
 * Params
 ***************************/

EtInt EiGetParamDefSize(const EtParamDef param) {
	switch(param.type) {
		case EI_TYPE_INT:
			return sizeof(EtInt);
		case EI_TYPE_FLOAT:
			return sizeof(EtFloat);
		default:
			return -1;
	}
}

EtParamDef EiParamDefInt(const char *name,const EtInt def) {
	EtParamDef temp;
	EtParamValue bar = {def};
	
	temp.name 	= name;
	temp.type 	= EI_TYPE_INT;
	temp.defVal	= bar;

	return temp;
}

