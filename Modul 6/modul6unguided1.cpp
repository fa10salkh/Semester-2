#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string reverseString(string sentence)
{
    stack<char> st;
    for (char ch : sentence)
    {
        st.push(ch);
    }

    string reversed_sentence = "";
    while (!st.empty())
    {
        reversed_sentence += st.top();
        st.pop();
    }
    return reversed_sentence;
}

bool isPalindrome (string str)
{
    string reversedStr = reverseString(str);
    return str == reversedStr;
}

int main()
{
    string sentence;
    cout << "Masukkan kalimat : ";
    getline(cin, sentence);

    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    if (isPalindrome(sentence))
    {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    }
    else
    {
        cout << "Kalimat tersebut adalah bukan palindrom." << endl;
    }
    return 0;
}

