#include <iostream>
#include <cassert>
#include "pieceTable.hpp"

void runTests() {
    {
        // Test 1: Initial state
        _pieceTable pt("HELLO GUYS");
        assert(pt.returnText() == "HELLO GUYS");
    }

    {
        // Test 2: Single insert in middle
        _pieceTable pt("HELLO GUYS");
        pt.addText("AAA", 2);
        // H E [insert AAA] LLO GUYS
        // Expect "HEAAALLO GUYS"
        std::string got = pt.returnText();
        std::string want = "HEAAALLO GUYS";
        assert(got == want);
    }

    {
        // Test 3: Two inserts at same index
        _pieceTable pt("HELLO GUYS");
        pt.addText("AAA", 2);
        pt.addText("BBB", 2);
        // First: HEAAA LLO GUYS
        // Then insert BBB at idx 2: HE(BBB)AAA LLO GUYS
        // Expect "HEBBBAAALLO GUYS"
        std::string got = pt.returnText();
        std::string want = "HEBBBAAALLO GUYS";
        assert(got == want);
    }

    {
        // Test 4: Insert at index 0 (beginning)
        _pieceTable pt("WORLD");
        pt.addText("HELLO ", 0);
        std::string got = pt.returnText();
        std::string want = "HELLO WORLD";
        assert(got == want);
    }

    {
        // Test 5: Insert at end
        _pieceTable pt("HELLO");
        pt.addText(" WORLD", 5);
        std::string got = pt.returnText();
        std::string want = "HELLO WORLD";
        assert(got == want);
    }

    {
        // Test 6: Multiple inserts and check order
        _pieceTable pt("12345");
        pt.addText("A", 1);   // "1A2345"
        pt.addText("B", 3);   // "1A2B345"
        pt.addText("C", 0);   // "C1A2B345"
        pt.addText("D", pt.returnText().size()); // append: "C1A2B345D"
        assert(pt.returnText() == "C1A2B345D");
    }

    std::cout << "All piece-table tests passed!\n";
}

int main() {
    runTests();
    return 0;
}
