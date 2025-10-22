#include "utils.h"

int calcSum(int start, int end) {
    int sum = 0;
    for(int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}