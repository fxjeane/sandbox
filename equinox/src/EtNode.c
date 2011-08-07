
#include <stdio.h>
#include "EtNode.h"

/********* Prototypes for private funtions *********/
void EiNodePrintNode(const EtNode *node);
void EiNodePrintParams(const EtNode *node); 
void* EiNodeGetParam(const EtNode *node, const EtChar *name);


/**************************************
 ********* Public Functions ***********
 *************************************/
EtNode EiNode(const EtChar *name) {
	EtPlugin *plugin = EiGetPlugin(name);
	//printf("creating instance of %s\n",plugin->name);
	plugin->mtds->dmethods->init();
	switch (plugin->pluginType) {
		case EI_PLUGIN_CAMERA : { 
			EtCameraMethods *cm = (EtCameraMethods *) plugin->mtds->umethods; 
			cm->createRay();
			break;
			}
	}

	EtNode temp;
	temp.name 			= name;
	temp.params 		= NULL;
	return temp;
}

void EiNodeAddParam(EtNode *node, const EtParam parm) {
	buf_push(node->params,parm);
}

/*********** Getters ***************/
int EiNodeGetNumParams(const EtNode *node) {
	return buf_len(node->params);	
}

/***********
 * Gets a EtParamData from a given name
 ***********/
// Byte
EtByte EiNodeGetByte(const EtNode *node,const EtChar *name)
{
	EtParam *param = EiNodeGetParam(node,name);
	if (param) {
		return param->val.BYTE;
	}
}
// Boolean
EtBoolean EiNodeGetBool(const EtNode *node,const EtChar *name)
{
	EtParam *param = EiNodeGetParam(node,name);
	if (param)
		return param->val.BOOL;
}
// Int
EtInt EiNodeGetInt(const EtNode *node,const EtChar *name)
{
	EtParam *param = EiNodeGetParam(node,name);
	if (param)
		return param->val.INT;
}
// UInt
EtUInt EiNodeGetUInt(const EtNode *node,const EtChar *name)
{
	EtParam *param = EiNodeGetParam(node,name);
	if (param)
		return param->val.UINT;
}
// Float
EtFloat EiNodeGetFlt(const EtNode *node,const EtChar *name)
{
	EtParam *param = EiNodeGetParam(node,name);
	if (param)
		return param->val.FLT;
}


/*********** Setters ***************/
// Byte
void EiNodeSetByte(EtNode *node,const EtChar *name,const EtByte val) {
	EtParam *param = EiNodeGetParam(node, name);
	if (param)
		param->val.BYTE = val;
}
// Boolean
void EiNodeSetBool(EtNode *node,const EtChar *name,const EtBoolean val) {
	EtParam *param = EiNodeGetParam(node, name);
	if (param)
		param->val.BOOL = val;
}
// Int
void EiNodeSetInt(EtNode *node,const EtChar *name,const EtInt val) {
	EtParam *param = EiNodeGetParam(node, name);
	if (param)
		param->val.INT = val;
}
// UInt
void EiNodeSetUInt(EtNode *node,const EtChar *name,const EtUInt val) {
	EtParam *param = EiNodeGetParam(node, name);
	if (param)
		param->val.UINT = val;
}
// Float
void EiNodeSetFlt(EtNode *node,const EtChar *name,const EtFloat val) {
	EtParam *param = EiNodeGetParam(node, name);
	if (param)
		param->val.FLT = val;
}

/*************************************
 ********* Private Functions *********
 *************************************/
void* EiNodeGetParam(const EtNode *node, const EtChar *name) {
	EtParam *params = node->params;
	EtInt i = 0;
	
	for (i ; i < buf_len(params); i++) {
		if (strcmp(params[i].name,name) == 0) {
			//printf("FOUND %s\n",name);
			return &params[i];
		}
	}
	//printf("NOT FOUND %s\n",name);
	return NULL;
}

/********** Debugging *****************/
void EiNodePrintNode(const EtNode *node)
{
	printf("###############\n");
	printf("Node  : %s\n",node->name);
	printf("Params:\n");
	EiNodePrintParams(node);
	printf("###############\n");
}

void EiNodePrintParams(const EtNode *node) {
	int i = 0;
	for (i; i < buf_len(node->params);i++) {
		printf("---------------------------\n");
		printf("\tName   = %s\n",node->params[i].name);
		printf("\tType   = %i\n",node->params[i].type);
		switch (node->params[i].type) {
			case EI_TYPE_BOOLEAN:
				printf("\tDefault= %i\n",node->params[i].def.BOOL);
				printf("\tValue  = %i\n",node->params[i].val.BOOL);
				break;
			case EI_TYPE_INT:
				printf("\tDefault= %d\n",node->params[i].def.INT);
				printf("\tValue  = %d\n",node->params[i].val.INT);
				break;
			case EI_TYPE_FLOAT:
				printf("\tDefault= %f\n",node->params[i].def.FLT);
				printf("\tValue  = %f\n",node->params[i].val.FLT);
				break;
		}
	}
}
