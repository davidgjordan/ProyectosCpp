#ifndef FILEENUMS_H_
#define FILEENUMS_H_

enum class MessageFiles
{
	DONTEXIST,
	EMPTY,
	BAD,
	EXIST,
	GOOD,
	BADFORMAT,
	GOODFORWORK
};

enum class ModeFiles
{
	WRITE,
	READ,
};

#endif //FILEENUMS_H_