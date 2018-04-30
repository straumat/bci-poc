#include <errno.h>
#include <stdio.h>
#include "Inspector.h"
//-------------------------------------------------------------------------------
float BitTransRule1Callback(ACTION& PerformedTransaction, RELATION** Goals, int GoalsCount, RELATION** Effects, int EffectsCount){
    if(EffectsCount != 1)
        return 0.f;
    //--
    RELATION& Effect = *Effects[0];    
	if(BITCOIN_INSPECTOR::IsDeducedByRule(1, Effect))
        return 0.f;  
    //--
    CONCEPT& TransactionInputs  = ACTIONS::GetActor(PerformedTransaction);
    CONCEPT& TransactionOutputs = ACTIONS::GetTarget(PerformedTransaction);
    //--
    CONCEPT* pFrom = NULL;
    CONCEPT* pTo = NULL;
    float fRegular = 0.f;
    float fGeoPos = 0.f;
    float fOwn = 0.f;
    for(int iGoal = 0; iGoal<GoalsCount; ++iGoal) {
        RELATION& Goal = *Goals[iGoal];
        float fGoalTruth = RELATIONS::GetTruth(Goal);
        ACTION& GoalLink = RELATIONS::GetLink(Goal);
        CONCEPT& GoalBeneficiary = RELATIONS::GetBeneficiary(Goal);
        if(fGoalTruth < 0.f)
            return 0.f;
        if(ACTIONS::IsDescendantOf(GoalLink, *ACTIONS::INBITTRANSACTION)) {
            if(&GoalBeneficiary == &TransactionInputs)
                pFrom = &RELATIONS::GetSource(Goal);
            else if(&GoalBeneficiary == &TransactionOutputs)
                pTo = &RELATIONS::GetSource(Goal);
        }
        else if(ACTIONS::IsDescendantOf(GoalLink, *ACTIONS::GEO_POS))
            fGeoPos = fGoalTruth;
        else if(ACTIONS::IsDescendantOf(GoalLink, *ACTIONS::OWN))
            fOwn = fGoalTruth;
    }

    time_t now = 1277897695; //-- June 30th, 2010
    //time(&now);
    if(pFrom && pTo) {
        int iTransactionsCount = BITCOIN_INSPECTOR::TransactionsCount(*pFrom, *pTo, now - 2*MONTH_SECONDS, now);
        if(iTransactionsCount >= 5) {
            fRegular = 0.8f;
        }
        else if(iTransactionsCount >= 2) {
            fRegular = 0.4f;
        }
    }

    float fFinal = fOwn*fGeoPos*fRegular;   
    return BITCOIN_INSPECTOR::UpdateHypothesis(1, Effect, fFinal);
}
float BitTransRule2Callback(ACTION& PerformedTransaction, RELATION** Goals, int GoalsCount, RELATION** Effects, int EffectsCount){
    if(GoalsCount < 1)
        return 0.f;

    float fIran = 0.f;
    for(int iGoal = 0; iGoal<GoalsCount; ++iGoal) {
        RELATION& Goal = *Goals[iGoal];
        float fGoalTruth = RELATIONS::GetTruth(Goal);
        ACTION& GoalLink = RELATIONS::GetLink(Goal);
        CONCEPT& GoalBeneficiary = RELATIONS::GetBeneficiary(Goal);
        if(fGoalTruth < 0.f)
            return 0.f;
        if(&GoalBeneficiary == CONCEPTS::IRAN) {
            fIran = fGoalTruth;
            break;
        }
    }

    RELATION& Effect = *Effects[0];
    float fBelief = fIran;
    return BITCOIN_INSPECTOR::UpdateHypothesis(2, Effect, fBelief);
}
float BitTransRule3Callback(ACTION& PerformedTransaction, RELATION** Goals, int GoalsCount, RELATION** Effects, int EffectsCount){
    if(GoalsCount < 1)
        return 0.f;
    
    float fFondation = 0.f;
    for(int iGoal = 0; iGoal<GoalsCount; ++iGoal) {
        RELATION& Goal = *Goals[iGoal];
        float fGoalTruth = RELATIONS::GetTruth(Goal);
        ACTION& GoalLink = RELATIONS::GetLink(Goal);
        CONCEPT& GoalSource = RELATIONS::GetSource(Goal);
        if(fGoalTruth < 0.f)
            return 0.f;
        if(CONCEPTS::IsDescendantOf(GoalSource, *CONCEPTS::FOUNDATION)) {
            fFondation = fGoalTruth;
            break;
        }
    }

    RELATION& Effect = *Effects[0];
    float fBelief = fFondation;
    return BITCOIN_INSPECTOR::UpdateHypothesis(3, Effect, fBelief);
}
float BitTransRule4Callback(ACTION& PerformedTransaction, RELATION** Goals, int GoalsCount, RELATION** Effects, int EffectsCount){
    if(GoalsCount < 1)
        return 0.f;

    float fAssociation = 0.f;
    for(int iGoal = 0; iGoal<GoalsCount; ++iGoal) {
        RELATION& Goal = *Goals[iGoal];
        float fGoalTruth = RELATIONS::GetTruth(Goal);
        ACTION& GoalLink = RELATIONS::GetLink(Goal);
        CONCEPT& GoalSource = RELATIONS::GetSource(Goal);        
        if(fGoalTruth < 0.f)
            return 0.f;
        if(CONCEPTS::IsDescendantOf(GoalSource, *CONCEPTS::ASSOCIATION)) {
            fAssociation = fGoalTruth;
            break;
        }
    }

    RELATION& Effect = *Effects[0];
    float fBelief = 0.9f*fAssociation;
    return BITCOIN_INSPECTOR::UpdateHypothesis(4, Effect, fBelief);
}
float BitTransRule5Callback(ACTION& PerformedTransaction, RELATION** Goals, int GoalsCount, RELATION** Effects, int EffectsCount){
    if(GoalsCount < 1)
        return 0.f;

    float fRansomeWare = 0.f;
    for(int iGoal = 0; iGoal<GoalsCount; ++iGoal) {
        RELATION& Goal = *Goals[iGoal];
        float fGoalTruth = RELATIONS::GetTruth(Goal);
        ACTION& GoalLink = RELATIONS::GetLink(Goal);
        CONCEPT& GoalSource = RELATIONS::GetSource(Goal);        
        if(fGoalTruth < 0.f)
            return 0.f;
        if(CONCEPTS::IsDescendantOf(GoalSource, *CONCEPTS::RANSOMEWARE)) {
            fRansomeWare = fGoalTruth;
            break;
        }
    }

    RELATION& Effect = *Effects[0];
    float fBelief = fRansomeWare;
    return BITCOIN_INSPECTOR::UpdateHypothesis(5, Effect, fBelief);
}
float BitTransRule6Callback(ACTION& PerformedTransaction, RELATION** Goals, int GoalsCount, RELATION** Effects, int EffectsCount){
    if(GoalsCount < 1)
        return 0.f;
    RELATION& Effect = *Effects[0];
    float fBelief = 1.f;
    return BITCOIN_INSPECTOR::UpdateHypothesis(6, Effect, fBelief);
}
float BitTransRule7Callback(ACTION& PerformedTransaction, RELATION** Goals, int GoalsCount, RELATION** Effects, int EffectsCount){
    if(GoalsCount < 1)
        return 0.f;
    RELATION& Effect = *Effects[0];
    //--
	if(BITCOIN_INSPECTOR::IsDeducedByRule(7, Effect))
        return 0.f;
    //--
    CONCEPT& TransactionInputs  = ACTIONS::GetActor(PerformedTransaction);
    CONCEPT& TransactionOutputs = ACTIONS::GetTarget(PerformedTransaction);
    //--
    CONCEPT* pFrom = NULL;
    CONCEPT* pTo = NULL;
    float fSalary = 0.f;
    float fCompany = 0.f;
    for(int iGoal = 0; iGoal<GoalsCount; ++iGoal) {
        RELATION& Goal = *Goals[iGoal];
        float fGoalTruth = RELATIONS::GetTruth(Goal);
        ACTION& GoalLink = RELATIONS::GetLink(Goal);
        CONCEPT& GoalSource = RELATIONS::GetSource(Goal);        
        CONCEPT& GoalBeneficiary = RELATIONS::GetBeneficiary(Goal);
        if(fGoalTruth < 0.f)
            return 0.f;
        if(ACTIONS::IsDescendantOf(GoalLink, *ACTIONS::INBITTRANSACTION)) {
            if(&GoalBeneficiary == &TransactionInputs)
                pFrom = &RELATIONS::GetSource(Goal);
            else if(&GoalBeneficiary == &TransactionOutputs)
                pTo = &RELATIONS::GetSource(Goal);
        }
        else  if(CONCEPTS::IsDescendantOf(GoalSource, *CONCEPTS::COMPANY))
            fCompany = fGoalTruth;
    }

    time_t now = 1276113205; //-- June 9th, 2010
    //time(&now);
    if(pFrom && pTo) {
        int iTransactionsCount1 = BITCOIN_INSPECTOR::TransactionsCount(*pFrom, *pTo, now - WEEK_SECONDS, now, 1000, 4000);
        int iTransactionsCount2 = BITCOIN_INSPECTOR::TransactionsCount(*pFrom, *pTo, now - 2*WEEK_SECONDS, now - WEEK_SECONDS, 1000, 4000);
        if(iTransactionsCount1 == 1 && iTransactionsCount2 == 1)
            fSalary = 0.8f;
    }

    float fBelief = fCompany * fSalary;
    return BITCOIN_INSPECTOR::UpdateHypothesis(7, Effect, fBelief);
}
//-------------------------------------------------------------------------------
ACTION* AddRule(int index) {

    switch(index) {

        //-- Rule 1 : IF an address (A) makes regular money transfer to another address B owned by an entity that is a restaurant 
        //--          THEN A's owner address country = B's owner address.
        case 1:
        {
            //-- Declaration of the rule. Takes as input a function that computes the rule's effects believes
            //-- according to the unified goals.
            ACTION& BitTransRule1 = NewRule(BitTransRule1Callback);

            //-- Variables declaration. A variable has a type e.g. A is of type BITADDRESS. 
            //-- L is of type "target of a GEO_POS action"
            CONCEPT& L = AddVariable(ACTIONS::GetTarget(*ACTIONS::GEO_POS));
            CONCEPT& A = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& B = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& P = AddVariable(*CONCEPTS::LEGAL_PERSON);

            //-- IF <A, InBitTransaction, Actor(Transaction)> AND <B, InBitTransaction, Target(Transaction)>
            //--	AND	<B, GeoPos, L> AND <P, Own, B>
            AddGoal(BitTransRule1, A, *ACTIONS::INBITTRANSACTION, ACTIONS::GetActor(BitTransRule1));
            AddGoal(BitTransRule1, B, *ACTIONS::INBITTRANSACTION, ACTIONS::GetTarget(BitTransRule1));
            AddGoal(BitTransRule1, B, *ACTIONS::GEO_POS, L);
            AddGoal(BitTransRule1, P, *ACTIONS::OWN, B);

             //-- THEN <A, GeoPos, L>				
            AddEffect(BitTransRule1, A, *ACTIONS::GEO_POS, L);

            return &BitTransRule1;
        }
        break;

        //-- Rule 2 : IF an address (A) makes a money transfer to IRAN 
        //--					THEN Raises an alert.
        case 2:
        {
            
            ACTION& BitTransRule2 = NewRule(BitTransRule2Callback);

            //-- Create variables
            CONCEPT& A = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& B = AddVariable(*CONCEPTS::BITADDRESS);

            //-- IF <X, Transaction Y>, <Y, GeoPos, IRAN> THEN <X, Inherite, Illegal>
            AddGoal(BitTransRule2, A, *ACTIONS::INBITTRANSACTION, ACTIONS::GetActor(BitTransRule2)  );
            AddGoal(BitTransRule2, B, *ACTIONS::INBITTRANSACTION, ACTIONS::GetTarget(BitTransRule2) );
            AddGoal(BitTransRule2, B, *ACTIONS::GEO_POS, *CONCEPTS::IRAN);

            AddEffect(BitTransRule2, A, *ACTIONS::INHERITE, *CONCEPTS::ILLEGAL);

            return &BitTransRule2;            
        }
        break;

        case 3:
        {
            //-- Rule 3 : IF a bitcoin address makes a transaction to a well known foundation (wikipedia) THEN create a relationship "made a donation" to the foundation.

            //-- IF <X, Transaction Y>, <Y, Inherite, Foundation> THEN <X, Donation, Y>

            ACTION& BitTransRule3 = NewRule(BitTransRule3Callback);

            //-- Create variables
            CONCEPT& A = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& B = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& Foundation1 = AddVariable(*CONCEPTS::FOUNDATION);

            //-- Setting up the rule
            AddGoal(BitTransRule3, A, *ACTIONS::INBITTRANSACTION, ACTIONS::GetActor(BitTransRule3)  );
            AddGoal(BitTransRule3, B, *ACTIONS::INBITTRANSACTION, ACTIONS::GetTarget(BitTransRule3) );
            AddGoal(BitTransRule3, Foundation1, *ACTIONS::OWN, B);
            AddEffect(BitTransRule3, A, *ACTIONS::DONATION, Foundation1);

            return &BitTransRule3;            
        }
        break;

        case 4:
        {
            //-- Rule 4 : I recently join an association by making a payment to the address : 1NVvJotS6V9SPYM1f6Mu9anu4dtFyTRNv9. 
            //-- If an address also make a payment to this address, then the owner is a member of the association (90%).
            //-- IF <X, Transaction, Y>, <Y, Inherite, Association> THEN <X, Belong, Y>

            ACTION& BitTransRule4 = NewRule(BitTransRule4Callback);

            CONCEPT& MonAssoAddress = AddConstant(*CONCEPTS::BITADDRESS, "1NVvJotS6V9SPYM1f6Mu9anu4dtFyTRNv9");
            CONCEPT& MonAsso = AddConstant(*CONCEPTS::ASSOCIATION, "UneAsso");
            RELATION& Fact = AddFact(MonAsso, *ACTIONS::OWN, MonAssoAddress);

            //-- Create variables
            CONCEPT& A    = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& Asso = AddVariable(*CONCEPTS::ASSOCIATION);

            //-- Setting up the rule
            AddGoal(BitTransRule4, A, *ACTIONS::INBITTRANSACTION, ACTIONS::GetActor(BitTransRule4)  );
            AddGoal(BitTransRule4, MonAssoAddress, *ACTIONS::INBITTRANSACTION, ACTIONS::GetTarget(BitTransRule4) );
            AddGoal(BitTransRule4, Asso, *ACTIONS::OWN, MonAssoAddress);

            AddEffect(BitTransRule4, A, *ACTIONS::BELONG, Asso);

            return &BitTransRule4;
        }
        break;

        case 5:
        {
            //-- Rule 5 : IF a known bitcoin address receives money from an address used by ransomeware THEN raise an alert.
            //-- IF <X, Transaction, Y>, <X, Inherite, RansomeWare> THEN <Y, Inherite, Illegal>
            ACTION& BitTransRule5 = NewRule(BitTransRule5Callback);

            //-- Create variables
            CONCEPT& A = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& B = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& C = AddVariable(*CONCEPTS::RANSOMEWARE);

            //-- Setting up the rule
            AddGoal(BitTransRule5, A, *ACTIONS::INBITTRANSACTION, ACTIONS::GetActor(BitTransRule5)  );
            AddGoal(BitTransRule5, B, *ACTIONS::INBITTRANSACTION, ACTIONS::GetTarget(BitTransRule5) );
            AddGoal(BitTransRule5, C, *ACTIONS::OWN, A);

            AddEffect(BitTransRule5, B, *ACTIONS::INHERITE, *CONCEPTS::ILLEGAL);

            return &BitTransRule5;		
        }
        break;

        case 6:
        {
            //-- Rule 6 : IF a payment is made to this distributor located in France THEN the country of the owner is France (25% sure).
            //-- IF <X, Transaction, ThisDistributor> THEN <X, GeoPos, France>
            ACTION& BitTransRule6 = NewRule(BitTransRule6Callback);

            CONCEPT& ThisDistributor = AddConstant(*CONCEPTS::LOCAL_SHOP, "ThisDistributor");
            CONCEPT& ThisDistributorAddress = AddConstant(*CONCEPTS::BITADDRESS, "1MNdEmGTuKvE2z7BeM1B6hRgg5NnMsXxAa");
            RELATION& Fact = AddFact(ThisDistributor, *ACTIONS::OWN, ThisDistributorAddress);

            //-- Create variables
            CONCEPT& A = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& B = AddVariable(*CONCEPTS::BITADDRESS);	

            //-- Setting up the rule
            AddGoal(BitTransRule6, A, *ACTIONS::INBITTRANSACTION, ACTIONS::GetActor(BitTransRule6)  );
            AddGoal(BitTransRule6, B, *ACTIONS::INBITTRANSACTION, ACTIONS::GetTarget(BitTransRule6) );			
            AddGoal(BitTransRule6, ThisDistributor, *ACTIONS::OWN, B);

            AddEffect(BitTransRule6, A, *ACTIONS::GEO_POS, *CONCEPTS::FRANCE);

            return &BitTransRule6;			
        }
        break;

        case 7:
        {
            //-- Rule 7 : IF a known entreprise make payment between 1 000 and 4 000 euros every month to an address THEN the owner is probably (80%) working for this company.

            //-- IF <X, Transaction, Y>, <X, Inherite, Company> THEN <Y, Belong, X>

            //-- Create variables
            ACTION& BitTransRule7 = NewRule(BitTransRule7Callback);

            //-- Create variables
            CONCEPT& A = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& B = AddVariable(*CONCEPTS::BITADDRESS);
            CONCEPT& C = AddVariable(*CONCEPTS::COMPANY);            

            //-- Setting up the rule
            AddGoal(BitTransRule7, A, *ACTIONS::INBITTRANSACTION, ACTIONS::GetActor(BitTransRule7)  );
            AddGoal(BitTransRule7, B, *ACTIONS::INBITTRANSACTION, ACTIONS::GetTarget(BitTransRule7) );
            AddGoal(BitTransRule7, C, *ACTIONS::OWN, A);
            AddEffect(BitTransRule7, B, *ACTIONS::BELONG, C);

            return &BitTransRule7;
        }
        break;

    }

    return NULL;
}
//-------------------------------------------------------------------------------
int main(int argc, char ** argv) {
    if(int RuleId = BITCOIN_INSPECTOR::Init(argc, argv)) {
        if(ACTION* pRule = AddRule(RuleId)) {
            BITCOIN_INSPECTOR::TriggerRule(*pRule);
            BITCOIN_INSPECTOR::Deinit();                  
        }
        else
            printf("rule %d is not defined", RuleId);
    }
    return 0;
}
//-------------------------------------------------------------------------------
