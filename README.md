# Mini Voting System in C

## Overview

This is a simple console-based mini voting system implemented in C. The program allows users to set up a list of candidates, conduct voting, and then displays the election results, including any ties.


## Features

- User-friendly console interface.
- Dynamic allocation of memory for candidate names.
- Support for the "None of the Above" (NOTA) option.
- Display of voting results and announcement of the winner.


## Prerequisites

- C compiler (e.g., GCC)
- Standard C libraries: stdio.h, stdlib.h


## Usage

1. Upon execution, the program prompts the user to enter the number of candidates. Ensure the entered value is at least 2.

2. Enter the names of each candidate when prompted.

3. Specify the number of voters, ensuring it is at least the same as the number of candidates.

4. Conduct the voting by entering the candidate number (1 to N) or 0 for NOTA (None of the Above).

5. The program will display the election results, indicating the winner or if there is a tie.


## How to Use

1. Compile the program
```bash
gcc Mini_Voting_System.c -o Mini_Voting_System
```

2. Run the program
```bash
./Mini_Voting_System
```

3. Follow On-Screen Instructions:
- Enter the number of candidates (minimum 2).
- Provide names for each candidate.
- Specify the number of voters (at least the number of candidates).

4. Vote Casting:
- Users will be prompted to cast their votes by entering the candidate number (1 to N) or 0 for NOTA (None of the Above).
- Invalid votes are handled gracefully, and users can re-enter their votes.

5. View Results:
- The program displays the results, indicating the number of votes each candidate received.
- In case of a tie, it notifies the user.
- The winner or if NOTA wins is declared based on the maximum votes

6. End of Program:
- The program deallocates memory and concludes.


## Error Handling

- The program handles invalid user inputs during candidate and voter number entry.
- Provides appropriate messages for errors and prompts the user to enter valid information.


## Memory Management

- Explains the dynamic memory allocation for candidate names and votes
- Highlights the importance of freeing allocated memory to prevent memory leaks.


## Limitations

- The program assumes valid user inputs and does not handle advanced error checking.
- The voting system is basic and doesn't include advanced features like voter authentication, encryption, etc.


## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.