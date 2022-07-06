#include <iostream>
#include "Movies.h"

using namespace std;

int main()
{
	Movies my_movie_list {};
	
	my_movie_list.display_movies();
	
	my_movie_list.add_movie("Titanic", "PG-13");
	my_movie_list.display_movies();
	
	my_movie_list.add_movie("Titanic", "PG-13");
	
	my_movie_list.add_movie("Avatar", "PG");
	my_movie_list.add_movie("Toy Story", "PG-13");
	
	my_movie_list.display_movies();
	
	my_movie_list.watch_movie("Avatar");
	my_movie_list.watch_movie("Avatar");
	
	my_movie_list.watch_movie("Titanic");
	my_movie_list.watch_movie("Titanic");
	my_movie_list.watch_movie("Titanic");
	
	my_movie_list.watch_movie("Toy Story");
	
	my_movie_list.watch_movie("Toy Story II");
	
	return 0;
}
