#ifndef CG_OPERATION_H
#define CG_OPERATION_H

#include <stdint.h>

#include "cgraph.h"
#include "cg_enums.h"

typedef struct CGBinaryOperation {
	struct CGNode* lhs;
	struct CGNode* rhs;
	
	CGBinaryOperationType type;
}CGBinaryOperation;

typedef struct CGSumOperation{
	struct CGNode* uhs;
	uint8_t axis;
}CGSumOperation;

typedef struct CGUnaryOperation {
	struct CGNode* uhs;
	CGUnaryOperationType type;
}CGUnaryOperation;


#endif
