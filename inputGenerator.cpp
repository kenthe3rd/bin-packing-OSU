#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    ofstream oFile;
    oFile.open("random.txt");

    oFile << 10 << "\n";
    for(int i=0; i<10; ++i){
        int binCap = rand() % 30 + 10;
        int numItems = rand() % 100 + 20;
        oFile << binCap << "\n" << numItems << "\n";
        for(int j=0; j<numItems; ++j){
            oFile << rand() % binCap + 1 << " ";
        }
        oFile << "\n";
    }

    oFile.close();
    return 0;
}