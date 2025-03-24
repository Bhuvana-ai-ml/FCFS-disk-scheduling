#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the minimum value in the array
int findMinDistance(int arr[], int size, int currentPosition) {
    int minDist = abs(arr[0] - currentPosition);
    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        int dist = abs(arr[i] - currentPosition);
        if (dist < minDist) {
            minDist = dist;
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to implement SSTF Disk Scheduling
void sstf(int requests[], int size, int start) {
    int seekCount = 0;
    int currentPosition = start;
    int visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0;  // Mark all requests as unvisited initially
    }

    printf("Order of service for SSTF disk scheduling:\n");

    for (int i = 0; i < size; i++) {
        // Find the index of the minimum distance request
        int minIndex = findMinDistance(requests, size, currentPosition);
        
        // Output the current request that is being processed
        printf("%d -> ", requests[minIndex]);

        // Calculate seek count
        seekCount += abs(requests[minIndex] - currentPosition);

        // Mark the request as visited
        visited[minIndex] = 1;

        // Update the current position of the disk head
        currentPosition = requests[minIndex];

        // Mark the visited request as "infinity" (to avoid revisiting it)
        requests[minIndex] = 10000;  // A number greater than any request position
    }

    printf("\nTotal seek count: %d\n", seekCount);
}

int main() {
    int size, start;
    
    // Input number of requests
    printf("Enter the number of requests: ");
    scanf("%d", &size);
    
    int requests[size];
    
    // Input request positions
    printf("Enter the request positions: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &requests[i]);
    }

    // Input starting position of the disk head
    printf("Enter the starting position of the disk head: ");
    scanf("%d", &start);

    // Call SSTF disk scheduling
    sstf(requests, size, start);
    
    return 0;
}
