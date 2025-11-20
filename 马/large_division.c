#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024

int compare(int* a, int len_a, int* b, int len_b) {
    if (len_a > len_b) return 1;
    if (len_a < len_b) return 0;
    for (int i = len_a - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 0;
    }
    return 1;
}

void subtract(int* a, int* len_a, int* b, int len_b) {
    int borrow = 0;
    for (int i = 0; i < len_b || borrow; i++) {
        a[i] -= borrow + (i < len_b ? b[i] : 0);
        if (a[i] < 0) {
            a[i] += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
    }
    while (*len_a > 1 && a[*len_a - 1] == 0) (*len_a)--;
}

void divide(char* dividend_str, char* divisor_str, int* quotient, int* quot_len, int* remainder, int* rem_len) {
    int dividend[MAX_LEN], divisor[MAX_LEN];
    int div_len = strlen(dividend_str);
    int dvs_len = strlen(divisor_str);
    
    for (int i = 0; i < div_len; i++) {
        dividend[i] = dividend_str[div_len - 1 - i] - '0';
    }
    for (int i = 0; i < dvs_len; i++) {
        divisor[i] = divisor_str[dvs_len - 1 - i] - '0';
    }
    
    memset(quotient, 0, sizeof(int) * MAX_LEN);
    *quot_len = 0;
    
    int current[MAX_LEN];
    int curr_len = 0;
    memset(current, 0, sizeof(current));

    for (int i = div_len - 1; i >= 0; i--) {
        for (int j = curr_len; j > 0; j--) {
            current[j] = current[j - 1];
        }
        current[0] = dividend[i];
        if (curr_len > 0 || current[0] > 0) curr_len++;
        int q = 0;
        while (compare(current, curr_len, divisor, dvs_len)) 
        {
            subtract(current, &curr_len, divisor, dvs_len);
            q++;
        }
        quotient[i] = q;
    }
    *quot_len = div_len;
    while (*quot_len > 1 && quotient[*quot_len - 1] == 0) (*quot_len)--;
    if (*quot_len == 0) 
    {
        *quot_len = 1;
    }
    if (curr_len == 0) 
    {
        *rem_len = 1;
        remainder[0] = 0;
    } 
    else 
    {
        for (int i = 0; i < curr_len; i++) 
        {
            remainder[i] = current[i];
        }
        *rem_len = curr_len;
        while (*rem_len > 1 && remainder[*rem_len - 1] == 0) (*rem_len)--;
    }
}

void print_number(int* num, int len) 
{
    for (int i = len - 1; i >= 0; i--) 
    {
        printf("%d", num[i]);
    }
}

int main() 
{
    char dividend[MAX_LEN], divisor[MAX_LEN];
    while (scanf("%s %s", dividend, divisor) == 2) 
    {
        int quotient[MAX_LEN], remainder[MAX_LEN];
        int quot_len, rem_len;
        divide(dividend, divisor, quotient, &quot_len, remainder, &rem_len);
        print_number(remainder, rem_len);
        printf(" ");
        print_number(quotient, quot_len);
        printf("\n");
    }
    return 0;
}