#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie
{
private:
	std::string name;
	std::string rating;
	unsigned int watched;
public:
	Movie(std::string mov_name = "Default", std::string mov_rating = "G", unsigned int mov_watched = 0);
	~Movie();
	std::string get_movie_name() const {return name;};
	std::string get_movie_rating() const {return rating;};
	unsigned int get_times_watched() const {return watched;};
	void watch_movie() {++watched;} const;
};

#endif // MOVIE_H
