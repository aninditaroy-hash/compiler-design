#include <iostream>
#include <fstream>


using namespace std;

bool isKeyword(string word)
{
    string keywords[] = {"int", "main" , "return", "cout", "float", "double", "char"};
    for (string k : keywords)
    {
        if (word == k)
            return true;
    }
    return false;
}

bool isOperator(string word)
{
    string operators[] = {"=", "<<", "+", "-", "*", "/", "==", "<=", ">="};
    for (string op : operators)
    {
        if (word == op)
            return true;
    }
    return false;
}

bool isPunctuation(char ch)
{
    return (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';');
}

int main()
{
    string myText;
    ifstream MyReadFile ("myfile.txt");               //text theke 1 ta line my
    int lineNumber = 1;

    if (!MyReadFile)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    while (getline(MyReadFile, myText))  // file open read txt and 1
    {
        cout << "\nLine " << lineNumber << ": " << myText << endl;

        string word = "";

        for (int i = 0; i < myText.length(); i++)
        {
            char ch = myText[i];
            if (ch == '"')
            {
                string strLiteral = "\"";
                i++;
                while (i < myText.length() && myText[i] != '"')
                {
                    strLiteral += myText[i];
                    i++;
                }
                strLiteral += "\"";
                cout << strLiteral << " is a String " << endl;
                continue;                                           //loop er baki part skip kore next iteration e chole jao
            }



            if (isspace(ch) || isPunctuation(ch))
            {
                if (word != "")
                {
                    if (isKeyword(word))
                        cout << word << " is a Keyword" << endl;
                    else if (isdigit(word[0]))
                        cout << word << " is a Constant" << endl;
                    else
                        cout << word << " is a Identifier" << endl;

                    word = "";
                }

                if (isPunctuation(ch))
                    cout << ch << " is a Punctuation" << endl;
            }





            else if (isOperator(string(1, ch)))
            {
                cout << ch << " is a Operator" << endl;
            }
            else
            {
                word += ch;
            }
        }

        //for loop done




        if (word != "")
        {
            if (isKeyword(word))
                cout << word << " is a Keyword" << endl;
            else if (isdigit(word[0]))
                cout << word << " is a Constant" << endl;
            else
                cout << word << " is a Identifier" << endl;
        }

        lineNumber++;
    }
    MyReadFile.close();
return 0;
}

