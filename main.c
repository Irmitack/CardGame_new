/*main.c*/
/***************************************************/
/* COP4338 U03
 Irma Castillo Koelig 5619244
   assignment #3 Deck of Cards, Thursday, 6 October 2016, 6:25 PM

   program description
     program will accept number of players and number of cards
     program will format output showing a deck of cards                         
    

   "I hereby certify that this collective work is my own and none of it is the
   work of any other person or entity, but I use online help from website, and
   from peers. "  
   * Irma Castillo Koelig 5619244


   how to compile and execute
     cardGame: main.c Card.c
     gcc -o main main.c Card.c -I.
*/
/***********************************************************/
#include "GameDefinitions.h"
#include "Cards.c"

/***********************************************************/
/*Pseudocode*/
/* 
 * it uses the function atoi showed on textbook on page: 
 that  converts a string into an integer numerical representation
 to validate  number of players, and ammount of cards.
 * After it validates the input if it is correct, it build the deck,
 * then distribute the cards, and show the old deck with card on hands.
 * It shuffle the deck
 * decide winner player with greatest rank on hand
 
 */

/***********************************************************/
int main(int argc, char** argv) {
    
    //First Input is Number of Players:
    //Second input is number of Cards:
    int numPlayers;
    int numCards;
    
    //Handle Command Line Arguments Error
    if (argc < 3){
      printf("Enter Number of Players and Number Cards.\n");
      return 0;
    }

    else{
        numCards = atoi(argv[1]); /* number of cards, first input param */
        numPlayers = atoi(argv[2]); /* number of players, second input param*/

        if (numPlayers < MINPLAYERS || numPlayers > MAXPLAYERS) {
            printf("Enter number of Player Again\n");
            return 0;
        }
        if (numCards < MINCARD || numCards > MAXCARD) {
            printf("Enter number of cards again\n");
            return 0;
        }
    }
        
    /*Build Deck*/
    struct card deckStruct[CARDSTOT];
    buildDeck(deckStruct); 
    
    /*Print deck*/
    printf("Printing Original Deck:\n");
    printDeckPretty(deckStruct);
    printf("\n");
    
    //Shuffle Deck
    shuffle(deckStruct);
    
    /*Print Deck*/
    printf("Deck After Shuffling:\n");
    printDeckPretty(deckStruct);
    printf("\n");
    
    /* Deal*/
    printf("Distributing Cards.\n\n");
    struct hand * handDealt = dealDeckPAX(numPlayers, numCards, deckStruct);
    
    /*Show Hands of players*/
    printf("Hands Dealt:\n");
    printHandsPretty(numPlayers, numCards, handDealt);
    printf("\n");

    //Decide winner
    decideGame(numPlayers, handDealt);
        
    return (0);
}
