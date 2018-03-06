/*
Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak,
 and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines. 
 Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. 
It is assumed that the initial status of a card deck is in the following order:

S1, S2, ..., S13, H1, H2, ..., H13, C1, C2, ..., C13, D1, D2, ..., D13, J1, J2

where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker".
A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, 
it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. 
Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, 
the result will be: C1, H5, S3, J2, D13.
≥¢ ‘∑≠“Î£∫œ¥≈∆ «“ª÷÷ 
*/
