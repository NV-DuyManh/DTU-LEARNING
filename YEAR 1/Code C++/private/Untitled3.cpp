#include <iostream>
using namespace std;

class Date {
private:
  int day;
  int month;
  int year;

public:
  Date(){
    this->day = 0;
    this->month = 0;
    this->year = 0;
  };

  Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
  };

  int getDay(){
    return day;
  };

  int getMonth(){
    return month;
  };

  int getYear(){
    return year;
  };

  void setDay(int day) {
    if(day >=1 && day <=31){
      this->day = day;
    }
    else{
      cout << "Error: Day must be between 1 and 31." << endl;
    }
  };

  void setMonth(int month) {
    if(month >=1 && month <=12){
      this->month = month;
    }
    else{
      cout << "Error: Month must be between 1 and 12." << endl;
    }
  };

  void setYear(int year) {
    if(year >=1){
      this->year = year;
    }
    else{
      cout << "Error!";
    }
  };

  void setDate(int day, int month, int year) {
    setDay(day);
    setMonth(month);
    setYear(year);
  };

  void Output(){
    cout <<day<<"/"<<month<<"/"<<year<<endl;

  }
};

int main(){
  Date *date = new Date(1,2,2024);
  date->Output();
  date->setDate(9, 12,2099);
  date->Output();
    cout <<"Month: "<<date->getMonth()<<endl;
    cout <<"Day:"<<date->getDay()<<endl;
    cout <<"Year: "<<date->getYear()<<endl;
  Date *date2 = new Date(3,4,2016);
  date2->Output();
  return 0;
}

