#pragma once

namespace HeaderFiles
{
	struct LogIn
	{
		string _username = "";
		string _password = "";
		bool _IsAdmin = false;

		LogIn() = default;
		LogIn(string username, string password) {
			_username = username;
			_password = password;
		}
	};
}