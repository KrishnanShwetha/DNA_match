/**
 * Using Loops, functions and arrays his program computes simple DNA matching between 2 sequences.
 **/


#include <stdio.h>
#include <stdbool.h>

#define BASE_SEQ_LEN 20
#define TARGET_SEQ_LEN 5
#define NUM_BASES 4
#define THRESHOLD 3



/* function prototypes */
/*  See function definitions below for documentation */
_Bool read_sequence(char[], int);
_Bool match(const char[], const char[], int, int, int);
void print_sequence_part(const char[], int, int);
void print_sequence(const char[], int);
_Bool is_valid_base(char);

/* external variables */
const char bases[] = {'A', 'T', 'C', 'G'};

/**
 * main: This function needs to read and store a sequence of length
 *       BASE_SEQ_LEN. Then it needs to read and store a sequence of 
 *       TARGET_SEQ_LEN. Finally it needs to call match() with both sequences.
**/
int main() {
  
    char s1[20], s2[5];
    
    // 1: Read base input sequence into s1 array
    if (read_sequence(s1, BASE_SEQ_LEN) == 0) {
      // if read_sequence returned false then there was an error
      printf("ERROR: sequence 1 is bad.  Exiting\n");
      return -1;
    }
     
    // FIXME: : Read target input sequence into s2 array
    if (read_sequence(s2, TARGET_SEQ_LEN) == 0){
      printf("ERROR: sequence 2 is bad.  Exiting\n");
      return -1;
    }

    // FIXME: : Call match function to look for match and print merged
    match(s1,s2,BASE_SEQ_LEN,TARGET_SEQ_LEN,THRESHOLD);
    return 0;
}

/****************************************************************************
 * Prints a sequence part indicated by the start and end (excluded) indices.*
 ****************************************************************************/
void print_sequence_part(const char s[], int start, int end) {
  int i;
    for (i=start; i<end; i++) {
        printf("%c", s[i]);
    }
}

/****************************************************************************
 * Prints a sequence of bases.                                              *
 ****************************************************************************/
void print_sequence(const char s[], int len) {
    print_sequence_part(s, 0, len);
    printf("\n");
}

/****************************************************************************
 * Prompts the user to input a seq_len sequence and press Enter/Return      *
 * reads a sequence of bases (A, T, C, G) and stores it in s.               *
 * Invalid bases (values that not one of the four valid bases) are ignored. *
 * If the  sequence inputed is too short then return false                  *
 *                                                                          *
 * A newline '\n' is generated when the user presses the Enter or Return    *
 * key. In such cases scanf will read the special ascii value '\n' into the *
 * variable.                                                                *  
 *                                                                          *
 * In our case we should continue to read values until we encounter a       *
 * newline.  Prior to reading a newline each valid base should be stored    *
 * consecutively into the s array until seq_len valid values have been      *
 * read.  Any addtioinal values should be ignored.                          *
 * eg.                                                                      *
 *   assuming seq_len=3                                                     *
 *    INPUT: "AGG\n"->  s[0]='A' s[1]='G' s[2]='G' return true              *
 *    INPUT: "aAgGqGv\n"->  s[0]='A' s[1]='G' s[2]='G' return true          *
 *    INPUT: "A\n"-> s[0]='A' return false                                  *
 *    INPUT: "aaaaaaaaaaaaaa' -> return false                               *
 *    INPUT: "AGGTAGGT" -> s[0]='A' s[1]='G' s[2]='G' return true           *
 ****************************************************************************/
_Bool read_sequence(char s[], int seq_len) {
    char b;
    int i = 0;

    printf("Enter a sequence of length %d: ", seq_len);
    // Read first character in to get us started
    scanf("%c", &b);
      // Loop until new line 
      // FIXME: ADD your loop here
      while (b != '\n'){
        if(i < seq_len){
          if(is_valid_base(b)==1){
            s[i] = b;
            i++;
          }
      }
        scanf("%c",&b);
    }

    // When we are done looping i should hold the length of valid bases read
    if (i != seq_len) {
      printf("Invalid: input sequence too short\n");
       return 0; // sequence too short
    }
    printf("Valid input sequence: ");
    print_sequence(s, seq_len);
    return 1;
}

/****************************************************************************
 * Checks whether the input character represents a valid base.              *
 * Returns false if b is not in the bases array which is preloaded with     *
 *  'A', 'C', 'G', 'T'.                                                     *
 ****************************************************************************/
_Bool is_valid_base(char b) {
  
  int i;
  for(i=0; i<NUM_BASES; i++){
    if(b == bases[i]){
      return 1;
    }
  }
  // if we got here then we must not have matched any of the bases elements
  return 0;
}

/****************************************************************************
 *  This function will do the real work to try and match the two DNA        *
 *  sequences. In this case, the base sequence (variable s1) will be the    * 
 *  DNA sequence we are trying to reconstruct, and its length is stored in  *
 *  the variable len1. The target sequence (s2) will be the DNA sequence    * 
 *  that we are trying to match to the base sequence to determine if it is  *
 *  a part of that sequence, and its length is stored in len2.              *
 *                                                                          *
 *  This function needs to detect matches, and return whether or not a      *
 *  match was found. Additionally, this function needs to print out one of  *
 *  two possibilities, depending on if a match was found. If a match was    *
 *  found, the function needs to print out "A match was found" and then the *
 *  concatenated sequence. You can use the print_sequence_part function to  *
 *  help with printing out the concatenated sequence. If a match was not    *
 *  found, the function needs to print out "No match found".                *
 *                                                                          *
 *  There are two cases for matching that the function should check for.    *
 *  First is if the target sequence appears inside the base sequence        *
 *  itself.                                                                 *
 *  For example:                                                            *
 *                                                                          *
 *  Base: AAACTGGGT             =>  A match was found.                      *
 *  Target: ACTGG                   AAACTGGGT                               *
 *                                                                          *
 *  This would be a match because the target string ACTGG appears fully     *
 *  within the base seqeunce.                                               *
 *                                                                          *
 *  The other case is if the base sequence is a proper prefix to the target *
 *  string (the last bases of base sequence are the same as the first bases *
 *  of the target sequence) AND the length of the overlap is equal to or    *
 *  greater than the threshold. For example, assuming a threshold of 3:     *
 *                                                                          *
 *  Base: AAACTGGG              =>  A match was found.                      *
 *  Target:    GGGTC                AAACTGGGTC                              *
 *                                                                          *
 *  Base: AAACTGGG              =>  No match found.                         *
 *  Target:     GGACT                                                       *
 *                                                                          *
 *  The first example is a match because GGG is the last 3 bases of the     *
 *  base and the first 3 bases of the target. The second example is NOT a   *
 *  match because only 2 bases overlap.                                     *
 *                                                                          *
 *  One way to implement this is by lining up s2 at the end of s1 so that   *
 *  they have `threshold` bases overlap. If no valid match is found, slide  *
 *  s2 to left by one position. Repeat until either a match is found or no  *
 *  overlap >= threshold is possible anymore.                               *
 *                                                                          *
 *  Example:                                                                * 
 *  --------                                                                * 
 *  s1 = CCGTTACAGG, s2 = TACAG, threshold = 3                              * 
 *                                                                          * 
 *  CCGTTACAGG                                                              * 
 *         TACAG                                                            * 
 *                                                                          * 
 *  CCGTTACAGG                                                              * 
 *        TACAG                                                             * 
 *                                                                          * 
 *  CCGTTACAGG                                                              * 
 *       TACAG                                                              * 
 *                                                                          * 
 *  CCGTTACAGG                  =>  A match was found.                      *
 *      TACAG                       CCGTTACAGG                              *
 *                                                                          *
 *                                                                          *
 *                                                                          *
 *  Base:     AAACTGGG          =>  A match was found.                      *
 *  Target: GTAAA                   GTAAACTGGG                              *
 *                                                                          *
 *  This would be a match because because AAA is the last 3 bases of the    *
 *  target sequence and the first 3 bases of the base sequence.             *
 *                                                                          *
 ****************************************************************************/
_Bool match(const char s1[], const char s2[],
     int len1, int len2, int threshold) {
   // FIXME:  This is where the real work has to happen 
   // implement this function using print_sequence_part as needed
  int trav1 = len1 - threshold;
  int overlap = 0;
  // loop through s1 backward 
  while(trav1 >= 0){
    int trav2 = 0;
    while(trav2 < len2){
      if(s1[trav1 + trav2] == s2[trav2]){
        overlap++;
        trav2++;
      }
      else{
        // if no matches found, slide trav1 to the left by 1 and initialize trav2 to 0
        overlap = 0;
        trav1--;
        trav2 = 0;
        break;
      }
      // condition 1: last 3 characters of s1 match the first 3 characters of s2
      if(trav1 == (len1-threshold)){
        if(overlap == threshold){
          printf("A match was found.\n");
          print_sequence_part(s1,0,trav1);
          print_sequence(s2,len2);
          return 1;
        }
      }
      // condition 2: last 4 characters of s1 match first 4 characters of s2
      if(trav1 == len1-(threshold+1)){
        if(overlap == threshold+1){
          printf("A match was found.\n");
          print_sequence_part(s1,0,trav1);
          print_sequence(s2,len2);
          return 1;
        }
      }
      // condition 3: target sequence appears in the base sequence
      else if(overlap > threshold){
        printf("A match was found.\n");
        print_sequence(s1,len1);
        return 1;
      }
    }
  }
  //If we enter here, there is no match found.
    printf("No match found.\n");
    return 0;
}
