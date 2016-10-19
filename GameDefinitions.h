
/*GameDefinitions.h*/
/*****************************************************************************/
/*
   assignment #3 Deck of Cards, Thursday, 6 October 2016, 6:25 PM

   program description
     program will accept number of players and number of cards
     program will format output showing a deck of cards                         
    

   "I hereby certify that this collective work is my own and none of it is the
   work of any other person or entity, but I use online help from website, and
   from peers. "  Irma Castillo Koelig */
/*****************************************************************************/
#ifndef GAME_DEFINITIONS_H
#define	GAME_DEFINITIONS_H

#include <stdio.h> 
#include <stdlib.h> 

#include "time.h"
#include "string.h"  

/********************************************************/
/*Programs definitions*/
#define MINPLAYERS 2          /*minumin amount of players */
#define MAXPLAYERS 7          /*maximun amount of players*/
#define MINCARD 5             /*min ammount of cards to play*/
#define MAXCARD 5             /*max ammount of cards to play*/
#define SUIT 4                /*number of suits in cards*/
#define RANK 13               /* rank value in cards*/
#define CARDSTOT SUIT*RANK    /*total number of cards*/

/*CARD codes*/
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"   


/*Defining card structure*/
struct card {
    int suit;
    int rank;
};

/*Building hand structure*/
struct hand{
    int rank;   /* card rank*/
    struct card numCards[MAXCARD];  /*num of cards in hand no more than 5 */
};

/* Function Prototypes */
char * getCardDetails(struct card crd);
struct card buildCard();
void showCard(struct card oneCard);
void buildDeck(struct card * deckStruct);
struct hand * dealDeckPAX(int numPlayers, int numCards, struct card * deckStruct);
void printDeckPretty(struct card * deckStruct);
void printHandsPretty(int numPlayers, int numCards, struct hand * handDealt);
void shuffle(struct card * deckStruct);
void change(struct card * card1, struct card * card2);
void decideGame(int numPlayers, struct hand * handDealt);

#endif

