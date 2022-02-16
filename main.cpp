#include <iostream>
#include <omp.h>

int main() {
    int i;
    int threadID = 0;
#pragma omp parallel for private(i, threadID) default(none)
    for (i = 0; i < 16; i++) {
        threadID = omp_get_thread_num();
#pragma omp critical
        {
            printf("Thread %d reporting\n", threadID);
        }
    }
    return 0;
}
