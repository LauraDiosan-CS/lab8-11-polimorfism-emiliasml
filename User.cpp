#include "User.h"

bool User::operator==(const User& u)
{
	return (userName == u.userName) and (password == u.password);
}
