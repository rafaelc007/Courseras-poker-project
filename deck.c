#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  //prints out the contents of a hand of cards
  for(unsigned i=0;i<hand->n_cards;i++){
    print_card(*hand->cards[i]);
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
  unsigned size = d->n_cards;
  card_t * tmp;
  for(unsigned i=size-1;i>1;i--){
    unsigned j = (unsigned)((float)(rand()/RAND_MAX)*(i+1));
    tmp = d->cards[i];
    d->cards[i] = d->cards[j];
    d->cards[j] = tmp;
  }
}

void assert_repeat(deck_t * d){
   // check for repeated cards
  for(unsigned i=0;i<d->n_cards-1;i++){
    for(unsigned j=i;j<d->n_cards;j++){
      if(equal_card(*d->cards[i],*d->cards[j])){
	  printf("ERROR: Deck contains repeated cards!");
	  assert(0);
      }
    }
  }
}

void assert_full_deck(deck_t * d) {
  assert_repeat(d);
  // check if the entire deck is present
  card_t card;
  for(unsigned i=0;i<53;i++){
    card = card_from_num(i);
    if(!deck_contains(d,card)){
      printf("ERROR: card ");
      print_card(card);
      printf(" is missing!");
      assert(0);
    }
  }
}
