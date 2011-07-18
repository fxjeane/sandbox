#include "buf.h"
#include <string.h>

#define EI_TYPE_INT         0x01  
#define EI_TYPE_DOUBLE		0x02 

/****************************
 * Params
 ***************************/
union EtParamValue {
	int		intVal;
	double	dblVal;
};
typedef union EtParamValue EtParamValue;

struct EtParamDef {
	const char 		*name;
	int 			type;
	EtParamValue	defVal;
};
typedef struct EtParamDef EtParamDef;

struct EtParamData {
	EtParamValue	val;
};
typedef struct EtParamData EtParamData;

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

/****************************
 * Node - Base
 ***************************/
struct EtNode {
	const char 	*name;
	EtParamDef 	*params;
	EtParamData	*paramData;
};
typedef struct EtNode EtNode;

EtParamDef EiParamDefInt(const char *name,const int def) {
	EtParamDef temp;
	EtParamValue bar = {def};
	
	temp.name = name;
	temp.type = EI_TYPE_INT;
	temp.defVal = bar;

	return temp;
}

EtNode EiNode(const char *name) {
	EtNode temp;
	temp.name 		= name;
	temp.params 	= NULL;
	temp.paramData 	= NULL;
	return temp;
}

void EiNodeAddParam(const EtNode *node, const EtParamDef parm) {
	buf_push(node->params,parm);
	switch ( parm.type ) {
		case EI_TYPE_INT: {
			EtParamValue bar = {parm.defVal.intVal};
			EtParamData data;
			data.val = bar;
			buf_push(node->paramData,data);
			break;
		}
		default:
			break;
	}
}

int EiNodeGetNumParams(const EtNode *node) {
	return buf_len(node->params);	
}

int EiNodeGetInt(const EtNode *node,const char *name)
{
	EtParamDef *params = node->params;
	EtParamData *paramData = node->paramData;

	int offset = 0;
	
	// to get the value first look for the name in the params array. 
	// use that index
	int i = 0;
	for (i; i < buf_len(params); ++i) {
		if (strcmp(params[i].name,name) == 0) {
			offset = (i * EiGetParamDefSize(params[i]));
			return (int) paramData[i].val.intVal;
		} else {
			offset = i * EiGetParamDefSize(params[i]);
		}
	}
	return -1;
}

