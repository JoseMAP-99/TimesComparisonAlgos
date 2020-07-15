#include <minwindef.h>
#include "ReadFile.h"

using namespace std;

int sum(int* num, int size){
    int total = 0;
    for(int cont = 0; cont < size; cont++){
        total += num[cont];
    }
    return total;
}

bool canPartitionRecursive(bool** dp, int* num, int sum, int size, int currentIndex){
    if(sum == 0) return true;
    
    if(size == 0 || currentIndex >= size) return false;
    
    if(dp[currentIndex][sum] == false){
        if(num[currentIndex] <= sum){
            if(canPartitionRecursive(dp, num, sum - num[currentIndex], size, currentIndex+1)){
                dp[currentIndex][sum] = true;
                return true;
            }
        }
        
        dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, size, currentIndex+1);
    }
    return dp[currentIndex][sum];
}

bool canPartition(int* num, int size){
    int s = sum(num, size);    
    if (s%2 != 0) return false;
    
    bool** dp = new bool*[size];
    for(int i = 0; i < size; i++) dp[i] = new bool[s/2 +1]{false};
        
    return canPartitionRecursive(dp, num, s/2, size, 0); 
}

int main() {
    ReadFile* file = new ReadFile("../fichVect.txt");
    int* vect = file->ReadFolder();
    int size = file->getSize();
    
    bool found = canPartition(vect, size);   
    cout << "Can partition: ";
    printf("%s", found ? "TRUE" : "FALSE");
    return 0;
}

