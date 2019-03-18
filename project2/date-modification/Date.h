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
    int days;
public:
    static const std::unordered_map<int, std::string> m;
    static const std::unordered_map<int, int> md;
    Date(){}
    Date(int m, int y, int d){
        setMonth(m);
        setYear(y);
        setDay(d);
    }
    static std::unordered_map<int, int> createMonthDaysMap(){
        std::unordered_map<int, int> md;
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
        return md;
    }
    static std::unordered_map<int, std::string> createMonthMap(){
        std::unordered_map<int, std::string> m;
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
        return m;
    }
    int getYear() const {
        return year;
    }
    void setYear(int year) {
        Date::year = year;
    }
    int getMonth() const {
        return month;
    }
    void setMonth(int month) {
        Date::month = month;
    }
    int getDay() const {
        return day;
    }
    void setDay(int day) {
        Date::day = day;
    }
    static bool validInput(std::string type, int input, int min, int max){
        if(input < min || input > max){
            return false;
        }
        return true;
    }
    Date& operator++(){
        // leap year and febrauary and end of month
        if(getYear() % 4 == 0 && getMonth() == 2 && getDay() == (md.find(getMonth())->second + 1)){
            setMonth(3);
            setDay(1);
        }
        // non-leap year
        else{
            if(getDay() < md.find(getMonth())->second){
                setDay(getDay()+1);
            }
            else if(getMonth() < 12){
                setMonth(getMonth() + 1);
                setDay(1);
            }
            else{
                setMonth(1);
                setDay(1);
                setYear(getYear()+1);
            }
        }
        return *this;
    }
    Date& operator--(){
        // leap year and march and first of month
        if(getYear() % 4 == 0 && getMonth() == 3 && getDay() == 1){
            setMonth(2);
            setDay(29);
        }
        // non-leap year
        else{
            if(getDay() != 1){
                setDay(getDay()-1);
            }
            else if(getMonth() > 1){
                setMonth(getMonth() - 1);
                setDay(md.find(getMonth())->second);
            }
            else{
                setMonth(12);
                setDay(md.find(getMonth())->second);
                setYear(getYear()-1);
            }
        }
        return *this;
    }
    friend int operator-(Date &date1, Date &date2){
        int days = 0;
        // same year
        if(date1.getYear() == date2.getYear()){
            if(date1.getMonth() == date2.getMonth()){
                return date1.getDay() - date2.getDay();
            }
            else{
                days += md.find(date2.getMonth())->second + Date::extraDayLeapYearFebraury(date2.getYear(), date2.getMonth()) - date2.getDay();
                for(int i = date2.getMonth() + 1; i < date1.getMonth(); i++){
                    days += md.find(i)->second + Date::extraDayLeapYearFebraury(date2.getYear(), i);
                }
                return days += date1.getDay();
            }
        }
        // different year 
        else{
            Date d1(12, date2.getYear(), 31);
            days = d1 - date2 + 1;
            for(int i = date2.getYear() + 1; i < date1.getYear(); i++){
                Date d1(12, i, 31);
                Date d2(1, i, 1);
                days += d1 - d2;
                days += 1;
            }
            Date d2(1, date1.getYear(), 1);
            return days += date1 - d2;
        }
    }
    static int extraDayLeapYearFebraury(int year, int month){
        return (month == 2 && year % 4 == 0)?(1):(0);
    }
};
const std::unordered_map<int, std::string> Date::m = Date::createMonthMap();
const std::unordered_map<int, int> Date::md = Date::createMonthDaysMap();

std::istream& operator>>(std::istream& input, Date &date){
    bool valid = false;
    int m;
    int y;
    int d;
    do{
        std::cout << "enter month:" << std::endl;
        input >> m;
    }while(!Date::validInput("month", m, 1, 12));

    do{
        std::cout << "enter year:" << std::endl;
        input >> y;
    }while(!Date::validInput("year", m, 0, 2019));

    int max = Date::md.find(m)->second;
    if(m == 2 && y % 4 == 0 ){
        max = 29;
    }
    do{
        std::cout << "enter day:" << std::endl;
        input >> d;
    }while(!Date::validInput("day", d, 1, max));
    date = Date(m, y, d);
    return input;
}

std::ostream& operator<<(std::ostream& output, Date &date){
    output <<  Date::m.find(date.getMonth())->second << " " << date.getDay() << ", " << date.getYear() << std::endl;
    return output;
}

#endif