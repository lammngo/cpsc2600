#include <iostream>
#include "IntSet.h"

using namespace std;

void print_bit(unsigned int set)
{
    if (set == 0)
        cout << "0000000000" << endl;

    for (int i = 10; i > 0; i--)
    {
        cout << ((set >> i - 1) & 1);
    }

    cout << endl;
}

int main()
{
    IntSet a;
    IntSet b;
    IntSet c;

    //Tests written here
    // 1.a.
    for (int i = 2; i <= IntSet::number_bits; i += 2)
        a.addElement(i);

    // 1.b.
    for (int i = 3; i <= IntSet::number_bits; i += 3)
        b.addElement(i);

    // 1.c.
    c.addElement(1);
    c.addElement(2);
    c.addElement(4);
    c.addElement(6);
    c.addElement(9);

    // 2.a.
    IntSet d = a.complement();

    // 2.b.
    IntSet e = a.unions(b);

    // 2.c.
    IntSet f = b.intersect(c);

    // 2.d.
    IntSet g = a.difference(b);

    // 2.e.
    IntSet h = b.unions(a.intersect(c));

    // 2.f.
    IntSet i = (a.unions(b)).difference(c);

    // 3.
    a.printBit();
    b.printBit();
    c.printBit();

    // 4.
    d.printSet();
    e.printSet();
    f.printSet();
    g.printSet();
    h.printSet();
    i.printSet();

    // 5.
    std::cout << "6 in H? " << (h.contains(6) ? "true" : "false") << std::endl;
    std::cout << "2 in D? " << (d.contains(2) ? "true" : "false") << std::endl;

    return 0;
}
