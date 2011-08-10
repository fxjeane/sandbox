
#include <stdio.h>
#include "EtNode.h"
#include "EtPluginManager.h"
#include "EtCamera.h"
typedef struct EtPlugin Etplugin;

/********* Prototypes for private funtions *********/
void EiNodePrintNode(const EtNode *node);
void EiNodePrintParams(const EtNode *node); 
void* EiNodeGetParam(const EtNode *node, const EtChar *name);


/**************************************
 ********* Public Functions ***********
 *************************************/
EtNode EiNode(const EtChar *name) {
	EtNode *temp = malloc(sizeof(EtNode));
	temp->params = NULL;
	temp->data = NULL;
	// the default name should be the name of the plugin plus a random hash
	temp->name 		= name;
	// get the plugin
	EtPlugin *plugin = EiGetPlugin(name);
	// if plugin is null then throw an execption and kill the program.
	plugin->mtds->dmethods->setParams(temp);
	plugin->mtds->dmethods->init(plugin);
	// initialize the data
	int i;
	for (i=0; i < buf_len(temp->params); i++) {
		buf_push(temp->data,temp->params[i].def);
	}

	
/*	
	switch (plugin->pluginType) {
		case EI_PLUGIN_CAMERA : { 
			EtCameraData *camd = (EtCameraData*)plugin->data;
			temp->data 		   = camd;
			break;
			}
	}
*/
	return *temp;
}

void EiNodeAddParam(EtNode *node, const EtParam parm) {
	//buf_push(node->params,parm);
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
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param) {
		return param->BYTE;
	}
}
// Boolean
EtBoolean EiNodeGetBool(const EtNode *node,const EtChar *name)
{
	EtParamValue *param = EiNodeGetParam(node,name);
	if (param)
		return param->BOOL;
}
// Int
EtInt EiNodeGetInt(const EtNode *node,const EtChar *name)
{
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		return param->INT;
}
// UInt
EtUInt EiNodeGetUInt(const EtNode *node,const EtChar *name)
{
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		return param->UINT;
}
// Float
EtFloat EiNodeGetFlt(const EtNode *node,const EtChar *name)
{
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		return param->FLT;
}
// Point
EtPoint EiNodeGetPnt(const EtNode *node,const EtChar *name)
{
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		return param->PNT;
}

/*********** Setters ***************/
// Byte
void EiNodeSetByte(EtNode *node,const EtChar *name,const EtByte val) {
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		param->BYTE = val;
}
// Boolean
void EiNodeSetBool(EtNode *node,const EtChar *name,const EtBoolean val) {
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		param->BOOL = val;
}
// Int
void EiNodeSetInt(EtNode *node,const EtChar *name,const int val) {
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		param->INT = val;
}
// UInt
void EiNodeSetUInt(EtNode *node,const EtChar *name,const unsigned val) {
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		param->UINT = val;
}
// Float
void EiNodeSetFlt(EtNode *node,const EtChar *name,const float val) {
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param)
		param->FLT = val;
}

// Point
void EiNodeSetPnt(EtNode *node,const EtChar *name,
						const double x,
						const double y,
						const double z) {
	EtParamValue *param = EiNodeGetParam(node, name);
	if (param) {param->PNT.x=x;param->PNT.y=y;param->PNT.z=z;}
}


/*************************************
 ********* Private Functions *********
 *************************************/
void* EiNodeGetParam(const EtNode *node, const EtChar *name) {
	EtParam *params = node->params;
	int i = 0;
	int j = 0;	
	for (i ; i < buf_len(params); i++) {
		if (strcmp(params[i].name,name) == 0) {
			return (EtParamValue*)&node->data[i];
		} else {
			j += EiGetParamSize(params[i]);
		}
	}
	return NULL;
}

/********** Debugging *****************/
/*
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
		EtParam	*data = (EtParam*)params[i].d;
		printf("---------------------------\n");
		printf("\tName   = %s\n",node->params[i].d->name);
		printf("\tType   = %i\n",node->params[i].d->type);
		switch (node->params[i].type) {
			case EI_TYPE_BOOLEAN:
				printf("\tDefault= %i\n",node->params[i].def.BOOL);
				//printf("\tValue  = %i\n",node->params[i].val.BOOL);
				break;
			case EI_TYPE_INT:
				printf("\tDefault= %d\n",node->params[i].def.INT);
				//printf("\tValue  = %d\n",node->params[i].val.INT);
				break;
			case EI_TYPE_FLOAT:
				printf("\tDefault= %f\n",node->params[i].def.FLT);
				//printf("\tValue  = %f\n",node->params[i].val.FLT);
				break;
		}
	}
}
*/
