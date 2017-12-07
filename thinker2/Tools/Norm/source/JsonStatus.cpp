
#include <JsonStatus.h>

bool IsJsonEmpty(JSON& json)
{
	return (json.empty()) ? true : false;
}

MessageJson VerifyJson(JSON& json, fstream& file, MessageFiles message, ModeFiles mode)
{
	if(mode == ModeFiles::READ)
	{
		if(message == MessageFiles::GOODFORWORK)
		{
			try
			{
				file >> json;
			}
			catch (const exception& ex)
			{
				return MessageJson::WRONG;
			}

			file.close();

			if(IsJsonEmpty(json))
			{
				return MessageJson::EMPTY;
			}
			else
			{
				return MessageJson::GOODFORWORK;
			}
		}
		else
		{
			return MessageJson::BAD;
		}
	}
	else
	{
		return MessageJson::BADFORMAT;
	}
}

string ShowJsonMessage(MessageJson message)
{
	switch(message)
	{
		case MessageJson::EMPTY:
		{
			return "THE JSON FILE IS EMPTY.";
		}
		break;
		case MessageJson::GOODFORWORK:
		{
			return "THE JSON FILE IS GOOD FOR WORK.";
		}
		break;
		case MessageJson::BAD:
		{
			return "UNABLE TO READ JSON FILE.";
		}
		break;
		case MessageJson::BADFORMAT:
		{
			return "BAD JSON FILE FORMAT.";
		}
		break;
		case MessageJson::WRONG:
		{
			return "THE JSON FILE DON'T HAVE THE CORRECT FORMAT.";
		}
		break;
		default:
		{
			return "THE MESSAGE FORMAT IS NOT THE CORRECT FOR THE JSON FILE.";
		}
		break;
	}
}