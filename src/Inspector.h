#pragma once

#include "neo4j-client.h"
#include "Rules.h"
#include "Common.h"

#define WEEK_SECONDS  604800
#define MONTH_SECONDS 2629743
#define YEAR_SECONDS  31556926

namespace BITCOIN_INSPECTOR {
	extern int gRuleId;	
	//-------------------------------------------------------------------------------	
	bool IsDeducedByRule(int RuleId, RELATION& Relation);
	//-------------------------------------------------------------------------------
	float UpdateHypothesis(int RuleId, RELATION& Relation, float fBelief);
	//-------------------------------------------------------------------------------
	int TransactionsCount(CONCEPT& BitAddressSrc, CONCEPT& BitAddressDst, time_t start, time_t end, unsigned int min = 0, unsigned int max = -1);    	
	//-------------------------------------------------------------------------------
	CONCEPT* GetNextTransactionInput(ACTION& Transaction, int& iCursor);
	//-------------------------------------------------------------------------------
	CONCEPT* GetNextTransactionOutput(ACTION& Transaction, int& iCursor);
	//-------------------------------------------------------------------------------
	int Init(int argc, char ** argv);
	//-------------------------------------------------------------------------------
	void TriggerRule(ACTION& Rule);
	//-------------------------------------------------------------------------------
	void Deinit();
}
