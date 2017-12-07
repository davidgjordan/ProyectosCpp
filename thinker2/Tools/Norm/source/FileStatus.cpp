
#include <FileStatus.h>

bool IsFileExist(fstream& file)
{
	 return (file.is_open()) ? true : false;
}

bool IsFileGood(fstream& file)
{
	return (file.good()) ? true : false;
}

bool IsFileEmpty(fstream& file)
{
	return (file.peek() == EOF) ? true : false;
}

MessageFiles VerifyFile(fstream& file, string fileName, ModeFiles mode)
{
	switch(mode)
	{
		case ModeFiles::READ:
		{
			file.open(fileName, ios::in);

			if(IsFileExist(file))
			{
				if(IsFileEmpty(file))
				{
					return MessageFiles::EMPTY;
				}
				else
				{
					if(IsFileGood(file))
					{
						return MessageFiles::GOODFORWORK;
					}
					else
					{
						return MessageFiles::BAD;
					}
				}
			}
			else
			{
				return MessageFiles::DONTEXIST;
			}

		}
		break;
		case ModeFiles::WRITE:
		{
			file.open(fileName, ios::out);

			if(IsFileExist(file))
			{
				return MessageFiles::EXIST;
			}
			else
			{
				return MessageFiles::GOODFORWORK;
			}
		}
		break;
		default:
		{
			return MessageFiles::BADFORMAT;
		}
		break;
	}
}

string ShowFileMessage(MessageFiles message)
{
	switch(message)
	{
		case MessageFiles::DONTEXIST:
		{
			return "THE FILE DON'T EXIST, CAN'T OPEN.";
		}
		break;
		case MessageFiles::EMPTY:
		{
			return "THE FILE IS EMPTY.";
		}
		break;
		case MessageFiles::BAD:
		{
			return "UNABLE TO READ FILE.";
		}
		break;
		case MessageFiles::EXIST:
		{
			return "THE FILE EXIST.";
		}
		break;
		case MessageFiles::GOOD:
		{
			return "THE FILE IS GOOD.";
		}
		break;
		case MessageFiles::BADFORMAT:
		{
			return "BAD WORKING FORMAT.";
		}
		break;
		case MessageFiles::GOODFORWORK:
		{
			return "THE FILE IS GOOD FOR WORK.";
		}
		break;
		default:
		{
			return "THE MESSAGE FORMAT IS NOT THE CORRECT FOR THE FILE.";
		}
		break;
	}
}