[OVERVIEW]
This is an attempt on replicating a simpler version of C++ Vector class.

[OBJECTIVE]
The project is meant to practice the Rule-Of-Five paradigm saying that:
If our class allocates memory dynamically, we must not only follow the 
Rule-Of-Three rule for adding additional assignment operator and destructor for proper handle of
the dynamically allocated memory, but now we also have to add move constructor and 
move assignment operator to avoid extra copies and maximize efficiency when possible.
AFTER ALL, C++ is all about performance!

[NOTE]
This custom Vector class does not work on custom types that do not have default constructor.
-- When using new keyword to allocate memory, C++ also calls the default constructor for the
    type.
-- A solution is to use malloc, which only allocates memory but no construction. But this is not
    the main focus of this project. 
