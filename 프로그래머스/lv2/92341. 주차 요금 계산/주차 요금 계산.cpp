#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

string get_car_number(string record) {
    string car_number(record.begin() + 6, record.begin() + 10);
    return car_number;
}

int get_int_time(string record) {
    int int_time = 0;
    
    int_time += (record[0] - '0') * 600;
    int_time += (record[1] - '0') * 60;
    int_time += (record[3] - '0') * 10;
    int_time += (record[4] - '0');
    
    return int_time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> car_records;
    
    for (int i = 0; i < records.size(); i++) {
        if (records[i][12] == 'N') {//IN이면
            string car_number = get_car_number(records[i]);
            int in_time = get_int_time(records[i]);
            bool enter_car = false;
            
            for (int j = i + 1; j < records.size(); j++) {
                string out_car_number = get_car_number(records[j]);

                if (records[j][12] == 'U' && car_number == out_car_number) {
                    enter_car = true;
                    
                    int out_time = get_int_time(records[j]);
                    car_records[car_number] += out_time - in_time;
                    
                    break;
                }
            }
            if (!enter_car) car_records[car_number] += 1439 - in_time;
        }
    }
    
    int money = 0;
    for (auto c : car_records) {
        double time = (c.second - fees[0]) < 0 ? 0 : c.second - fees[0];
        int money = fees[1] + ceil(time / (double)fees[2]) * fees[3];
        
        answer.push_back(money);
    }

    return answer;
}