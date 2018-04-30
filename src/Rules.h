#pragma once
#include "Common.h"
//-------------------------------------------------------------------------------
RELATION&   AddFact(CONCEPT& Source, ACTION& Link, CONCEPT& Target, float fBelief = 1.f);
//-------------------------------------------------------------------------------
RELATION&	AddGoal(ACTION& Rule, CONCEPT& Source, ACTION& Link, CONCEPT& Beneficiary, CONCEPT* pObject = NULL);
//-------------------------------------------------------------------------------
RELATION&	AddEffect(ACTION& Rule,  CONCEPT& Source, ACTION& Link, CONCEPT& Beneficiary, CONCEPT* pObject = NULL);
//-------------------------------------------------------------------------------
CONCEPT&	AddVariable(CONCEPT& Type);
//-------------------------------------------------------------------------------
CONCEPT&	AddConstant(CONCEPT& Type, const char* Value);
//-------------------------------------------------------------------------------
ACTION&     NewRule(float (*pUpdater)(ACTION&, RELATION**, int, RELATION**, int));
//-------------------------------------------------------------------------------
