#pragma once

#include <time.h>

struct CONCEPT;
struct ACTION;
struct RELATION;

#ifndef NULL
    #define NULL 0
#endif

namespace CONCEPTS {
    extern CONCEPT* BITADDRESS       ;
    extern CONCEPT* LEGAL_PERSON     ;
    extern CONCEPT* ILLEGAL          ;
    extern CONCEPT* IRAN             ;
    extern CONCEPT* FRANCE           ;
    extern CONCEPT* COUNTRY          ;
    extern CONCEPT* FOUNDATION       ;
    extern CONCEPT* COMPANY          ;
    extern CONCEPT* RANSOMEWARE      ;
    extern CONCEPT* ASSOCIATION      ;
    extern CONCEPT* LOCAL_SHOP       ;
    RELATION* GetNextRelation(CONCEPT& Concept, ACTION& Action, int& iCursor);
    bool	  IsDescendantOf(CONCEPT& Child, CONCEPT& Parent);
    int GetNumConcepts();
}

namespace ACTIONS {
    extern ACTION*  BITTRANSACTION   ;
    extern ACTION*  INBITTRANSACTION ;
    extern ACTION*  DONATION         ;
//    extern ACTION*  SHOPPING         ;
    extern ACTION*  OWN              ;
    extern ACTION*  BELONG           ;
    extern ACTION*  INHERITE         ;
    extern ACTION*  GEO_POS          ;

    CONCEPT& GetTarget(ACTION& Action);
    CONCEPT& GetActor(ACTION& Action);
    bool	  IsDescendantOf(ACTION& Child, ACTION& Parent);
    
}

namespace RELATIONS {
    void  SetTruth(RELATION& Relation, float fTruth);
    float GetTruth(RELATION& Relation);
    float   CombineTruth(RELATION& Relation, float fTruth, float fWeakening = 0.f);    
    CONCEPT& GetSource(RELATION& Relation);
    ACTION&  GetLink(RELATION& Relation);
    CONCEPT& GetBeneficiary(RELATION& Relation);
    int GetNumRelations();
}


