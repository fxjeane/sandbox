/************************************************
 * EtNode.h
 *
 *
 *
 ************************************************/
#ifndef	ET_NODE_H
#define ET_NODE_H

#include "EtApi.h"
#include "buf.h"
#include "EtTypes.h"
#include "EtParam.h"

struct EtNode {
	const char	 	*name;
	const char		*type;
	EtParam			*params;
	EtParamValue 	*data;
	unsigned int	numParams;
};
typedef struct EtNode EtNode;

// Node creator
ET_API EtNode EiNode(const EtChar *name);
// Add parameter to a node
void EiNodeAddParam(EtNode *node, const EtParam parm);

/********* Getters ***********/
// Get number of params on a node
ET_API EtInt EiNodeGetNumParams(const EtNode *node);
// Get Byte
ET_API EtByte EiNodeGetByte(const EtNode *node,const EtChar *name);
// Get Boolean
ET_API EtBoolean EiNodeGetBool(const EtNode *node,const EtChar *name);
// Get integer
ET_API EtInt EiNodeGetInt(const EtNode *node,const EtChar *name);
// Get unsigned integer
ET_API EtUInt EiNodeGetUInt(const EtNode *node,const EtChar *name);
// Get float
ET_API EtFloat EiNodeGetFlt(const EtNode *node,const EtChar *name);
// Get Point
ET_API EtPoint EiNodeGetPnt(const EtNode *node,const EtChar *name);

/********* Setters ***********/
// Set byte parameter
ET_API void EiNodeSetChar(EtNode *node,const EtChar *name,
						const EtChar val);
// Set boolean parameter
ET_API void EiNodeSetBool(EtNode *node,const EtChar *name,
						const EtBoolean val);
// Set integer parameter
ET_API void EiNodeSetInt(EtNode *node,const EtChar *name,
						const EtInt val);
// Set unsigned integer parameter
ET_API void EiNodeSetUInt(EtNode *node,const EtChar *name,
						const EtUInt val);
// Set float parameter
ET_API void EiNodeSetFlt(EtNode *node,const EtChar *name,
						const EtFloat val);
// Set Point
ET_API void EiNodeSetPnt(EtNode *node,const EtChar *name,
						const double x,
						const double y,
						const double z);
#endif  //ETNODE_H
