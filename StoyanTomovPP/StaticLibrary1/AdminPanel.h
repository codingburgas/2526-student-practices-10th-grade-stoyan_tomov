#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <vector>
#include <string>

struct Movie {
    std::string name;
    std::vector<std::string> showtimes;
};


extern std::vector<Movie> movies;

void adminPanel();
void showtimesSection();

#endif