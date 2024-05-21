#include <iostream>
#include <stack>

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

int main()
{
    string sentence;
    cout << "Masukkan kalimat      : ";
    getline(cin, sentence);

    string reversed_sentence = reverseString(sentence);

    cout << "Hasil setelah dibalik : " << reversed_sentence << endl;

    return 0;
}