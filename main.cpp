#include <iostream>
#include <string>

using namespace std;

bool isValidSourceString(const string& source) {
    for (char c : source) {
        if (c <= 31 || (33 <= c && c <= 47) || (58 <= c && c <= 64) ||
            (91 <= c && c <= 96) || (123 <= c && c <= 127)) {
            return false;
        }
    }
    return true;
}

string readSourceString() {
    string source;
    bool isEnd = false;
    while (!isEnd) {
        string word;
        cin >> word;
        if (word == "END" || word == "end") {
            isEnd = true;
        } else {
            source += word + " ";
        }
    }
    source.pop_back();  // remove trailing space
    return source;
}

bool isValidSearchString(const string& search) {
    if (search.length() < 2) {
        return false;
    }
    char lastChar = search.back();
    return (lastChar == '+' || lastChar == '.' || lastChar == '*');
}

int main() {
    string source = readSourceString();

    while (!isValidSourceString(source)) {
        cout << "Invalid source string. Please try again." << endl;
        source = readSourceString();
    }
    
    source = " " + source + " "; // Add a space to avoid errors

    string search;
    cout << "Enter search string: ";
    cin >> search;

    while (search != "quit" && search != "QUIT") {
        if (isValidSearchString(search)) {
            // perform search
            char lastChar = search.back();
            // ... your code here ...
        } else {
            cout << "Invalid search string. Please try again." << endl;
        }
        cout << "Enter search string: ";
        cin >> search;
        continue ;
    }
    string slast2 = search.substr(search.length()-2);
    string snosign = search.substr(0,search.length()-1);
    string snolast2 = search.substr(0,search.length()-2);
    // "+"
            if (source == "+"){
                int pos = source.find(snosign);
                
                while(pos != string::npos){
                    if(source.at(pos-1) == ' '){
                        int space = source.find(" ",pos);
                        cout << "index: " << pos-1 << " word: " << source.substr(pos,(space-pos)) << endl;
                    }
                    pos = source.find(snosign,pos+1);
                }
            }
    // "."
            else if (slast2 == "."){
                int pos = source.find(snosign);
                    
                while(pos != string::npos){
                    if(source.at(pos + snosign.length()) == ' '){
                        int prespace = source.rfind(" ",pos);
                        int space = source.find(" ",pos);
                        cout << "index: " << pos-1 << " word: " << source.substr(prespace+1,((pos-1)-prespace)) << endl;
                    }
                    pos = source.find(snosign,pos+1);
                }
            }
    // "*"
            else if (slast2 == "*" && searchLast2String != "**"){
                int searchPosition = source.find(searchWithoutSign);

                while(searchPosition != string::npos){
                    if(source.substr(source.rfind(" ",searchPosition)+1,searchWithoutSign.length()) != searchWithoutSign &&
                        source.substr(source.find(" ",searchPosition)-searchWithoutSign.length(),searchWithoutSign.length()) != searchWithoutSign){
                        int prevSpaceIndex = source.rfind(" ",searchPosition);
                        int postSpaceIndex = source.find(" ",searchPosition);
                        cout << "index: " << searchPosition-1 << " word: " << source.substr(prevSpaceIndex+1,((postSpaceIndex-1)-prevSpaceIndex)) << endl;
                    }
                    searchPosition = source.find(searchWithoutSign,searchPosition+1);
                }
            }
    return 0;
}
