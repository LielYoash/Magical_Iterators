#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("MagicalContainer"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(1);
    CHECK(container.size() == 1);
    container.removeElement(1);
    CHECK(container.size() == 0);
    // delete &container;
    CHECK_THROWS_AS(container.size(), std::exception);
}

TEST_SUITE("AscendingIterator"){
    TEST_CASE("Constructor & Destructor"){
        MagicalContainer container;
        container.addElement(1);
        container.addElement(8);
        container.addElement(6);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::AscendingIterator iterator(container);
        CHECK(iterator.operator*() == 1);
        CHECK(iterator.operator++().operator*() == 6);
        MagicalContainer::AscendingIterator iterator2(iterator);
        CHECK(iterator2.operator*() == 6);
        // delete &iterator;
        // delete &iterator2;
        CHECK_THROWS_AS(iterator.operator*(), std::exception);
        CHECK_THROWS_AS(iterator2.operator*(), std::exception);
    }

    TEST_CASE("Operators"){
        MagicalContainer container;
        container.addElement(1);
        container.addElement(8);
        container.addElement(6);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::AscendingIterator iterator(container);
        MagicalContainer::AscendingIterator iterator2(container);
        CHECK(iterator.operator*() == 1);
        CHECK(iterator2.operator*() == 1);
        CHECK(iterator==iterator2);
        CHECK(iterator++.operator*() == 6);
        CHECK_FALSE(iterator==(iterator2));
        CHECK(iterator!=iterator2);
        CHECK(iterator>iterator2);
        CHECK_FALSE(iterator2<iterator);
        CHECK(iterator == ++iterator2);
        iterator2++;
        CHECK(iterator2.operator*() == 8);
        CHECK_FALSE(iterator>iterator2);
        CHECK(iterator<iterator2);
        MagicalContainer::AscendingIterator iterator3(container);
        iterator3 = iterator2;
        CHECK(iterator3.operator*() == 8);
        }
    
    TEST_CASE("Methods"){
        MagicalContainer container;
        container.addElement(1);
        container.addElement(8);
        container.addElement(6);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::AscendingIterator iterator(container);
        iterator.begin();
        CHECK(iterator.operator*() == 1);
        iterator.end();
        CHECK(iterator.operator*() == 15);
        container.removeElement(1);
        iterator.begin();
        CHECK(iterator.operator*() == 6);
        container.removeElement(15);
        iterator.end();
        CHECK(iterator.operator*() == 8);
    }
}

TEST_SUITE("SideCrossIterator"){
    TEST_CASE("Constructor & Destructor"){
        MagicalContainer container;
        container.addElement(1);
        container.addElement(8);
        container.addElement(6);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::SideCrossIterator iterator(container);
        CHECK(iterator.operator*() == 15);
        CHECK(iterator.operator++().operator*() == 6);
        MagicalContainer::SideCrossIterator iterator2(iterator);
        CHECK(iterator2.operator*() == 6);
        // delete &iterator;
        // delete &iterator2;
        CHECK_THROWS_AS(iterator.operator*(), std::exception);
        CHECK_THROWS_AS(iterator2.operator*(), std::exception);
    }

    TEST_CASE("Operators"){
        MagicalContainer container;
        container.addElement(1);
        container.addElement(8);
        container.addElement(6);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::SideCrossIterator iterator(container);
        MagicalContainer::SideCrossIterator iterator2(container);
        CHECK(iterator.operator*() == 1);
        CHECK(iterator2.operator*() == 1);
        CHECK(iterator==iterator2);
        CHECK(iterator++.operator*() == 15);
        CHECK_FALSE(iterator==(iterator2));
        CHECK(iterator!=iterator2);
        CHECK(iterator>iterator2);
        CHECK_FALSE(iterator2<iterator);
        CHECK(iterator == ++iterator2);
        iterator2++;
        CHECK(iterator2.operator*() == 8);
        CHECK_FALSE(iterator>iterator2);
        CHECK(iterator<iterator2);
        MagicalContainer::SideCrossIterator iterator3(container);
        iterator3 = iterator2;
        CHECK(iterator3.operator*() == 8);
        }
    
    TEST_CASE("Methods"){
        MagicalContainer container;
        container.addElement(1);
        container.addElement(8);
        container.addElement(6);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::SideCrossIterator iterator(container);
        iterator.begin();
        CHECK(iterator.operator*() == 1);
        iterator.end();
        CHECK(iterator.operator*() == 15);
        container.removeElement(1);
        iterator.begin();
        CHECK(iterator.operator*() == 8);
        container.removeElement(15);
        iterator.end();
        CHECK(iterator.operator*() == 6);
    }
}

TEST_SUITE("PrimeIterator"){
    TEST_CASE("Constructor & Destructor"){
        MagicalContainer container;
        container.addElement(2);
        container.addElement(8);
        container.addElement(5);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::PrimeIterator iterator(container);
        CHECK(iterator.operator*() == 2);   
        CHECK(iterator.operator++().operator*() == 5);
        MagicalContainer::PrimeIterator iterator2(iterator);
        CHECK(iterator2.operator*() == 2);
        // delete &iterator;
        // delete &iterator2;
        CHECK_THROWS_AS(iterator.operator*(), std::exception);
        CHECK_THROWS_AS(iterator2.operator*(), std::exception);
    }

    TEST_CASE("Operators"){
        MagicalContainer container;
        container.addElement(2);
        container.addElement(8);
        container.addElement(5);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::PrimeIterator iterator(container);
        MagicalContainer::PrimeIterator iterator2(container);
        CHECK(iterator.operator*() == 2);
        CHECK(iterator2.operator*() == 2);
        CHECK(iterator==iterator2);
        CHECK(iterator++.operator*() == 5);
        CHECK_FALSE(iterator==(iterator2));
        CHECK(iterator!=iterator2);
        CHECK(iterator>iterator2);
        CHECK_FALSE(iterator2<iterator);
        CHECK(iterator == ++iterator2);
        iterator2++;
        CHECK(iterator2.operator*() == 8);
        CHECK_FALSE(iterator>iterator2);
        CHECK(iterator<iterator2);
        MagicalContainer::PrimeIterator iterator3(container);
        iterator3 = iterator2;
        CHECK(iterator3.operator*() == 8);
        }
    
    TEST_CASE("Methods"){
        MagicalContainer container;
        container.addElement(2);
        container.addElement(8);
        container.addElement(5);
        container.addElement(15);
        CHECK(container.size() == 4);
        MagicalContainer::PrimeIterator iterator(container);
        iterator.begin();
        CHECK(iterator.operator*() == 2);
        iterator.end();
        CHECK(iterator.operator*() == 5);
        container.removeElement(2);
        iterator.begin();
        CHECK(iterator.operator*() == 5);
        iterator.end();
        CHECK(iterator.operator*() == 5);
    }
}

