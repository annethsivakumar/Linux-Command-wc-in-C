/*
 * Program Name: wc.c
 * Description: This program mimics the built-in Unix/Linux command of wc.
 * This program reads from the standard input, and counts the number of lines, words, and characters up to the end of the file.
 */

#include <stdio.h>
#include <string.h>

/**
 * This function is the main method used to mimic the built-in Unix/Linux command of wc.
 */
int main(){
    // Variables to keep track of the number of lines, words, and character.
    int nlines = 0, nwords = 0, ncharacters = 0;
    // A "boolean" or flag to check if we are currently inside a word.
    int in_word = 0;
    int c;

    while((c=getchar()) != EOF){
        // Each space is considered a character, 
        // Thus, increment character count by 1, until EOF.
        ncharacters++;

        // Check for newlines charcter '\n' to count lines.
        if(c == '\n'){
            nlines++;
        }

        // Check for delimiters to count words.
            // Note: the assignment says we should use '.', ':', ';' as delimiters. However the wc command in Linix, 
            // only considers '\n', '\t', and ' ' as words. Therefore, we consider '\n', '\t', and ' ' as characters for determining words.
        if(c == '\n' || c == '\t' || c == ' '){
            in_word = 0;
        } else if(!in_word){
            nwords++;
            in_word = 1;
        }

    }

    // Display the results.
    printf("Number of lines: %d\n", nlines);
    printf("Number of words: %d\n", nwords);
    printf("Number of letters: %d\n", ncharacters);



}
