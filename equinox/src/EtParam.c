#include "EtParam.h"
#include <stdio.h>

/****************************
 * Params
 ***************************/

int EiGetParamSize(const EtParam param) {
	switch(param.type) {
		case EI_TYPE_BYTE:
			return sizeof(EtByte);
		case EI_TYPE_BOOLEAN:
			return sizeof(EtBoolean);
		case EI_TYPE_INT:
			return sizeof(EtInt);
		case EI_TYPE_UINT:
			return sizeof(EtUInt);
		case EI_TYPE_FLOAT:
			return sizeof(EtFloat);
		case EI_TYPE_POINT:
			return sizeof(EtPoint);
		default:
			return -1;
	}
}

void EiNodeParamVec(EtParam **params,
					const char *name,
					EtVector defval)
{
	EtParam tmp;
	tmp.name=name;
	tmp.type=EI_TYPE_VECTOR;
	EtParamValue def;
	def.VEC = defval;
	tmp.def = def;
	buf_push(*params,tmp);
}

void EiNodeParamPoint(EtParam **params,
					const char *name,
					double x,double y, double z)
{
	EtParam tmp;
	tmp.name=name;
	tmp.type=EI_TYPE_POINT;
	EtParamValue def;
	EtVector dval= {x,y,z};
	def.PNT = dval ;
	tmp.def = def;
	buf_push(*params,tmp);
}

/*
EtParam EiParamByte(const char *name,const EtByte val) {
	EtParam tmp;
	tmp.name 	= name;
	tmp.type	= EI_TYPE_BYTE;
	tmp.def.INT= val;
	tmp.val.INT= val;
	return tmp;
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

EtParam EiParamUInt(const char *name,const EtUInt val) {
	EtParam tmp;
	tmp.name 	= name;
	tmp.type	= EI_TYPE_UINT;
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
*/
