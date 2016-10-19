/*Cards.c*/
/*****************************************************************************/
/* COP4338 U03
 Irma Castillo Koelig 5619244
   assignment #3 Deck of Cards, Thursday, 6 October 2016, 6:25 PM

   program description
     program will accept number of players and number of cards
     program will format output showing a deck of cards                         
    

   "I hereby certify that this collective work is my own and none of it is the
   work of any other person or entity, but I use online help from website, and
   from peers. "  Irma Castillo Koelig */
/*****************************************************************************/
#include "GameDefinitions.h"  /* To include definitions and function prototypes*/
/******************************************************************************/
/*To handle special cases of the cards*/
char * getCardDetails(struct card crd) {

    char suit[10]; 
    char rank[6];

   
    switch (crd.rank) {
        case 1:
            strcpy(rank, "Ace");
            break;
        case 11:
            strcpy(rank, "Jack");
            break;
        case 12:
            strcpy(rank, "Queen");
            break;
        case 13:
            strcpy(rank, "King");
            break;   
        default: 
            sprintf(rank, "%i", crd.rank);
            break;
    }

    switch (crd.suit) {
        case 1:
            strcpy(suit, CLUB);
            break;
        case 2:
            strcpy(suit, SPADE);
            break;
        case 3:
            strcpy(suit, HEART);
            break;
        case 4:
            strcpy(suit, DIAMOND);
            break;
        default:
            break;
    }
    static char final[20]; 
    sprintf(final, "%s of %s ", rank, suit);
    return final;
}

/*****************************************************************************/
/*Construct Card*/
/*builds a card using the defined structure for cards*/
/*Par@: Suit and rank of the cards*/
struct card buildCard(int suit, int rank) {

    struct card oneCard;

    oneCard.suit = suit;
    oneCard.rank = rank;

    return oneCard;
}


/*****************************************************************************/
/*Print Card*/
/*Param: Cards*/
void showCard(struct card oneCard) {
    char *c = getCardDetails(oneCard);
    printf("%s",c);
}

/*****************************************************************************/
/*Construct deck of cards by passing the card structure rank, and suit to 
 a position from 1 to 52 on a deck. The function works by iterating over a
 double for loop on the suits, and ranks.
 par@ams: cards*/
void buildDeck(struct card * deckStruct) {

    int position = 0;

    int i;
    int j;

    for (i = 1; i <= SUIT; i++) { 
        for (j = 1; j <= RANK; j++) {
            struct card oneCard = buildCard(i, j);
            deckStruct[position] = oneCard;
            position++;
        }
    }
}


/*****************************************************************************/
/* Builds a hand for players by the amount of players, and the amount of cards,
 * also having in considerations the deck structure.
 * par@:total number of players
 *      number of cards
 * return: hand dealt per players
 */
struct hand * dealDeckPAX(int numPlayers, int numCards, struct card * deckStruct) {

    static struct hand handDealt[MAXPLAYERS];

    int card;
    int currentPlayer;
    int k = 0;

    for (card = 0; card < numCards; card++) { 

        for (currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++) {          
            handDealt[currentPlayer].numCards[card] = deckStruct[k];
            k++;
        }
    }
    return handDealt;

}

/**********************************************************************/
/*Print Deck ordered*/
/*params: a deck
  return: not returm*/
void printDeckPretty(struct card * deckStruct) {
    int i;
    for (i = 0; i < CARDSTOT; i++) {
        showCard(*(deckStruct + i));
        printf("\n");
    }
}


/***************************************************************************/
/* print the players cards on hand, by accessing to the amount of players, and
 * players current cards on hand.
 * par@: number of players, number of cards, and dealt
 */
void printHandsPretty(int numPlayers, int numCards, struct hand * handDealt) {

    int currentPlayer;
    int card;

    for (currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++) { 

        printf("Player %i: \n", currentPlayer + 1);

        for (card = 0; card < numCards; card++) { 

            printf("\tCard-%i Suit: %i Value: %i\n"
                    , card + 1, handDealt[currentPlayer].numCards[card].suit
                    , handDealt[currentPlayer].numCards[card].rank);
        }

        printf("\n");
    }

}

/******************************************************************************/
/* Shuffle Deck*/
/* Starting by 52 which is the max number of cards and decreasing */
/* the cards number the algorithm srand mixes the cards by using time*/
/* and this warranties that there are no repetitions on the construction*/
/* of a new deck.*/
/* par@: a deck*/

void shuffle(struct card * deckStruct) {

    srand(time(NULL));
    
    /*Shuffling Algorithm*/
    int i;
    for (i = CARDSTOT - 1; i > 0; i--) {

        int j = rand() % (i + 1);

        change(&deckStruct[i], &deckStruct[j]);
    }

}


/**************************************************************************/
/*Auxiliary method used in the shuffle method to swap the card in the deck*/
/*params: card1, card2 */

void swap(struct card * card1, struct card * card2) {
    struct card temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}


/**************************************************************************/
/*Decides the winner of the game*/
void decideGame(int numPlayers, struct hand * handDealt) {
    
    int currentPlayer;
    int maxRank = 0;
    for (currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++) {
        if (handDealt[currentPlayer].rank > maxRank) {
            maxRank = handDealt[currentPlayer].rank;
        }
    }

    printf("Winner: ");
    for (currentPlayer = 0; currentPlayer < numPlayers; currentPlayer++) {
        if (handDealt[currentPlayer].rank == maxRank) {
            printf("%i", currentPlayer + 1);
            printf(",");
        }
    }
    printf("\n");
}
