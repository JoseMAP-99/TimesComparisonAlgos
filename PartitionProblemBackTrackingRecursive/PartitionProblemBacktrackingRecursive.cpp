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
        return (canPartitionRecursive(num, sum - num[currentIndex], size, currentIndex+1));
    }
}

bool canPartition(int* num, int size){
    int s = sum(num, size);
    
    return (s%2 != 0)? false : canPartitionRecursive(num, s/2, size, 0);    
}

int main() {
    ReadFile* file = new ReadFile("../fichVect.txt");
    int* vect = file->ReadFolder();
    int size = file->getSize();    
    bool found = canPartition(vect, size);
    
    cout << "Can partition: ";
    printf("%s", found ? "TRUE" : "FALSE");
    
    delete(file);
    return 0;
}

