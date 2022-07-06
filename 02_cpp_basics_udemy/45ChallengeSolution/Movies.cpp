#include <iostream>
#include "Movies.h"

Movies::Movies()
{
}

Movies::~Movies()
{
}

bool Movies::movie_exists(std::string movie_name)
{
	for(Movie movie : movie_list)
	{
		if(movie.get_movie_name() == movie_name)
		{
			return true;
		}
	}
	
	return false;
}

void Movies::add_movie(std::string mov_name, std::string mov_rating, unsigned int mov_watched)
{
	
	if(!movie_exists(mov_name))
	{
		Movie movie_to_add {mov_name, mov_rating, mov_watched};
		movie_list.push_back(movie_to_add);
		std::cout << "Movie " << mov_name << " added to the database." << std::endl;
	} else {
		std::cout << "Error: The movie " << mov_name << " already exists in the database." << std::endl;
	}
	
}

void Movies::watch_movie(std::string mov_name)
{
	
	if(movie_exists(mov_name))
	{
		for(int i = 0; i < movie_list.size(); i++)
		{
			if(movie_list.at(i).get_movie_name() == mov_name)
			{
				movie_list.at(i).watch_movie();
				std::cout << "Now the movie " << mov_name << " has been watched " << movie_list.at(i).get_times_watched() << " times." << std::endl;
				break;
			}
		}
		
		
		
	} else {
		std::cout << "Error: The movie " << mov_name << " does not exists in the database." << std::endl;
	}
}

void Movies::display_movies()
{
	if(movie_list.size() == 0)
	{
		std::cout << "Sorry, no movies to display." << std::endl;
	} else {
		
		for(Movie movie : movie_list)
		{
			std::cout << movie.get_movie_name() << std::endl;
		}
	}

}