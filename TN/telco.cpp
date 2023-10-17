#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;

struct Call
{
    string from_number;
    string to_number;
    // string date;
    // int start_hour;
    // int start_min;
    // int start_sec;
    // int end_hour;
    // int end_min;
    // int end_sec;
};

vector<int> output;
vector<Call> calls;

map<string, int> num_calls_from;
map<string, int> time_calls_from;

bool isValid(string call_from, string call_receive){
    const regex pattern("[0-9]{10}");
    if (regex_match(call_from, pattern) && regex_match(call_receive, pattern))
    {
        return true;
    }else
    {
        return false;
    }
}

void inputHandling()
{
    string input;
    string word;
    int h1, m1, s1, h2, m2, s2;
    string p_from, p_receive, date;
    string time_start, time_end;
    Call call_input;
    while (getline(cin, input))
    {
        if (input == "#")
        {
            break;
        }
        else
        {
            stringstream ss(input);
            ss >> word;
            ss >> p_from;
            ss >> p_receive;
            ss >> date;
            ss >> time_start;
            ss >> time_end;
            sscanf(time_start.c_str(), "%d:%d:%d", &h1, &m1, &s1);
            sscanf(time_end.c_str(), "%d:%d:%d", &h2, &m2, &s2);
            call_input.from_number = p_from;
            call_input.to_number = p_receive;
            // call_input.date = date;
            // call_input.start_hour = h1;
            // call_input.start_min = m1;
            // call_input.start_sec = s1;
            // call_input.end_hour = h2;
            // call_input.end_min = m2;
            // call_input.end_sec = s2;
            calls.push_back(call_input);
            num_calls_from[call_input.from_number] = num_calls_from[call_input.from_number] + 1;
            time_calls_from[call_input.from_number] = time_calls_from[call_input.from_number] + ((h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1));
        }
    }
}

void queryHandling()
{
    string input;
    string query;
    string phonenumber;
    while (getline(cin, input))
    {
        if (input == "#")
        {
            break;
        }
        else
        {
            stringstream ss(input);
            ss >> query; 
            if (query == "?check_phone_number")
            {                      
                int result = 1;
                for (int i = 0; i < calls.size(); i++)
                {
                    if (!isValid(calls[i].from_number, calls[i].to_number))
                    {
                        result = 0;
                        break;
                    }     
                }
                
                output.push_back(result);
            }
            else if (query == "?number_calls_from")
            { 
                ss >> phonenumber;
                int result = num_calls_from[phonenumber];
                output.push_back(result);
            }  
            else if (query == "?number_total_calls")
            {             
                int result = calls.size();
                output.push_back(result);
            }
            else if (query == "?count_time_calls_from")
            {
                ss >> phonenumber;
                int result = time_calls_from[phonenumber];
                output.push_back(result);
            }
        }
    }
}

void outputHandling()
{
   for (int i = 0; i < output.size(); i++)
   {
      cout << output[i] << endl;
   }
   
}

int main()
{
    inputHandling();
    queryHandling();
    outputHandling();
}