//
// Created by jake on 9/9/22.
//
int *ptr;

cout << ptr;  // 0xF34A (address pointer is storing)
cout << &ptr; // 0x5412 (address where pointer is stored)
cout << *ptr; // 8 (value stored in the address that the pointer is storing)

ptr = new int;

delete ptr; // deletes the value which ptr is pointing to

ptr = new int;

int *data; // init array with pointers

data = new int[4]; // pt 2

data[0] = 3; // sets array value at 0 to 3 (works normally)

delete[] array; // removes entire array (data is pointing to first address)

class Dcontain
{
public:
    Dcontain();

    // THE BIG 3
    ~Dcontain(); // deconstructor

    // copy ctor (creates new object that is a copy)
    Dcontain(const &Dcontain other);
    void operator=(const &Dcontain other);
    void add_item(double new);

private:
    double *data;
    int used;
    int size;

    void resize();
};

Dcontain::Dcontain()
{
    size = 5;
    data = new double[size];
    used = 0;
}

void Dcontain::add_item(double new)
{
    if (used == size)
    {
        resize();
    }
    data[used] = new;
    used++;
}

void Dcontain::resize()
{
    // allocate a new array
    double *tmp;
    tmp = new double[size + 5];
    // copy everything
    for (int i = 0; i < used; ++i)
    {
        tmp[i] = data[i];
    }
    // alternative copy #include <algorithm>
    // copy(begin, end, destination);
    // copy(data, data + used, tmp);

    delete[] data;
    data = tmp;
    size += 5;
}
// THE BIG THREE DEFINITIONS
Dcontain::Dcontain(const &Dcontain other)
{
    used = other.used;
    size = other.size;

    data = new double[size];
    copy(other.data, other.data + other.used, data); // MUST #include <algorithm>
}

Dcontain::~Dcontain()
{
    delete[] data;
}

void operator=(const &Dcontain other)
{
    // check for self assignment
    if (this == &other)
    {
        return;
    }
    // deallocate old aray
    delete[] data;
    // make a copy
    used = other.used;
    size = other.size;
    data = new double[size];
    copy(other.data, other.data + other.used, data);
}