
#include "catch.hpp"

#include <type_traits>

#include "../catbook.hpp"

namespace detail {

template <typename...> using void_t = void;

template <typename T, typename = void>
struct has_like
        : std::false_type {
};

template <typename T>
struct has_like<T, void_t<
            decltype(std::declval<T&>().like())
        >>
        : std::true_type {
};

template <typename T, typename = void>
struct has_get_num_likes
        : std::false_type {
};

template <typename T>
struct has_get_num_likes<T, std::enable_if_t<std::is_convertible<
        decltype(std::declval<const T&>().get_num_likes()),
        int>::value>>
        : std::true_type {
};



}


TEST_CASE("CatPicture base class has a like() member function")
{
    REQUIRE(detail::has_like<cb::CatPicture>::value);
}

TEST_CASE("CatPicture base class has a get_num_likes() member function")
{
    REQUIRE(detail::has_get_num_likes<cb::CatPicture>::value);
}