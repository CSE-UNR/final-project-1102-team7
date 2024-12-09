// Kenneth Cardinalli, Jeff Shoemaker
//Final Project -Madlibs-
// 12-3-2024


#include<stdio.h>
#define STR_CAP 100
#define ROW 22
#define COLUMN 100
#define FILE_NAME "madlib1.txt"

//Function prototypes
void stringCopy(char[], char[]);
void stringSwap(char[], char[]);
void userPrompt(char[][COLUMN], char[][COLUMN]);
//Please put inital next to chosen function, and feel free to change whatever
void textGrab(FILE* fPtr, char[][COLUMN]); //JS
void wordSwap();

int main(){
	char fullText[ROW][COLUMN], swappedText[ROW][COLUMN], words[10][COLUMN];
	
	FILE* fPtr = fopen(FILE_NAME, "r");
		if(fPtr == NULL){	
		printf("Cant open file\n");
		return 0;
		}
	textGrab(fPtr, fullText);
	fclose(fPtr);
	userPrompt(words, fullText);

 

	
return 0;
}

//Functions
//Idk if you guys will use this one but if you need it will output the value of the string length
void stringCopy(char source[], char dest[]){
	for(int index = 0; source[index] != '\0'; index++){
	dest[index] = source[index];
	}
}
void stringSwap(char str1[], char str2[]){
	char strCopy[STR_CAP];
	
	stringCopy(str1, strCopy);
	stringCopy(str2, str1);
	stringCopy(strCopy, str2);
}
void userPrompt(char words[][COLUMN], char fullText[][COLUMN]){
	int index3 = 0;
	for(int index = 0; index < ROW; index++){
		for(int index2 = 0; fullText[index][index2] != 0; index2++){
			if(ROW % 2 == 0){
			switch(fullText[index][index2]){
				case 'A':
					printf("Please enter an adjective:");
					scanf("%s", words[index3][COLUMN]);
					index3 += 1;
					break;
				case 'N':
					printf("Please enter a noun:");
					scanf("%s", words[index3][COLUMN]);
					index3 += 1;
					break;
				case 'V':
					printf("Please enter a verb:");
					scanf("%s", words[index3][COLUMN]);
					index3 += 1;
					break;
				}
			}
		}
	}
}
void textGrab(FILE* fPtr, char fullText[][COLUMN]){
	for(int index = 0; index < ROW; index++){
		for(int index2 = 0; fullText[index][index2] != 0; index2++){
		fscanf(fPtr, "%s", fullText[index][index2]);
		}
	}
}
