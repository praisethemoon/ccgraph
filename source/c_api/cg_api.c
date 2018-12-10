/** \file cg_api.c
 *  \brief External API implementation
 */


#include <inttypes.h>

#include "cgraph.h"
#include "cg_operation.h"
#include "cg_types.h"
#include "cg_variables.h"
#include "cg_factory.h"
#include "cg_constants.h"
#include "cg_diff.h"
#include "cg_enums.h"

#include <malloc.h>

CGraph* cg_newGraph(char* name, CGNode* root){
	CGraph* graph = makeGraph(name);
	graph->root = root;
	
	return graph;
}

CGraph* cg_freeGraph(CGraph* graph){
	freeGraph(graph);
}

CGNode* cg_newDoubleNode(double v){
	return makeDoubleConstantNode(v);
}

CGNode* cg_newDouble0Node(){
	return makeZeroDoubleConstantNode();
}

CGNode* cg_newVectorNode(uint64_t len, double* v){
	return makeVectorConstantNode(len, v);
}

CGNode* cg_newVector0Node(uint64_t len){
	return makeZeroVectorConstantNode(len);
}

CGNode* cg_newMatrixNode(uint64_t rows, uint64_t cols, double* v){
	return makeMatrixConstantNode(rows, cols, v);
}

CGNode* cg_newMatrix0Node(uint64_t rows, uint64_t cols){
	return makeZeroMatrixConstantNode(rows, cols);
}

CGNode* cg_newVariable(char* name){
	return makeVarNode(name);
}

CGNode* cg_newBinOp(CGBinaryOperationType type, CGNode* lhs, CGNode* rhs){
	return makeBinaryOpNode(type, lhs, rhs);
}

CGNode* cg_newUnOp(CGUnaryOperationType type, CGNode* uhs){
	return makeUnaryOpNode(type, uhs);
}


CGNode* cg_newSumOp(struct CGNode* uhs, uint8_t axis){
	return makeSumNode(uhs, axis);
}

CGNode* cg_newGraphNode(CGraph* graph){
	return makeGraphNode(graph);
}

void cg_setVar(CGraph* graph, char* var, CGNode* value){
	graphSetVar(graph, var, value);
}

CGNode* cg_getVar(CGraph* graph, char* var){
	return graphGetVar(graph, var);
}

CGResultNode* cg_evalGraph(CGraph* graph){
	return computeGraph(graph);
}

CGError* cg_getResultError(CGResultNode* result){
	return result->error;
}

CGErrorType cg_getErrorType(CGError* error){
	return error->errorType;
}

const char* cg_getErrorMessage(CGError* error){
	return error->message;
}

CGNode* cg_getErrorFaultyNode(CGError* error){
	return error->faultyNode;
}

CGVarType cg_getResultType(CGResultNode* result){
	return result->type;
}

CGDouble* cg_getResultDoubleVal(CGResultNode* result){
	return result->value;
}
CGVector* cg_getResultVectorVal(CGResultNode* result){
	return result->value;
}

CGMatrix* cg_getResultMatrixVal(CGResultNode* result){
	return result->value;
}

CGraph* cg_diffGraph(CGraph* graph, char* newName, CGNode* wrtVar){
	return differentiateGraphWRTNode(graph, newName, wrtVar);
}
