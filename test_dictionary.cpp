#include "catch.hpp"

#include "hash_dictionary.hpp"

#include <iostream> // for debugging
#include <sstream>  // for std::ostringstream
#include <string>   // for std::string

typedef unsigned int KeyType;
typedef std::string ValueType;
typedef std::size_t (*FunctionType)(const KeyType &key);
typedef HashDictionary<KeyType, ValueType, FunctionType> DictionaryType;

std::size_t hash(const KeyType& key) { return key; }

TEST_CASE("Basic Tests", "[Dictionary]") {

    
    DictionaryType dict(hash);

        dict.add(1, "One");
        dict.add(2, "Two");
        dict.add(3, "Three");

        REQUIRE(dict.size() == 3);
        REQUIRE(dict.get(1) == "One");
        REQUIRE(dict.get(2) == "Two");
        REQUIRE(dict.get(3) == "Three");
    
        dict.remove(2);

        REQUIRE(dict.size() == 2);
        REQUIRE(dict.contains(1));
        REQUIRE_FALSE(dict.contains(2));
        REQUIRE(dict.contains(3));

        dict.clear();

        REQUIRE(dict.isEmpty());
        REQUIRE(dict.size() == 0);
        REQUIRE_FALSE(dict.contains(1));
        REQUIRE_FALSE(dict.contains(2));
        REQUIRE_FALSE(dict.contains(3));
}

TEST_CASE("Test large Dictionary", "[Dictionary]") {


    DictionaryType dict(hash);

    for (int i = 0; i < 97; i++) {
        dict.add(i, std::to_string(i));
      
    }
    REQUIRE(dict.size() == 97);
   
    //dictionary properly increased its size if these tests pass
    for (int i = 97; i < 117; i++) {
        dict.add(i, std::to_string(i));

    }
    REQUIRE(dict.size() == 117);
    REQUIRE(dict.contains(112));
}

