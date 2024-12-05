// Kenneth Cardinalli, 
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
int stringLength(char[]);
void userPrompt(char[], char[][COLUMN]);
//Please put inital next to chosen function, and feel free to change whatever
void textGrab();
void wordSwap();

int main(){
	char fullText[ROW][COLUMN], swappedText[ROW][COLUMN], letters[11];
	
	FILE* fPtr = fopen(FILE_NAME, "r");
		if(fPtr == NULL){	
		printf("Cant open file\n");
		return 0;
		}




	fclose(fPtr);
return 0;
}

//Functions
//Idk if you guys will use this one but if you need it will output the value of the string length
int stringLength(){
	int counter = 0;
		for(int index = 0; str[index] != '\0'; index++){
		counter++;	
		}
	
	 
	return str[counter];
}
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
void userPrompt(char letters[], char fullText[][COLUMN]){
	
	for(int index = 0; index < ROW; index++){
		for(int index2 = 0; fullText[index][index2] != 0; index2++){
		fscanf(fPtr, fullText[index][index2]);
		}
	}
}
