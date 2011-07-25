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
	const EtChar 		*name;
	EtParam 			*params;
};
typedef struct EtNode EtNode;

// Node creator
EtNode EiNode(const EtChar *name);
// Add parameter to a node
void EiNodeAddParam(EtNode *node, const EtParam parm);

/********* Getters ***********/
// Get number of params on a node
EtInt EiNodeGetNumParams(const EtNode *node);
// Get Byte
EtByte EiNodeGetByte(const EtNode *node,const EtChar *name);
// Get Boolean
EtBoolean EiNodeGetBool(const EtNode *node,const EtBoolean *name);
// Get integer
EtInt EiNodeGetInt(const EtNode *node,const EtChar *name);
// Get unsigned integer
EtUInt EiNodeGetUInt(const EtNode *node,const EtChar *name);
// Get float
EtFloat EiNodeGetFlt(const EtNode *node,const EtChar *name);

/********* Setters ***********/
// Set byte parameter
void EiNodeSetChar(EtNode *node,const EtChar *name,const EtChar val);
// Set boolean parameter
void EiNodeSetBool(EtNode *node,const EtChar *name,const EtBoolean val);
// Set integer parameter
void EiNodeSetInt(EtNode *node,const EtChar *name,const EtInt val);
// Set unsigned integer parameter
void EiNodeSetUInt(EtNode *node,const EtChar *name,const EtUInt val);
// Set float parameter
void EiNodeSetFlt(EtNode *node,const EtChar *name,const EtFloat val);

#endif  //ETNODE_H
