
#include <stdint.h>

#include "ccgraph.h"
#include "cg_operation.h"

const char* BinaryOperationTypeString[] = {
	"+",
	"-",
	"*",
	"/",
	"^",
	"dot",
	"^T*"
};

const char* UnaryOperationTypeString[] = {
	"-",
	"inv",
	"T",
	"exp",
	"log",
};

const char* NodeTypeString[] = {
	"VARIABLE",
	"CONSTANT",
	"GRAPH",
	"BINARY_OPERATION",
	"UNARY_OPERATION"
};

const char* VariableTypeString[] = {
	"DOUBLE",
	"VECTOR",
	"MATRIX"
};

const char* ErrorTypeString[] = {
	"INCOMPATIBLE_ARGS_EXCEPTION",
	"INCOMPATIBLE_DIMENTIONS_EXCEPTION",
	"OVERFLOW_EXCEPTION",
	"VARIABLE_DOES_NOT_EXIST"
};

const char* getBinaryOperationTypeString(CGBinaryOperationType type){
	return BinaryOperationTypeString[type];
}

const char* getUnaryOperationTypeString(CGUnaryOperationType type){
	return UnaryOperationTypeString[type];
}

const char* getNodeTypeString(CGNodeType type){
	return NodeTypeString[type];
}

const char* getVariableTypeString(CGVarType type){
	return VariableTypeString[type];
}

const char* getErrorTypeString(CGErrorType type){
	return ErrorTypeString[type];
}
