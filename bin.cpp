#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void firstFit(char*);
void firstFitDecreasing(char*);

int main(){
    firstFit((char*)"bin.txt");
    firstFitDecreasing((char*)"bin.txt");
    return 0;
}

void firstFit(char* filename){
    ifstream iFile;
    iFile.open(filename);
    string iLine = "";
    vector<float> bins;
    int numOfTests = -1;
    float binCapacity = 0.0;
    int numOfItems = -1;
    float sizeOfItem = 0.0;
    bool fitsInOpenBin = false;
    getline(iFile, iLine);
    stringstream testsInput(iLine);
    testsInput >> numOfTests;
    for(int i=0; i<numOfTests; ++i){
        while(!bins.empty()){
            bins.pop_back();
        }
        getline(iFile, iLine);
        stringstream binCapacityInput(iLine);
        binCapacityInput >> binCapacity;
        getline(iFile, iLine);
        stringstream numOfItemsInput(iLine);
        numOfItemsInput >> numOfItems;
        getline(iFile, iLine);
        stringstream itemsInput(iLine);
        bins.push_back(0.0);
        for(int j=0; j<numOfItems; ++j){
            itemsInput >> sizeOfItem;
            fitsInOpenBin = false;
            for(int k=0; k<bins.size(); ++k){
                if(bins[k] + sizeOfItem <= binCapacity){
                    bins[k] += sizeOfItem;
                    fitsInOpenBin = true;
                    break;
                }
            }
            if(!fitsInOpenBin){
                bins.push_back(0.0);
                bins[bins.size()-1] += sizeOfItem;
            }
        }
        cout << "First fit required " << bins.size() << " bins for case #" << i+1 << endl;
    }
    iFile.close();
}

void firstFitDecreasing(char* filename){
    ifstream iFile;
    iFile.open(filename);
    string iLine = "";
    vector<float> bins;
    int numOfTests = -1;
    float binCapacity = 0.0;
    int numOfItems = -1;
    float sizeOfItem = 0.0;
    bool fitsInOpenBin = false;
    getline(iFile, iLine);
    stringstream testsInput(iLine);
    testsInput >> numOfTests;
    for(int i=0; i<numOfTests; ++i){
        while(!bins.empty()){
            bins.pop_back();
        }
        getline(iFile, iLine);
        stringstream binCapacityInput(iLine);
        binCapacityInput >> binCapacity;
        getline(iFile, iLine);
        stringstream numOfItemsInput(iLine);
        numOfItemsInput >> numOfItems;
        getline(iFile, iLine);
        stringstream itemsInput(iLine);
        bins.push_back(0.0);
        vector<float> items;
        for(int j=0; j<numOfItems; ++j){
            itemsInput >> sizeOfItem;
            items.push_back(sizeOfItem);
        }
        sort(items.begin(), items.end());
        reverse(items.begin(), items.end());
        for(int j=0; j<numOfItems; ++j){
            sizeOfItem = items[j];
            fitsInOpenBin = false;
            for(int k=0; k<bins.size(); ++k){
                if(bins[k] + sizeOfItem <= binCapacity){
                    bins[k] += sizeOfItem;
                    fitsInOpenBin = true;
                    break;
                }
            }
            if(!fitsInOpenBin){
                bins.push_back(0.0);
                bins[bins.size()-1] += sizeOfItem;
            }
        }
        cout << "First fit decreasing required " << bins.size() << " bins for case #" << i+1 << endl;
    }
    iFile.close();
}

