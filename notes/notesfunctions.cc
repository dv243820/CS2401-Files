// Linked List Containers

LLContain::LLContain()
{
    head = NULL;
}

LLContain::~LLContain()
{
    Node *rmptr;
    while (head != NULL) // continue walking head down list until null to delete entire array
    {
        rmptr = head;
        head = head->next();
        delete rmptr;
    }
}

LLContain::LLContain(const LLContain &other)
{
    if (other.head == NULL)
    {
        head = NULL;
    }
    else
    { // need a source and destination, copying array to another position
        Node *src, *dest;
        head = new Node(other.head->data());
        src = other.head->next();
        dest = head; // sets destination to first in new

        while (src != NULL)
        {
            // dest -> set_next(new Node(src -> data()));
            tmp = new Node(src->data());
            dest->set_next(tmp);

            src = src->mext();
            dest = dest->next();
        }
    }
}

LLContain &LLContain::operator=(const LLContain &other)
{
    // check for self assignment
    if (this == &other) // checks if this is equal to the address of other
    {
        return *this;
    }

    // destroy old list (deconstructor)
    Node *rmptr;
    while (head != NULL)
    {
        rmptr = head;
        head = head->next();
        delete rmptr;
    }

    // make a copy (copy constructor)
    if (other.head == NULL)
    {
        head = NULL;
    }
    else
    { // need a source and destination, copying array to another position
        Node *src, *dest;
        head = new Node(other.head->data());
        src = other.head->next();
        dest = head; // sets destination to first in new

        while (src != NULL)
        {
            // dest -> set_next(new Node(src -> data()));
            tmp = new Node(src->data());
            dest->set_next(tmp);

            src = src->mext();
            dest = dest->next();
        }
    }
}

void LLContain::add_head(int d)
{
    head = new Node(d, head);
}

void LLContain::add_end(int d)
{
    if (head == NULL)
    {
        head = new Node(d);
    }
    else
    {
        Node *cursor = head; // walk thru the list
        while (cursor->next() != NULL)
        {
            cursor = cursor->next();
        }
        cursor->set_next(new Node(d));
    }
}

void LLContain::display() const;
{
    Node *cursor *head;
    while (cursor != NULL)
    {
        cout << cursor->data() << endl;
        cursor = cursor->next();
    }
}

void LLContain::remove(int target)
{
    Node *cursor, *prev;
    cursor = head;
    if (head == NULL)
    {
        return;
    }

    if (head->data() == target)
    {
        head = head->next();
        delete cursor;
    }
    else
    {
        while (cursor != NULL && cursor->data() != target)
        {
            prev = cursor;
            cursor = cursor->next();
        }
        if (cursor != NULL)
        {
            prev->set_next(cursor->next());
            delete cursor;
        }
    }
}



