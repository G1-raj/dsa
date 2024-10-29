#include <iostream>
#include <vector>
#include "Strings.cpp"

using namespace std;

int main() {

    String str = String("Hello World!");
    String label = String("This is a String - Seprated by comma - and we are here - new part");
    String sli;
    vector<String> splitted = label.split('-');
  

    str.print();

    cout << endl;

    sli = str.slice(3,7);

    sli.print();

    cout << endl;

    for(int i = 0; i < splitted.size(); i++) {
        splitted[i].print();
        cout << endl;
    }
    


    return 0;
}