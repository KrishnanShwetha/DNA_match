# DNA_match
Using Loops, functions and arrays his program computes simple DNA matching between 2 sequences.

I came into university as a biology major and the concepts of genetics have 
always intrigued me. This program tries to match two inputed DNA sequences
(base and target).  In this case, the base sequence (variable s1) will be the 
 DNA sequence we are trying to reconstruct, and its length is stored in  
   the variable len1. The target sequence (s2) will be the DNA sequence    
   that we are trying to match to the base sequence to determine if it is  
   a part of that sequence, and its length is stored in len2.            
                                                                           
   This function needs to detect matches, and return whether or not a      
   match was found. Additionally, this function needs to print out one of  
   two possibilities, depending on if a match was found. If a match was   
   found, the function needs to print out "A match was found" and then the 
   concatenated sequence. You can use the print_sequence_part function to  
   help with printing out the concatenated sequence. If a match was not    
   found, the function needs to print out "No match found".                
                                                                           
   There are two cases for matching that the function should check for.    
   First is if the target sequence appears inside the base sequence        
   itself.                                                                 
   For example:                                                            
                                                                           
   Base: AAACTGGGT             =>  A match was found.                      
   Target: ACTGG                   AAACTGGGT                               
                                                                           
   This would be a match because the target string ACTGG appears fully     
   within the base seqeunce.                                               
                                                                           
   The other case is if the base sequence is a proper prefix to the target 
   string (the last bases of base sequence are the same as the first bases 
   of the target sequence) AND the length of the overlap is equal to or    
   greater than the threshold. For example, assuming a threshold of 3:    
                                                                           
   Base: AAACTGGG              =>  A match was found.                      
   Target:    GGGTC                AAACTGGGTC                              
                                                                           
   Base: AAACTGGG              =>  No match found.                         
   Target:     GGACT                                                       
                                                                           
   The first example is a match because GGG is the last 3 bases of the     
   base and the first 3 bases of the target. The second example is NOT a   
   match because only 2 bases overlap.                                     
                                                                           
   One way to implement this is by lining up s2 at the end of s1 so that   
   they have `threshold` bases overlap. If no valid match is found, slide  
   s2 to left by one position. Repeat until either a match is found or no  
   overlap >= threshold is possible anymore.                               
                                                                           
   Example:                                                                 
   --------                                                                 
   s1 = CCGTTACAGG, s2 = TACAG, threshold = 3                               
                                                                            
   CCGTTACAGG                                                               
          TACAG                                                             
                                                                            
   CCGTTACAGG                                                               
         TACAG                                                              
                                                                            
   CCGTTACAGG                                                               
        TACAG                                                               
                                                                            
   CCGTTACAGG                  =>  A match was found.                      
       TACAG                       CCGTTACAGG                              
                                                                           
                                                                        
                                                                           
   Base:     AAACTGGG          =>  A match was found.                    
   Target: GTAAA                   GTAAACTGGG                             
                                                                           
   This would be a match because because AAA is the last 3 bases of the    
   target sequence and the first 3 bases of the base sequence.             
                                             
