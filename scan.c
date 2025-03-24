#include <stdio.h>
#include <stdlib.h>

void scan(int arr[], int n, int head, int direction) {
    int i, j, temp;
    int left[100], right[100];
    int left_count = 0, right_count = 0;
    int seek_count = 0;

    // Dividing requests into left and right arrays
    for (i = 0; i < n; i++) {
        if (arr[i] < head) {
            left[left_count++] = arr[i];
        } else {
            right[right_count++] = arr[i];
        }
    }

    // Sorting both arrays
    for (i = 0; i < left_count - 1; i++) {
        for (j = 0; j < left_count - i - 1; j++) {
            if (left[j] < left[j + 1]) {
                temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < right_count - 1; i++) {
        for (j = 0; j < right_count - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    // Moving the head to the left and then to the right
    if (direction == 0) { // Moving towards left
        for (i = left_count - 1; i >= 0; i--) {
            printf("%d -> ", left[i]);
            seek_count += abs(head - left[i]);
            head = left[i];
        }
        for (i = 0; i < right_count; i++) {
            printf("%d -> ", right[i]);
            seek_count += abs(head - right[i]);
            head = right[i];
        }
    } else { // Moving towards right
        for (i = 0; i < right_count; i++) {
            printf("%d -> ", right[i]);
            seek_count += abs(head - right[i]);
            head = right[i];
        }
        for (i = left_count - 1; i >= 0; i--) {
            printf("%d -> ", left[i]);
            seek_count += abs(head - left[i]);
            head = left[i];
        }
    }

    printf("Total Seek Time: %d\n", seek_count);
}

int main() {
    int arr[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int head = 50;  // Initial head position
    int direction = 1;  // 0 -> Left, 1 -> Right

    printf("SCAN Disk Scheduling:\n");
    scan(arr, n, head, direction);
    return 0;
}
