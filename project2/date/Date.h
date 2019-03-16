#ifndef DATE_CC
#define DATE_CC

#include <iostream>
#include <string>
#include <unordered_map>

class Date{
private:
    int year; 
    int month;
    int day;
    std::unordered_map<int, std::string> m;
    std::unordered_map<int, int> md;
public:
    Date(){
        addMonthMap();
        addMonthDays();
        setMonth();
        setYear();
        setDay();
    }
    void addMonthMap(){
        m[1] = "January";
        m[2] = "February";
        m[3] = "March";
        m[4] = "April";
        m[5] = "May";
        m[6] = "June";
        m[7] = "July";
        m[8] = "August";
        m[9] = "September";
        m[10] = "October";
        m[11] = "November";
        m[12] = "December";
    }
    void addMonthDays(){
        md[1] = 31;
        md[2] = 28;
        md[3] = 31;
        md[4] = 30;
        md[5] = 31;
        md[6] = 30;
        md[7] = 31;
        md[8] = 31;
        md[9] = 30;
        md[10] = 31;
        md[11] = 30;
        md[12] = 31;
    }
    int getYear() const {
        return year;
    }
    void setYear() {
        int year = getInput("Year", 0, 2019);
        Date::year = year;
    }
    int getMonth() const {
        return month;
    }
    void setMonth() {
        int month = getInput("Month", 1, 12);
        Date::month = month;
    }
    int getDay() const {
        return day;
    }
    void setDay() {
        int max = md[getMonth()];
        if(getMonth() == 2 && getYear() % 4 == 0 ){
            int max = 29;
        }
        int day = getInput("Day", 1, max);
        Date::day = day;
    }
    int getInput(std::string type, int min, int max){
        int input = -1;
        while (input < min || input > max){
            std::cout << "Enter " << type << "(" << min << "-" << max << "): " << std::endl;
            std::cin >> input;
        }
        return input;
    }
    void printDate1(){
        std::cout << getMonth() << "/" << getDay() << "/" << getYear() << std::endl;
    }
    void printDate2(){
        std::cout << m[getMonth()] << " " << getDay() << ", " << getYear() << std::endl;
    }
    void printDate3(){
        std::cout << getDay() << " " << m[getMonth()] << " " << getYear() << std::endl;
    }
};
#endif