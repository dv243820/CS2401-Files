template <class T>
class STACK : private list<T> //LIST ALREADY EXISTS
{
public:
    void push(T item) { push_front(item); }
    void pop() { pop_front(); }
    T top() const { return *begin(); }
    bool empty()const {return size() == 0;}

private:
};


int main(){
    STACK<int> s;
    s.push(2);
    s.top();
    s.push_back(17); //cannot find because it is considered private to the stack class rather than public
                     //public and private just put that entire class functions into private or public
}


//PROJECT 5
/*

main class called Product,,,,,,,,       list<Product*>

same input from file layout as last projects

create an iterator
(*it) -> output(cout);
 ^^ *it gives Product *, so we can use -> after if marked as virtual 

list<Product*>::iterator    declaring iterator same way as on project 4

pushback with tmp
really think of all the types of data being stored and what could be inputted, be specific

data file each starts with type name

shirt   <--------
long
cotton
red
shoe   <-------
black
8.5
flat

*/