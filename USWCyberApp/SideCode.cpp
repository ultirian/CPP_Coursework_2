//
// Created by Chris on 19/11/2020.
//
#include <iostream>
#include <string>
using namespace std;
bool isVowel(char);
int count(string);
int main()
{
    string sentence;
    while (true) {
        cout << "Please enter a string" << endl;
        getline(cin, sentence);
        cout << count(sentence) << endl;
    }

}

bool isVowel(char ch)
{

    return if(ch =='a' || 'A' || 'e' || 'E' || 'i' || 'I' || 'o' || 'O' || 'u' || 'U');
}

int count(string vow)
{
    int count = 0;
    for (int i = 0; i < vow.length(); i++)
        if (isVowel(vow[i]))
            ++count;
    cout << "There is " << count << " vowels" << endl;
    return 0;

}
