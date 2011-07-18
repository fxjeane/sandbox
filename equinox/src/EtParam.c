#include "EtParam.h"

/****************************
 * Params
 ***************************/

int EiGetParamDefSize(const EtParamDef param) {
	switch(param.type) {
		case EI_TYPE_INT:
			return sizeof(int);
		case EI_TYPE_DOUBLE:
			return sizeof(double);
		default:
			return -1;
	}
}

EtParamDef EiParamDefInt(const char *name,const int def) {
	EtParamDef temp;
	EtParamValue bar = {def};
	
	temp.name = name;
	temp.type = EI_TYPE_INT;
	temp.defVal = bar;

	return temp;
}

