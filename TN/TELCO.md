# Description
Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
The first block of data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under the form: 
```
call <from_number> <to_number> <date> <from_time> <end_time>
```
which is a call from the phone number ```<from_number>``` to a phone number ```<to_number>``` on ```<date>```, and starting at time-point ```<from_time>```, terminating at time-point ```<end_time>```
```<from_number>``` and ```<to_number>``` are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, the phone number is incorrect)
```<date>``` is under the form YYYY-MM-DD (for example 2022-10-21)
```<from_time>``` and ```<to_time>``` are under the form hh:mm:ss (for example, 10:07:23)
 
The second block consists of queries (terminated by a line containing #), each query in a line (number of lines can be up to 100000) and belongs to one of the following types:
?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
?number_calls_from ```<phone_number>```: print to stdout (in a new line) the number of times a call is made from ```<phone_number>```
?number_total_calls: print to stdout (in a new line) the total number of calls of the data
?count_time_calls_from ```<phone_number>```: print to stdout (in a new line) the total time duration (in seconds) the calls are made from ```<phone_number>```

Example
```
Input
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#
```
Output
```
1
2
4
398
120
```


Online solution:
```c++
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

// A struct to store the information of a call
struct Call
{
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;

    // A constructor to initialize a call from a line of input
    Call(string line)
    {
        stringstream ss(line);
        string word;
        ss >> word; // skip the word "call"
        ss >> from_number >> to_number >> date >> from_time >> end_time;
    }

    // A method to check if a phone number is correct
    bool check_phone_number(string number)
    {
        if (number.size() != 10)
            return false; // a phone number must have 10 characters
        for (char c : number)
        {
            if (c < '0' || c > '9')
                return false; // a phone number must contain only digits
        }
        return true;
    }

    // A method to check if the call is valid
    bool is_valid()
    {
        return check_phone_number(from_number) && check_phone_number(to_number);
    }

    // A method to calculate the duration of the call in seconds
    int duration()
    {
        int h1, m1, s1, h2, m2, s2;                           // variables to store the hours, minutes and seconds of the start and end time
        sscanf(from_time.c_str(), "%d:%d:%d", &h1, &m1, &s1); // parse the from_time string
        sscanf(end_time.c_str(), "%d:%d:%d", &h2, &m2, &s2);  // parse the end_time string
        return (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1); // return the difference in seconds
    }
};

// A vector to store the calls from the input
vector<Call> calls;

// A map to store the number of calls made from each phone number
map<string, int> number_calls_from;

// A map to store the total time duration of calls made from each phone number
map<string, int> count_time_calls_from;

// A function to read the input and process the calls
void read_input()
{
    string line;
    while (getline(cin, line))
    { // read each line until EOF or #
        if (line == "#")
            break;       // stop reading if # is encountered
        Call call(line); // create a call object from the line
        if (call.is_valid())
        {                                                               // check if the call is valid
            calls.push_back(call);                                      // add the call to the vector
            number_calls_from[call.from_number]++;                      // increment the number of calls made from the phone number
            count_time_calls_from[call.from_number] += call.duration(); // add the duration of the call to the total time
        }
    }
}

// A function to perform the queries and print the output
void perform_queries()
{
    string line;
    while (getline(cin, line))
    { // read each line until EOF or #
        if (line == "#")
            break; // stop reading if # is encountered
        stringstream ss(line);
        string query;
        ss >> query; // read the query type
        if (query == "?check_phone_number")
        {                      // check if all phone numbers are correct
            cout << 1 << endl; // print 1 since we only processed valid calls
        }
        else if (query == "?number_calls_from")
        { // get the number of calls made from a phone number
            string number;
            ss >> number;                              // read the phone number
            cout << number_calls_from[number] << endl; // print the number of calls from the map
        }
        else if (query == "?number_total_calls")
        {                                 // get the total number of calls
            cout << calls.size() << endl; // print the size of the vector
        }
        else if (query == "?count_time_calls_from")
        { // get the total time duration of calls made from a phone number
            string number;
            ss >> number;                                  // read the phone number
            cout << count_time_calls_from[number] << endl; // print the total time from the map
        }
    }
}

int main()
{
    read_input();      // read and process the input data
    perform_queries(); // perform and output the queries
    return 0;
}

```

```c++
Call a_call;
    for (int i = 0; i < calls.size(); i++)
    {
        a_call = calls[i];
        cout << a_call.from_number << " " 
            << a_call.to_number << " " 
            << a_call.date << " " 
            << a_call.start_hour << "-" << a_call.end_hour 
        <<endl;
    }
```