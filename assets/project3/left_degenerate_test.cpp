#include <iostream>
#include <vector>

#include "b-tree.h"
#include "person.h"
#include "data.h"
#include "utils.h"


/**
 * This test will try to populate the tree with keys that are in strictly
 * decreasing order. This will generate a degenerate tree that leans to the
 * left! (also known as a way too compilcated list)
 */
int main () {
    
    /**
     * Remember, the purpose of the index here is we give it the employee id
     * (i.e. the key) and it will give us the index (i.e where it is located in
     * the database)
     */
    BTree<int, unsigned int> simpleIndex (3, 3);

    auto& employees = Employees_Descending;

    populateTree(simpleIndex, employees);

    for (auto& expected : employees) {

        unsigned int index(-1);

        bool found = false;

        found = simpleIndex.try_find(expected.ID, index);

        if (!found) {
            std::cout<< "Key " << expected.ID << " was not found, when it should be in the tree!" << std::endl;
            continue;
        }

        /**
         * If index was not modifed it will be a HUUUUUUGE value since -1 as unsiged int
         * is the same as the max value of unsigned int (a bit over 4 billion)
         */
        if (index >= employees.size()) {
            std::cout << "Asked for key: " << expected.ID << " end got index: " << index << '\n';
            std::cout << "This value is outside the range of Employees_Descending: [0, " << employees.size() -1 << "]";
            std::cout << std::endl;
            continue;
        }

        // Use the index to fetch the employee
        auto& actual = employees[index];

        // Let's make sure we got the correct employee (and by extension index)
        if (expected.ID != actual.ID) {
            std::cout << "We got the wrong index, and therfore the wrong employee back.\n";
            std::cout << "Expected: \n";
            std::cout << "\t" << expected << '\n';
            std::cout << "Instead got:\n";
            std::cout << "\t" << actual << '\n';
            std::cout << "Value of index was " << index << std::endl;
            continue;
        }

        std::cout << "Found employee: " << actual << std::endl;
    }
    
    return 0;
}