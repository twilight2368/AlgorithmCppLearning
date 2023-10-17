#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
map<string, int> my_data;
vector<int> result;

void inputHandling(){
    string input;
    while (getline(cin, input))
    {
        if (input == "*") break;
        my_data[input] = 1;
    }
}

void queryHandling(){
    string input;
    string query;
    string data;
    while (getline(cin, input))
    {
        if(input == "***") break;
        stringstream ss(input);
        ss >> query;
        ss >> data;
        if (query == "find")
        {
            result.push_back(my_data[data]);
        }else if (query == "insert")
        {
            if (my_data[data] == 0 && data.length() <= 50 && data.length() > 0)
            {
                my_data[data] = 1;
                result.push_back(1);
            }else
            {
                result.push_back(0);
            }     
        }    
    }   
}


void handlingResult(){
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
}
int main(){
    inputHandling();
    queryHandling();
    handlingResult();
    return 0;
}