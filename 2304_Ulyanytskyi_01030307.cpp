#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <unordered_map>

using namespace std;

class Soulution
{
public:
    int find_lucky(vector<int>& array)
    {
        int result = -1;
        unordered_map<int, int> frequency;

        for (int number : array)
            frequency[number]++;

        for (auto& pair : frequency)
        {
            if (pair.first == pair.second && pair.first > result)
                result = pair.first;
        }            

        return result;
    }
};

int main()
{
    vector<int> items;
    string line;
    int item, lucky_number;    

    cout << "Enter numbers with a space between the numbers!\n";
    cout << "Enter 'Exit' for exit!\n\n";

    while (true)
    {
        cout << "Enter: ";
        getline(cin, line);
        istringstream is(line);

        if (line == "Exit" || line == "exit")
        {
            cout << "Exit!\n";
            break;
        }

        while (is >> item)
        {
            items.push_back(item);
        }

        Soulution solution;
        lucky_number = solution.find_lucky(items);

        if (lucky_number == -1)
            cout << "No lucky number found";
        else
            cout << "Lucky number: " << lucky_number;

        cout << endl << endl;
        items.clear();
    }    

    return 0;
}