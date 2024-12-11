// Kenneth Cardinalli, Jeff Shoemaker, Cosmo Vazquez Tirado
//Final Project -Madlibs-
// 12-3-2024


#include<stdio.h>
#define STR_CAP 100
#define ROW 100
#define COLUMN 100
#define FILE_NAME "madlib2.txt"

// Function prototypes
void stringCopy(char[], char[]);
void displayMadlib(char fullText[][COLUMN]);
void userPrompt(char[][COLUMN], char[][COLUMN]);
void textGrab(FILE* fPtr, char[][COLUMN]);
void textReplace(char[][COLUMN], char[][COLUMN]);

int main() {
    char fullText[ROW][COLUMN], swappedText[ROW][COLUMN], words[10][COLUMN];
    
    FILE* fPtr;
    fPtr = fopen(FILE_NAME, "r");
    if(fPtr == NULL){    
        printf("Can't open file\n");
        return 0;
    }
    textGrab(fPtr, fullText);
    fclose(fPtr);
    userPrompt(words, fullText);
    textReplace(fullText, words);
    displayMadlib(fullText);
    return 0;
}

// Functions
void stringCopy(char source[], char dest[]) {
    for(int index = 0; source[index] != '\0'; index++) {
        dest[index] = source[index];
    }
}

void displayMadlib(char fullText[][COLUMN]){
	for(int index = 0; index < ROW; index++){
		printf("%s ", fullText[index]);
	}
}

void userPrompt(char words[][COLUMN], char fullText[][COLUMN]) {
    int index3 = 0;  // Start at the beginning of the words array
    int count = 0;   // Counter to track how many inputs we've taken

    for(int index = 0; index < ROW; index++) {
        for(int index2 = 0; fullText[index][index2] != '\0'; index2++) {
            if (count >= 10) {
                return;  // Exit after taking 10 inputs
            }
            switch(fullText[index][index2]) {
                case 'A':
                    printf("Please enter an adjective: ");
                    scanf("%s", words[index3]);
                    index3 += 1;
                    count++;  // Increment count after each input
                    break;
                case 'N':
                    printf("Please enter a noun: ");
                    scanf("%s", words[index3]);
                    index3 += 1;
                    count++;  // Increment count after each input
                    break;
                case 'V':
                    printf("Please enter a verb: ");
                    scanf("%s", words[index3]);
                    index3 += 1;
                    count++;  // Increment count after each input
                    break;
            }
        }
    }
}

void textGrab(FILE* fPtr, char fullText[ROW][COLUMN]) {
    	int index = 0;
        while (fscanf(fPtr, "%s", fullText[index]) == 1){  // Read the file into fullText
    		index++;
    }
}
void textReplace(char fullText[][COLUMN], char words[][COLUMN]){
	int indexW = 0;
	for(int index = 0; index < ROW; index++){
		if(fullText[index] == "A" || fullText[index] == "V" || fullText[index] == "N"){
		stringCopy(words[indexW], fullText[index]);
		}
	index += 1;
	indexW += 1;
	}
}
