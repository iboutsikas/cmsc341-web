#pragma once

#include <vector>

#include "person.h"
#include "b-tree.h"

static void populateTree(BTree<int, unsigned int>& tree, std::vector<Person>& employees) {
    for (size_t i = 0; i < employees.size(); i++) {
        auto& employee = employees[i];

        bool added = false;
        do {
            added = tree.try_add(employee.ID, i);

            if (!added) {
                std::cout << "Failed to add " << employee << " with index " << i << '\n';
                std::cout << "Retrying..." << std::endl;
            }
        } while(!added);
        
    }
}
