
#include "catch.hpp"

#include <type_traits>

#include "../catbook.hpp"

using namespace cb;

namespace detail {

template <typename T, typename = void>
struct has_get_item_text
        : std::false_type {
};

template <typename T>
struct has_get_item_text<T, std::enable_if_t<std::is_convertible<
        decltype(std::declval<const T&>().get_item_text()),
        std::string>::value>>
        : std::true_type {
};

}


TEST_CASE("NewsItem is an abstract base class")
{
    REQUIRE(std::is_abstract<NewsItem>::value);
}

TEST_CASE("NewsItem has a virtual destructor")
{
    REQUIRE(std::has_virtual_destructor<NewsItem>::value);
}

TEST_CASE("NewsItem has a get_item_text() public member function")
{
    REQUIRE(detail::has_get_item_text<NewsItem>::value);
}

TEST_CASE("CatPicture inherits from NewsItem")
{
    constexpr bool publicly_inherits_from_NewsItem =
            std::is_base_of<cb::NewsItem, cb::CatPicture>::value &&
                    std::is_convertible<cb::CatPicture&, cb::NewsItem&>::value;

    REQUIRE(publicly_inherits_from_NewsItem);
}