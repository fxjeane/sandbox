
#include "EtNode.h"

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

/*********** Getters ***************/
int EiNodeGetNumParams(const EtNode *node) {
	return buf_len(node->params);	
}

/***********
 * gets a EtParamData from a given name
 ***********/
void* EiNodeGetParam(const EtNode *node, const char *name) {
	EtParamDef *params = node->params;
	EtParamData *paramData = node->paramData;
	int offset = 0;
	// to get the value first look for the name in the params array. 
	// use that index
	int i = 0;
	for (i; i < buf_len(params); ++i) {
		offset = i * EiGetParamDefSize(params[i]);
		if (strcmp(params[i].name,name) == 0) {
			return &paramData[i];
		}
	}
	return NULL;
}

int EiNodeGetInt(const EtNode *node,const char *name)
{
	EtParamData *param = EiNodeGetParam(node,name);
	if (param)
		return param->val.intVal;
	else
		return -1;
}

/*********** Setters ***************/
void EiNodeSetInt(EtNode *node,const char *name,const int val) {
	EtParamData *param = EiNodeGetParam(node,name);
	EtParamValue bar = {val};
	param->val = bar;
}
