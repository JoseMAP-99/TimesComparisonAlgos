#include "ReadFile.h"

using namespace std;

int sum(int* num, int size){
    int total = 0;
    for(int cont = 0; cont < size; cont++){
        total += num[cont];
    }
    return total;
}

bool canPartitionRecursive(int* num, int sum, int size, int currentIndex){
    if(sum == 0) return true;
    
    if(size == 0 || currentIndex >= size) return false;
    
    if(num[currentIndex] <= sum){
        if(canPartitionRecursive(num, sum - num[currentIndex], size, currentIndex+1))
            return true;
    }
    return canPartitionRecursive(num, sum, size, currentIndex+1);
}

bool canPartition(int* num, int size) {
    int s = sum(num, size);
    if (s % 2 != 0) return false;
    
    return canPartitionRecursive(num, s/2, size, 0); 
}

int main() {
    ReadFile* file = new ReadFile("../fichVect.txt");
    int* read = file->ReadFolder();
    int size = file->getSize();
    bool found = canPartition(read, size);
    
    cout << "Can partition: ";
    printf("%s", found ? "TRUE" : "FALSE");
    
    delete(file);    
    return 0;
}

