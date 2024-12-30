#include <algorithm>
#include <iomanip>
#include <optional>

template <typename T>
class MyVector
{
public:
    // Default Constructor
    // If no init val given,
    /**
     * @brief Construct a new My Vector object
     *
     * @param size optional
     * @param val optional
     * If size not specified --
     *      Allocate a vector with size = 0, capacity = 32
     * If size specified --
     *      Allocate a vector with size = #, capacity = max(32, 2 * #)
     *
     */
    MyVector(int size = 0)
        : mCapacity(std::move(size * 2)), mSize(std::move(size))
    {
        if (mCapacity == 0)
        {
            mCapacity = std::max(32, mCapacity);
        }

        mArr = new T[mCapacity];
    }

    // Copy Constructor
    MyVector<T>(const MyVector &other)
        : mCapacity(std::move(other.mCapacity)), mSize(std::move(other.mSize))
    {
        mArr = new T[mCapacity];
        for (int i = 0; i < mSize; ++i)
        {
            mArr[i] = other.mArr[i];
        }
    }

    // Move Constructor
    MyVector<T>(MyVector &&other)
        : mCapacity(std::move(other.mCapacity)), mSize(std::move(other.mSize)), mArr(std::move(other.mArr))
    {
        // need to set other's mArr to nullptr
        // (So that when other is destructed the actual vector won't be destructed)
        other.mArr = nullptr;
    }

    // Copy Assignment Operator
    MyVector operator=(const MyVector &other)
    {
        if (this != &other)
        {
            delete[] mArr;

            mCapacity = other.mCapacity;
            mSize = other.mSize;
            mArr = new T[mCapacity];

            for(int i = 0; i < mCapacity; ++i)
            {
                mArr[i] = other[i];
            }
        }

        return *this;
    }

    // Move Assignment Operator
    MyVector operator=(MyVector &&other)
    {
        if (this != &other)
        {
            delete[] mArr;

            mCapacity = std::move(other.mCapacity);
            mSize = std::move(other.mSize);
            mArr = std::move(other.mArr);
            other.mArr = nullptr;
        }

        return *this;
    }

    // Destructor
    ~MyVector()
    {
        delete[] mArr;
    };

    /* ------------------- [ Supporting Basic Functionalities ] ------------------- */
    void push_back(int val)
    {
        // Expand dynamic array
        if (mSize == mCapacity)
        {
            mCapacity = std::move(mSize * 2);
            T *newArr = new T[mCapacity];

            for (int i = 0; i < mSize; ++i)
            {
                newArr[i] = mArr[i];
            }

            delete[] mArr;
            mArr = newArr;
        }

        mArr[mSize] = std::move(val);
        ++mSize;

        return;
    }

    void pop_back()
    {
        --mSize;
        return;
    }

    int getSize() { return mSize; }
    int getCapacity() { return mCapacity; }
    // Return by reference to allow assignment
    T &operator[](const int &i)
    {
        return mArr[i];
    }

    /* ------------------- [ For Unit Teesting ] ------------------- */
    std::optional<T> getElement(int i)
    {
        if (i >= 0 && i < mSize)
        {
            return mArr[i];
        }
        return {};
    };

    T *getMArr() { return mArr; }

private:
    int mCapacity; // The total capacity of this dynamic array
    int mSize;     // The current size of this dynamic array (# of active elements)
    T *mArr;
};