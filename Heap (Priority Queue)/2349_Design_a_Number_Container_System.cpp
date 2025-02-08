#include <unordered_map>
#include <set>

class NumberContainers {
private:
    std::unordered_map<int, int> indexToNumber;  
    std::unordered_map<int, std::set<int>> numberToIndices; 

public:
    NumberContainers() {}

    void change(int index, int number) {
     
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int prevNumber = indexToNumber[index];
            numberToIndices[prevNumber].erase(index);

           
            if (numberToIndices[prevNumber].empty()) {
                numberToIndices.erase(prevNumber);
            }
        }

        
        indexToNumber[index] = number;

        
        numberToIndices[number].insert(index);
    }

    int find(int number) {
        
        if (numberToIndices.find(number) != numberToIndices.end() && !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin();
        }
        return -1;  
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */
