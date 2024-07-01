#include <stdio.h>

void FIFO(int rs[], int n, int f);
void LRU(int rs[], int n, int f);
void LFU(int rs[], int n, int f);

int main() {
    int i, n, f, choice;
    int rs[25];

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    do {
        printf("\nChoose Page Replacement Algorithm:\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. LFU\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                FIFO(rs, n, f);
                break;
            case 2:
                LRU(rs, n, f);
                break;
            case 3:
                LFU(rs, n, f);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

void FIFO(int rs[], int n, int f) {
    int i, j, k, m[10], count = 0, pf = 0;

    for (i = 0; i < f; i++) {
        m[i] = -1;
    }
    
    printf("\nThe Page Replacement Process using FIFO is:\n");
    for (i = 0; i < n; i++) {
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                break;
            }
        }

        if (k == f) {
            m[count] = rs[i];
            count = (count + 1) % f;
            pf++;
        }

        for (j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }

        if (k == f) {
            printf("PF No. %d", pf);
        }
        printf("\n");
    }

    printf("\nThe number of Page Faults using FIFO are %d\n", pf);
}

void LRU(int rs[], int n, int f) {
    int i, j, k, min, m[10], count[10], flag[25], pf = 0, next = 0;

    for (i = 0; i < f; i++) {
        count[i] = 0;
        m[i] = -1;
    }

    for (i = 0; i < n; i++) {
        flag[i] = 0;
    }

    printf("\nThe Page Replacement Process using LRU is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                count[j] = next++;
                break;
            }
        }

        if (flag[i] == 0) {
            if (i < f) {
                m[i] = rs[i];
                count[i] = next++;
            } else {
                min = 0;
                for (j = 1; j < f; j++) {
                    if (count[min] > count[j]) {
                        min = j;
                    }
                }
                m[min] = rs[i];
                count[min] = next++;
            }
            pf++;
        }

        for (j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }
        if (flag[i] == 0) {
            printf("PF No. %d", pf);
        }
        printf("\n");
    }

    printf("\nThe number of Page Faults using LRU are %d\n", pf);
}

void LFU(int rs[], int n, int f) {
    int i, j, k, min, m[10], freq[10], flag[25], pf = 0;

    for (i = 0; i < f; i++) {
        m[i] = -1;
        freq[i] = 0;
    }

    for (i = 0; i < n; i++) {
        flag[i] = 0;
    }

    printf("\nThe Page Replacement Process using LFU is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;
                freq[j]++;
                break;
            }
        }

        if (flag[i] == 0) {
            min = 0;
            for (j = 1; j < f; j++) {
                if (freq[min] > freq[j]) {
                    min = j;
                }
            }
            m[min] = rs[i];
            freq[min] = 1;
            pf++;
        }

        for (j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }
        if (flag[i] == 0) {
            printf("PF No. %d", pf);
        }
        printf("\n");
    }

    printf("\nThe number of Page Faults using LFU are %d\n", pf);
}