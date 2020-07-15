#include "IteratorCombinations.h"
#include "ReadFile.h"
#include <iostream>

using namespace std;

int sum(int* num, int size){
    int total = 0;
    for(int cont = 0; cont < size; cont++){
        total += num[cont];
    }
    return total;
}

bool canPartitionIterator(int* num, int sum, int size){
    bool found = false;
    IteratorCombinations* it = new IteratorCombinations(num, sum, size);
    while(!it->lastCombination()){
        it->nextCombination(found);
        if(it->searchedCombination()) found = true;
    }
    delete(it);
    return found;
}

bool canPartition(int* num, int size){
    int s = sum(num, size);
    
    return (s%2 != 0)? false : canPartitionIterator(num, s/2, size);
}

int main(){
    ReadFile* file = new ReadFile("../fichVect.txt");
    int* read = file->ReadFolder();
    int size = file->getSize();
    bool found = canPartition(read, size);
    
    cout << "Can partition: ";
    printf("%s", found ? "TRUE" : "FALSE");
    
    delete(file);
    return 0;
}


