#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isLeapYear(int year) {
    // Leap years are divisible by 4
    // Except for years that are divisible by 100, but not by 400

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int Totaldays(int dd,int mm ,int yy,int dd2,int mm2,int yy2){
    int x1 =0 , x2 = 0,x3 = 0,y1=0,y2=0;
        int arr[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};


        if(yy == yy2){
             if(isLeapYear(yy)){
                if(mm>2){

                y1 =(arr[mm - 1-1] + dd) +1;
                }
                else{
                y1 =(arr[mm - 1-1] + dd);

                    }
                }
            else{
                    y1 =(arr[mm - 1-1] + dd);
                }

             if(isLeapYear(yy2)){
                if(mm2>2){

                y2 =(arr[mm2 - 1-1] + dd2) +1;
                }
                else{
                y2 =(arr[mm2 - 1-1] + dd2);

                    }
                }
            else{
                    y2 =(arr[mm2 - 1-1] + dd2);
                }

                return y2 - y1;
        }




    if(isLeapYear(yy)){
        x1 = 366 - (arr[mm - 1-1] + dd);
    }
    else{
        x1 = 365 - (arr[mm - 1-1] + dd);
    }

    for (int i = yy + 1; i < yy2;i++){
        if(isLeapYear(i))
            x2 = x2 + 366;
        else
            x2 = x2 + 365;
    }

    if(isLeapYear(yy2)){
        if(mm2>2){
            x3 = x3 + arr[mm2 - 1-1] + dd2 + 1;
        }
        else{
            x3 = x3 + arr[mm2 - 1-1] + dd2;
        }
    }else{
         
            x3 = x3 + arr[mm2 - 1-1] + dd2;
        
    }

    return x1 + x2 + x3;
}


int main(){
    cout << "First date .. \n";
    int dd;
    int mm;
    int yy;
    cin >> dd >> mm >> yy;

    cout << "\nSecond date ...\n";
    int dd2, mm2, yy2;
    cin >> dd2 >> mm2 >> yy2;

    

    cout << "Totanl number of betwwn two given dates"<<Totaldays(dd, mm, yy, dd2, mm2, yy2);
    

    return 0;
}