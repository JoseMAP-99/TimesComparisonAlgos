#include "IteratorCombinations.h"

IteratorCombinations::IteratorCombinations(int* num, int sum, int size) {
    this->size = size;
    this->combination = new int(size); 
    this->num = num;
    this->sum = sum;
}

bool IteratorCombinations::lastCombination() {
    for(int i = 0; i < size; i++){
        if(combination[i] == 0) return false;
    }
    return true;
}

void IteratorCombinations::nextCombination(bool found) {
    for(int i = 0; i < size; i++){
        if(combination[i] == maxValue){
            combination[i] = minValue;
        }else{
            combination[i] = maxValue;
            if(isValidCombination()){
                return;
            }else{
                combination[i] = minValue;
            }
        }
    }
    noMoreCombinations(found);
}

bool IteratorCombinations::searchedCombination() {
    int actSum = totalValues();
    return (actSum == sum);
}

bool IteratorCombinations::isValidCombination() {
    return (totalValues() <= sum);
}

int IteratorCombinations::totalValues() {
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(combination[i] == 1){
            sum += num[i];
        }
    }
    return sum;
}

void IteratorCombinations::noMoreCombinations(bool found) {
    cout << "Can partition: ";
    printf("%s", found ? "TRUE" : "FALSE");
    exit(0);
}

