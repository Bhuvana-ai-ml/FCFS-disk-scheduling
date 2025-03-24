#include <stdio.h>
#include <stdlib.h>

void findTotalHeadMovement(int arr[], int n, int start) {
    int totalMovement = 0;
    int currentPosition = start;

    // Print the initial position of the disk head
    printf("Initial position of the disk head: %d\n", start);

    // Calculate total head movement
    for (int i = 0; i < n; i++) {
        int movement = abs(arr[i] - currentPosition);
        totalMovement += movement;
        printf("Moving from track %d to track %d, Movement = %d\n", currentPosition, arr[i], movement);
        currentPosition = arr[i];
    }

    // Print the total head movement
    printf("\nTotal head movement: %d\n", totalMovement);
}

int main() {
    int n, start;

    // Read number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    // Read the disk requests
    int arr[n];
    printf("Enter the disk request positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the initial position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &start);

    // Function call to calculate and print total head movement
    findTotalHeadMovement(arr, n, start);

    return 0;
}
