#include <stdio.h>

struct poly {
    int coeff;
    int exp;
};

struct poly p1[100], p2[100], result[200];
int t1, t2, r;

int readpoly(struct poly p[100]) {
    int t1, i;

    printf("Enter the total number of terms in the polynomial: ");
    scanf("%d", &t1);

    printf("Enter the coefficient & exponent in descending order\n");
    for (i = 0; i < t1; i++) {
        printf("Enter the Coefficient(%d): ", i);
        scanf("%d", &p[i].coeff);
        printf("Enter the exponent(%d): ", i);
        scanf("%d", &p[i].exp); 
    }
    return t1;
}

void displaypoly(struct poly p[100], int term) {
    int i;
    for (i = 0; i < term - 1; i++) {
        printf("%dx^%d + ", p[i].coeff, p[i].exp);
    }
    printf("%dx^%d", p[term - 1].coeff, p[term - 1].exp);
}

int addpoly(struct poly p1[100], struct poly p2[100], struct poly result[200], int t1, int t2) {
    int i = 0, j = 0, k = 0;
    while (i < t1 && j < t2) {
        if (p1[i].exp == p2[j].exp) {
            result[k].coeff = p1[i].coeff + p2[j].coeff;
            result[k].exp = p1[i].exp;
            i++; j++; k++;
        }
        else if (p1[i].exp > p2[j].exp) {
            result[k].coeff = p1[i].coeff;
            result[k].exp = p1[i].exp;
            i++; k++;
        }
        else {
            result[k].coeff = p2[j].coeff;
            result[k].exp = p2[j].exp;
            j++; k++;
        }
    }

    while (i < t1) {
        result[k].coeff = p1[i].coeff;
        result[k].exp = p1[i].exp;
        i++; k++;
    }

    while (j < t2) {
        result[k].coeff = p2[j].coeff;
        result[k].exp = p2[j].exp;
        j++; k++;
    }

    return k;
}

int main() {
    printf("ENTER THE FIRST POLYNOMIAL\n");
    t1 = readpoly(p1);
    printf("First Polynomial: ");
    displaypoly(p1, t1);

    printf("\nENTER THE SECOND POLYNOMIAL\n");
    t2 = readpoly(p2);
    printf("Second Polynomial: ");
    displaypoly(p2, t2);

    printf("\nRESULTANT POLYNOMIAL\n");
    r = addpoly(p1, p2, result, t1, t2);
    displaypoly(result, r);

    return 0;
}
