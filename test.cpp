// tests.cpp
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main function
#include "catch.hpp"       // Include Catch2 header

// Splits a single string on separator into a vector of strings
std::vector<std::string> Split(std::string whole, std::string separator){
	std::vector<std::string> result;
    size_t pos = 0;
    
    // Loop until no separator is found
    while ((pos = whole.find(separator)) != std::string::npos) {
        result.push_back(whole.substr(0, pos));  // Add substring before the separator
        whole.erase(0, pos + separator.length()); // Remove the processed part of the string
    }
    
    // Add the remaining part of the string (after the last separator)
    if (!whole.empty()) {
        result.push_back(whole);
    }

    return result;
}

std::string RemoveAllSubstrings(std::string s1, std::string s2) {
    size_t pos = 0;
    
    // While we can find s2 in s1
    while ((pos = s1.find(s2, pos)) != std::string::npos) {
        // Erase the occurrence of s2
        s1.erase(pos, s2.length());
    }

    return s1;
}


// Test case for the Split function
TEST_CASE("Split works correctly", "[Split]") {
    REQUIRE(Split("apple,banana,cherry", ",") == std::vector<std::string>{"apple", "banana", "cherry"});
    REQUIRE(Split("apple;banana;cherry", ";") == std::vector<std::string>{"apple", "banana", "cherry"});
    REQUIRE(Split("apple", ",") == std::vector<std::string>{"apple"}); // No separator
    REQUIRE(Split("", ",") == std::vector<std::string>{}); // Empty string
}

// Test case for the RemoveAllSubstrings function
TEST_CASE("RemoveAllSubstrings works correctly", "[RemoveAllSubstrings]") {
    REQUIRE(RemoveAllSubstrings("hello world, hello universe", "hello") == " world,  universe");
    REQUIRE(RemoveAllSubstrings("abcabcabc", "abc") == "");
    REQUIRE(RemoveAllSubstrings("apple pie apple", "apple") == " pie ");
    REQUIRE(RemoveAllSubstrings("hello", "x") == "hello"); // No match
}
