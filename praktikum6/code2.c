#include <stdio.h>
#include <stdlib.h>



struct Stone {
    char abjad;
    struct Stone *next;
};

void addStone(struct Stone **head, char abjad) {
    struct Stone *newStone = (struct Stone *)malloc(sizeof(struct Stone));
    newStone->abjad = abjad;
    newStone->next = 0;

    if (*head == 0) {
        *head = newStone;
        return;
    }

    struct Stone *restStone = *head;
    while (restStone->next !=0) {
        restStone = restStone->next;
    }
    restStone->next = newStone;
}

void printStones(struct Stone *TOP) {
    struct Stone *current = TOP;
    while (current != 0) {
        printf("%c", current->abjad);
        current = current->next;
    }
}

int main() {
    struct Stone *TOP = 0;

    // Menambahkan ke linked list
   
    addStone(&TOP, 'I');addStone(&TOP, 'N');  addStone(&TOP, 'F');
     addStone(&TOP, 'O');addStone(&TOP, 'R'); addStone(&TOP, 'M');
  addStone(&TOP, 'A'); addStone(&TOP, 'T');  addStone(&TOP, 'I');
    addStone(&TOP, 'K'); addStone(&TOP, 'A');

    // Mencetak huruf
    printStones(TOP);

  
    struct Stone *current = TOP;
    struct Stone *next;
    while (current != 0) {
        next = current->next;
        (current);
        current = next;
    }

    return 0;
}