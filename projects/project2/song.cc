/**
 *        @file: Untitled-1
 *      @author: Drew VanAtta
 *        @date: September 16, 2022
 *       @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Song.h"
#ifndef SONG
#define SONG
using namespace std;

Song::Song()
{
    // I wasn't sure what to do for these so just made them blank as default
    name = "";
    release = Date();
    artist = "";
}

string Song::get_name() const
{
    return name;
}
Date Song::get_release() const
{
    return release;
}
string Song::get_artist() const
{
    return artist;
}

bool Song::operator==(const Song &other) const
{
    return (other.release == release && other.name == name && other.artist == artist);
}

bool Song::operator!=(const Song &other) const
{
    return (!(other.release == release && other.name == name && other.artist == artist));
}

void Song::input(istream &ins)
{

    if (&ins == &cin)
    {

        cout << "Enter the song name: " << endl;
        while (ins.peek() == '\n' || ins.peek() == '\r') // switching from ins >> to getline, used from class example
        {
            ins.ignore();
        }
        getline(ins, name);
        cout << "Enter the release date in MM/DD/YYYY format: " << endl;
        ins >> release;
        cout << "Enter the artist of the song: " << endl;
        while (ins.peek() == '\n' || ins.peek() == '\r') // switching from ins >> to getline, used from class example
        {
            ins.ignore();
        }
        getline(ins, artist);
    }
    else
    {
        getline(ins, name);
           // cout << name << endl;
        ins >> release;
           // cout << release << endl;
        while (ins.peek() == '\n' || ins.peek() == '\r')
        {
            ins.ignore();
        }
        getline(ins, artist);
            //cout << artist << endl; left over while testing, kept in as documentation
    }
}
void Song::output(ostream &outs) const
{
    if (&outs == &cout)
    {
        outs << "Song: " << name << endl;
        outs << "Release Date: " << release << endl;
        outs << "Artist : " << artist << endl;
    }
    else
    {
        outs << name << endl;
        outs << release << endl;
        outs << artist; // no endl here, in playlist.cc so it doesnt output to file
    }
}

istream &operator>>(std::istream &ins, Song &s)
{
    s.input(ins);
    return ins;

}
ostream &operator<<(std::ostream &outs, const Song &s)
{
    s.output(outs);
    return outs;
}
#endif