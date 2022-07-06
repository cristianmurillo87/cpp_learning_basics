#include "Movie.h"

Movie::Movie(std::string mov_name, std::string mov_rating, unsigned int mov_watched)
	:name{mov_name}, rating{mov_rating}, watched{mov_watched} {
}

Movie::~Movie()
{
}
