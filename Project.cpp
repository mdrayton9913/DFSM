// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using std::ifstream;
using namespace std;
bool DFSM(vector<int> accept, char alphabet[], int states, string input)
{

    vector<int> machine_states;
    int place_counter = 0;
    bool accepted = false;
    //cout << accept[1] << endl << accept[2] << endl;
    for (int i = 1; i < states + 1; i++)
    {
        machine_states.push_back(i);
    }
    //cout << machine_states[0] << endl << machine_states[1] << endl;
    //cout << input.size() << endl;
    //cout << accept.size() << endl;
    //cout << machine_states[1] << endl;
    if (accept.size() > 2)
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (place_counter == 0 && input[i] == alphabet[0])
            {
                for (int j = 1; j < accept.size() + 1; j++)
                {
                    if (machine_states[place_counter] != accept[j] + 1)
                    {
                        accepted = false;
                        //cout << accepted;
                    }
                    else
                    {
                        accepted = true;
                        //cout << accepted << endl;
                        break;
                    }
                }
            }
            else if (place_counter == 0 && input[i] == alphabet[1])
            {
                place_counter++;
                //cout << place_counter << endl;
                for (int j = 1; j < accept.size() + 1; j++)
                {
                    if (machine_states[place_counter] != accept[j] + 1)
                    {
                        accepted = false;
                        //cout << accepted << endl;
                    }
                    else
                    {
                        accepted = true;
                        //cout << accepted << endl;
                        break;
                    }
                }
            }
            else if (place_counter == states - 1)
            {
                for (int j = 1; j < accept.size() + 1; j++)
                {
                    if (machine_states[place_counter] != accept[j] + 1)
                    {
                        if (input[i] == alphabet[0] || input[i] == alphabet[1])
                        {
                            accepted = false;
                            //cout << accepted << endl;
                        }
                        break;
                    }
                    else
                    {
                        if (input[i] == alphabet[1])
                        {
                            place_counter--;
                        }
                        else
                        {
                            accepted = true;
                            //cout << accepted << endl;
                            break;
                        }
                    }
                }
            }
            else
            {
                for (int j = 1; j < accept.size() + 1; j++)
                {
                    if (machine_states[place_counter] != accept[j] + 1)
                    {
                        accepted = false;
                        if (input[i] == alphabet[1])
                        {
                            place_counter++;
                        }
                        else
                        {
                            place_counter--;
                        }
                        break;
                    }
                    else
                    {
                        accepted = true;
                        if (input[i] == alphabet[1])
                        {
                            place_counter++;
                        }
                        else
                        {
                            place_counter--;
                        }
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (place_counter == 0 && input[i] == alphabet[0])
            {
                for (int j = 1; j < accept.size(); j++)
                {
                 if (machine_states[place_counter] != accept[j] + 1)
                 {
                        accepted = false;
                        //cout << accepted << endl;
                 }
                 else
                 {
                    accepted = true;
                    //cout << accepted << endl;
                    break;
                 }
                }
            }
            else if (place_counter == 0 && input[i] == alphabet[1])
            {
                place_counter++;
                //cout << place_counter << endl;
                for (int j = 1; j < accept.size(); j++)
                {
                    if (machine_states[place_counter] != accept[j] + 1)
                    {
                        accepted = false;
                        //cout << accepted << endl;
                    }
                    else
                    {
                        accepted = true;
                        //cout << accepted << endl;
                        break;
                    }
                }
            }
            else if (place_counter == states - 1)
            {
                for (int j = 0; j < accept.size(); j++)
                {
                    if (machine_states[place_counter] != accept[j] + 1)
                    {
                        if (input[i] == alphabet[0] || input[i] == alphabet[1])
                        {
                         accepted = false;
                         //cout << accepted << endl;
                        }
                    }
                    else
                    {
                        if (input[i] == alphabet[1])
                        {
                            place_counter--;
                        }
                        else
                        {
                            accepted = false;
                            //cout << accepted << endl;
                        }
                    }
                }
            }
            else
            {
                for (int j = 1; j < accept.size() + 1; j++)
                {
                    if (machine_states[place_counter] != accept[j])
                    {
                     accepted = false;
                        if (input[i] == alphabet[1])
                        {
                          place_counter++;
                        }
                        else
                        {
                            place_counter--;
                        }
                     break;
                    }
                    else
                    {
                        accepted = true;
                        if (input[i] == alphabet[1])
                        {
                            place_counter++;
                        }
                        else
                        {
                            place_counter--;
                        }
                        break;
                    }
                }
            }
        }
    }
    return accepted;
}
int main()
{   
    //cout << "Hello World!\n";
    fstream user_file;
    user_file.open("DFSM.txt");
    if (!user_file)
    {
        cerr << "Error: file cannot be opened" << endl;
        exit(1);
    }
    else
    {
        cout << "File Opened\n";
    }
    string user_input;
    //char alphabet_one;
    //char alphabet_two;
    char read;
    int number_of_states = 0;
    char alphabet[2] = { '0', '0' };
    int counter = 0;
    vector<int> acceptance_states;
    while (user_file.get(read))
    {
        if (read != ',' && read != ' ' && counter < 2)
        {
            alphabet[counter] = read;
            counter++;
        }
        else if(read != '\n' && counter == 2)
        {
            number_of_states = read - '0';
            counter = 3;
        }
        else if (read != ',' && read != ' ' && counter == 3)
        {
          acceptance_states.push_back(read - '0');
        }
    }
    cout << counter << endl;
    cout << alphabet[0];
    cout << ",";
    cout << alphabet[1] << endl;
    cout << number_of_states << endl;
    //cout << acceptance_states[1] << endl;
    //cout << acceptance_states[2] << endl;

    do
    {
        cout << "Please give an input for the DFSM, enter E to exit: " << endl;
        cin >> user_input;
        if (DFSM(acceptance_states, alphabet, number_of_states, user_input) == 1)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    } while (user_input != "E");
    user_file.close();

 
 
 


}
/*bool DFSM(vector<int> accept, char alphabet[], int states, string input)
{
    vector<int> machine_states;
    int place_counter = 0;
    bool accepted = false;
    for (int i = 0; i < states; i++)
    {
        machine_states.push_back(i);
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (place_counter == 0 && input[i] == alphabet[0])
        {
            for (int j = 0; j < accept.size(); j++)
            {
                if (machine_states[place_counter] != accept[j])
                {
                    accepted = false;
                }
                else
                {
                    accepted = true;
                }
            }
        }
        else if  (place_counter == 0 && input[i] == alphabet[1])
        {
            place_counter++;
            for (int j = 0; j < accept.size(); j++)
            {
                if (machine_states[place_counter] != accept[j])
                {
                    accepted = false;
                }
                else
                {
                    accepted = true;
                }
            }
        }
        else if (place_counter == states - 1)
        {
            for (int j = 0; j < accept.size(); j++)
            {
                if (machine_states[place_counter] != accept[j])
                {
                    if (input[i] == alphabet[0] || input[i] == alphabet[1])
                    {
                        accepted = false;
                    }
                }
                else
                {
                    if (input[i] == alphabet[0])
                    {
                        place_counter--;
                    }
                    else
                    {
                        accepted = true;
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < accept.size(); j++)
            {
                if (machine_states[place_counter] != accept[j])
                {
                    accepted = false;
                    if (input[i] == alphabet[1])
                    {
                        place_counter++;
                    }
                    else
                    {
                        place_counter--;
                    }
                }
                else
                {
                    accepted = true;
                    if (input[i] == alphabet[1])
                    {
                        place_counter++;
                    }
                    else
                    {
                        place_counter--;
                    }
                }
            }
        }

    }
    return accepted;
} */

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
