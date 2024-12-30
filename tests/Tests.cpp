#include <type_traits>
#include <string>
#include <catch2/catch_test_macros.hpp>
#include "MyVector.cpp"

TEST_CASE("Basic Tests (Constructors)")
{
    SECTION("basic_default_constrcutor")
    {
        MyVector<int> v;
        REQUIRE(v.getSize() == 0);
        REQUIRE(v.getCapacity() == 32);
        REQUIRE(v.getElement(-1).has_value() == false);
        REQUIRE(v.getElement(0).has_value() == false);
        REQUIRE(v.getElement(1).has_value() == false);
    }

    SECTION("basic_copy_constructor")
    {
        MyVector<int> v1;
        for(int i = 0; i < 10; ++i)
        {
            v1.push_back(i);
        }

        MyVector<int> v2(v1);
        for(int i = 0; i < 10; ++i)
        {
            REQUIRE(v2[i] == i);
        }

        REQUIRE(v1.getSize() == v2.getSize());
        REQUIRE(v1.getCapacity() == v2.getCapacity());

    }

    SECTION("basic_move_constructor")
    {
        MyVector<int> v1;
        for(int i = 0; i < 10; ++i)
        {
            v1.push_back(i);
        }

        MyVector<int> v2(std::move(v1));
        for(int i = 0; i < 10; ++i)
        {
            REQUIRE(v2[i] == i);
        }

        REQUIRE(v1.getSize() == v2.getSize());
        REQUIRE(v1.getCapacity() == v2.getCapacity());
        REQUIRE(v1.getMArr() == nullptr);
    }

    SECTION("basic_copy_assignment")
    {
        MyVector<int> v1;
        for(int i = 0; i < 10; ++i)
        {
            v1.push_back(i);
        }

        MyVector<int> v2 = v1;
        for(int i = 0; i < 10; ++i)
        {
            REQUIRE(v1[i] == i);
            REQUIRE(v2[i] == i);
        }

        REQUIRE(v1.getSize() == v2.getSize());
        REQUIRE(v1.getCapacity() == v2.getCapacity());
        REQUIRE(v1.getMArr() != nullptr);
    }

    SECTION("basic_move_assignment")
    {
        MyVector<int> v1;
        for(int i = 0; i < 10; ++i)
        {
            v1.push_back(i);
        }

        MyVector<int> v2 = std::move(v1);
        for(int i = 0; i < 10; ++i)
        {
            REQUIRE(v2[i] == i);
        }

        REQUIRE(v1.getSize() == v2.getSize());
        REQUIRE(v1.getCapacity() == v2.getCapacity());
        REQUIRE(v1.getMArr() == nullptr);
    }
}

TEST_CASE("Basic Tests (Functionalities)")
{
    SECTION("basic_push_pop")
    {
        MyVector<int> v;
        v.push_back(20);
        REQUIRE(v[0] == 20);
        REQUIRE(v.getSize() == 1);
        REQUIRE(v.getElement(1).has_value() == false);

        v.pop_back();
        REQUIRE(v.getElement(0).has_value() == false);

        for (int i = 0; i < 31; ++i)
        {
            v.push_back(i);
        }

        REQUIRE(v.getSize() == 31);

        for (int i = 0; i < 31; ++i)
        {
            REQUIRE(v[i] == i);
        }
    }

    SECTION("basic_push_pop_2")
    {
        MyVector<int> v;
        v.push_back(20);
        REQUIRE(v[0] == 20);

        v.pop_back();
        REQUIRE(v.getElement(0).has_value() == false);

        v.push_back(15);
        REQUIRE(v[0] == 15);
    }

    SECTION("basic_access")
    {
        MyVector<int> v;
        v.push_back(20);
        REQUIRE(v[0] == 20);
        v[0] = 15;
        REQUIRE(v[0] == 15);

    }

    SECTION("basic_capacity_extension")
    {
        MyVector<int> v;
        for(int i = 0; i < 33; ++i)
        {
            v.push_back(i);
        }

        REQUIRE(v.getCapacity() == 64);
        REQUIRE(v.getSize() == 33);

        for(int i = 0; i < 33; ++i)
        {
            REQUIRE(v[i] == i);
            REQUIRE(v.getElement(33).has_value() == false);
        }
    }
}