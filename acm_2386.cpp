#include <iostream>

using namespace std;

int main()
{
    char word;
    string sentence;

    cin >> word;
    while (word != '#')
    {
        int count = 0;
        getline(cin, sentence);
        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == word)
                count++;
            else if (char(sentence[i] + 32) == word)
                count++;
        }
        cout << word << " " << count << endl;
        cin >> word;
    }
}