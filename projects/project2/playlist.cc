/**
 *        @file: Untitled-1
 *      @author: Drew VanAtta
 *        @date: September 17, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include "Playlist.h"

using namespace std;

/**
 * Playlist - default constructor
 */
Playlist::Playlist()
{
    capacity = 5;
    data = new Song[capacity]; // creates an array for data to point to
    used = 0;
}

// The Big 3
/**
 * ~Playlist - deconstructor
 */
Playlist::~Playlist() // deconstructor
{
    delete[] data;
}

/**
 * Playlist - copies the playlist passed thru
 * @param other - a playlist that is copied
 */
Playlist::Playlist(const Playlist &other) // copy
{
    used = other.used;
    capacity = other.capacity;
    data = new Song[capacity];
    copy(other.data, other.data + used, data);
}

/**
 * operator= - overloading the = operator to use our playlist class
 * @param other - a playlist that is copied
 */
void Playlist::operator=(const Playlist &other)
{
    if (this == &other)
    {
        return;
    }
    delete[] data;
    used = other.used;
    capacity = other.capacity;
    data = new Song[capacity];
    for (int i = 0; i < used; i++)
    {
        data[i] = other.data[i];
    }
}

// Functions for the internal iterator

/**
 * start - resets the current_index to zero
 */
void Playlist::start()
{
    current_index = 0; // resets the current index
}

/**
 * advance - increases the current_index by one
 */
void Playlist::advance()
{
    current_index++; // advances the current index
}

/**
 * is_item - checks if the current index is less than used
 * @return bool, true or false
 */
bool Playlist::is_item() const
{
    return (current_index < used); // checks if current index is less than used
}

/**
 * current - returns the song of the current index of the playlist
 * @return the song of the current index
 */
Song Playlist::current() const
{
    return (data[current_index]); // returns the song of the current inde
}

/**
 * remove_current - removes the current song in the array
 */
void Playlist::remove_current()
{
    for (int i = current_index; i < used; i++)
    {
        data[i] = data[i + 1]; // copies all from the right over
    }
    used--;
}

/**
 * insert - inserts a song into the array
 * @param s - a song to be inserted
 */
void Playlist::insert(const Song &s)
{
    if (used == capacity) // first got to resize if it cant fit any more
    {
        resize();
    }
    if (used > 0)
    {
        for (int i = used - 1; i >= current_index; i--) // start from the right, and copy it over one
        {
            data[i + 1] = data[i];
        }
    }
    data[current_index] = s;
    used++;
}

/**
 * attach - attaches a song after the current index
 * @param s - song to be attached
 */
void Playlist::attach(const Song &s) // exact same as insert but it inserts it a spot up
{
    if (used == capacity)
    {
        resize();
    }
    if (used > 0)
    {
        for (int i = used - 1; i > current_index; i--) // got rid of = so that it works correctly
        {
            data[i + 1] = data[i];
        }
    }
    data[current_index + 1] = s; // heres where the difference is. Current index + 1 so that it adds it to the right
    used++;
}

/**
 * show_all - shows all the songs in the 
 * @param outs - the stream of which will be used
 */
void Playlist::show_all(std::ostream &outs) const
{
    for (int i = 0; i < used; i++) // goes thru array outputs all used spots
    {
        outs << data[i] << endl;
    }
}

/**
 * releaseDate_sort() - sorts the array by release date
 */
void Playlist::releaseDate_sort() // generic bubble sort
{
    int i, upper_bound = used - 1;
    Song tmp;
    bool done = false;

    while (!done)
    {
        done = true;

        for (i = 0; i < upper_bound; i++)
        {
            if (data[i].get_release() > data[i + 1].get_release())
            {
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;

                done = false;
            }
        }
        upper_bound--;
    }
}

/**
 * artist_sort - sorts the array by artist
 */
void Playlist::artist_sort() // generic bubble sort
{
    int i, upper_bound = used - 1;
    Song tmp;
    bool done = false;

    while (!done)
    {
        done = true;

        for (i = 0; i < upper_bound; i++)
        {
            if (data[i].get_artist() > data[i + 1].get_artist())
            {
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;

                done = false;
            }
        }
        upper_bound--;
    }
}

/**
 * find_song - finds if the song is in the array and returns it
 * @param name - name of the song to be found
 * @param artist - artist of the song
 * @return the song if found
 */
Song Playlist::find_song(const std::string &name, const std::string &artist) const
{
    for (int i = 0; i < used; i++)
    {
        if (data[i].get_artist() == artist && data[i].get_name() == name) // checks if name and artist are the same (in order for it to be the same)
        {
            return (data[i]); // returns the Song of where it is in the array
        }
    }

    // will only run if song wasn't found because return in loop
    cout << "Song not found" << endl;
    return Song();
}

/**
 * is_song - returns a bool value of if the song is found
 * @param s - song to be compared with
 * @return true or false
 */
bool Playlist::is_song(const Song &s) const
{
    for (int i = 0; i < used; i++) // this loop only can return true if it finds a song
    {
        if (data[i] == s)
        {
            return true;
        }
    }
    return false; // will only do if it gets through the loop and cant find the song
}

/**
 * load - loads a playlist from songs from a file
 * @param ins - the input stream
 */
void Playlist::load(std::istream &ins)
{
    Song a;
    while (!ins.eof()) // while not the end of the file
    {

        a.input(ins); // uses the input from song.cc
        insert(a);
    }
}

/**
 * save - saves the playlist by outputting the songs to a file
 * @param outs - the output stream
 */
void Playlist::save(std::ostream &outs) const
{
    for (int i = 0; i < used; i++)
    {
        outs << data[i];
        if (i + 1 < used)
        {
            outs << endl;
        }
    }
}

/**
 * resize - resizes the array when there are no spaces left. does this by copying the playlist to a new one with capacity + 5
 */
void Playlist::resize() // resizes the playlist to add five slots for data
{
    Song *tmp;
    tmp = new Song[capacity + 5];
    std::copy(data, data + used, tmp);
    capacity += 5;
    delete[] data;
    data = tmp;
}