#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  //prints out the contents of a hand of cards
  card_t * cards = hand->cards[0];
  for(unsigned i=0;i<hand->n_cards;i++){
    print_card(cards[i]);
    printf(" ");
  }
}

int equal_card(card_t c1, card_t c2){
  if(c1.value == c2.value && c1.suit == c2.suit)
    return 1;
  else
    return 0;
}

int deck_contains(deck_t * d, card_t c) {
  for(unsigned i=0;i<d->n_cards;i++){
    if(equal_card(*d->cards[i],c))
      return 1;
  }
  return 0;
}

void shuffle(deck_t * d){

}

void assert_full_deck(deck_t * d) {

}
