/*
 * Problem Statement: https://www.codechef.com/MARCH20B/problems/ADASHOP2
 * Author: striker
 *
 * Copyright 2020 striker
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

typedef unsigned long long ull_t;
typedef long long ll_t;

typedef struct Point2D {
    int x, y;
} point_2d_t;

#define MOD (1000000000 + 7) // Prime Number
#define PI 3.141592653589793 // Number of digits(15) of Pi which JPL uses for Interplanetary Caculations.
#define GOLDEN_RATIO 1.618033988749895 // Number of digits(15).

#define MEMORY_ALLOCATION_FAILED_ERROR(variable, bytes) fprintf(stderr, "Line number: %u: Not able to allocate <%lu> bytes of memory to <%s> variable.\n", __LINE__, (bytes), #variable)
#define CONSTRAINTS_OUT_OF_BOUND_ERROR(variable, constraints) fprintf(stderr, "Line number: %u: Constraints not satisfied for the variable <%s>, i.e. %s.\n", __LINE__, #variable, #constraints)
#define SCANF_READ_ERROR(expected_return_val) fprintf(stderr, "Line number: %u: scanf() read error!\nExpected-Return-Value: %d.\n", __LINE__, expected_return_val); exit(0)
#define STREAM_LINK_ERROR(file_path, stream_name) fprintf(stderr, "Line number: %u: Stream Link Error! Not able to link <%s> file to <%s> stream.\n", __LINE__, #file_path, #stream_name);
#define INITIALISE_INT_CONTAINER_ZERO(container, bytes) memset(container, 0, (bytes))
#define INITIALISE_CHAR_CONTAINER_ZERO(container, bytes) memset(container, '0', (bytes))
#define FIND_MAX(a, b) (a) > (b) ? (a) : (b)
#define FIND_MIN(a, b) (a) < (b) ? (a) : (b)
#define FIND_MID(start, end) (((end) - (start)) >> 1) + (start)

// The below function macros refers to the GCC functions for doing computation directly on the bit-level of a number.
#define COMPUTE_SET_BITS(number) __builtin_popcountll(number) // Returns the number of set-bits in number (unsigned long long).
#define COMPUTE_PARITY(number) __builtin_parityll(number) // Returns the parity of the number (unsigned long long) i.e. True if 1's are odd else False.
#define COUNT_LEAD_ZEROES(number) __builtin_clzll(number) // Returns the count of lead zeroes before first set-bit from MSB in number (unsigned long long).
#define COUNT_TRAIL_ZEROES(number) __builtin_ctzll(number) // Return the count of trailing zeroes in number(unsigned long long).

#define MIN_MOVES 29

int main(void) {
    #ifndef ONLINE_JUDGE
        if(!freopen("test-cases/test-case-1.in", "r", stdin)) {
            STREAM_LINK_ERROR(test-cases/test-case-1.in, stdin);
        }
        if(!freopen("test-cases/test-case-1.out", "w", stdout)) {
            STREAM_LINK_ERROR(test-cases/test-case-1.out, stdout);
        }
    #endif
    int test;
    if(1 == scanf("%d", &test)) {
        const point_2d_t moves[MIN_MOVES] = {{1, 1}, {8, 8}, {7, 7}, {6, 8}, {5, 7}, {4, 8}, {3, 7}, {2, 8}, {1, 7}, {2, 6}, {1, 5}, {2, 4}, {1, 3}, {3, 1}, {4, 2}, {5, 1}, {6, 2}, {7, 1}, {8, 2}, {7, 3}, {8, 4}, {7, 5}, {8, 6}, {7, 7}, {4, 4}, {3, 5}, {4, 6}, {6, 4}, {5, 3}};
        while(test--) {
            point_2d_t initial_pos_bishop;
            if(2 == scanf("%d%d", &initial_pos_bishop.x, &initial_pos_bishop.y)) {
                if(initial_pos_bishop.x == 1 && initial_pos_bishop.y == 1) {
                    printf("%d\n", MIN_MOVES - 1);
                    for(register int i = 1; i < MIN_MOVES; ++i) {
                        printf("%d %d\n", moves[i].x, moves[i].y);
                    }
                    continue;
                }
                if(initial_pos_bishop.x == initial_pos_bishop.y) {
                    printf("%d\n", MIN_MOVES);
                    for(register int i = 0; i < MIN_MOVES; ++i) {
                        printf("%d %d\n", moves[i].x, moves[i].y);
                    }
                    continue;
                }
                point_2d_t curr_pos_bishop;
                memcpy(&curr_pos_bishop, &initial_pos_bishop, sizeof(point_2d_t));
                if(initial_pos_bishop.x > initial_pos_bishop.y) {
                    while(!(curr_pos_bishop.x == curr_pos_bishop.y)) {
                        --curr_pos_bishop.x; ++curr_pos_bishop.y;
                    }
                } else {
                    while(!(curr_pos_bishop.x == curr_pos_bishop.y)) {
                        ++curr_pos_bishop.x; --curr_pos_bishop.y;
                    }
                }
                printf("%d\n", MIN_MOVES + 1);
                printf("%d %d\n", curr_pos_bishop.x, curr_pos_bishop.y);
                for(register int i = 0; i < MIN_MOVES; ++i) {
                    printf("%d %d\n", moves[i].x, moves[i].y);
                }
            } else {
                SCANF_READ_ERROR(1);
            }
        }
    } else {
        SCANF_READ_ERROR(1);
    }
    return EXIT_SUCCESS;
}
