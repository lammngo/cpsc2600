#ifndef HW3_INTSET_H
#define HW3_INTSET_H

#include <iostream>

#define UNIVERSAL_SET_CARDINALITY 10
#define BITSET_SIZE 1024 // 2^10

using namespace std;

typedef unsigned short bit;

class IntSet
{

private:
    //Complete the private section of the class
    bit set;

public:
    static constexpr short number_bits = UNIVERSAL_SET_CARDINALITY;
    static constexpr short set_capacity = BITSET_SIZE;
    // Default constructor: the domain of the set is {1, 2, 3, ..., 10}.
    // The set is initially a null set.
    IntSet();

    // Adds the value to the set if not already an element.
    void addElement(int val);

    // Removes the value if it is in the set.
    // Nothing happens if the value is not in the set.
    void removeElement(int val);

    // Returns true if the set contains the value.
    // Returns false otherwise.
    bool contains(int val) const;

    // Displays the set to the screen in the format: {1, 3, 4}
    void printSet() const;

    // Displays the set to the screen using the bit string format.
    void printBit() const;

    // Returns the number of elements in the set.
    int size() const;

    IntSet unions(const IntSet &operand) const;

    IntSet intersect(const IntSet &operand) const;

    IntSet difference(const IntSet &operand) const;

    IntSet complement() const;

    bool isEqual(const IntSet &operand) const;
};

#endif //HW3_INTSET_H
