#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// Node structure for the queue
struct Node {
char player[4];
struct Node* next;
};
// Function to create a new node in the queue
struct Node* createNode(char player[4]) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
strcpy(newNode->player, player);
newNode->next =NULL;
return newNode;
}
// Function to enqueue a player into the queue
void enqueue(struct Node** front,struct Node** rear, char player[4]) {
struct Node* newNode = createNode(player);
if (*front == NULL) {
*front = *rear = newNode;
} else {
(*rear)->next = newNode;
*rear = newNode;
}
}
// Function to dequeue a player from the queue
void dequeue(struct Node** front) {
if (*front == NULL) {
return;
}
struct Node* temp = *front;
*front = (*front)->next;
free(temp);
}
// Function to get the dice roll
int rollDice() {
return rand() % 6 + 1;
}
// Function to display the board
void displayBoard(int curPos1, int curPos2) {
printf("Snake and Ladder Board\n");
printf("+ ----------------------------------+\n");
for (int i = 100; i >= 1; i--) {
if (i == curPos1) {
printf("| $P1 ");
} else if (i == curPos2) {
printf("| $P2 ");
} else {
printf("| %3d ", i);
}
if (i % 10 == 1) {
printf("|\n");
printf("|----------------------------------|\n");
}
}
printf("+ ----------------------------------+\n");
}
int main() {
int curPos1 = 1, curPos2 = 1;
struct Node* front = NULL;
struct Node* rear = NULL;
while (1) {
printf("***** SNAKE AND LADDER GAME *****\n");
printf("Player 1 position: %d\n", curPos1);
printf("Player 2 position: %d\n", curPos2);
char ch;
printf("Choose your option\n");
printf("1. Player 1 plays\n");
printf("2. Player 2 plays\n");
printf("3. Exit\n");
scanf(" %c", &ch);
int dice = rollDice();
printf("Dice Roll: %d\n", dice);
switch (ch) {
case '1':
curPos1 += dice;
break;
case '2':
curPos2 += dice;
break;
case '3':
exit(0);
break;
default:
printf("Incorrect choice. Try Again\n");
continue;
}
// Check for snakes and ladders
if (curPos1 == 99 || curPos1 == 65 || curPos1 == 25)
curPos1 = 1;
else if (curPos1 == 70)
curPos1 = 93;
else if (curPos1 == 60)
curPos1 = 83;
else if (curPos1 == 13)
curPos1 = 42;
if (curPos2 == 99 || curPos2 == 65 || curPos2 == 25)
curPos2 = 1;
else if (curPos2 == 70)
curPos2 = 93;
else if (curPos2 == 60)
curPos2 = 83;
else if (curPos2 == 13)
curPos2 = 42;
// Display the board
displayBoard(curPos1, curPos2);
// Enqueue the playersfor the next turn
enqueue(&front, &rear, "$P1$");
enqueue(&front, &rear, "$P2$");
// Dequeue the playersfor the next turn
dequeue(&front);
dequeue(&front);
}
return 0;
}
