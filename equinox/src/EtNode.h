/************************************************
 * EtNode.h
 *
 *
 *
 ************************************************/

#ifndef	ETNODE_H
#define ETNODE_H

#include "buf.h"
#include "EtTypes.h"
#include "EtParam.h"

struct EtNode {
	const EtChar 	*name;
	EtParamDef 	*params;
	EtParamData	*paramData;
};
typedef struct EtNode EtNode;

// Node creator
EtNode EiNode(const EtChar *name);
// Add parameter to a node
void EiNodeAddParam(const EtNode *node, const EtParamDef parm);

/********* Getters ***********/
// Get number of params on a node
int EiNodeGetNumParams(const EtNode *node);
// Get an integer parameter
int EiNodeGetInt(const EtNode *node,const EtChar *name);


/********* Setters ***********/
// Set integer parameter
void EiNodeSetInt(EtNode *node,const EtChar *name,const EtInt val);

#endif  //ETNODE_H
