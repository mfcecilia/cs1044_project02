#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

string user;
int solve;
string words;
int x;
int results;
std::vector< int > contents;
ifstream textFile;
int count = 1;

void loop()
{
    for (int i = 0; i < contents.size(); i++)
            {
                cout << "array contents = " << contents[i] << endl;
            }
}

void calc()
{
        if (words == "add")
        {
            textFile >> x;
            contents.push_back(x);
            textFile >> x;
            contents.push_back(x);
            results = results + contents[0] + contents[1];
            contents.clear();
            loop();
        }

        if (words == "add_prev")
        {
            textFile >> x;
            contents.push_back(x);
            results = results + x;
            contents.clear();
        }

        if(words == "mul_prev")
        {
            textFile >> x;
            contents.push_back(x);
            results = results * x;
            contents.clear();
        }

        if (words == "sub")
        {
            textFile >> x;
            contents.push_back(x);
            textFile >> x;
            contents.push_back(x);
            results = contents[0] - contents[1];
            contents.clear();
        }

        if (words == "div_prev")
        {
            textFile >> x;
            contents.push_back(x);
            results = results/x;
            contents.clear();
        }

}

int main()
{
    cout << "Please enter a file name:" << endl;
    cin >> user;
    textFile.open(user.c_str());

    //read file while there's something to read
    while (textFile)
    {


        //stores the number of calculations are in a set
        textFile >> solve;

        //main events
        if (solve > 0)
        {
            for (int a = 0; a < solve; a++)
            {
                    textFile >> words;
                    calc();
            }
            cout << "The result of calculation "<< count << " is: " << results << endl;
            results = 0;
            solve = 0;
            count++;
        }
        else
        {
            //close
            textFile.close();
        }
    }
}
