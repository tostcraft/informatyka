#include <iostream>
using std::cin; using std::cout;

class my_time{
    public:
    int hour;
    int minute;

    bool is_between(my_time time1, my_time time2){
        if(time1.hour == time2.hour && minute > time1.minute && minute<time2.minute){
            return true;
        }
        if(hour > time1.hour && hour<time2.hour){
            return true;
        }
        if(hour == time1.hour && minute >= time1.minute){
            return true;
        }
        if(hour == time2.hour && minute <= time2.hour){
            return true;
        }
        return false;
    }
}foo;

my_time parse_hour(std::string text){
    my_time rtrn;
    rtrn.hour = std::stoi(text.substr(0, 2));
    rtrn.minute = std::stoi(text.substr(3, 2));
    return rtrn;
}


int main(){
    std::string input;
    cin >> input;
    my_time start = parse_hour(input);
    cin >> input;
    my_time end = parse_hour(input);
    cin >> input;
    my_time meeting = parse_hour(input);
    if(meeting.is_between(start, end)){
        cout <<"TAK\n";
    }
    else{
        cout <<"NIE\n";
    }
    return 0;
}