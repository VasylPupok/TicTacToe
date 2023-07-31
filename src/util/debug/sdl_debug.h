#pragma once

#include <stdio.h>
#include <SDL.h>

#ifdef SDL_DEBUG_ON

#define SDL_DEBUG_MSG(msg) printf("%s\n", msg);

#define SDL_ERROR_MSG(msg)\
	fprintf(stderr, "Error has occurred: %s.\nSDL error message: %s\n", msg, SDL_GetError());

#define SDL_ASSERT(statement, error_msg)\
	if (!statement) { SDL_ERROR_MSG(error_msg); }

#else

#define SDL_DEBUG_MSG(msg)
#define SDL_ERROR_MSG(msg)
#define SDL_ASSERT(statement, error_msg)

#endif


