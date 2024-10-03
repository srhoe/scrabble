#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Point values for each letter
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void)
{
    // Get input from two players
    char word1[100];
    char word2[100];

    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);

    // Remove newline characters from input
    word1[strcspn(word1, "\n")] = '\0';
    word2[strcspn(word2, "\n")] = '\0';

    // Calculate scores for each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

int compute_score(char *word)
{
    // Initialize score
    int score = 0;

    // Calculate score for each character in the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
