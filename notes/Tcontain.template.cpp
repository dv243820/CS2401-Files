// Drew VanAtta - notes
// 10/10/22    --- templates continued
// make a template class

template <class T>
Tcontain<T>::Tcontain() //<T> needed for scope resolution
{
    used = 0;
}

template <class T>
void Tcontain<T>::add(const T &item)
{
    data[used] = item;
    used++;
}

template <class T> // THIS IS NEEDED BEFORE EVERY ONE
void Tcontain<T>::display(std::ostream &outs) const;
{
    for (int i = 0; i < used; i++)
    {
        outs << data[i] << endl;
    }


//how to use template class now
#include "Tcontain.h" //include at the top of the main.cc file

int main(){
    //use <type> when I instantiate
    Tcontain<int> nums;
    Tcontain<double> decimals;
    Tcontain<Song> songs;
    Tcontain<refrigerator> fridge;


    nums.add(1);
    decimals.add(3.14);
    nums.display();
    decimals.display(); //can call same funciton on different types

    //doesn't matter what type, we can do whatever
};

/*if I use the name of the template class outside the .h, I must follow up with ankle brackets <T>
when outside of definition (main, other application), ankle brackets and type needed inside (duh)

*/



