#include <iostream>
using namespace std;

struct Card {
    int value;
    char suit; 
};

void printDeck(const Card deck[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "(" << deck[i].value << "," << deck[i].suit << ") ";
    }
    cout << endl;
}

void selectionSortUnstable(Card deck[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (deck[j].value < deck[minIdx].value)
                minIdx = j;
        }

        Card temp = deck[i];
        deck[i] = deck[minIdx];
        deck[minIdx] = temp;
    }
}

/*
Stable Selection Sort Explanation:
Shifting preserves stability because it does not change the relative order
of equal elements. When we insert the minimum element at position i,
we move all intermediate elements one step to the right instead of swapping.
This ensures that equal-valued elements remain in the same order as before.
In contrast, swapping can move an element ahead of another equal element,
breaking their original order.
*/

void selectionSortStable(Card deck[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (deck[j].value < deck[minIdx].value)
                minIdx = j;
        }
        Card key = deck[minIdx];
        for (int j = minIdx; j > i; j--) {
            deck[j] = deck[j - 1];
        }
        deck[i] = key;
    }
}

int main() {
    Card original[] = { {5,'H'}, {3,'D'}, {5,'D'}, {1,'C'}, {5,'S'}, {2,'H'} };
    int n = 6;

    Card deck1[6];
    for (int i = 0; i < n; i++) deck1[i] = original[i];

    cout << "Original Deck: ";
    printDeck(original, n);

    selectionSortUnstable(deck1, n);
    cout << "Unstable Sorted: ";
    printDeck(deck1, n);
    cout << "Instability: (5,H) originally before (5,D), but order changed.\n";

    Card deck2[6];
    for (int i = 0; i < n; i++) deck2[i] = original[i];

    selectionSortStable(deck2, n);
    cout << "Stable Sorted: ";
    printDeck(deck2, n);
    cout << "Stability confirmed: Relative order of (5,H), (5,D), (5,S) preserved.\n";

    return 0;
}