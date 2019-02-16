#include <stdio.h>
#include <string.h>

void checkInt() {
   int a = 100; 
   if( a == 10 ) { 
      printf("Value of a is 10\n" ); 
   } else if( a == 20 ) {
      printf("Value of a is 20\n" ); 
   } else if( a == 30 ) { 
      printf("Value of a is 30\n" ); 
   } else { 
      printf("None of the values is matching\n" ); 
   } 
   printf("Exact value of a is: %d\n", a ); 
} 

void conditionalOperator(){
   int a , b;
   a = 10;
   printf( "Value of b is %d\n", (a == 1) ? 20: 30 );
   printf( "Value of b is %d\n", (a == 10) ? 20: 30 );
}

void switchStatement () {
   char grade = 'B';
   switch(grade) {
      case 'A' :
         printf("Excellent!\n" );
         break;
      case 'B' :
      case 'C' :
         printf("Well done\n" );
         break;
      case 'D' :
         printf("You passed\n" );
         break;
      case 'F' :
         printf("Better try again\n" );
         break;
      default :
         printf("Invalid grade\n" );
   }
   printf("Your grade is  %c\n", grade );
}

int A;
int B;
int fun(){
  static int count = 0;
  count++;
  return count;
}
int Add(){
    return A + B;
}
void staticVariable(){
    int answer;
    A = 5;
    B = 7;
    answer = Add();
    printf("%d\n",answer);
    printf("%d ", fun());
    printf("%d ", fun());
}

double balance1[10] = {1000.0, 2.0, 3.4, 7.0, 50.0};
double balance2[] = {1000.0, 2.0, 3.4, 7.0, 50.0};

int printIntArray() {
   int n[ 10 ];
   int i,j;
   for ( i = 0; i < 10; i++ ) {
      n[ i ] = i + 100;
   }
   for (j = 0; j < 10; j++ ) {
      printf("Element[%d] = %d\n", j, n[j] );
   }
   return 0;
}

void intPointer () {
   int  var = 20;
   int x = 10;
   int  *ip;
   ip = NULL;
   ip = &var;
   x = x + *ip;
   ip = &x;
   ip = ip + 3;
   printf("Address of var variable: %ls\n", &var  );
   printf("Address stored in ip variable: %ls\n", ip );
   printf("Value of *ip variable: %d\n", *ip );
}

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
void initializeStruct( ) {
   struct Books Book1;
   struct Books Book2;
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);
}

void printBook( struct Books *book );
void passByReferenceStruct( ) {
   struct Books Book1;
   struct Books Book2;
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
   printBook( &Book1 );
   printBook( &Book2 );
}
void printBook( struct Books *book ) {
   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}

void printBook2( struct Books book );
void passByValueStruct( ) {
   struct Books Book1;
   struct Books Book2;
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
   printBook2( Book1 );
   printBook2( Book2 );
}
void printBook2( struct Books book ) {
   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}

union Data {
   int i;
   float f;
   char str[20];
};
void sizeOfUnion( ) {
   union Data data;
   printf( "Memory size occupied by data : %ld\n", sizeof(data));
}

void initializeUnion(){
	union Data data;
	data.i = 10;
	data.f = 220.5;
	strcpy(data.str, "C Programming");
	printf("data.i : %d\n", data.i);
	printf("data.f : %f\n", data.f);
	printf("data.str : %s\n", data.str);
}

void swap(int *x, int *y)  {
    int z = *x;
    *x = *y;
    *y = z;
}
void passByReferenceSwap()
{
    int a = 45, b = 35;
    printf("Before Swap\n");
    printf("a = %d b = %d\n",a,b);
    swap(&a, &b);
    printf("After Swap with pass by reference\n");
    printf("a = %d b = %d\n",a,b);
}

typedef int number;
void typedefNumber() {
   number c;
   printf( "Enter a value: ");
   fflush(stdout);
   c = getchar( );
   printf( "\nYou entered: ");
   putchar( c );
   getchar();
}

void stringInput( ) {
   char str[100];
   printf( "Enter a value :");
   fflush(stdout);
   fgets( str, sizeof(str), stdin );
   printf( "\nYou entered: ");
   puts( str );
}

void multipleInputs( ) {
   char str[100];
   int i;
   printf( "Enter a value :");
   fflush(stdout);
   scanf("%s %d", str, &i);
   printf( "\nYou entered: %s %d ", str, i);
}

void writeToFile(){
	FILE *fp;
	fp = fopen("textFile.txt", "w+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);
}

void  readFromFile() {
   FILE *fp;
   char buff[255];
   fp = fopen("textFile.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);
}
