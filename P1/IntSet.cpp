#include "IntSet.h"

IntSet::IntSet()
{
    this->set = 0;
}

void IntSet::addElement(int val)
{
    // Assume val is within the domain of the set
    if (this->contains(val))
        return;

    this->set |= 1 << (val - 1);
}

void IntSet::removeElement(int val)
{
    if (!this->contains(val))
        return;

    this->set ^= 1 << (val - 1);
}

bool IntSet::contains(int val) const
{
    // Assume val is within the domain of the set

    // Right shift to the desired bit and check for one or zero
    return (this->set >> (val - 1) & 1);
}

void IntSet::printSet() const
{
    if (!this->size())
        std::cout << "{}" << std::endl;

    std::cout << "{";
    for (int i = 0, j = 0; i < number_bits; i++) // Using j to keep track of the commas.
    {

        if ((this->set >> i) & 1)
        {
            if (j != 0)
            {
                std::cout << ", ";
            }
            std::cout << (i + 1);
            j = 1;
        }
    }
    std::cout << "}" << std::endl;
}

void IntSet::printBit() const
{
    if (this->set == 0)
        std::cout << "0000000000" << std::endl;

    // i represents the position of the current bit:
    for (int i = number_bits; i > 0; i--)
    {
        std::cout << ((this->set >> i - 1) & 1);
    }

    std::cout << std::endl;
}

int IntSet::size() const
{
    if (this->set == 0)
        return 0;

    int count = 0;
    // i represents the position of the current bit:
    for (int i = number_bits; i > 0; i--)
    {
        count += ((this->set >> i - 1) & 1);
    }

    return count;
}

IntSet IntSet::unions(const IntSet &operand) const
{
    IntSet new_set;

    new_set.set = this->set | operand.set;

    return new_set;
}

IntSet IntSet::intersect(const IntSet &operand) const
{
    IntSet new_set;

    new_set.set = this->set & operand.set;

    return new_set;
}

IntSet IntSet::difference(const IntSet &operand) const
{
    return this->intersect(operand.complement());
}

IntSet IntSet::complement() const
{
    IntSet new_set;

    for (int i = 0; i < number_bits; i++)
    {
        if (!((this->set >> i) & 1))
        {
            new_set.set |= 1 << i;
        }
    }

    return new_set;
}

bool IntSet::isEqual(const IntSet &operand) const
{
    // If there is a difference in bit positions, XOR will result to a one in that position.
    // If XOR results to zero, there is no difference.
    return !(this->set ^ operand.set);
}










