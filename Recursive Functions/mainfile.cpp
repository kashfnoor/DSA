#include <iostream>
#include <iomanip> 
#include "functions.h"

using namespace std;

int main() {
    int sizes[] = { 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "                              DATA ANALYSIS RESULTS                       \n";
    cout << "-----------------------------------------------------------------------------------------\n";
    cout << left << setw(5) << "N"
        << setw(10) << "Max"
        << setw(10) << "Min"
        << setw(10) << "Range"
        << setw(10) << "Sum"
        << setw(15) << "Product"
        << setw(10) << "Mode"
        << setw(10) << "Mean"
        << setw(10) << "Std Dev"
        << endl;
    cout << "-----------------------------------------------------------------------------------------\n";

    for (int n : sizes) {
        RecursiveAnalysis data(n);


        cout << "Generated Data: "; 
        data.display();
        cout << "\n";
        cout << left << setw(5) << n
            << setw(10) << data.findmax()
            << setw(10) << data.findmin()
            << setw(10) << data.findrange()
            << setw(10) << data.findsum()
            << setw(15) << data.findprod()
            << setw(10) << data.findmode()
            << setw(10) << fixed << setprecision(2) << data.findmean()
            << setw(10) << fixed << setprecision(2) << data.sdev()
            << endl;
        cout << "-----------------------------------------------------------------------------------------\n";

    }

    cout << "                         Create to search & sort your own array!\n";
int n;
cout << "        - Enter the size of the array: "; // Creating own array
cin >> n;

RecursiveAnalysis analysis(n);

cout << "\n        --> Your generated array: ";
analysis.display();
long long usernum;
cout << "\n        - Enter a number to search in the array(index starts from 0!): "; // Searching for the selected number in the randomly created array
cin >> usernum;
int index = analysis.search(usernum);
if (index != -1) {
    cout << "\n        --> Your number " << usernum << " is found at index " << index << "!\n";
}
else {
    cout << "        --> Your number " << usernum << " is not in this array.\n";
}
cout << "\n        - Let's sort this array\n";
cout << "\n        --> Your sorted array: ";
analysis.sortArray(); 
analysis.display(); 
return 0;

}