#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGHT 50
#define MAX_TIERS 6

struct WordWithHint
{
	char word[MAX_WORD_LENGHT];
	char hint[MAX_WORD_LENGHT];
};

void displayword(const char word[], const bool guessed[]);

void drawHangame(int tiers);


int main() 
{
	srand(time(NULL));

	struct WordWithHint wordList[] = {
		 
         { "desktop", "Computer coding" },
         { "elephant", "A large mammal with a trunk" },
         { "pizza", "A popular Italian dish" },
         { "beach", "Sandy shore by the sea" },

	};
	
    int wordIndex = rand() % 4; 

	const char* secretword = wordList[wordIndex].word;
	const char* hint = wordList[wordIndex].hint;

	int wordLenght = strlen(secretword);
	char guessesword[MAX_WORD_LENGHT] = {0};
	bool guessedletter[26] = {false};

	printf("welcome to hangame!\n");
	printf("Hint: %s\n", hint );

	int tiers = 0;

	while (tiers < MAX_TIERS){
		printf("\n");
		displayword(guessesword, guessedletter);
		drawHangame(tiers);

		char guess;
		printf("enter a letter:\n");
        scanf("%c\n", &guess);
		guess = tolower(guess);

		if (guessedletter[guess - 'a']){
			printf("\nyou've already guessed that letter." "try again.\n");
			continue;

		}

		guessedletter[guess - 'a'] = true;

		bool found = false;
		for (int i = 0; i < wordLenght; i++){
			if (secretword[i] == guess) {
               found = true;
			   guessesword[i] = guess;
			}
		}
		if (found) {
			printf("good guess:\n");
		}
		else {
			printf("\nsorry, the letter in not in the " 
			      "word:%c\n",
			       guess);
				   tiers++;

		}
		if (strcmp(secretword, guessesword) == 0){
			printf("\nCongurlation! you've guessed the" 
			"word:%s\n",
			secretword);
			break;
		}
	}

	if (tiers>= MAX_TIERS) {
		printf("\nSorry, you've run out tiers. the word "
		      "was: %s\n",
			  secretword);
	}
	return 0;
}

void displayword(const char word[], const bool guessed[])
{
  printf("word:\n");
  for (int i = 0; word[i] != '\0'; i++ ){
	if (guessed[word[i] - 'a']){
		printf("%c\n",word[i]);
	}
	else {
		printf("_ ");
	}
  }
  printf("\n");
}

void drawHangame(int tiers)

{
	const char* hangameparts[]
	= { "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |" };

    printf("\n");
    for (int i = 0; i <= tiers; i++){
	     printf("%s\n", hangameparts[i]);

    }
}