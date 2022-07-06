#ifndef MOVIES_H
#define MOVIES_H
#include <vector>
#include "Movie.h"

class Movies
{
private:
	std::vector<Movie> movie_list{};
public:
	Movies();
	~Movies();
	bool movie_exists(std::string movie_name);
	void add_movie(std::string mov_name = "Default", std::string mov_rating = "G", unsigned int mov_watched = 0);
	void watch_movie(std::string mov_name);
	void display_movies();

};

#endif // MOVIES_H
