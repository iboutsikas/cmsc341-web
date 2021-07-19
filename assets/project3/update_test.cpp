#include "b-tree.h"
#include "distributed_index.h"
#include "data.h"


/**
 * This test will check for normal operation on add and find
 * 
 */
int main () {
    
    /**
     * Remember, the purpose of the index here is we give it the server key
     * (i.e. the key) and it will give us the index (i.e where it is located in
     * the database). We do not "fetch data" from the database in this test. We care
     * about the indices themselves!
     */
    BTree<UUID, DistributedIndex> simpleIndex (3, 2);


    for( auto index: DistributedIndices) {
        bool added = simpleIndex.try_add(index.Key, index);

        if (!added) {
            std::cout << "Failed to add: " << index << "\n";
            std::cout << "Exiting...\n";
            return 1;
        }
    }

    DistributedIndex existingIndex = DistributedIndices[6];
    // Assignment opertator, newIndex is a copy
    // Cannot change DistributedIndex::Key, otherwise the implementation becomes TOO hard
    // to still make sense
    DistributedIndex newIndex = existingIndex;
    newIndex.ServerIP = "1.1.1.1";
    newIndex.DiskSector = 42;


    if (!simpleIndex.try_update(existingIndex.Key, newIndex)) {
        std::cout << "Was not able to update index with key: 0x"  << std::hex << std::uppercase << existingIndex.Key  << std::dec << '\n'; 
        return 1;
    }

    DistributedIndex updatedIndex;

    if (!simpleIndex.try_find(existingIndex.Key, updatedIndex)) {
        std::cout << "Unable to find index after update" << std::endl;
        return 1;
    }

    if (updatedIndex.Key == newIndex) {
        std::cout << "Keys match as expected\n";
    }
    else {
        std::cout << "Keys do not match, but they should!\n";
    }


    if (updatedIndex.ServerIP == "1.1.1.1") {
        std::cout << "Server IP has been updated, as expected\n";
    }
    else {
        std::cout << "Expected the new server ip to be 1.1.1.1, but got " << updatedIndex.ServerIP << " instead\n";
    }

    if (updatedIndex.DiskSector == 42) {
        std::cout << "Disk sector was updated, as expected\n";
    }
    else {
        std::cout << "Expected new disk sector to be 42, but got " << updatedIndex.DiskSector << " instead";
    }

    /* Let's see what happens when the key and index are not in the tree */

    std::cout << "Trying to update non existing index/key combo\n";
    if (!simpleIndex.try_update(32, updatedIndex)) {
        std::cout << "try_update returned false as expected\n";
    }
    else {
        std::cout << "try_update returned true with a non existing key/index combo\n";
    }
    // updatedIndex should NOT have changed at this point

    if (updatedIndex.ServerIP == "1.1.1.1") {
        std::cout << "Server IP is still 1.1.1.1, as expected\n";
    }
    else {
        std::cout << "Expected the server ip to still  be 1.1.1.1, but got " << updatedIndex.ServerIP << " instead\n";
    }
    
    if (updatedIndex.DiskSector == 42) {
        std::cout << "Disk sector is still 42, as expected\n";
    }
    else {
        std::cout << "Expected disk sector to still be 42, but got " << updatedIndex.DiskSector << " instead";
    }

}