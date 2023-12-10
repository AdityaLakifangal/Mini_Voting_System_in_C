#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

int main() {
    // Declaration of variables
    char **candidate_names;
    int *votes;
    int total_candidates = 0, total_vote = 0, i, choice;

    // Welcome message
    printf("Physics Project - Mini Voting System\n");
    printf("\t\tWelcome to the voting system\n");

    // Input number of candidates with validation
    do {
        printf("Enter the number of candidates: ");
        scanf("%d", &total_candidates);

        if (total_candidates < 2) {
            printf("Invalid number of candidates. Please choose at least 2.\n");
        }
    } while (total_candidates < 2);

    // Memory allocation for candidate names
    candidate_names = (char **)malloc(total_candidates * sizeof(char *));
    if (candidate_names == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    // Input candidate names
    for (i = 0; i < total_candidates; i++) {
        candidate_names[i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        if (candidate_names[i] == NULL) {
            printf("Memory allocation error.\n");
            return 1;
        }

        printf("Enter the name for Candidate %d: ", i + 1);
        scanf("%s", candidate_names[i]);
    }

    // Memory allocation for votes
    votes = (int *)malloc((total_candidates + 1) * sizeof(int));
    if (votes == NULL) {
        printf("Memory allocation error.\n");
        return 1;2
    }

    // Initialize votes to zero
    for (i = 0; i <= total_candidates; i++) {
        votes[i] = 0;
    }

    // Input number of voters with validation
    do {
        printf("Enter the number of voters (at least %d): ", total_candidates);
        scanf("%d", &total_vote);

        if (total_vote < total_candidates) {
            printf("Invalid number of voters. There should be at least %d voters.\n", total_candidates);
        } else {
            printf("Thank you for providing a valid number of voters.\n");
        }
    } while (total_vote < total_candidates);

    // Voting process
    printf("\nVoting has started. Enter the candidate number (1 to %d) or 0 for NOTA.\n", total_candidates);
    for (i = 1; i <= total_vote; i++) {
        printf("Candidates:\n");
        for (int j = 0; j < total_candidates; j++) {
            printf("Enter %d for \"%s\"\n", j + 1, candidate_names[j]);
        }
        printf("Enter 0 for NOTA\n");

        scanf("%d", &choice);

        // Validate vote and update counts
        if (choice >= 0 && choice <= total_candidates) {
            votes[choice]++;
        } else {
            printf("Invalid vote\n");
            i--;
        }
    }

    // Display voting results
    printf("\n\t\tResult of the vote\n");
    for (i = 1; i <= total_candidates; i++) {
        printf("%s got %d vote(s)\n", candidate_names[i - 1], votes[i]);
    }
    printf("NOTA got %d vote(s)\n", votes[0]);

    // Determine the winner or if it's a tie
    int maxVotesIndex = 0;
    int tieFlag = 0;

    for (i = 1; i <= total_candidates; i++) {
        if (votes[i] > votes[maxVotesIndex]) {
            maxVotesIndex = i;
            tieFlag = 0;
        } else if (votes[i] == votes[maxVotesIndex]) {
            tieFlag = 1;
        }
    }

    // Display the election result
    if (tieFlag) {
        printf("The vote result is tied\n");
    } else {
        if (maxVotesIndex == 0) {
            printf("NOTA wins the election\n");
        } else {
            printf("%s wins the election with %d vote(s)\n", candidate_names[maxVotesIndex - 1], votes[maxVotesIndex]);
        }
    }

    // Free allocated memory
    for (i = 0; i < total_candidates; i++) {
        free(candidate_names[i]);
    }
    free(candidate_names);
    free(votes);

    // Program conclusion
    printf("The program has ended\n");

    return 0;
}