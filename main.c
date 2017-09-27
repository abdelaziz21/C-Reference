#include <stdio.h>
#include <stdlib.h>

/* function declaration */
int foo(int bar);

void moo() {
    /* do something and don't return a value */
}

//static
int runner()
{
    static int count = 0;
    count++;
    return count;
}

static int fun(void) {
   printf("I am a static function.");
}
//Structures
struct point {
    int x;
    int y;
};



typedef struct {
    int x;
    int y;
} point;

typedef struct {
    char * name;
    int age;
} person;


void addone(int n) {
    n++;
}

void add1(int * n) {
    (*n)++;
}
//Pointers to Structures
void move(point * p) {
    (*p).x++;
    (*p).y++;
}

void move1(point * p) {
    p->x++;
    p->y++;
}

typedef struct node {
    int val;
    struct node * next;
} node_t;

//Union
union intParts {
  int theInt;
  char bytes[sizeof(int)];
};

void someFunction(int arg)
{
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}


int compare(const void* left, const void* right)
{
    return (*(int*)right - *(int*)left);
    // go back to ref if this seems complicated: http://www.cplusplus.com/reference/cstdlib/qsort/
}

int main()
{
    //Variables and Types
    printf("Hello world!\n");
    int foo1;
    int bar = 1;

    int a = 0,b = 1,c = 2,d = 3, e = 4;
    a = b - c + d * e;
    printf("%d\n", a); /* will print 1-2+3*4 = 11 */

    int numbers[10];
//Arrays
/* populate the array */
numbers[0] = 10;
numbers[1] = 20;
numbers[2] = 30;
numbers[3] = 40;
numbers[4] = 50;
numbers[5] = 60;
numbers[6] = 70;
//Strings
/* print the 7th number from the array, which has an index of 6 */
printf("The 7th number in the array is %d", numbers[6]);

char name1[] = "John Smith";
/* is the same as */
char name2[11] = "John Smith";

char * name3 = "Nikhil";
printf("%d\n",strlen(name3));

char * name4 = "John";

if (strncmp(name4, "John", 4) == 0) {
    printf("Hello, John!\n");
} else {
    printf("You are not John. Go away.\n");
}

int i;
for (i = 0; i < 10; i++) {
    printf("%d\n", i);
}
//Another way to declare Array
int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int sum = 0;
int j;
//For loops
for (j = 0; j < 10; j++) {
    sum += array[j];
}

/* sum now contains a[0] + a[1] + ... + a[9] */
printf("Sum of the array is %d\n", sum);
//While loops
int n = 0;
while (1) {
    n++;
    if (n == 10) {
        break;
    }
}

int s = 0;
while (s < 10) {
    s++;

    /* check that s is odd */
    if (s % 2 == 1) {
        /* go back to the start of the while block */
        continue;
    }

    /* we reach this code only if n is even */
    printf("The number %d is even.\n", s);
}

    /* calling foo from main */
    printf("The value of foo is %d", foo(1));

     moo();

    printf("%d ", runner());
    printf("%d ", runner());

    char * hisname = "John";

    /* define a local variable a */
int z = 1;

/* define a pointer variable, and point it to a using the & operator */
int * pointer_to_z = &z;

printf("The value z is %d\n", z);
printf("The value of z is also %d\n", *pointer_to_z);

int y = 1;
int * pointer_to_y = &y;

/* let's change the variable a */
y += 1;

/* we just changed the variable a again! */
*pointer_to_y += 1;

/* will print out 3 */
printf("The value of y is now %d\n", y);

int q;
printf("Before: %d\n", q);
addone(n);
printf("After: %d\n", q);

int p;
printf("Before: %d\n", p);
add1(&n);
printf("After: %d\n", p);

//Dynamic Allocation
person * myperson = malloc(sizeof(person));

myperson->name = "John";
myperson->age = 27;

free(myperson);

//Arrays and Pointers
char vowels[] = {'A', 'E', 'I', 'O', 'U'};
char *pvowels = &vowels;
int k;

// Print the addresses
for (k = 0; k < 5; k++) {
    printf("&vowels[%d]: %u, pvowels + %d: %u, vowels + %d: %u\n", k, &vowels[k], k, pvowels + k, k, vowels + k);
}

// Print the values
for (k = 0;k < 5; k++) {
    printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", k, vowels[k], k, *(pvowels + k), k, *(vowels + k));
}

// Allocate memory to store five characters
int u = 5;
char *pvowels1 = (char *) malloc(u * sizeof(char));
int v;

pvowels1[0] = 'A';
pvowels1[1] = 'E';
*(pvowels1 + 2) = 'I';
pvowels1[3] = 'O';
*(pvowels1 + 4) = 'U';

for (v = 0; v < u; v++) {
    printf("%c ", pvowels1[v]);
}

printf("\n");

free(pvowels1);

int nrows = 2;
int ncols = 5;
int x, h;

// Allocate memory for nrows pointers
char **pvowels2 = (char **) malloc(nrows * sizeof(char *));

// For each row, allocate memory for ncols elements
pvowels2[0] = (char *) malloc(ncols * sizeof(char));
pvowels2[1] = (char *) malloc(ncols * sizeof(char));

pvowels2[0][0] = 'A';
pvowels2[0][1] = 'E';
pvowels2[0][2] = 'I';
pvowels2[0][3] = 'O';
pvowels2[0][4] = 'U';

pvowels2[1][0] = 'a';
pvowels2[1][1] = 'e';
pvowels2[1][2] = 'i';
pvowels2[1][3] = 'o';
pvowels2[1][4] = 'u';

for (x = 0; x < nrows; x++) {
    for(h = 0; h< ncols; h++) {
        printf("%c ", pvowels2[x][h]);
    }

    printf("\n");
}

// Free individual rows
free(pvowels2[0]);
free(pvowels2[1]);

// Free the top-level pointer
free(pvowels2);

//Linked lists
node_t * head = NULL;
head = malloc(sizeof(node_t));
head->val = 1;
head->next = malloc(sizeof(node_t));
head->next->val = 2;
head->next->next = NULL;

union intParts parts;
parts.theInt = 5968145; // arbitrary number > 255 (1 byte)

printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

//Pointer Arithmetic
    int intarray[5] = {10,20,30,40,50};

    int g;
    for(g = 0; g < 5; g++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[3]; //point to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

    intpointer++; //now increase the pointer's address so it points to the 5th elemnt in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 5th element

    int *intpointer1 = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer1, *intpointer1); //print the address of the 5th element

    intpointer1--; //now decrease the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer1, *intpointer1); //print the address of the 4th element

    int *intpointer2 = &intarray[1]; //point to the 2nd element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer); //print the address of the 2nd element

    intpointer2 += 2; //now shift by two the point's address so it points to the 4th element in the array
    printf("address: %x - has value %d\n", intpointer2, *intpointer2); //print the addres of the 4th element


    int *intpointer3 = &intarray[4]; //point to the 5th element in the array
    printf("address: %x - has value %d\n", intpointer3, *intpointer3); //print the address of the 5th element

    intpointer3 -= 2; //now shift by two the point's address so it points to the 3rd element in the array
    printf("address: %x - has value %d\n", intpointer3, *intpointer3); //print the address of the 3rd element

    //Function Pointers
        void (*pf)(int);
    pf = &someFunction;
    printf("We're about to call someFunction() using a pointer!\n");
    (pf)(5);
    printf("Wow that was cool. Back to main now!\n\n");

        int (*cmp) (const void* , const void*);
    cmp = &compare;

    int iarray[] = {1,2,3,4,5,6,7,8,9};
    qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);

    int t = 0;
    while (t < sizeof(iarray)/sizeof(*iarray))
    {
        printf("%d \t", iarray[t]);
        t++;
    }

    return 0;
}

int foo(int bar) {
    return bar + 1;
}
