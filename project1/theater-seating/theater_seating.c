#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "theater_seating.h"

struct Theater{
    double prices[15];
    char seats[15][30];
    int seats_solds;
    int seats_purchased;
    double total_sales;
}theater;

void load_seat_prices(){
    FILE* file = fopen("seat_prices.txt", "r");
    char buff[10];
    int i = 0;
    fscanf(file, "%s\n", &buff);
    while(!feof(file)){
        theater.prices[i] = atof(buff);
        fscanf(file, "%s\n", &buff);
        i++;
    }
    fclose(file);
}

void set_seat_price(int r, float price){
    theater.prices[r] = price;
    FILE* file = fopen("seat_prices.txt", "w");
    for(int i = 0; i < 15; i++ ){
        fprintf(file, "%.2f\n", theater.prices[i]);
    }
    fclose(file);
}

void print_seat_prices(){
    for(int r = 0; r < 15; r++ ){
        printf("%s %2d %s $%4.2f\n", "Row", (r+1), ":", theater.prices[r]);
    }
}

void print_available_seats_row(){
    for(int r = 0; r < 15; r++ ){
        int sum = 0; 
        for(int s = 0; s < 30; s++){
            if(theater.seats[r][s] == '#'){
                sum++;
            }
        }
        printf("%s %2d %s %d seats \n", "Row", (r+1), ":", sum);
    }
}

void load_available_seats(){
    FILE* file = fopen("seats_available.txt", "r");
    int r = 0;
    char buff[255];
    fscanf(file, "%s", buff);
    while(!feof(file)){
        for(int s = 0; s < 30; s++){
            theater.seats[r][s] = buff[s];
        }
        r++;
        fscanf(file, "%s", buff);
    }
    fclose(file);

    file = fopen("seats_purchased.txt", "r");
    int p = 0;
    fscanf(file, "%d", &p);
    theater.seats_purchased = p;
    fclose(file);

    file = fopen("total_sales.txt", "r");
    fscanf(file, "%s\n", &buff);
    theater.total_sales = atof(buff);
    fclose(file);
}

void set_seat_sold(int row, int seat){ 
    theater.seats[row][seat] = '*';
    FILE* file = fopen("seats_available.txt", "w");
    for(int r = 0; r < 15; r++){
        for(int s = 0; s < 30; s++){
            fputc(theater.seats[r][s], file);
        }
        fputc('\n', file);
    }
    fputc('\n', file);
    fclose(file);

    theater.seats_purchased++;
    file = fopen("seats_purchased.txt", "w");
    fprintf(file, "%d", theater.seats_purchased);
    fclose(file);

    theater.total_sales += theater.prices[row];
    file = fopen("total_sales.txt", "w");
    fprintf(file, "%.2f", theater.total_sales);
    fclose(file);
}

void print_available_seats(){
    printf("%25s\n", "Seats");
    printf("         ");
    for(int i = 0; i < 30; i++){
        printf("%d", (i+1)%10);
    }
    printf("\n");
    for(int r = 0; r < 15; r++){
        printf("Row %2d   ", (r+1));
        for(int s = 0; s < 30; s++){
            putchar(theater.seats[r][s]);
        }
        printf("\n");
    }
    printf("available seats : %d \n", 30*15-theater.seats_purchased);
}

int prompt_menu(){
    int c = -1; 
    while(c < 0 || c > 9){
        printf("%5s%s \n", " ", "1. set one row price");
        printf("%5s%s \n", " ", "2. set all row prices");
        printf("%5s%s \n", " ", "3. view seat prices");
        printf("%5s%s \n", " ", "4. purchase one ticket");
        printf("%5s%s \n", " ", "5. purchase group tickets");
        printf("%5s%s \n", " ", "6. view available seats");
        printf("%5s%s \n", " ", "7. view available seats per row");
        printf("%5s%s \n", " ", "8. view number tickets sold");
        printf("%5s%s \n", " ", "9. view total sales");
        printf("%5s%s \n", " ", "0. quit");
        fflush(stdout);
        printf("%10s%s", " ", "enter (0-9): ");
        scanf("%d", &c);
        getchar();
    }
    return c;
}

int get_int_prompt(char *prompt, int min, int max){
    int c = 0; 
    while(c < min || c > max){
        printf("%-20s (%d-%-2d): ", prompt, min, max);
        fflush(stdout);
        scanf("%d", &c);
        getchar();
    }
    return c;
}

float get_float_prompt(char *prompt, float min, float max){
    float c = -1; 
    while(c < min || c > max){
        printf("%-20s (%.2f-%.2f): ", prompt, min, max);
        fflush(stdout);
        scanf("%f", &c);
        getchar();
    }
    return c;
}

void theater_seating_program(){
    printf("%5s%s \n", " ", "Theater Seating Program");
    printf("%7s%s \n", " ", "> loading current seat prices");
    load_seat_prices();
    printf("%7s%s \n", " ", "> loading available seat prices");
    load_available_seats();

    int choice = -1;
    while(choice != 0){ 
        printf("\n");
        choice = prompt_menu();
        if(choice == 1){
            printf("\n");
            int row = get_int_prompt("enter row number ", 1, 15);
            float price = get_float_prompt("enter price ", 0, 1000);
            set_seat_price(row - 1, price);
        }
        else if(choice == 2){
            printf("\n");
            for(int r = 0; r < 15; r++){
                printf("%s %2d ", "row", r+1);
                float price = get_float_prompt("enter price ", 0, 1000);
                set_seat_price(r, price);
            }
        }
        else if(choice == 3){
            printf("\n");
            print_seat_prices();
        }
        else if(choice == 4){
            printf("\n");
            int sold = 1;
            int row, seat;
            while(sold == 1){
                row = get_int_prompt("enter row number ", 1, 15);
                seat = get_int_prompt("enter seat number  ", 1, 30);
                if(theater.seats[row-1][seat-1] == '*'){
                    printf("row %d seat %d is sold\n", row, seat);
                }
                else{
                    sold = 0;
                }
            }
            printf("total purchase : $%.2f \n", theater.prices[row-1]);
            set_seat_sold(row-1, seat-1);
        }
        else if(choice == 5){
            printf("\n");
            int n = get_int_prompt("number of seats ", 1 , 30*15-theater.seats_purchased);
            double purchases = 0;
            for(int i = 0; i < n; i++){
                printf("\nTicket %3d \n", (i+1));
                int sold = 1;
                int row, seat;
                while(sold == 1){
                    row = get_int_prompt("enter row number ", 1, 15);
                    seat = get_int_prompt("enter seat number  ", 1, 30);
                    if(theater.seats[row-1][seat-1] == '*'){
                        printf("row %d seat %d is sold\n", row, seat);
                    }
                    else{
                        sold = 0;
                    }
                }
                purchases += theater.prices[row-1];
                set_seat_sold(row-1, seat-1);
            }
            printf("total purchases : $%.2f \n", purchases);
        }
        else if(choice == 6){
            printf("\n");
            print_available_seats();
        }
        else if(choice == 7){
            printf("\n");
            print_available_seats_row();
        }
        else if(choice == 8){
            printf("\ntotal tickets sold : %d \n", theater.seats_purchased);
        }
        else if(choice == 9){
            printf("\ntotal sales : $%.2f \n", theater.total_sales);
        }
    }
}