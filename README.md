
C++ London University Week 14 Inheritance Exercise
==================================================

Congratulations! You have been appointed as Chief Technology Officer for 
*CatBook*, a new social media start-up which allows users to post pictures of 
their cats.


Task 1
------

A user's *news feed* consists of cat pictures. There are two types of pictures
that *CatBook* supports: cute cats and grumpy cats.

1. Write an *abstract base class* `CatPicture` with a *pure virtual member function*
   `std::string get_description() const`.
   
2. Write a class `CuteCatPicture` which inherits from `CatPicture`. Its constructor
   should take an argument which is a `std::string` of the cat's name. It should
   implement `get_description()`, returning the string
   
   > A picture of `<cat name>` looking adorably cute
   
   where `<cat name>` was the name provided to the `CuteCatPicture` constructor.
   
3. Write another similar class `GrumpyCatPicture` which again inherits from `CatPicture`,
   and again allows you to pass the cat name to its constructor. This time,
   the implementation of `get_description()` should return 
   
   > A picture of `<cat name>` looking really grumpy
   
Task 2
------

Hooray, *CatBook* is starting to attract users! It's time to take this opportunity
to improve your code. The `CuteCatPicture` and `GrumpyCatPicture` subclasses do
very similar things: you can move some of this common code into the `CatPicture`
base class.

1. Add a constructor to the `CatPicture` base class which
   takes a `std::string` and stores it in a field named `cat_name`.
   Add a member function `get_cat_name()` *which only derived classes may call*.
   
2. Refactor your `CuteCatPicture` and `GrumpyCatPicture` subclasses to call the
   new base class constructor. Use the new `get_cat_name()` function in each
   implementation of `get_description()`.
   
3. Everybody likes cat pictures. Add a new member function `like()` which, when
   called, increments the `like_count` of a picture. Add a member function
   `get_num_likes()` which returns a picture's current `like_count`.
   
Task 3
------

Oh no, your investor funding has run out! *CatBook* needs to make money, fast.

We need to remodel the code so that body `CatPicture`s and `Advert`s can be
displayed in the news feed.

 1. Add a new abstract base class `NewsItem` which represents an item in the
    news feed. This class should have a `get_item_text()` pure virtual member
    function.
    
 2. Make `CatPicture` inherit from `NewsItem`, and implement `get_item_text()`
    appropriately.
    
 3. Write an `Advert` class which takes a `std::string slogan` in its constructor.
    Implement the `get_item_text()` function so that it returns the `slogan`.
    

