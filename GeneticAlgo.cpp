#include<bits/stdc++.h>
using namespace std;
#define ll long long

std::string intToBinaryString(int num) {
    if (num == 0)
        return "00000";  // Return '00000' for input 0

    std::string binaryString = "";

    while (num > 0) {
        if (num % 2 == 0) {
            binaryString = "0" + binaryString;
        } else {
            binaryString = "1" + binaryString;
        }
        num /= 2;
    }

    // Pad with leading zeros to ensure a length of 5
    while (binaryString.length() < 5) {
        binaryString = "0" + binaryString;
    }

    return binaryString;
}


int main(){
    int sum = 0, Max = 0;
    double avg;
    cout << "Random number are generating ..\n";

    vector<int> randomInt;
      vector<int> fx;
         srand(time(0));
    for (int i = 0; i < 4;i++){
         srand(time(0));
        int x = rand() % 10;

        randomInt.push_back(x);
        fx.push_back(x * x);
        Max = max(Max, x * x);
        sum += x*x;
    }
    avg = sum / 4;
    cout << Max << " " << sum << " " << avg<<endl;

    for (int i = 0; i < randomInt.size();i++){
        cout << randomInt[i] << " ,";
    }

    vector<string> binaryNum;

    for (int i = 0; i < randomInt.size();i++){
        binaryNum.push_back(intToBinaryString(randomInt[i]));
    }

     for (int i = 0; i < randomInt.size();i++){
        cout << binaryNum[i] << " ";
    }

    vector<double> prob;
    for (int i = 0; i < fx.size();i++){
        prob.push_back(fx[i] / sum);
    }
    cout << "\npercentage probability ... \n";
    for (int i = 0; i < fx.size();i++){
        prob[i] = prob[i] * 100;
    }

    vector<double> expectedCount;
    for (int i = 0; i < 4;i++){
        expectedCount[i] = fx[i] / avg;
    }
    for (int i = 0; i < 4;i++){
        cout<<expectedCount[i]<<" ";
    }


        return 0;
}