
#include "catch.hpp"
#include <type_traits>

#include "../catbook.hpp"

namespace detail {

template <typename...>
using void_t = void;

template <typename T, typename = void>
struct has_get_description
        : std::false_type {
};

template <typename T>
struct has_get_description<T, std::enable_if_t<std::is_convertible<
        decltype(std::declval<const T&>().get_description()),
        std::string>::value>>
        : std::true_type {
};

template <typename T, typename = void>
struct do_get_description_test {
    bool operator()(const std::string& name, const std::string& expected) const
    {
        return false;
    }
};

template <typename T>
struct do_get_description_test<T, std::enable_if_t<
        std::is_constructible<T, const std::string&>::value>> {
    bool operator()(const std::string& name, const std::string& expected) const
    {
        const T pic(name);
        return pic.get_description() == expected;
    }
};


}

TEST_CASE("CatPicture is an abstract base class")
{
    REQUIRE(std::is_abstract<cb::CatPicture>::value);
}

TEST_CASE("CatPicture has a virtual destructor")
{
    REQUIRE(std::has_virtual_destructor<cb::CatPicture>::value);
}

TEST_CASE("CatPicture has a get_description() public member function")
{
    REQUIRE(detail::has_get_description<cb::CatPicture>::value);
}

TEST_CASE("CuteCatPicture inherits from CatPicture")
{
    constexpr bool publicly_inherits_from_CatPicture =
            std::is_base_of<cb::CatPicture, cb::CuteCatPicture>::value &&
            std::is_convertible<cb::CuteCatPicture&, cb::CatPicture&>::value;

    REQUIRE(publicly_inherits_from_CatPicture);
}

TEST_CASE("CuteCatPicture is not abstract")
{
    REQUIRE_FALSE(std::is_abstract<cb::CuteCatPicture>::value);
}

TEST_CASE("CuteCatPicture can be constructed from a string")
{
    REQUIRE(std::is_constructible<cb::CuteCatPicture, const std::string&>::value);
}

TEST_CASE("CuteCatPicture::get_descirption() is implemented correctly")
{
    REQUIRE(detail::do_get_description_test<cb::CuteCatPicture>{}(
        "Mr Fluffy", "A picture of Mr Fluffy looking adorably cute"));
}


TEST_CASE("GrumpyCatPicture inherits from CatPicture")
{
    constexpr bool publicly_inherits_from_CatPicture =
            std::is_base_of<cb::CatPicture, cb::GrumpyCatPicture>::value &&
                    std::is_convertible<cb::GrumpyCatPicture&, cb::CatPicture&>::value;

    REQUIRE(publicly_inherits_from_CatPicture);
}

TEST_CASE("GrumpyCatPicture is not abstract")
{
    REQUIRE_FALSE(std::is_abstract<cb::GrumpyCatPicture>::value);
}

TEST_CASE("GrumpyCatPicture can be constructed from a string")
{
    REQUIRE(std::is_constructible<cb::GrumpyCatPicture, const std::string&>::value);
}

TEST_CASE("GrumpyCatPicture::get_descirption() is implemented correctly")
{
    REQUIRE(detail::do_get_description_test<cb::GrumpyCatPicture>{}(
            "Mr Fluffy", "A picture of Mr Fluffy looking really grumpy"));
}
