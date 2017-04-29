#ifndef SESSION_H
#define SESSION_H
#include <Wt/Dbo/Session>
#include <Wt/Dbo/ptr>
#include <Wt/Dbo/backend/Sqlite3>
#include <Wt/Auth/Login>

#include "User.h"

namespace dbo = Wt::Dbo;

typedef Wt::Auth::Dbo::UserDatabase<AuthInfo> UserDatabase;

class Session : public dbo::Session
{
public:
  Session(const std::string& sqliteDb);

  Wt::Auth::AbstractUserDatabase& users();
  Wt::Auth::Login& login() { return login_; }


private:
  dbo::backend::Sqlite3 connection_;
  UserDatabase *users_;
  Wt::Auth::Login login_;

};
#endif // SESSION_H
